#ifndef OPTIONS_H_
#define OPTIONS_H_
#include <string>


using namespace std;
class Options
{
public:
    Options(); // Default constuctor needed if a global object is created
    Options (int argc, char const ** argv);
    virtual ~Options(){};
    bool setArguments (int argc, const char **argv); // Needed if the default constuctor was used
    void setOptstring(string &validopt);
	virtual string getopt(void) = 0;	//=0 makes the class abstract
	int numopt(void);

protected: 				//protected vars are inherrited as private
	int argC,count;
	const char **argV;


	string optstring;	//optstring is to be tested against in getopt()

};

#endif /* OPTIONS_H_ */
