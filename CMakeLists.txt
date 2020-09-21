cmake_minimum_required(VERSION 3.5)

project (DisparityMap)

set(SOURCES 
		src/main.cpp 
		src/disparitymap.cpp
)


find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
	message(SEND_ERROR "Failed to find OpenCV")
	return()
else()
	include_directories(${OpenCV_INCLUDE_DIR})
endif()


add_executable(DisparityMap ${SOURCES})

target_include_directories(DisparityMap
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(DisparityMap ${OpenCV_LIBS})