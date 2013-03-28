#!/bin/bash
/usr/bin/c++  \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/Document.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/Document_parser.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/Lemm_collection.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/LoadFile.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/Ngramms.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/TextFeatures.cpp.o \
	CMakeFiles/Annotation.dir/home/rayrafael/Рабочий_стол/annot/Source/main.cpp.o \
	 -o Annotation -rdynamic \
	-L../libs/AgramtabLib/build -L../libs/GraphanLib/build -L../libs/LemmatizerLib/build -L../libs/MorphWizardLib/build -L../libs/StructDictLib/build -L../libs/SynanLib/build -L../libs/TrigramLib/build \
	libAgramtabLib.a libGraphanLib.a libLemmatizerLib.a libMorphWizardLib.a libStructDictLib.a libSynanLib.a libTrigramLib.a
