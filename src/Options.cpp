#include "Options.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

Options::Options()
{

	//init
	argC = 0;
	argV = NULL;

	optstring = "";
	count = 1; 			//count is the iterator used to select argV
}

Options::Options(int argc, const char **argv)
{
	argC = argc;
	argV=argv;
	optstring = "";
	count = 1;
}

//reads in the valid options from main
void Options::setOptstring(string &validopt)
{
	//getopt() can't reset count, so rather here than a explicit function
	count = 0;

	//this could be done inside the validopt
	//test if the CHARS are set by the programmer
	if (validopt.length() == 0)
	{
		throw 1;
	}

	optstring = validopt;
}

//invokes getopt() to count how many options are on cmdline
int Options::numopt(void)
{
	//You can never reset count too often
	count = 0;
	int number = 0;
	while (getopt() != "INVALID")
	{
		number++;
	}
	count = 0;
	return (number);
}

/*
 * setArguments is needed if default constructor was used to create an
 * object of this class
 */
bool Options::setArguments(int argc, const char **argv)
{
	if (argc > 1 && argv != NULL)
	{
		argC = argc;
		argV = argv;
		return (true);
	}
	return (false);

}
