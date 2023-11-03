cmake_minimum_required(VERSION 3.5)
project(DevWorkSpace)

set(VERSION_MAJOR 1)
set(VERSION_MINOR_0 5)
set(VERSION_MINOR_1 0)
set(VERSION_PLAIN ${VERSION_MAJOR}.${VERSION_MINOR_0}.${VERSION_MINOR_1})

set(FLTK_INCLUDE_DIR 3rdparty/fltk)


set(DEVWINDOWSRC 
    ${CMAKE_SOURCE_DIR}/src/Window/DevWindow.cpp
)



# add_subdirectory(3rdparty/fltk-1.3.8)
# remember to remove comment bellow when rebuilding flkt.
# file(GLOB FLTK_A_FILES ${PROJECT_SOURCE_DIR}/3rdparty/fltk/lib/*.a)


# add_subdirectory(libgit2)
message(${CMAKE_SOURCE_DIR})



add_executable(${PROJECT_NAME}
WIN32 
main.cpp
${DEVWINDOWSRC}
)


# set (OPTIONAL_LIBS)

# if (WIN32)
# 	list(APPEND OPTIONAL_LIBS opengl32.lib)
# 	list(APPEND OPTIONAL_LIBS glu32.lib)
# 	list(APPEND OPTIONAL_LIBS comctl32.lib)
# 	list(APPEND OPTIONAL_LIBS comdlg32.lib)
# 	list(APPEND OPTIONAL_LIBS gdi32.lib)
# 	list(APPEND OPTIONAL_LIBS ws2_32.lib)
# 	list(APPEND OPTIONAL_LIBS vfw32.lib)
# 	list(APPEND OPTIONAL_LIBS advapi32.lib)
# 	list(APPEND OPTIONAL_LIBS user32.lib)
# 	list(APPEND OPTIONAL_LIBS shell32.lib)
# 	list(APPEND OPTIONAL_LIBS ole32.lib)
# else()
# 	list(APPEND OPTIONAL_LIBS X11)
# endif (WIN32)



include_directories(${PROJECT_SOURCE_DIR}/includes)


target_link_libraries(
	
    ${PROJECT_NAME} 

    xcb
	Xext
    X11
    fltk
    fltk_forms
    fltk_images

)