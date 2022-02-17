include(FetchContent)

include(FetchContent)

FetchContent_Declare(
        xlnt
        GIT_REPOSITORY "https://github.com/tfussell/xlnt"
        GIT_TAG "master"
)

FetchContent_MakeAvailable(xlnt)

cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#Source files here
set(SOURCE_FILES
        include/boxoffice.h
        include/normal.h
        include/reduced.h
        include/ticket.h
        include/movie.h
        include/screening.h
        include/room.h
        include/seat.h
        include/registry.h
        src/boxoffice.cpp
        src/main.cpp
        src/normal.cpp
        src/reduced.cpp
        src/ticket.cpp
        src/movie.cpp
        src/screening.cpp
        src/room.cpp
        src/seat.cpp
        )

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)
target_link_libraries(
        Project
        xlnt)

#TESTs
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        test/TestBoxOffice.cpp
        test/TestTickets.cpp
        src/boxoffice.cpp
        src/main.cpp
        src/normal.cpp
        src/reduced.cpp
        src/ticket.cpp
        src/movie.cpp
        src/screening.cpp
        src/room.cpp
        src/seat.cpp
        )

add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})