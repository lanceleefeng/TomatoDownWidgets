cmake_minimum_required(VERSION 3.6)
project(TomatoDownWidgets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        mainwindow.cpp
        mainwindow.h tomato.cpp tomato.h unitlabel.cpp unitlabel.h button.cpp button.h lineedit.cpp lineedit.h db.cpp db.h init.cpp init.h settingmodel.cpp settingmodel.h basemodel.cpp basemodel.h datetime.cpp datetime.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

add_executable(TomatoDownWidgets ${SOURCE_FILES})

target_link_libraries(TomatoDownWidgets Qt5::Core Qt5::Widgets Qt5::Sql)

