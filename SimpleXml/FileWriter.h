#pragma once

#include <fstream>

#include "AXmlWriter.h"

using namespace std;


class FileWriter : public AXmlWriter
{

	string fileName;

protected:

	virtual void storeXmlString(const string &xml) const;

public:
	FileWriter();

	virtual ~FileWriter();

	void setFileName(const string &val);

	const string &getFileName() const;

};

