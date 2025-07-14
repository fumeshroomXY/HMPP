project(07111605)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:StorageManager,Saving,CameraController,GPSModule,EncryptionModule,GPS,Frame,TimeManager,VideoConfig,VideoRecorder,PolicemanInfo,
# Specification Path: 

