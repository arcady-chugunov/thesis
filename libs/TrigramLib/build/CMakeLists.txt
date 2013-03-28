cmake_minimum_required (VERSION 2.6)

set (PROJECT TrigramLib)

project (${PROJECT})

set (HEADERS ../stdafx.h ../TagSet.h ../TrigramModel.h)
set (SOURCES ../NGramFile.cpp ../ReadLexFile.cpp ../stdafx.cpp ../TagSet.cpp ../TrigramLemmatizer.cpp ../TrigramModel.cpp ../TrigramSerialize.cpp ../Viterbi.cpp ../ViterbiInfo.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
