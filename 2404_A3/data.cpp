#include "data.h"
#include <iostream>

Data::Data(const char *fName){
  sqlite3_open(fName, &db);
}

Data::~Data(){
  cout << "\nDATABASE OBJECT DELETED\n";
}

static int callback(
  //callback function that will be called by sqlite3_exec() for each
  //row in the query result table when the query has completed.
  void * data, //pass through data provided to sqlite3_exec() [4th argument]
  int argc, //Number of columns in answer table row
  char ** argv, //array of strings representing table row values
  char ** azColName //array of strings representing column names
  ){
    //cout << (const char *) data << "\n";
	//print values for the row
    for (int i=0; i<argc; i++){
      cout << argv[i] << ", ";
    }
    cout << "\n";
    return 0;
  }


void Data::queryData(string queryArgument){
  int execReturn;
  const char * dataPassed = "callback called";
  char * queryError = 0;
  if (queryArgument.empty()){
    return;
  }else {
    const char * sqlArgrument = queryArgument.c_str();
    execReturn = sqlite3_exec(db, sqlArgrument, callback, (void *) dataPassed, &queryError);

  }
  if (execReturn == SQLITE_OK){
    cout << "\nSQL QUERY HAS SUCCEEDED\n";
  }else{
    cout << "\nERRORY EXECUTING THE FOLLOWING COMMAND: " << queryError << "\n";
    sqlite3_free(queryError);

  }
}

void Data::close(){
  sqlite3_close(db);
}
