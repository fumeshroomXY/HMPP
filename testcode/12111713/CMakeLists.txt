project(12111713)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GpsInfo.cpp src/PolicemanInfo.cpp src/VideoConfig.cpp src/VideoStorage.cpp src/CameraController.cpp src/VideoRecorder.cpp src/VideoEncrypter.cpp src/TimeManager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:TimeManager,VideoEncrypter,VideoRecorder,CameraController,VideoStorage,VideoConfig,PolicemanInfo,GpsInfo,
# Specification Path: 

