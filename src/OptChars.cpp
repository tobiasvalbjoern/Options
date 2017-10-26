#include "OptChars.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

OptChars::OptChars()
{
}

OptChars::OptChars(int argc, char const ** argv)
{
	argC=argc;
	argV=argv;
}

//This looks for the CHAR commands starting with '-'
string OptChars::getopt(void)
{
	for (; count < argC; count++)
	{

		//char commands can be stored in a single string, so we loop it by char
		for (size_t j = 0; j < optstring.size(); j++)
		{

			//first element should be '-' and ALWAYS 2 elements long
			if (argV[count][0] == '-' && strlen(argV[count]) == 2)
			{
			if(argV[count][1] == optstring[j]) 	//Is this a valid option?
					{
				count++;
				return (optstring.substr(j,1));	//If yes, return it.
					}
				}
			}
		}

	return ("INVALID");							//If no, return "INVALID"
}
