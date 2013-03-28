cmake_minimum_required (VERSION 2.6)

set (PROJECT PcreRmlLib)

project (${PROJECT})

set (HEADERS ../pcre_rml.h)
set (SOURCES ../pcre_rml.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
