
file(GLOB RESOURCES
    "resource/*.qrc"
    "resource/*.rc"
    "qml/*.qrc"
    )

# 添加所有子目录
FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
include_directories(${children})

foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        if(NOT ${child} STREQUAL qml)
            if(NOT ${child} STREQUAL resource)
                if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt)
                    add_subdirectory(${child})
                endif()
            endif()
        endif()
    endif()
endforeach()

if(WITH_DEBUG_OUTPUT)
    add_executable(${PROJECT_NAME} main.cpp  ${RESOURCES})
else()
    add_executable(${PROJECT_NAME} WIN32 main.cpp ${RESOURCES})
endif()


qt_add_qml_module(${PROJECT_NAME}
    URI qml
    VERSION 1.0
    QML_FILES main.qml
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE ${QtModules} CorePlugin)
