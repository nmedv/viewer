cmake_minimum_required(VERSION 3.5)

project(viewer VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Widgets)

set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../opencv/build-mingw64")
set(OpenCV_STATIC true)
find_package(OpenCV REQUIRED)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME}
	src/Dialog.h	
	src/Main.cpp
	src/MainWindow.h
	src/MainWindow.cpp
	src/VideoArea.h
	src/VideoArea.cpp
	src/VideoPlayer.h
	src/VideoPlayer.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt6::Widgets ${OpenCV_LIBS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	MACOSX_BUNDLE TRUE
	WIN32_EXECUTABLE TRUE
)