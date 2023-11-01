cmake_minimum_required(VERSION 3.5)
project(DevWorkSpace)

set(VERSION_MAJOR 1)
set(VERSION_MINOR_0 5)
set(VERSION_MINOR_1 0)
set(VERSION_PLAIN ${VERSION_MAJOR}.${VERSION_MINOR_0}.${VERSION_MINOR_1})



add_subdirectory(fltk)

# add_subdirectory(libgit2)

message(${CMAKE_SOURCE_DIR})



add_executable(${PROJECT_NAME} WIN32 main.cpp)


set (OPTIONAL_LIBS)

if (WIN32)
	list(APPEND OPTIONAL_LIBS opengl32.lib)
	list(APPEND OPTIONAL_LIBS glu32.lib)
	list(APPEND OPTIONAL_LIBS comctl32.lib)
	list(APPEND OPTIONAL_LIBS comdlg32.lib)
	list(APPEND OPTIONAL_LIBS gdi32.lib)
	list(APPEND OPTIONAL_LIBS ws2_32.lib)
	list(APPEND OPTIONAL_LIBS vfw32.lib)
	list(APPEND OPTIONAL_LIBS advapi32.lib)
	list(APPEND OPTIONAL_LIBS user32.lib)
	list(APPEND OPTIONAL_LIBS shell32.lib)
	list(APPEND OPTIONAL_LIBS ole32.lib)
endif (WIN32)



include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${FLTK_INCLUDE_DIR})

target_link_libraries(
    ${PROJECT_NAME} 
    ${OPTIONAL_LIBS} 
    fltk)