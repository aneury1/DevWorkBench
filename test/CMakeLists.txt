# cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 14)


if(BUILD_TESTING)
    message("Building testing just that....")
    add_executable(testmain testmain.cc)
    target_link_libraries(testmain PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(testmain)
endif()

