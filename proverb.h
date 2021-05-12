#ifndef  PROVERB_H
#define PROVERB_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {

	struct proverb {
		string country;
	};

	proverb* proverb_Input(ifstream& ifst);
	void proverb_Output(struct proverb* proverb, ofstream& ofst);
} // end type_phrases namespace
#endif // PROVERB_H

