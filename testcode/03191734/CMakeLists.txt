project(03191734)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/PolicemanInfo.cpp src/VideoConfig.cpp src/CameraController.cpp src/TimeManager.cpp src/GpsInfo.cpp src/VideoRecorder.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:VideoRecorder,GpsInfo,TimeManager,CameraController,VideoConfig,PolicemanInfo,
# Specification Path: 

