project(20241211)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoConfig.cpp src/PolicemanInfo.cpp src/TimeManager.cpp src/GpsInfo.cpp src/CameraController.cpp src/VideoStorage.cpp src/VideoRecorder.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,VideoRecorder,VideoStorage,CameraController,GpsInfo,TimeManager,PolicemanInfo,VideoConfig,
# Specification Path: 

