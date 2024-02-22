//#include "Console.cpp"
#include "Collection.cpp"
#include <iostream>

using namespace std;

int main() {

    cout << "Hello, World!" << endl;

    Console* console = new Console(
        "Nintendo",
        "N64",
        1996,
        nullptr //new Cpu("NEC", "VR4300", "93.75 MHz", 1993),
    );
    //console->print();

    //console->setCpu(new Cpu("NEC", "VR4300", "93.75 MHz", 1993));
    //console->print();

    //Console two(*console);
    //cout << "COPY" << endl;
    //two.print();
    //two.getCpu().name = "Hoggerino";
    //two.print();

    Collection col;

    col.test();
    //col.print();

    col.addItem(*console);

    //col.print();
    //col.sortByYear();
    col.sortByName();

    //cout << "SORTED" << endl;
    col.print();

    return 0;
}