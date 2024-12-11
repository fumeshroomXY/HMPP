project(12111853)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/VideoStorage.cpp src/VideoEncrypter.cpp src/PolicemanInfo.cpp src/CameraController.cpp src/VideoConfig.cpp src/VideoRecorder.cpp src/TimeManager.cpp src/GpsInfo.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:GpsInfo,TimeManager,VideoRecorder,VideoConfig,CameraController,PolicemanInfo,VideoEncrypter,VideoStorage,
# Specification Path: 

