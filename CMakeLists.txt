cmake_minimum_required(VERSION 3.10) # required
project(arr)  # project name
		
file(GLOB_RECURSE cpp_headers headers/*.hpp)
file(GLOB_RECURSE cpp_sources sources/*.cpp)
set(cpp_srcs ${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

add_library(${PROJECT_NAME} STATIC ${cpp_srcs})
        
# Enable include with <> pair
if(${CMAKE_PROJECT_NAME} STREQUAL "arr")
    target_include_directories(${PROJECT_NAME} PUBLIC . headers tlbx tlbx/headers)
else()
    target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/arr ${CMAKE_SOURCE_DIR}/arr/headers
        ${CMAKE_SOURCE_DIR}/tlbx ${CMAKE_SOURCE_DIR}/tlbx/headers)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PRIVATE tlbx)

# submodules
message(STATUS "project ${CMAKE_PROJECT_NAME}")
if(${CMAKE_PROJECT_NAME} STREQUAL "arr")
    add_subdirectory(tlbx)
    add_subdirectory(examples)
endif()
