#pragma once
#include"MiscWord.h"

//This class is used to store Preposition's.
class Preposition : public MiscWord
{
public:
	Preposition(string, string);

	string getDefinition() override;
};
