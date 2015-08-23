#include <iostream>
#include <string>

using namespace std;

class Unique {
    //ACSII implementation
    bool unique;
    public:
        Unique (string str) {
            if (str.length() > 255) {
                unique = false;
                return;
            }

            bool char_set[255] = {false};
            for (unsigned int i = 0; i < str.length(); ++i) {
                int val = str[i] + 128;
                if (char_set[val]) {
                    unique = false;
                    return;
                }
                char_set[val] = true;
            }
            unique = true;
        };
        bool isUnique () {
            return unique;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING" << endl <<
        "Determine if all characters in STRING are unique." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 2 ) {
        printUsage(argv[0]);
        return 1;
    }

    Unique str(argv[1]);
    if (str.isUnique())
        cout << "String is unique." << endl;
    else
        cout << "String is not unique." << endl;

    return 0;
}
