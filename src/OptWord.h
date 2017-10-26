#ifndef OPTWORD_H
#define OPTWORD_H
#include "Options.h"

class OptWord : public Options			  //derived from class Options
{
public:
    OptWord();
    OptWord(int argc, char const ** argv);
    virtual ~OptWord(){};
	string getopt(void);				  //returns all valid WORDS on cmd
};

#endif // OPTWORD_H
