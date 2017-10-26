#ifndef FILEHANDLER_H
#define FILEHANDLER_H

class FileHandler
{
public:
	FileHandler();
	virtual ~FileHandler();
	void setFileName(const char* file_user);
	void readFile();


protected:
	//protected vars are inherrited as private
	const char* filename;	//optstring is to be tested against in getopt()
};

#endif
