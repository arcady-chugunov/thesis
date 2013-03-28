cmake_minimum_required (VERSION 2.6)

set (PROJECT Annotation)
set (LINKER_LANGUAGE CXX)
set (CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -static)

project (${PROJECT})

include_directories (../)
include_directories (../libs/AgramtabLib)
include_directories (../libs/GraphanLib)
include_directories (../libs/LemmatizerLib)

set (LIBRARIES
		AgramtabLib
		PcreRmlLib
		RmlThesLib
		GraphanLib
		LemmatizerLib
		MorphWizardLib
		StructDictLib
		SynanLib
		TrigramLib
		)

foreach (LIBRARY ${LIBRARIES})
#	add_subdirectory (../libs/${LIBRARY}/build bin/${LIBRARY})
	#add_library(${LIBRARY} ../libs/${LIBRARY})
	#set_target_properties(${LIBRARY} PROPERTIES LINKER_LANGUAGE CXX)
	link_directories(../libs/${LIBRARY}/build)
	find_library(${LIBRARY} ${LIBRARY})
endforeach ()
link_directories(../libs/PCRE/build)
find_library(PcreRmlLib PcreRmlLib)
find_library(pcre pcre)

if (MSVC)
	add_definitions (/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	#add_definitions (-Wall -pedantic)
else ()
	message ("Unknown compiler")
endif ()

set (HEADERS ../Document.h ../Document_parser.h ../Lemm_collection.h ../LoadFile.h ../LoadQuery.h ../Ngramms.h ../TextFeatures.h ../io_vector_util.h ../MorphologyHolder.h ../utilit.h)
set (SOURCES ../Document.cpp ../Document_parser.cpp ../Lemm_collection.cpp ../LoadFile.cpp ../Ngramms.cpp ../TextFeatures.cpp ../main.cpp)
set(COMMON ../libs/common/utilit.cpp ../libs/common/gra_descr.cpp ../libs/common/MorhologyHolder.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
source_group ("Common" FILES ${COMMON})

add_executable (${PROJECT} ${HEADERS} ${SOURCES} ${COMMON})

target_link_libraries (${PROJECT} ${LIBRARIES} PcreRmlLib pcre)
set_target_properties(${PROJECT} PROPERTIES LINKER_LANGUAGE CXX)
