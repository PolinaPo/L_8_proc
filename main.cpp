#include <iostream>
#include <fstream>
#include "container.h"
#include "sort.h"

using namespace std;
namespace type_phrases {
    // Сигнатуры требуемых функций
    void aphorism_Out(struct container* list, ofstream& ofst);
}
using namespace type_phrases;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Incorrect command line!\n"
             << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);
    if (!ifst.is_open()) {
        cout << "Input file is not open!" << endl;
    }
    else {
        ofstream ofst(argv[2]);
        if (!ofst.is_open())
        {
            cout << "Output file is not open!" << endl;
        }
        else {
            cout << "Start" << endl;
            container* c = new container;
            container_Init(c);
            container_Fill(c, ifst);
            cout << "Filled container" << endl;
            sort(c->size, c->head);
            cout << "Sorted container" << endl;
            container_Output(c, ofst);
            cout << "Output container" << endl;
            ofst << endl;
            aphorism_Out(c, ofst);
            cout << "Output of aphorisms only" << endl;
            container_Clear(c);
            cout << "Empty container" << endl;
            container_Output(c, ofst);
            cout << "Stop" << endl;

            ifst.close();
            ofst.close();
        }
    }
    system("pause");
    return 0;
}