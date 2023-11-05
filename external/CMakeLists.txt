# WARNING...
# if you dont want to use FetchContent macro you can add a submodule of this
# git submodule add https://github.com/googletest.git external/googletest
# git submodule //listing the dld. 
# git submodule update --init --recursive


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

# add_executable(
#   hello_test
#   test/testmain.cc
# )
# target_link_libraries(
#   hello_test
#   GTest::gtest_main
# )

include(GoogleTest)
# gtest_discover_tests(hello_test)
