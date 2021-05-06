cmake_minimum_required(VERSION 3.5)

project(QTLearn)
#set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\msvc2019_64")
set (CMAKE_PREFIX_PATH "C:\\workspace\\github\\qt5\\qtbase")
find_package(Qt5 REQUIRED Core)
find_package(Threads REQUIRED)

aux_source_directory(./src sourceFiles)


add_executable(${PROJECT_NAME} ${sourceFiles})

target_link_libraries(${PROJECT_NAME} Qt5::Core Threads::Threads)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)