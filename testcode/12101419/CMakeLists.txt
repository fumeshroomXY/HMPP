project(12101419)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/Videostorage.cpp src/Policemaninfo.cpp src/CameraController.cpp src/Videoconfig.cpp src/Videorecorder.cpp src/GPSInfo.cpp src/Timemanager.cpp src/Videoencrypter.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:Videoencrypter,Timemanager,GPSInfo,Videorecorder,Videoconfig,CameraController,Policemaninfo,Videostorage,
# Specification Path: 

