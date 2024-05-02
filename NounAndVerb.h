#pragma once
#include"Noun.h"
#include"Verb.h"	
#include"Word.h"

//This class is used to store VerbAndNoun's.
class VerbAndNoun : public Verb, public Noun
{
public:
	VerbAndNoun(string,string);
	bool isVerb() override;
	bool isNoun() override;

	string getDefinition() override;


};

