#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

class Data{
public:
  Data(const char *fName);
  ~Data();
  void queryData(string queryArgument);
  void close();
private:
  sqlite3 *db;
};

#endif
