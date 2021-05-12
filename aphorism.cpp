#include <iostream>
#include <fstream>
#include "aphorism.h"

namespace type_phrases {
	// сигнатура
	string check_input_string(ifstream& ifst);

	aphorism* aphorism_Input(ifstream& ifst) {
		aphorism* newObj = new aphorism();
		if ((newObj->author = check_input_string(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}

	void aphorism_Output(struct aphorism* aphorism, ofstream& ofst) {
		ofst << "\nAuthor's name: " << aphorism->author << ";" << endl;
	}
}