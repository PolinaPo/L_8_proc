#ifndef  PROGRAM_H
#define PROGRAM_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {

	enum type { APHORISM, PROVERB };

	struct aphorism {
		type k;
		string author;
	};

	struct proverb {
		type k;
		string country;
	};

	struct phrase {		
		string content;
		type key;
		//void* obj;
	};

	struct node {
		phrase* info;
		node* next;
		node* prev;
	};

	struct container { // list type
		int size;
		node* head; // pointer to the first item in the list
		node* tail;
	};

	void container_Init(container* list);
	void container_Clear(struct container* list);
	void container_Fill(struct container* list, ifstream &ifst);
	void container_Output(struct container* list, ofstream& ofst);

	bool node_Add(struct container* currentList, ifstream &ifst);
	bool node_Output(struct node* headNode, int pos, ofstream& ofst);

	aphorism* aphorism_Input(ifstream& ifst);
	void aphorism_Output(struct aphorism* aphorism, ofstream& ofst);

	proverb* proverb_Input(ifstream& ifst);
	void proverb_Output(struct proverb* proverb, ofstream& ofst);

	phrase* phrase_Input(ifstream& ifst);
	bool phrase_Output(struct phrase* phrase, ofstream& ofst);
} // end type_phrases namespace
#endif // PROGRAM_H
