cmake_minimum_required(VERSION 3.5)

project(QCron LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(QCRON_USE_QT6 "Use Qt6")
if(QCRON_USE_QT6)
    set(QV_QT_LIBNAME Qt6)
else()
    set(QV_QT_LIBNAME Qt5)
endif()

find_package(${QV_QT_LIBNAME} COMPONENTS Core Gui Widgets REQUIRED)

set(LIBCRON_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/Cron.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/CronClock.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/CronData.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/CronRandomization.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/CronSchedule.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/DateTime.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/Task.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include/libcron/TimeTypes.h
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/src/CronClock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/src/CronData.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/src/CronRandomization.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/src/CronSchedule.cpp
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/src/Task.cpp)

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/include
    ${CMAKE_CURRENT_LIST_DIR}/libs/libcron/libcron/externals/date/include
    )


add_executable(QCron
    main.cpp
    QCronJobDaemon.cpp
    QCronJobDaemon.hpp
    ${LIBCRON_SOURCES}
    )

if(NOT MSVC)
        # Assume a modern compiler (gcc 9.3)
        target_compile_definitions (${PROJECT_NAME} PRIVATE -DHAS_UNCAUGHT_EXCEPTIONS)
endif()

target_link_libraries(QCron
    ${QV_QT_LIBNAME}::Core
    ${QV_QT_LIBNAME}::Gui
    ${QV_QT_LIBNAME}::Widgets)
