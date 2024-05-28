cmake_minimum_required(VERSION 3.16)

project(media_stuff VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appmedia_stuff
    main.cpp
)

qt_add_qml_module(appmedia_stuff
    URI media_stuff
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES image_handler.h image_handler.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appmedia_stuff PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appmedia_stuff
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appmedia_stuff
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appmedia_stuff
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
