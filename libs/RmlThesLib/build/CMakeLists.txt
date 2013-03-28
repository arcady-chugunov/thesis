cmake_minimum_required (VERSION 2.6)

set (PROJECT RmlThesLib)

project (${PROJECT})

set (HEADERS ../Models.h ../StdRmlThes.h ../Thesaurus.h ../RmlThesConsts.h)
set (SOURCES ../Termins.cpp ../Synonyms.cpp ../Concepts.cpp ../StdRmlThes.cpp ../ThesOborots.cpp ../Thesaurus.cpp ../Models.cpp ../Relats.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
