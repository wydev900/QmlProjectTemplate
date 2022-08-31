cmake_minimum_required(VERSION 3.21)

project(TemplateProject LANGUAGES CXX VERSION 1.0.0)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/app/debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/lib)
    set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/app/debug)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/app/release)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}/lib)
    set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/app/release)
endif()

# Win32 unicode fix and msvc utf8 flag
if(WIN32)
    add_definitions(-DUNICODE)
    if(MSVC)
        add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
        add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
        add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/openmp>")
    endif()
endif()

add_compile_definitions(APP_NAME="${CMAKE_PROJECT_NAME}")
add_compile_definitions(APP_VERSION="${CMAKE_PROJECT_VERSION}")

# qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# options & macro
option(WITH_DEBUG_OUTPUT "Enable debug output" OFF)

# Qt Packages
find_package(Qt6 6.3 COMPONENTS Core Concurrent Quick QuickControls2 Widgets Sql Multimedia REQUIRED)

set(QtModules
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Concurrent
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickControls2
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Multimedia
    )

set(3RDPARTYPATH ${CMAKE_SOURCE_DIR}/3rdparty)

set(RootDirPath "${CMAKE_CURRENT_LIST_DIR}")
set(SrcDirPath "${RootDirPath}/src")

enable_testing()

# 3rdparty
add_subdirectory(3rdparty)

# src
add_subdirectory(src)



