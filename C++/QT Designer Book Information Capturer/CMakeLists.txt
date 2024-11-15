cmake_minimum_required(VERSION 3.14)

project(Question_1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Qt6_DIR "C:/Qt/6.7.0/mingw_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Question_1
  main.cpp
  book.h book.cpp
  bookwriter.h bookwriter.cpp
  bookinput.h bookinput.cpp
)
target_link_libraries(Question_1 Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Question_1 Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS Question_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
