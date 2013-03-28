cmake_minimum_required (VERSION 2.6)

set (PROJECT StructDictLib)

project (${PROJECT})

set (HEADERS ../Domen.h ../Field.h ../ItemsContainer.h ../LessDomItem.h ../Ross.h ../Signat.h ../StdRoss.h ../StructDictConsts.h ../TempArticle.h ../TextField.h)
set (SOURCES ../ItemsContainer.cpp ../Ross.cpp ../StdRoss.cpp ../TempArticle.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
