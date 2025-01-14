project(12111720)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoRecorder.cpp src/PolicemanInfo.cpp src/GpsInfo.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/CameraController.cpp src/TimeManager.cpp src/VideoStorage.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoStorage,TimeManager,CameraController,VideoConfig,VideoEncrypter,GpsInfo,PolicemanInfo,VideoRecorder,
# Specification Path: 

