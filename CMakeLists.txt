cmake_minimum_required(VERSION 3.5)

project(QTLearn)
set(CMAKE_CXX_STANDARD 20)
find_package(Qt6 QUIET COMPONENTS Core DBus StateMachine)
if(Qt6_FOUND)
    message("Qt6 FOUND")
    set(QtLibs Qt6::Core Qt6::DBus Qt6::StateMachine)
    qt6_wrap_cpp(qt_moc_files ${qt_moc_sources})
else()
    message("Qt6 Not FOUND, try Qt5 instead")
    if((${CMAKE_GENERATOR} MATCHES "Visual Studio") AND (${CMAKE_GENERATOR_PLATFORM} MATCHES "ARM64"))
        message(FATAL_ERROR "Windows ARM64 must use Qt6")
    else()
        find_package(Qt5 COMPONENTS REQUIRED Core DBus)
        set(QtLibs Qt5::Core Qt5::DBus)
        qt5_wrap_cpp(qt_moc_files ${qt_moc_sources})
    endif()
endif()
find_package(Threads REQUIRED)

aux_source_directory(./src sourceFiles)


add_executable(${PROJECT_NAME} ${sourceFiles})

target_link_libraries(${PROJECT_NAME} ${QtLibs} Threads::Threads)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)