project(01171558)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/TimeManager.cpp src/CameraController.cpp src/VideoRecorder.cpp src/GPSInfo.cpp src/PolicemanInfo.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoStorage,VideoEncrypter,VideoConfig,PolicemanInfo,GPSInfo,VideoRecorder,CameraController,TimeManager,
# Specification Path: 

