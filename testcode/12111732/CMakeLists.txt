project(12111732)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/TimeManager.cpp src/VideoStorage.cpp src/PolicemanInfo.cpp src/GpsInfo.cpp src/VideoEncrypter.cpp src/VideoConfig.cpp src/VideoRecorder.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoRecorder,VideoConfig,VideoEncrypter,GpsInfo,PolicemanInfo,VideoStorage,TimeManager,CameraController,
# Specification Path: 

