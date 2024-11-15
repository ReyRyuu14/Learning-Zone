cmake_minimum_required(VERSION 3.5)

project(Search)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
