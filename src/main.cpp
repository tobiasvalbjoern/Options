#include <iostream>
#include <vector>

#include "OptChars.h"
#include "OptWord.h"
#include "Options.h"
#include "FileHandler.h"
using namespace std;

//we use the global option for single dashes, and local for doble dashes.
//this exercises is used as a template on how to use both.
//we tried to make a base function for numopt, setopstring. This has added
//a complexity that was not needed, if we had just implemented them in the
//children classes
FileHandler fileobj;
OptChars gopt;

void case_f(int argc, const char** argv, int o);
void case_file(int argc, const char** argv);

int main(int argc, char const **argv)
{
	try
	{
		int WordArgs = 0;
		string validOpt = "abof";
		vector<string> validWords{"log","help","file"};

		//while using the global object. It will catch if there is no input
		if (!gopt.setArguments(argc, argv))
		{
			cout
					<< "Could not set arguments in global object. \n"
					<<"Leaving this world."
					<< endl;
			throw(-1);
		}

		//copy dynamically allocated obj to the global class and clean up
		OptWord *opts = new OptWord(argc, (const char**) argv);

		//sets the valid options for '-' commands,
		//count them up and loop them out
		gopt.setOptstring(validOpt);
		int args = gopt.numopt();
		if (args != 0)
		{
			cout << "Valid chars on cmdline: " << args << endl;
			for (int o = 1; o <= args; ++o)
			{
				string str = gopt.getopt();
				if (str != "INVALID")			//don't want to spam "INVALID"
				{
					cout << "Found match: -" << str << endl;

					if (str == "f")
					{
						case_f(argc, argv, o);
					}
				}
			}

		}

		//sets the valid options for '--' commands and count them up
		for (string n : validWords)
		{
			opts->setOptstring(n);
			args = opts->numopt();
			WordArgs += args;
		}
		if (WordArgs != 0)
		{
			cout << "valid words on cmdline: " << WordArgs << endl;

			//loop out the '--' commands. Nested for loop because words options
			// take a string each and needs to be set each time
			for (string n : validWords)
			{
				opts->setOptstring(n);

				for (int o = 1; o <= WordArgs; o++)
				{
					string str = opts->getopt();
					if (str != "INVALID")		//don't want to spam "INVALID"
					{
						cout << "Found match: --" << str << endl;

						if (str == "file")
						{
							case_file(argc, argv);

						}

					}
				}
			}
			delete opts;
		}
	} catch (int x)
	{
		cout << "ErrorID: " << x << endl;
	} catch (exception &s)
	{
		cout << "exception found: " << s.what() << endl;
	} catch (...)
	{
		cout << "something went wrong" << endl;
	}
	return (0);
}

void case_f(int argc, const char** argv, int o)
{
	cout << "Ready to perform some file action."
			<< " The char handler got me here" << endl;
	//fileobj.setFileName("test_file.txt");
	const char* filename = NULL;

	if (argc > o + 1)
	{
		filename = argv[o + 1];
		cout << "Here is the filename:\n " << filename << endl;
	}
	else
		cout << "No file name" << filename << endl;

	fileobj.setFileName(filename);
	fileobj.readFile();
}

void case_file(int argc, const char** argv)
{
	cout << "Ready to perform some file action."
			<< " The word command got me here" << endl;

	const char* filename = NULL;

	for (int a = 1; a < argc; a++)
	{
		if (string(argv[a]) == "--file")
		{
			filename = argv[a + 1];
			cout << "Here is the filename:\n " << filename << endl;
			if (!filename)
				cout << "No file name" << filename << endl;

			fileobj.setFileName(filename);
			fileobj.readFile();
		}

	}

}
