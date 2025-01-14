project(12101722)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoRecorder.cpp src/TimeManager.cpp src/VideoConfig.cpp src/VideoStorage.cpp src/CameraController.cpp src/GpsInfo.cpp src/VideoEncrypter.cpp src/PolicemanInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:PolicemanInfo,VideoEncrypter,GpsInfo,CameraController,VideoStorage,VideoConfig,TimeManager,VideoRecorder,
# Specification Path: 

