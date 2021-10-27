cmake_minimum_required(VERSION 3.20)

project(
    vector
    VERSION 1.0.0
    DESCRIPTION "Simple vector math library"
    LANGUAGES CXX
    )

# Pokud není hlavním projektem, pravděpodobně nechceme sestavovat testy.
if(DEFINED  PROJECT_NAME)
        set(${PROJECT_NAME}_IS_SUBPROJECT ON)
        message(STATUS "${PROJECT_NAME}_IS_SUBPROJECT: True")
    else()
        set(${PROJECT_NAME}_IS_SUBPROJECT OFF)
        message(STATUS "${PROJECT_NAME}_IS_SUBPROJECT: False")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Výcozí sestavení je Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Ochrana před sestavením přímo v adresáři projektu.
if (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR "Building in-source is not supported!")
    message(STATUS "Create a `build` directory and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

##############################################################################
# Library
##############################################################################
add_library(${PROJECT_NAME} STATIC
    src/vector.cpp
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/vector
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

Include(FetchContent)

##############################################################################
# Testing (only when this is a main project and also not a Python project)
##############################################################################
if (NOT ${PROJECT_NAME}_IS_SUBPROJECT)
    FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.0-preview3
    )

    FetchContent_MakeAvailable(Catch2)

    enable_testing()

    add_executable(${PROJECT_NAME}_test tests/vector_test.cpp)

    target_include_directories(${PROJECT_NAME}_test
            PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/include
                ${CMAKE_CURRENT_SOURCE_DIR}/include/vector
    )

    target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2WithMain)

    add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
endif()


##############################################################################
# Python
##############################################################################
# FetchContent_Declare(
#     pybind11
#     GIT_REPOSITORY https://github.com/pybind/pybind11
#     GIT_TAG        v2.8.0
# )
# FetchContent_MakeAvailable(pybind11)
# FetchContent_GetProperties(pybind11)

# if(NOT pybind11_POPULATED)
#     FetchContent_Populate(pybind11)
#     add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
# endif()

# find_package(pybind11 CONFIG REQUIRED)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pybind11)

# message(${CMAKE_CURRENT_SOURCE_DIR})

# if(NOT pybind11_FOUND)
#     message(FATAL_ERROR "PYBIND NOT FOUND")
#     message("${pybind11_INCLUDE_DIR}")
# endif()

# pybind11_add_module(${PROJECT_NAME}_py
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/vector.cpp)

# include_directories(${PROJECT_NAME}_py
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/src
#         ${CMAKE_CURRENT_SOURCE_DIR}/include
#         ${CMAKE_CURRENT_SOURCE_DIR}/include/vector
#     INTERFACE
#         ${CMAKE_CURRENT_SOURCE_DIR}/include
#     )