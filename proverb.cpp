#include <iostream>
#include <fstream>
#include "proverb.h"

namespace type_phrases {
	// ñèãíàòóðà
	string check_input_string(ifstream& ifst);

	proverb* proverb_Input(ifstream& ifst) {
		proverb* newObj = new proverb();
		if ((newObj->country = check_input_string(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}

	void proverb_Output(struct proverb* proverb, ofstream& ofst) {
		ofst << "Ñountry: " << proverb->country << ";" << endl;
	}
}