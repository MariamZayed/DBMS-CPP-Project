#include <iostream>
#include <string>
#include <iostream>
using namespace std;
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <sstream>

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
int checkTableExistence(std::string & path)
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
            //print the file name if existed
            _tprintf(TEXT("%s\n"),ffd.cFileName);
        }
        while (::FindNextFile(hFind, &ffd) == TRUE);
        ::FindClose(hFind);
    }
    else
    {
        printf("Failed to find path: %s", path.c_str());
    }
}


int main()
{
    //check if table existed or not
    std::string  table_name = std::string("C:\\Users\\mylap\\Desktop\\DBMS_Final\\school\\teacher.txt");
    checkTableExistence(table_name);

/////*bring path of current dir *///////
    //table name want to exclude from the full path of this current dir
    char filename[] = "foo";
    // assign in a arr
    char fullFilename[MAX_PATH];
    //pass arr to function to assign the current dir
    GetFullPathName(filename, MAX_PATH, fullFilename, NULL);
    //removing table name from path to bring current dit
    string sperator = "\\";
    vector<string> v = split (fullFilename, sperator);
    v.pop_back();

    return 0;
}
