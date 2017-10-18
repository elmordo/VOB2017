#include "FileWriter.h"


void FileWriter::storeXmlString(const string &xml) const
{
	ofstream output(fileName.c_str(), ios::out);
	output << xml << endl;
	output.close();
}

FileWriter::FileWriter()
{
}


FileWriter::~FileWriter()
{
}

void FileWriter::setFileName(const string &val)
{
	fileName = val;
}

const string &FileWriter::getFileName() const
{
	return fileName;
}
