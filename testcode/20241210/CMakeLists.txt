project(20241210)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GPSInfo.cpp src/VideoEncrpyter.cpp src/CameraController.cpp src/VideoConfig.cpp src/TimeManager.cpp src/VideoRecorder.cpp src/VideoStorage.cpp src/PolicemanInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:PolicemanInfo,VideoStorage,VideoRecorder,TimeManager,VideoConfig,CameraController,VideoEncrpyter,GPSInfo,
# Specification Path: 

