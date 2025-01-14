project(12111538)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GpsInfo.cpp src/VideoConfig.cpp src/VideoEncrypter.cpp src/CameraController.cpp src/VideoStorage.cpp src/TimeManager.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoRecorder,PolicemanInfo,TimeManager,VideoStorage,CameraController,VideoEncrypter,VideoConfig,GpsInfo,
# Specification Path: 

