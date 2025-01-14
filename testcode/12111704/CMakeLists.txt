project(12111704)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/VideoStorage.cpp src/VideoEncrypter.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/GpsInfo.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:PolicemanInfo,VideoConfig,GpsInfo,TimeManager,VideoRecorder,VideoEncrypter,VideoStorage,CameraController,
# Specification Path: 

