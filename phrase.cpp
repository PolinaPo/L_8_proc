#include <iostream>
#include <fstream>
#include "phrase.h"

namespace type_phrases {

	string check_input_string(ifstream& ifst)
	{
		string temp = "";
		if (!ifst.eof()) {
			getline(ifst, temp);
			return temp;
		}
		else {
			cout << "|Input file ended|" << endl;
			return "0";
		}
	}

	phrase* phrase_Input(ifstream& ifst) {
		phrase* newObj;
		string ev("");
		string k("");
		getline(ifst, k);
		if (k != "") {
			switch (atoi(k.c_str()))
			{
			case 1:
				newObj = new phrase;
				if ((newObj->phrase = aphorism_Input(ifst)) == 0) {
					return 0;
				}
				if ((newObj->content = check_input_string(ifst)) == "0") {
					return 0;
				}
				if ((ev = check_input_string(ifst)) == "0") {
					return 0;
				}
				try {
					newObj->eval = stoi(ev);
					if (newObj->eval < 0 || newObj->eval > 10) {
						cout << "|Evaluetion value is not in the range 0-10|" << endl;
						return 0;
					}
				}
				catch (invalid_argument e) {
					cout << "|Caught Invalid Argument Exception for evaluetion|" << endl;
					return 0;
				}
				newObj->key = phrase::type::APHORISM;
				break;
			case 2:
				newObj = new phrase;
				if ((newObj->phrase = proverb_Input(ifst)) == 0) {
					return 0;
				}
				if ((newObj->content = check_input_string(ifst)) == "0") {
					return 0;
				}
				if ((ev = check_input_string(ifst)) == "0") {
					return 0;
				}
				try {
					newObj->eval = stoi(ev);
					if (newObj->eval < 0 || newObj->eval > 10) {
						cout << "|Evaluetion value is not in the range 0-10|" << endl;
						return 0;
					}
				}
				catch (invalid_argument e) {
					cout << "|Caught Invalid Argument Exception for evaluetion|" << endl;
					return 0;
				}
				newObj->key = phrase::type::PROVERB;
				break;
			case 3:
				newObj = new phrase;
				if ((newObj->phrase = riddle_Input(ifst)) == 0) {
					return 0;
				}
				if ((newObj->content = check_input_string(ifst)) == "0") {
					return 0;
				}
				if ((ev = check_input_string(ifst)) == "0") {
					return 0;
				}
				try {
					newObj->eval = stoi(ev);
					if (newObj->eval < 0 || newObj->eval > 10) {
						cout << "|Evaluetion value is not in the range 0-10|" << endl;
						return 0;
					}
				}
				catch (invalid_argument e) {
					cout << "|Caught Invalid Argument Exception for evaluetion|" << endl;
					return 0;
				}
				newObj->key = phrase::type::RIDDLE;
				break;
			default:
				cout << "|There are no such type of phrases|" << endl;
				for (unsigned short i = 0; i < 3; i++) {
					k = check_input_string(ifst);
					if (k == "0") {
						break;
					}
				}
				return 0;
			}
			return newObj;
		}
		else {
			cout << "|Missing an empty string|" << endl;
			return 0;
		}
	}

	bool phrase_Output(struct phrase* phrase, ofstream& ofst) {
		if (phrase->key == phrase::type::APHORISM) {
			aphorism_Output((aphorism*)phrase->phrase, ofst);
			ofst << "Aphorism: " << phrase->content << "\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else if (phrase->key == phrase::type::PROVERB) {
			proverb_Output((proverb*)phrase->phrase, ofst);
			ofst << "Proverb: " << phrase->content << "\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else if (phrase->key == phrase::type::RIDDLE) {
			riddle_Output((riddle*)phrase->phrase, ofst);
			ofst << "Riddle: " << phrase->content << "\n" << "Evaluetion: " << phrase->eval << "." << endl;
			return true;
		}
		else {
			ofst << "Incorrect phrase!" << endl;
			return false;
		}
	}
}