cmake_minimum_required(VERSION 3.5)
project(DevWorkSpace)

add_subdirectory(fltk)
add_subdirectory(libgit2)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/fltk fltk)


add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME} fltk)