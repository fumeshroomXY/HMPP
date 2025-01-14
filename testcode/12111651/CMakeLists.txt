project(12111651)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/VideoStorage.cpp src/GpsInfo.cpp src/PolicemanInfo.cpp src/VideoRecorder.cpp src/VideoConfig.cpp src/TimeManager.cpp src/VideoEncrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoEncrypter,TimeManager,VideoConfig,VideoRecorder,PolicemanInfo,GpsInfo,VideoStorage,CameraController,
# Specification Path: 

