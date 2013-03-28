#pragma once

#include "LoadFile.h"
#include "TextFeatures.h"
#include "io_vector_util.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Document_parser
{
public:
  Document_parser(void);
  ~Document_parser(void);

  vector<vector<int> > *doc_collection;
  vector<string> *lemm_collection;

  void Read_docs(const string &file_name_prefix, const string &fout_name, vector<vector<int> > *doc_collection_in );
  void Read_query(const string &fin_name, vector<int> *query);
  void Read_document(const string &fin_name, vector<int> *doc, vector<string> *doc_str);
  void Read_lemmas(const char *filename, vector<string> *lemm_collection_in);
  void Print_data(const char *filename);
  void Read_test_data(const string &fin_name, vector<vector<int> > *doc_collection_in);
};

