set(public_headers
		mth.hpp
		trg.hpp
		arr.hpp
		arr1.hpp
		arr2.hpp
		arr2slice.hpp
		arr2sub.hpp
		arr3.hpp
		barr1.hpp
		barr2.hpp
		barr2slice.hpp
		barr2sub.hpp
		barr3.hpp
		darr1.hpp
		darr2.hpp
		darr2slice.hpp
		darr2sub.hpp
		uiarr1.hpp
		uiarr2.hpp
		)

add_library(${PROJECT_NAME}_interface INTERFACE ${public_headers})
target_include_directories(${PROJECT_NAME}_interface INTERFACE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME}_interface INTERFACE ${PROJECT_NAME})
