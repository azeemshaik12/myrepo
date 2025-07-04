cmake_minimum_required(VERSION 3.16)

project(bluetoothscan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Qt 6 required modules (now including Bluetooth)
find_package(Qt6 REQUIRED COMPONENTS Quick Bluetooth)

qt_standard_project_setup(REQUIRES 6.5)

# Define the application executable
qt_add_executable(appbluetoothscan
    main.cpp
)

# Add your QML module with BluetoothScanner C++ sources
qt_add_qml_module(appbluetoothscan
    URI bluetoothscan
    VERSION 1.0
    QML_FILES
        Main.qml
    SOURCES
        bluetoothscanner.h
        bluetoothscanner.cpp
)

# Platform settings for bundle identifier (optional for macOS/iOS)
set_target_properties(appbluetoothscan PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link Qt libraries (add Qt6::Bluetooth)
target_link_libraries(appbluetoothscan
    PRIVATE
        Qt6::Quick
        Qt6::Bluetooth
)

# Install rules
include(GNUInstallDirs)
install(TARGETS appbluetoothscan
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
