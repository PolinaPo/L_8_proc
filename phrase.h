#ifndef  PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_phrases {
	// структура, обощающа€ все имеющиес€ изречени€
	struct phrase {
		enum type { APHORISM, PROVERB, RIDDLE };
		type key;
		string content;
		short eval;
		void* phrase;
	};

	string check_input_string(ifstream& ifst);
	phrase* phrase_Input(ifstream& ifst);
	bool phrase_Output(struct phrase* phrase, ofstream& ofst);
} // end type_phrases namespace
#endif // PHRASE_H