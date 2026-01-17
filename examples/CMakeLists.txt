
# Example executable
set(example_sources
        examples.cpp
        )
		
add_executable(${PROJECT_NAME}_examples ${example_sources})
target_include_directories(${PROJECT_NAME}_examples PRIVATE ${CMAKE_SOURCE_DIR}/tlbx)
target_link_libraries(${PROJECT_NAME}_examples PUBLIC ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}_examples PRIVATE cxx_std_17)

# Code sign to avoid macOS permission dialogs
if(APPLE)
    set_target_properties(${PROJECT_NAME}_examples PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "-"
        XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
        XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    )
endif()
