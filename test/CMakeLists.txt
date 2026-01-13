set(test_headers
        unit-test.hpp
        )

set(test_sources
        arrTest.cpp
        unit-test-main.cpp
        )

set(files ${test_headers} ${test_sources})

# Organize files into groups for Xcode/Visual Studio
source_group("headers" FILES ${test_headers})
source_group("sources" FILES ${test_sources})

add_executable(${PROJECT_NAME}_tests ${files})

target_compile_features(${PROJECT_NAME}_tests PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME}_tests PRIVATE "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/headers")

target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME} gtest)

include(GoogleTest)

gtest_discover_tests(
        ${PROJECT_NAME}_tests
        TEST_PREFIX ${PROJECT_NAME}:
)
