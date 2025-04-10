project(BWC_VideoRecording)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GpsInfo.cpp src/VideoRecorder.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/CameraController.cpp src/PolicemanInfo.cpp src/TimeManager.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoStorage,TimeManager,PolicemanInfo,CameraController,VideoEncrypter,VideoConfig,VideoRecorder,GpsInfo,System,
# Specification Path: 

