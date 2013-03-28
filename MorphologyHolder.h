#ifndef MorphologyHolder_H
#define MorphologyHolder_H

#include "utilit.h"
#include "libs/LemmatizerLib/PLMLineCollection.h"
#include "libs/GraphanLib/GraphmatFile.h"
#include "libs/AgramtabLib/RusGramTab.h"
#include "libs/AgramtabLib/GerGramTab.h"
#include "libs/AgramtabLib/EngGramTab.h"

class CMorphologyHolder
{
public:
	bool							m_bTimeStatis;
	MorphLanguageEnum				m_CurrentLanguage;
	CPlmLineCollection				m_PlmLines;
	CAgramtab*						m_pGramTab;
	CLemmatizer*					m_pLemmatizer;
	CGraphmatFile					m_Graphan;

	CMorphologyHolder();
	~CMorphologyHolder();

	bool GetMorphology(string str, bool bFile, int& CountOfWords);
	bool LoadGraphanAndLemmatizer(MorphLanguageEnum langua);
	void DeleteProcessors();
	DwordVector GetParadigmIdsByNormAndAncode(std::string &str, const std::string &code) const;
	void		string_to_ids(const char *str, DwordVector &ids, bool bNorm) const;
	std::string		id_to_string(long id) const;
	CFormInfo		id_to_paradigm(long id) const;
};



#endif
