#pragma once
#include"Word.h"

using namespace std;

//This class is used to store Adjective's.
class Adjective : public Word
{
public:
	Adjective(string, string);

	string getDefinition() override;

};

