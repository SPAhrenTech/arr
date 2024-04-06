set(library_sources
		arr_tests.cpp
		test-main.cpp
	)

add_executable(${PROJECT_NAME}_tests ${library_sources})

target_compile_features(${PROJECT_NAME}_tests PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME}_tests PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME} gtest)

include(GoogleTest)

gtest_discover_tests(
	${PROJECT_NAME}_tests
	TEST_PREFIX ${PROJECT_NAME}:
	)
