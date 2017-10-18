#pragma once

#include "FileWriter.h"
#include "ConsoleWriter.h"


class WriterFactory
{
public:

	virtual IXmlWriter *createWriter(const string &param) const = 0;

};


class FileFactory : public WriterFactory
{

public:

	virtual IXmlWriter *createWriter(const string &param) const;

};


class ConsoleFactory : public WriterFactory
{

public:

	virtual IXmlWriter *createWriter(const string &param) const;

};

