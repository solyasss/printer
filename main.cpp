#include "printer.h"
#include <iostream>

using namespace std;

int main()
{
    Queue printer;

    printer.queue("Tamara", 2);
    printer.queue("Kate", 1);

    printer.print();
    printer.print();

    printer.display_history();

    return 0;
}
