#include "Document.h"
#include "Document_parser.h"
#include "Lemm_collection.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;

const int N_MAX_DOC = 10000;


int main(int argc, char** argv)
{

	Document_parser doc_parser;
	vector <vector<int> > doc_coll(N_MAX_DOC, vector<int>(0));
	vector <string> lemm_coll;
	vector <string> doc_str;
	vector <int> query;
	vector <int> doc;


	doc_parser.Read_test_data("test_doc_coll_nums.txt", &doc_coll);

	//doc_parser.Read_docs("test_doc_collection/file_", "test_doc_coll_nums.txt", &doc_coll); // -- Init test doc collection

	//doc_parser.Read_lemmas("association.txt", &lemm_coll);

	//doc_parser.Print_data("output_data.txt");

	doc_parser.Read_query("source_files/query.txt", &query);

	doc_parser.Read_document("source_files/doc.txt", &doc, &doc_str);

	Lemm_collection dict(&doc_str);

	//dict.Init(doc_coll, "LDC_map.txt");

	dict.Init_from_file(doc_coll, "LDC_map.txt");

	Document test_doc(&dict, &query, doc, doc_str);

	test_doc.Divide_into_frags();

	test_doc.Make_annotation();

	test_doc.Print_annotation("RESULT_new.txt", doc_str);

	getchar();

	return 0;
}
