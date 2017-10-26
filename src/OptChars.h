#ifndef OPTCHARS_H
#define OPTCHARS_H
#include "Options.h"

class OptChars : public Options			   //derived from class Options
{
public:
	OptChars(int argc, char const ** argv);
    OptChars();
    virtual ~OptChars(){};
	string getopt(void);				   //returns all valid CHARS on cmd
};

#endif // OPTCHARS_H
