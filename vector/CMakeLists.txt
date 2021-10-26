cmake_minimum_required(VERSION 3.20)

# Pokud není hlavním projektem, pravděpodobně nechceme sestavovat testy.
if(NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
    message(STATUS "IS_SUBPROJECT: True")
else()
    set(NOT_SUBPROJECT OFF)
endif()

project(
    vector
    VERSION 1.0.0
    DESCRIPTION "Simple vector math library"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

##############################################################################
# Testing
##############################################################################
if (NOT IS_SUBPROJECT)
    Include(FetchContent)

    FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.0-preview3
    )

    FetchContent_MakeAvailable(Catch2)

    enable_testing()

    add_executable(vector_unit_test tests/vector_test.cpp)
    target_link_libraries(vector_unit_test PRIVATE Catch2::Catch2WithMain)
    add_test(NAME vector_unit_test COMMAND vector_unit_test)
endif()