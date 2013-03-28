#include "Document_parser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>


using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::string;
using std::stringstream;
using std::ostringstream;
using std::sort;

Document_parser::Document_parser(void)
{
}


Document_parser::~Document_parser(void)
{
}



void Document_parser::Read_test_data(const string &fin_name, vector<vector<int> > *doc_collection_in) 
{
  ifstream fin(fin_name.c_str());
  
  int num;
  vector<vector<int> >::iterator doc_iter(doc_collection_in->begin());

  string str;

   cout << "parsing test data..." << endl;

  while (fin.good()) {
    getline(fin, str);
    stringstream strstr(str);

    while (strstr >> num)
      doc_iter->push_back(num);
    
    getline(fin, str);
    doc_iter++;
  }

  doc_collection = doc_collection_in;

  cout << "done!" << endl;
}

void Document_parser::Read_docs(const string &file_name_prefix, const string &fout_name, vector<vector<int> > *doc_collection_in )
{
  string str;
  char symb;

  ofstream fout(fout_name.c_str());
  
  int num;
  vector<vector<int> >::iterator doc_iter(doc_collection_in->begin());

  cout << "parsing document collection..." << endl;

  for (int i = 0; i < 3000; i++) {

    CMorphologyHolder holder;

    cout << i << ": " << endl;

    char *ch_num;

    ostringstream num;
    num << i;
    string name = file_name_prefix+num.str()+".txt";

//    string name = file_name_prefix+std::to_string((long long)i)+".txt";

    LoadFile(name, &holder);
    TextFeatures text(&holder);

    const CGraphmatFile* Gr = &(holder.m_Graphan);
    CLemmatizer* m_pLemmatizer = holder.m_pLemmatizer;
    int iter = 0;

    //ofstream fout("output.txt");

    vector<CFormInfo> results;
    results.reserve(5);


    int word_position = 0;

    for (iter = 0; iter < Gr->GetTokensCount(); iter++) //начало
    {
      
      if (m_pLemmatizer->GetLanguage() == Gr->GetTokenLanguage(iter)) { //смотрим что слово на русском
	
	        string InputWordStr = Gr->GetToken(iter); 
	        m_pLemmatizer->CreateParadigmCollection(false, InputWordStr, !Gr->HasDescr(iter, OLw), true, results);	        
	        //string input_form = results[0].m_InputWordBase;
          if (!results.empty()) {
            string base_form = results[0].GetWordForm(0);
            /*int tmp_lemm_id = GetLemmID(base_form);
            if (tmp_lemm_id < 0) { //если слово новое -> добавить в словарь
              tmp_lemm_id *= -1;
              fout << base_form << ' ' << tmp_lemm_id << endl;
            }*/
            int id = results[0].GetParadigmId();
            if (id == -1) 
              doc_iter->push_back(-2); //unknown word!!
            else
              doc_iter->push_back(id);
            
            
           //cout << results[0].GetWordForm(0);
        }
      } else {
        if (Gr->IsOneFullStop(iter)) {
          //string token = Gr->GetToken(iter);
          doc_iter->push_back(-1);
        }
      }
    }

    results.clear();

    //save new doc
    fout << *doc_iter << endl << endl;

    doc_iter++;
  }

  fout.close();

  doc_collection = doc_collection_in;

  cout << "done!" << endl;

}

/*void Document_parser::Print_data( const char *filename )
{
  ofstream fout(filename);

  for (vector<vector<int> >::iterator it = doc_collection->begin(); it != doc_collection->end(); ++it) {
    fout << "<BEGIN_DOC>" << endl;
    for (vector<int>::iterator itt = it->begin(); itt != it->end(); ++itt) {
      fout << *itt << ' ';
    }
    fout << endl << "<END_DOC>" << endl;
  }
}

void Document_parser::Read_lemmas(const char *filename, vector<string> *lemm_collection_in)
{
  ifstream fin(filename);

  lemm_collection = lemm_collection_in;
  string str, lemm;
  int lemm_id;
  
  lemm_collection->push_back("000");

  cout << "parsing lemmas..." << endl;


  while (fin.good())
  {
    getline(fin, str);
    stringstream(str) >> lemm;
    lemm_collection->push_back(lemm);
  }

  fin.close();

  cout << "done!" << endl;
}*/

void Document_parser::Read_query( const string &fin_name, vector<int> *query )
{
  CMorphologyHolder holder;

  LoadFile(fin_name, &holder);
  TextFeatures text(&holder);

  const CGraphmatFile* Gr = &(holder.m_Graphan);
  CLemmatizer* m_pLemmatizer = holder.m_pLemmatizer;
  int iter = 0;

  //ofstream fout("output.txt");

  vector<CFormInfo> results;
  results.reserve(5);


  cout << "parsing query..." << endl;

  for (iter = 0; iter < Gr->GetTokensCount(); iter++) //начало
  {

    if (m_pLemmatizer->GetLanguage() == Gr->GetTokenLanguage(iter)) { //смотрим что слово на русском

      string InputWordStr = Gr->GetToken(iter); 
      m_pLemmatizer->CreateParadigmCollection(false, InputWordStr, !Gr->HasDescr(iter, OLw), true, results);	        

      if (!results.empty()) {
        //string base_form = results[0].GetWordForm(0);

        int id = results[0].GetParadigmId();

        if (id != -1) 
          query->push_back(id); //unknown word!!
        

        //cout << results[0].GetWordForm(0);
      } 
    }
  }

  results.clear();

  cout << "done!" << endl;
}

void Document_parser::Read_document(const string &fin_name, vector<int> *doc, vector<string> *doc_str)
{

  CMorphologyHolder holder;

  MorphLanguageEnum English_lang;

  GetLanguageByString("ENGLISH", English_lang);

  LoadFile(fin_name, &holder);
  TextFeatures text(&holder);

  const CGraphmatFile* Gr = &(holder.m_Graphan);
  CLemmatizer* m_pLemmatizer = holder.m_pLemmatizer;
  int iter = 0;

  //ofstream fout("output.txt");

  vector<CFormInfo> results;
  results.reserve(5);

  cout << "parsing input document..." << endl;

  for (iter = 0; iter < Gr->GetTokensCount(); iter++) //начало
  {
      
    if (m_pLemmatizer->GetLanguage() == Gr->GetTokenLanguage(iter)) { //смотрим что слово на русском
	
	      string InputWordStr = Gr->GetToken(iter); 
	      m_pLemmatizer->CreateParadigmCollection(false, InputWordStr, !Gr->HasDescr(iter, OLw), true, results);	        

        if (!results.empty()) {
          //string base_form = results[0].GetWordForm(0);
          doc_str->push_back(InputWordStr);

          int id = results[0].GetParadigmId();

          if (id == -1) 
            doc->push_back(-4); //unknown word!!
          else
            doc->push_back(id);
            
            
          //cout << results[0].GetWordForm(0);
        } 
    } else if (Gr->IsOneFullStop(iter)) {
      //string token = Gr->GetToken(iter);
      doc->push_back(-1);
      doc_str->push_back(".");
    } else if (Gr->GetTokenLanguage(iter) == English_lang) { //если слово на английском, пока непонятно что делать
      /*string InputWordStr = Gr->GetToken(iter); 
      
      
      doc->push_back(-2);
      doc_str->push_back(InputWordStr);
      */ 
    }
  }

  results.clear();

  cout << "done!" << endl;
}
