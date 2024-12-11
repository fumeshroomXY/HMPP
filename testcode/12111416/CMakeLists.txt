project(12111416)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/GpsInfo.cpp src/VideoConfig.cpp src/VideoStorage.cpp src/VideoRecorder.cpp src/CameraController.cpp src/TimeManager.cpp src/PolicemanInfo.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,PolicemanInfo,TimeManager,CameraController,VideoRecorder,VideoStorage,VideoConfig,GpsInfo,
# Specification Path: 

