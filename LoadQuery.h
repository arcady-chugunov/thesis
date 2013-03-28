#include <sstream>
#include <fstream>

using std::stringstream;
using std::string;

bool LoadQuery(const string &fin_name, vector<string> &query) {
  fstream fin;
  string query_str, token;

  fin.open(fin_name.c_str());

  if(!fin.good()) 
    return 0;

  getline(fin, query_str);

  fin.close();

  stringstream str_stream = stringstream(query_str);

  while (str_stream >> token) {
    query.push_back(token);
  }
  return 1;
}