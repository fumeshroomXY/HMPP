project(12111800)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/TimeManager.cpp src/VideoRecorder.cpp src/PolicemanInfo.cpp src/VideoEncrypter.cpp src/GpsInfo.cpp src/CameraController.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoConfig,VideoStorage,CameraController,GpsInfo,VideoEncrypter,PolicemanInfo,VideoRecorder,TimeManager,
# Specification Path: 

