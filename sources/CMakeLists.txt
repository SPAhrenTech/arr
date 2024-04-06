# Main library
set(library_sources
	mth.cpp
	trg.cpp
	arr.cpp
	arr1.tem
	arr2.tem
	arr2slice.tem
	arr2sub.tem
	arr3.tem
	barr1.cpp
	barr2.cpp
	barr2slice.cpp
	barr2sub.cpp
	barr3.cpp
	darr1.cpp
	darr2.cpp
	darr2slice.cpp
	darr2sub.cpp
	uiarr1.cpp
	uiarr2.cpp
	)

option(${PROJECT_NAME}_STATIC_LIB "Make ${PROJECT_NAME} a static library" ON)

if (${PROJECT_NAME}_STATIC_LIB)
    add_library(${PROJECT_NAME} STATIC ${library_sources})
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-D${PROJECT_NAME}_STATIC_DEFINE")
else ()
    set(CMAKE_MACOSX_RPATH 1)
    add_library(${PROJECT_NAME} SHARED ${library_sources})
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/headers")
#target_link_libraries(${PROJECT_NAME} PUBLIC courierr fmt nanodbc)

target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic>
        )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})

if (${PROJECT_NAME}_COVERAGE)
    add_coverage(${PROJECT_NAME})
endif ()
