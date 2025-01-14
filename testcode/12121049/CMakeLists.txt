project(12121049)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoConfig.cpp src/VideoEncrypter.cpp src/CameraController.cpp src/VideoRecorder.cpp src/VideoStorage.cpp src/TimeManager.cpp src/GpsInfo.cpp src/PolicemanInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:PolicemanInfo,GpsInfo,TimeManager,VideoStorage,VideoRecorder,CameraController,VideoEncrypter,VideoConfig,
# Specification Path: 

