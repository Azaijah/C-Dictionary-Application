#pragma once
#include"Word.h"

using namespace std;

//This class is used to store Verb's.
class Verb : virtual public Word
{
public:
	Verb(string, string);
	bool isVerb() override;

	string getDefinition() override;
};


