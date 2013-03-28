cmake_minimum_required (VERSION 2.6)

set (PROJECT AgramtabLib)

project (${PROJECT})

set (HEADERS ../agramtab_.h ../eng_consts.h ../EngGramTab.h ../ger_consts.h ../GerGramTab.h ../morph_const.h ../rus_consts.h ../RusGramTab.h ../StdGramtab.h)
set (SOURCES ../agramtab_.cpp ../EngGramTab.cpp ../GerGramTab.cpp ../RusGramTab.cpp ../StdGramtab.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} SHARED ${HEADERS} ${SOURCES})
