#include <iostream>
#include <string>
#include "ArrayIterator.h"
#include "DictionaryIterator.h"
using namespace std;

int main(int argc, char *argv[])
{
    double arrData[] = { 1.2, 2.3, -3.5};
    ArrayIterator<double> arrayIterator(arrData, sizeof(arrData)/sizeof(arrData[0]));
    while (arrayIterator.HasNext()) {
        cout << arrayIterator.Next() << " ";
    }
    cout << endl;

    cout << "invert output: " << endl;
    while (arrayIterator.HasPrev()) {
        cout << arrayIterator.Prev() << " ";
    }
    cout << endl;

    std::pair<string, int> dictData[] = {{"One", 1}, {"Two",2},{"Three",3}};
    DictionaryIterator<string, int> dictionIterator(dictData, sizeof(dictData) / sizeof(dictData[0]));
    while (dictionIterator.HasNext()) {
        auto p = dictionIterator.Next();
        cout << p.first << ": " << p.second << " ";
    }
    cout << endl;
    cout << "invert output: " << endl;
    while (dictionIterator.HasPrev()) {
        auto p = dictionIterator.Prev();
        cout << p.first << " : " << p.second << " ";
    }
    cout << endl;
    return 0;
}
