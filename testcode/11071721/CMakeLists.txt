project(11071721)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCE_FILES src/Student.cpp src/CustomerRegistration.cpp src/Test1.cpp src/main.cpp)

set(HEADER_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# Project Info: 
# IncludedClass:Test1,    CustomerRegistration,    Student,    ,   Student,   ,  Student,  , Student, 
# Specification Path: 

