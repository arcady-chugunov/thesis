cmake_minimum_required (VERSION 2.6)

set (PROJECT MorphWizardLib)

project (${PROJECT})

set (HEADERS ../FormInfo.h ../OperationMeter.h ../wizard.h)
set (SOURCES ../wizard.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
link_directories(../../PCRE/build)
find_library(PcreRmlLib PcreRmlLib)

add_library (${PROJECT} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT} PcreRmlLib)
