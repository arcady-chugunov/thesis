// ==========  This file is under  LGPL, the GNU Lesser General Public Licence
// ==========  Dialing Syntax Analysis (www.aot.ru)
// ==========  Copyright by Dmitry Pankratov, Igor Nozhov, Alexey Sokirko


#ifndef __SENTENCESCOLLECTION_H_
#define __SENTENCESCOLLECTION_H_


#include "Sentence.h"
#include "../common/utilit.h"


class CSentencesCollection  
{
public:
	CSentencesCollection();
	~CSentencesCollection();
	vector<CSentence*>						m_vectorSents;
	bool									m_bEnableProgressBar;
	bool									m_bLogProcessedSentence;

	bool CreateOptions(MorphLanguageEnum langua);
	bool InitializeProcesser();
	bool ProcessData(const CPlmLineCollection* piPlmLine);
	void ClearSentences();
	void ClearOptions();
	void put_SilentMode(bool newVal);
	//void SetThesaurus(UINT ThesId, const CThesaurus* Thes);
	void SetLemmatizer(const CLemmatizer* R);
	void SetOborDic(const CDictionary* D);
	void SetEnableAllThesauri(bool Value);
	const CSyntaxOpt* GetOpt() const 
	{
		return m_pSyntaxOptions;
	};


protected:
	
	CSyntaxOpt*								m_pSyntaxOptions;



	/*
	 ���� m_bDeleteEqualPrimitiveClauseVariants  ��� ��������� ������ ���� ����� true,
	 �  ��� VisualSynan - false.
	 ���� �� ������, ����� ���������  ��� ��������������� ��������, 
	 ������  � ��������� �� �������� ����(!). ��������, ���� � ������ ���� ��� 
	 ����� �1 � �2,	 �1 - ������ � ����� ����������, �2 - ����� � ����� ���������,
	 ����� �� ���� ��������� ��������� ���� (�����).
	 ��� �����, ����� ��������� �� ����������  ���������� ��������.
	*/
	bool	m_bDeleteEqualPrimitiveClauseVariants;

	bool ReadAndProcessSentences(const CPlmLineCollection* piPLMLinePtr);
};

#endif //__SENTENCESCOLLECTION_H_
