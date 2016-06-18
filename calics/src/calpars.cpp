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


#include <iostream>
using namespace std;

// todo:
// Define unordered_set of text patterns.
// In next step it could be defined in the file and read into unordered_set
// during initialization.


void parse(string filename)
{

	//todo:
	// unordered_set count method should be used to check is word
	// much to the stored word pattern.


	string out_filename = "";

    fstream outfile;
    outfile.open ("data.txt",ios_base::out);
    !outfile.is_open();
    if (!outfile)
    {
       cout<<"Error writing to file!";
       return 0;
    }
    else
    {
    cout<<"Please enter a string to be written to the file:\n";

    //cin>>w_content;  // With this, "Hey You" will be stored as "Hey" only.
                       //The operator >> skips only leading whitespace.
                       //It stops extracting when it reaches the end of a word.
    getline(cin,w_content);

    cout<<"Writing to file...\n";
    //send data to file before closing
    outfile<<w_content;
    outfile.close();
    }

    fstream infile;
    infile.open("data.txt",ios_base::in);
    if (!infile)
    {
        cout<<"Error reading file!";
        return 0;
    }
    else
    {
    cout<<"\nReading from file...\n";
    //read data in before closing
    getline(infile,r_content);
    cout<<"The file contents are:\n";
    cout<<r_content;
    infile.close();
    }



}



int main() {

	//todo:
	// Extract filename from the arguments.


	cout << "Start" << endl; // prints !!!Hello World!!!
	return 0;
}
