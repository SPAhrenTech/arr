cmake_minimum_required(VERSION 3.10) # required

project(arr)  # project name
		
file(GLOB_RECURSE cpp_headers headers/*.hpp headers/*.tem)
file(GLOB_RECURSE cpp_sources sources/*.cpp)
set(cpp_srcs ${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

# Organize files into groups for Xcode/Visual Studio
source_group("headers" FILES ${cpp_headers})
source_group("sources" FILES ${cpp_sources})
source_group("" FILES ${PROJECT_NAME}.hpp)

# Configure .tem files to be treated as C++ files
file(GLOB tem_files headers/*.tem)
#set_source_files_properties(${tem_files} PROPERTIES LANGUAGE CXX)

add_library(${PROJECT_NAME} STATIC ${cpp_srcs})
        
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set(modules_dir "")
else()
    set(modules_dir "${CMAKE_SOURCE_DIR}/")
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/headers
    ${modules_dir}tlbx ${modules_dir}tlbx/headers)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PRIVATE tlbx)

# submodules
message(STATUS "project ${CMAKE_PROJECT_NAME}")
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    add_subdirectory(tlbx)
    add_subdirectory(examples)
endif()

option(${PROJECT_NAME}_BUILD_TESTING "Build the testing tree" ON)

if (${PROJECT_NAME}_BUILD_TESTING)
    # Only add googletest if tlbx is the main project
    if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
        enable_testing()
        set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
        set(CMAKE_SUPPRESS_REGENERATION ON CACHE BOOL "" FORCE)
        add_subdirectory(googletest)
    endif()
    add_subdirectory(test)
endif()
