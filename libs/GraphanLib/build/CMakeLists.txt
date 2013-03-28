cmake_minimum_required (VERSION 2.6)

set (PROJECT GraphanLib)

project (${PROJECT})

set (HEADERS ../abbrev.h ../Consent.h ../graline.h ../GraphanDicts.h ../GraphmatFile.h ../HTMLConv.h ../StdGraph.h ../UnitHolder.h)
set (SOURCES ../abbrev.cpp ../C_desc.cpp ../Consent.cpp ../Cs_hiera.cpp ../graline.cpp ../GraphanDicts.cpp ../GraphmatFile.cpp ../HtmlConv.cpp ../Nc_desc.cpp ../Oborots.cpp ../Sentences.cpp ../StdAfx.cpp ../UnitHolder.cpp ../Writegra.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
