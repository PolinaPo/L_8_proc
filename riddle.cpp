#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {
	// ���������
	string check_input_string(ifstream& ifst);

	// ���� ���������� ������� �� �����
	riddle* riddle_Input(ifstream& ifst) {
		riddle* newObj = new riddle();
		if ((newObj->answer = check_input_string(ifst)) != "0") {
			return newObj;
		}
		else {
			return 0;
		}
	}
	// ����� ���������� ������� � ������������� �����
	void riddle_Output(struct riddle* riddle, ofstream& ofst) {
		ofst << "\nAnswer: " << riddle->answer << ";" << endl;
	}
}