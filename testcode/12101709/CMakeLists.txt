project(12101709)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/VideoStorage.cpp src/VideoConfig.cpp src/PolicemanInfo.cpp src/GpsInfo.cpp src/TimeManager.cpp src/VideoRecorder.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,VideoRecorder,TimeManager,GpsInfo,PolicemanInfo,VideoConfig,VideoStorage,CameraController,
# Specification Path: 

