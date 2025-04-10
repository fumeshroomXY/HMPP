project(03191415)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoRecorder.cpp src/TimeManager.cpp src/CameraController.cpp src/GpsInfo.cpp src/System.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:System,GpsInfo,CameraController,TimeManager,VideoRecorder,
# Specification Path: 

