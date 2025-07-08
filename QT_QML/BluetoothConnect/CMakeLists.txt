cmake_minimum_required(VERSION 3.16)

project(bluetooth_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Bluetooth)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appbluetooth_app
    main.cpp
)

qt_add_qml_module(appbluetooth_app
    URI bluetooth_app
    VERSION 1.0
    QML_FILES
        Main.qml
    SOURCES
        bluetoothmanager.h
        bluetoothmanager.cpp
)

set_target_properties(appbluetooth_app PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appbluetooth_app
    PRIVATE Qt6::Quick Qt6::Bluetooth
)

include(GNUInstallDirs)
install(TARGETS appbluetooth_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
