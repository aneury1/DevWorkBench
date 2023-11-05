## this code is taken from youtube channel, codeforyourself.

find_package(Git QUIET)

if(GIT_FOUND)
    option(UPDATE_SUBMODULES "Check submodules during build" OFF)
    if(NOT UPDATE_SUBMODULES)
        message("this feature if off, we wont update submodules..")
        return ()
    endif()

    execute_process(COMMAND ${GIT_EXECUTABLE} submodule
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    OUTPUT_VARIABLE_EXISTING_SUBMODULES
                    RESULT_VARIABLE RETURN_CODE)
    
    message(STATUS "Updating git submodules:\n${EXISTING_SUBMODULES}")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule --update --init --recursive
                    OUTPUT_VARIABLE_EXISTING_SUBMODULES
                    RESULT_VARIABLE RETURN_CODE)

    if(NOT RETURN_CODE EQUAL "0")
        message(WARNING "Cannot update submodules. Git command failed")
        return()
    endif()
    message("This feature has finish")     
endif()