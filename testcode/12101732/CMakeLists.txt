project(12101732)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoStorage.cpp src/VideoEncrypter.cpp src/VideoRecorder.cpp src/GpsInfo.cpp src/CameraController.cpp src/PolicemanInfo.cpp src/VideoConfig.cpp src/TimeManager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:TimeManager,VideoConfig,PolicemanInfo,CameraController,GpsInfo,VideoRecorder,VideoEncrypter,VideoStorage,
# Specification Path: 

