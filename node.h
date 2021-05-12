#ifndef  NODE_H
#define NODE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	struct phrase;

	struct node {
		phrase* info;
		node* next;
		node* prev;
	};

	bool node_Add(struct container* currentList, ifstream& ifst);
	bool node_Output(struct node* headNode, int pos, ofstream& ofst);
	struct node* get_node(struct node* head, int index);
} // end type_phrases namespace
#endif // NODE_H
