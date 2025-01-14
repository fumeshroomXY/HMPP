project(12111816)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoRecorder.cpp src/VideoStorage.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/CameraController.cpp src/TimeManager.cpp src/GpsInfo.cpp src/PolicemanInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:PolicemanInfo,GpsInfo,TimeManager,CameraController,VideoConfig,VideoEncrypter,VideoStorage,VideoRecorder,
# Specification Path: 

