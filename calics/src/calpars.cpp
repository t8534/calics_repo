//============================================================================
// Name        : calpars.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// calpars file.ics
// Take file.ics as a parameter an write into file.txt all lines
// which begin with key word set defined.
//
// todo:
//
// 1.
// File name as parameter.
//
// 2.
// Output file name based on input one, plus "_out"
//
// 3.
// Separate each description section with empty line.
//
// 4.
// Only one return from the function.
//


#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;


// Define unordered_set of text patterns.
// todo: In next step it could be defined in the file and read into
// unordered_set during initialization.
//
//todo replace with unordered_set if you have c++11 compiler.
//     Also, initialization below is C++11 specific.
//set<string> keys = {"DTSTART;",	"DESCRIPTION:"};
// This is for older versions:
string init[] = { "DTSTART;", "DESCRIPTION:"};
set<string> keys(init, init + 2);



//unsigned int parse(const string ifname)
unsigned int parse()
{
	unsigned int ret = 0;  // 0 or 1 ?
	const string ofname = "out.txt";
	ifstream infile;
	ofstream outfile;
	string line;

	//test
	string ifname = "sample.ics";

	//todo:
	// unordered_set count method should be used to check is word
	// much to the stored word pattern.

	//infile.open(ifname.c_str(), std::ifstream::in);    //todo: replace, C++11 have string.
	infile.open(ifname.c_str());
	//if (!infile.is_open())
    if (!infile)  // same as: if (myfile.good())
    {
       cout << "Error opening input file:" << ifname << endl;
       ret = 1;
       return ret;
    }

	//outfile.open(ofname.c_str(), std::ofstream::out);
    outfile.open(ofname.c_str());
    //if (!outfile.is_open())
    if (!outfile)  // same as: if (myfile.good())
    {
    	infile.close();
    	cout<<"Error opening output file:" << ofname << endl;
    	ret = 1;
    	return ret;
    }

    //while( outfile.good() )
    while( getline(infile, line)) // same as: while (getline( myfile, line ).good())
    {
    	// First approach, find a keys word in the line.
    	for (set<string>::iterator it = keys.begin(); it != keys.end(); ++it)
    	{
        	//Note: "found!" will be printed if s2 is a substring of s1, both s1 and s2 are of type std::string.
        	if (line.find(*it) != std::string::npos) {
        	    std::cout << "Found!: " << line << '\n';
            	outfile << line << endl;
        	}
    	}

    	// ? Second approach, extract first label from line and use set.find()


    	// Using find()
    	/*
    	set<std::string>::const_iterator got = keys.find(line);
    	if ( got == keys.end() )
    		cout << "Not found in myset, find(), line: " << line << endl;
    	else
    		cout << *got << " is in myset, find(), line: " << endl;
		*/

    	// Using count()
    	/*
        if (keys.count(line) != 0)
          cout << " is an element of myset, count(), line: " << line << endl;
        else
          cout << " is not an element of myset, count(), line: " << line << endl;
		*/

    }


    infile.close();
    outfile.close();

    return ret;
}



int main() {

	//todo:
	// Extract filename from the arguments.


	cout << "Start" << endl;
	parse();
	cout << "Stop" << endl;

	return 0;
}

