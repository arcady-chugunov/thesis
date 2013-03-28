cmake_minimum_required (VERSION 2.6)

set (PROJECT LemmatizerLib)

project (${PROJECT})

set (HEADERS ../LemmaInfoSerialize.h ../Lemmatizers.h ../MorphAutomat.h ../MorphAutomBuilder.h ../MorphDict.h ../MorphDictBuilder.h ../Paradigm.h ../PLMLineCollection.h ../Predict.h ../StaticVectorMap.h ../Statistic.h ../StdMorph.h)
set (SOURCES ../CreatePredictionBase.cpp ../Lemmatizers.cpp ../MorphAutomat.cpp ../MorphAutomBuilder.cpp ../MorphDict.cpp ../MorphDictBuilder.cpp ../Paradigm.cpp ../PLMLineCollection.cpp ../Predict.cpp ../Statistic.cpp ../StdMorph.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
