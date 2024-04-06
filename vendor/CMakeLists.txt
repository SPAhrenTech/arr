include(initialize-submodules)
initialize_submodules()

# googletest library
if (${PROJECT_NAME}_BUILD_TESTING AND NOT TARGET gtest)

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GTEST ON CACHE BOOL "" FORCE)
 
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)

endif ()
