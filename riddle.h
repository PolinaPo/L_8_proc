#ifndef  RIDDLE_H
#define RIDDLE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// загадка
	struct riddle {
		string answer; // ответ
	};

	riddle* riddle_Input(ifstream& ifst);
	void riddle_Output(struct riddle* riddle, ofstream& ofst);
} // end type_phrases namespace
#endif // RIDDLE_H