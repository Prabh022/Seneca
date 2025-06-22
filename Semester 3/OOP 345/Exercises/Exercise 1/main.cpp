#include <iostream>
#include <fstream>
#include "FoodOrder.h"

using namespace std;
using namespace seneca;

int main(int argc, char* argv[]) {
    // TODO: Echo command-line arguments
    for (int i = 1; i < argc; ++i) {
        cout << i << ": " << argv[i] << endl;
    }

    // Loop through each file passed as argument
    for (int i = 1; i < argc; ++i) {
        ifstream file(argv[i]);

        cout << "--------------------------" << endl;
        cout << "Orders from " << argv[i] << ":" << endl;
        cout << "--------------------------" << endl;

        if (file) {
            // Read and set tax and discount rate
            file >> g_taxrate;
            file.ignore();  // skip comma or newline
            file >> g_dailydiscount;
            file.ignore(1000, '\n');  // skip rest of the line

            FoodOrder order;
            while (file) {
                order.read(file);
                order.display();
            }
        }
        else {
            cout << "Cannot open file [" << argv[i] << "]. Skipping..." << endl;
        }

        cout << "--------------------------" << endl;
    }

    return 0;
}
