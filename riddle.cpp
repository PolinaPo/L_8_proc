#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {
	// сигнатура
	string check_input_string(ifstream& ifst);

	// ввод параметров загадки из файла
	riddle* riddle_Input(ifstream& ifst) {
		riddle* newObj = new riddle();
		if ((newObj->answer = check_input_string(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}
	// вывод параметров загадки в форматируемый поток
	void riddle_Output(struct riddle* riddle, ofstream& ofst) {
		ofst << "\nAnswer: " << riddle->answer << ";" << endl;
	}
}