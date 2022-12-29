#include <iostream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

// split string to a vector
vector<string> split (string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos)
    {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// finding if table is existed in DB
bool checkTableExistence(string & path)
{
    int counter = 0;
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    // Start iterating over the files in the path directory.
    hFind = ::FindFirstFileA (path.c_str(), &ffd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do // Managed to locate and create an handle to that folder.
        {
            counter++;
//            //print the file name if existed
//            _tprintf(TEXT("%s\n"),ffd.cFileName);

        }
        while (::FindNextFile(hFind, &ffd) == TRUE);
        ::FindClose(hFind);
        return TRUE;
    }
    else
    {
        printf("Failed to find path: %s", path.c_str());
        return FALSE;
    }
}

// bring path of current dir
string getDir()
{
    //table name want to exclude from the full path of this current dir
    char filename[] = "foo";
    // assign in a arr
    char fullFilename[MAX_PATH];
    //pass arr to function to assign the current dir
    GetFullPathName(filename, MAX_PATH, fullFilename, NULL);
    //removing table name from path to bring current dir
    string separator = "\\";
    vector<string> path_vector = split (fullFilename, separator);
    path_vector.pop_back();

    string correct_path= "";
    for(vector<string>::iterator i=path_vector.begin(); i!=path_vector.end(); ++i)
    {
        correct_path = correct_path + (*i+"\\");
    }
    return correct_path;
}

void checkExistenceReturn(){
    if(checkTableExistence(check_table_existence) == FALSE){
            cout<<" :("<<endl;
    }
    else{
        alterOperation();
    }
}

void alterOperation(){
    if(){
        if(prompt[2] == "add"){
            string column_name = prompt[3];
            string data_type = prompt[4];

            // add operation in  Alter query
            string add(column_name,data_type){
                ifstream table_content("C:\\Users\\mylap\\Desktop\\DBMS_Final\\school\\student.txt");

                if (table_content.good()){
                    string first_Line;

                    getline(table_content, first_Line);
                    first_Line =first_Line + "," + column_name;
                    table_content.close();
                }
            }
                // rename operation in  Alter query
                // drop operation in  Alter query
        }
    }
}

int main()
{
    // get current DB dir
    string path = getDir();

    // simulation user prompt till rest of team make the function
    string prompt[5] = {"alter table", "schools\\student.txt", "add", "age", "int"};

    // get table name from another class
    string table_name = prompt[1];

    // check if table existed or not
    string check_table_existence = string(path+table_name);
    checkExistenceReturn(check_table_existence);

    // start of Alter query operation
    alterOperation();

//    ifstream stream("filename.txt");
//
//// Get and drop a line
//stream.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
//
//// Get and store a line for processing.
//// std::getline() has a third parameter the defaults to '\n' as the line
//// delimiter.
//std::string line;
//std::getline(stream,line);
//
//std::string word;
//stream >> word; // Reads one space separated word from the stream.

    return 0;
}
