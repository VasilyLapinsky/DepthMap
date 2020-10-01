cmake_minimum_required(VERSION 3.5)

# project name
project (DisparityMap)

# source files
set(SOURCES 
		src/main.cpp
		src/StereoImagePreprocessor
		src/DisparityMapMaker
		src/DisparityMapWriter
		src/DepthMapMaker
		src/DepthImageMaker
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
add_executable(DisparityMap ${SOURCES})

# adding resource file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Qf25.txt
    ${EXECUTABLE_OUTPUT_PATH} COPYONLY)

# adding include dir
target_include_directories(DisparityMap
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(DisparityMap ${OpenCV_LIBS})

