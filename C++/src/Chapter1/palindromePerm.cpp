#include <iostream>
#include <string>

using namespace std;

class palindromePerm {
    //ACSII implementation
    bool palPerm;
    public:
        palindromePerm (string str) {
            bool one_odd = false;
            int char_freq[255] = {0};
            for (unsigned int i = 0; i < str.length(); ++i) {
                int val = str[i] + 128;
                char_freq[val] += 1;
            }

            for (int i = 0; i < 255; ++i) {
                if (char_freq[i] % 2 == 1) {
                    if (str.length() % 2 == 0) {//even length string
                        palPerm = false;
                        return;
                    } else if (one_odd == false) {//one_odd allowed
                        one_odd = true;
                    } else { 
                        palPerm = false;
                        return;
                    }
                }
            }

            palPerm = true;
        };
        bool isPermutation () {
            return palPerm;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING" << endl <<
        "Determine if STRING is a permutation of a palindrome." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 2 ) {
        printUsage(argv[0]);
        return 1;
    }

    palindromePerm str(argv[1]);
    if (str.isPermutation())
        cout << "String is a palindrome permutation." << endl;
    else
        cout << "String isn't a palindrome permutation." << endl;

    return 0;
}
