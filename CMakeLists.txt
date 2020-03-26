cmake_minimum_required(VERSION 3.10)

project(solid_trans VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}")

find_package(OpenCV REQUIRED)


add_executable(main "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/canvas.cpp")
target_include_directories(main PUBLIC ${OpenCV_INCLUDE_DIRS} ${PROJECT_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS} Transformations)



add_library(Transformations STATIC "${PROJECT_SOURCE_DIR}/src/Transformations.cpp")
target_include_directories(Transformations PUBLIC ${PROJECT_INCLUDE_DIRS})