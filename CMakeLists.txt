
cmake_minimum_required(VERSION 3.20)

project(example
    VERSION 1.0.0
    DESCRIPTION "Very nice project"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    message(STATUS "This project is a top-level one")
else()
    message(STATUS "This project has a top-level one called `${CMAKE_PROJECT_NAME}`")
endif()

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(vector)

configure_file(version.tpl version.hpp)

add_executable(example example.cpp)

target_link_libraries(example PRIVATE vector)

target_include_directories(example
    PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

# option(USE_CGV "Use tutorial provided math implementation" ON)
