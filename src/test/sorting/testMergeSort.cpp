#include <fstream>
#include "testSorting.cpp"
#include "../../main/sorting/mergeSort.cpp"

using namespace std;
int main(int argc, char** argv) {
    ofstream fileOutputStream;
    fileOutputStream.open("testMergeSort.log", ofstream::out | ofstream::ate | ofstream::app);
    cout << (testSorting(&fileOutputStream, mergeSort) ? "true" : "false") << endl;
    fileOutputStream.close();
}