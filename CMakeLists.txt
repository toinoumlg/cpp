cmake_minimum_required(VERSION 3.10)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find folders containing source/ and include/
file(GLOB children LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(child ${children})
    if(IS_DIRECTORY "${child}"
            AND IS_DIRECTORY "${child}/source"
            AND IS_DIRECTORY "${child}/include")

        get_filename_component(target_name "${child}" NAME)

        file(GLOB_RECURSE sources
                "${child}/source/*.cpp"
                "${child}/source/*.cc"
                "${child}/source/*.cxx"
        )

        if(sources)
            add_executable(${target_name} ${sources})

            target_include_directories(${target_name}
                    PRIVATE "${child}/include"
            )

            message(STATUS "Target found: ${target_name}")
        endif()
    endif()
endforeach()
