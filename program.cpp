#include <iostream>
#include <fstream>
#include "program.h"

namespace type_phrases {
	void container_Init(container* list) {
		list->size = 0;
		list->head = NULL;
		list->tail = NULL;
	}

	void container_Clear(struct container* list) {
		if (list->head == NULL) return;
		else {
			node* currentNode;
			for (int i = 0; i < list->size; i++) {
				currentNode = list->tail;
				list->tail = list->tail->prev;
				free(currentNode);
			}
			list->head = NULL;
			list->tail = NULL;
			list->size = 0;
		}		
	}

	aphorism* aphorism_Input(ifstream& ifst) {
		aphorism* newObj = new aphorism();
		getline(ifst, newObj->author);
		return newObj;
	}

	proverb* proverb_Input(ifstream& ifst) {
		proverb* newObj = new proverb();
		getline(ifst, newObj->country);
		return newObj;
	}

	phrase* phrase_Input(ifstream& ifst) {
		phrase* newObj;
		string k;
		getline(ifst, k);
		switch (atoi(k.c_str()))
		{
		case 1:
			newObj = new phrase;
			newObj = (phrase*)aphorism_Input(ifst);
			getline(ifst, newObj->content);
			newObj->key = APHORISM;
			break;
		case 2:
			newObj = new phrase;
			newObj = (phrase*)proverb_Input(ifst);
			getline(ifst, newObj->content);
			newObj->key = PROVERB;
			break;
		default:
			cout << "There are no such type of phrases!" << endl;
			return 0;
		}
		return newObj;
	}

	bool node_Add(struct container* currentList, ifstream& ifst) {
		struct node* newNode = new node;
		newNode->info = phrase_Input(ifst);
		if (newNode->info == 0) {
			delete(newNode);
			return false;
		}
		if (currentList->head == NULL) {
			currentList->head = newNode;
			currentList->tail = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else {
			newNode->next = NULL;
			newNode->prev = currentList->tail;
			currentList->tail->next = newNode;
			currentList->tail = newNode;
		}
		return true;
	}

	void container_Fill(struct container* list, ifstream& ifst) {
		while (!ifst.eof()) {
			if (node_Add(list, ifst)) {
				(list->size)++;
			}
		}
	}

	void aphorism_Output(struct aphorism* aphorism, ofstream& ofst) {
		ofst << "Author's name: " << aphorism->author << ";" << endl;
	}

	void proverb_Output(struct proverb* proverb, ofstream& ofst) {
		ofst << "Ñountry: " << proverb->country << ";" << endl;
	}

	bool phrase_Output(struct phrase* phrase, ofstream& ofst) {
		if (phrase->key == APHORISM) {
			aphorism_Output((aphorism*)phrase, ofst);
			ofst << "Aphorism: " << phrase->content << "." << endl;
			return true;
		}
		else if (phrase->key == PROVERB) {
			proverb_Output((proverb*)phrase, ofst);
			ofst << "Proverb: " << phrase->content << "." << endl;
			return true;
		}
		else {
			ofst << "Incorrect phrase!" << endl;
			return false;
		}
	}

	bool node_Output(struct node* headNode, int pos, ofstream& ofst) {
		node* currentNode = headNode;
		for (int i = 0; i < pos; i++) {
			currentNode = currentNode->next;
		}
		if (!phrase_Output(currentNode->info, ofst)) {
			cout << "Cannot to output phrase!" << endl;
			return false;
		}
		return true;
	}

	void container_Output(struct container* list, ofstream& ofst) {
		if (list->size == 0) {
			cout << "|List is empty!|" << endl;
			return;
		}
		ofst << "Container contains " << list->size << " elements." << endl;
		cout << "|Container contains " << list->size << " elements.|" << endl;
		for (int i = 0; i < list->size; i++) {
			if (!node_Output(list->head, i, ofst)) {
				cout << "Error in node #" << i << " output" << endl;
			}
		}
	}
}