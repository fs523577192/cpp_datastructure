#include <fstream>
#include "testSorting.cpp"
#include "../../main/sorting/selectionSort.cpp"

using namespace std;
int main(int argc, char** argv) {
    ofstream fileOutputStream;
    fileOutputStream.open("testSelectionSort.log", ofstream::out | ofstream::ate | ofstream::app);
    cout << (testSorting(&fileOutputStream, selectionSort) ? "true" : "false") << endl;
    fileOutputStream.close();
}