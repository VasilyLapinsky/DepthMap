cmake_minimum_required(VERSION 3.5)

# project name
project (DepthMap)

# source files
set(SOURCES 
		src/main.cpp
		src/StereoImagePreprocessor
		src/DisparityMapMaker
		src/DisparityMapWriter
		src/DepthMapMaker
		src/DepthBfMapMaker
		src/DepthByQImageMaker
		src/DepthByBfImageMaker
		src/dispmapvideotesting
		src/depthmapvideotesting
)

# adding papackages
find_package(OpenCV REQUIRED)
if(NOT OpenCV_FOUND)
	message(SEND_ERROR "Failed to find OpenCV")
	return()
else()
	include_directories(${OpenCV_INCLUDE_DIR})
endif()

# adding exe
add_executable(DepthMap ${SOURCES})

# adding resource file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Qf25.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# adding include dir
target_include_directories(DepthMap
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(DepthMap ${OpenCV_LIBS})

