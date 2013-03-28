cmake_minimum_required (VERSION 2.6)

set (PROJECT SynanLib)

project (${PROJECT})

set (HEADERS ../FormatCallerInit.h ../HomonymsKiller.h ../RusClause.h ../RusFormatCaller.h ../RusGroup.h ../RusOborot.h ../RusPlmLine.h ../RusSentence.h ../RusSyntaxOpt.h ../RusThesaurus.h ../RusWord.h ../StdSynan.h)
set (SOURCES ../Adverbs.cpp ../AnalyticalForms.cpp ../BaseRules.cpp ../foreign_term.cpp ../FormatCallerInit.cpp ../FragCoord.cpp ../FragDisrupt.cpp ../FragPustycha.cpp ../gen_chains.cpp ../Gleiche.cpp ../HomonymsKiller.cpp ../Names.cpp ../noun_adjunct_group.cpp ../NSO.cpp ../Numbers.cpp ../Participles.cpp ../prepositions.cpp ../RuleForSimilarNounGroupClauses.cpp ../RusBuildInitialClauses.cpp ../RusClause.cpp ../RusFormatCaller.cpp ../RusGroup.cpp ../RusOborot.cpp ../RusParenthesis.cpp ../RusPlmLine.cpp ../RusSentence.cpp ../RusSyntaxOpt.cpp ../RusThesaurus.cpp ../RusWord.cpp ../Selective.cpp ../similar_adjs.cpp ../similar_advs.cpp ../similar_common.cpp ../similar_infs.cpp ../similar_noun_groups.cpp ../similar_numerals.cpp ../StdSynan.cpp ../SynanDash.cpp ../SynSubjPred.cpp ../Verbs.cpp)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})
