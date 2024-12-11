project(12111400)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoConfig.cpp src/CameraController.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/PolicemanInfo.cpp src/GpsInfo.cpp src/VideoEncrypter.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoStorage,VideoEncrypter,GpsInfo,PolicemanInfo,TimeManager,VideoRecorder,CameraController,VideoConfig,
# Specification Path: 

