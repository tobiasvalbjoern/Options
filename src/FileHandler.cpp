#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "FileHandler.h"

using namespace std;

FileHandler::FileHandler()
{
	filename = NULL;
}

FileHandler::~FileHandler()
{

}

void FileHandler::setFileName(const char* file_user)
{
	filename = file_user;
}


void FileHandler::readFile()
{
	cout << "Reading the log" << endl;

	ifstream infile(filename);
	if (infile.is_open())
	{
		// we need a buffer, but don't know how big. Find out
		infile.seekg(0, ios::end);
		// Now the read pointer are at the end of the file, i.e. tellg will
		// tell us the position which is equal to the length.
		long int len = infile.tellg();
		// Go to the beginning again
		infile.seekg(0, ios::beg);
		cout << "there are " << len << " bytes in the file" << endl;

		// Allocate the buffer
		char *buf = new char[len];
		// Read from the file into the buffer
		infile.read(buf, len);
		infile.close();
		cout << "This was read from the file: " << endl << buf << endl;
		// Deliver back what you borrowed
		delete[] buf;
	}
	else
	{
		cout << "was not able to open the file for reading" << endl;
		return;
	}

	ofstream outfile;
	outfile.open(filename, std::ios_base::app);

	if (outfile.is_open())
	{
		// current date/time based on current system
		time_t now = time(0);

		// convert now to string form
		char* dt = ctime(&now);
		outfile << "\nDate and time for the last read: " << dt<<endl;
	}
	else
	{
		cout << "was not able to open the file for writing" << endl;
		return;
	}

	return;
}
