#include <fstream>
#include "testSorting.cpp"
#include "../../main/sorting/bubbleSort.cpp"

using namespace std;
int main(int argc, char** argv) {
    ofstream fileOutputStream;
    fileOutputStream.open("testBubbleSort.log", ofstream::out | ofstream::ate | ofstream::app);
    cout << (testSorting(&fileOutputStream, bubbleSort) ? "true" : "false") << endl;
    fileOutputStream.close();
}