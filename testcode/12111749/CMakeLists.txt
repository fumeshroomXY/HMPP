project(12111749)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoStorage.cpp src/CameraController.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/GpsInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:GpsInfo,VideoConfig,VideoEncrypter,TimeManager,VideoRecorder,PolicemanInfo,CameraController,VideoStorage,
# Specification Path: 

