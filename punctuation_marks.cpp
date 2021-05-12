#include "phrase.h"

namespace type_phrases {
	int num_punct_marks(struct phrase* phrase) {
		string punctM = ".,;:\"!?()-";
		unsigned short int cnt = 0; // От 0 до 65535
		for (unsigned int i = 0; i < phrase->content.length(); i++) {
			for (unsigned j = 0; j < punctM.length(); j++) {
				if (phrase->content[i] == punctM[j]) {
					if (cnt > 65535) {						
						return -1;
					}
					cnt++;
				}
			}
		}
		return cnt;
	}
}