cmake_minimum_required(VERSION 3.16)

project(AuroraCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(AuroraCore )

#include(GNUInstallDirs)
#install(TARGETS AuroraCore
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)

#add_subdirectory(core)
add_subdirectory(editor)
