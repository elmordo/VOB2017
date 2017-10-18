#include "factories.h"


IXmlWriter *FileFactory::createWriter(const string &param) const
{
	FileWriter *result = new FileWriter();
	result->setFileName(param);
	return result;
}

IXmlWriter *ConsoleFactory::createWriter(const string &param) const
{
	return new ConsoleWriter();
}
