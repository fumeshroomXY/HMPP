project(12101500)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/CameraController.cpp src/Videorecorder.cpp src/Gpsinfo.cpp src/Videoconfig.cpp src/Policemaninfo.cpp src/Videostorage.cpp src/Videoencrypter.cpp src/Timemanager.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:Timemanager,Videoencrypter,Videostorage,Policemaninfo,Videoconfig,Gpsinfo,Videorecorder,CameraController,
# Specification Path: 

