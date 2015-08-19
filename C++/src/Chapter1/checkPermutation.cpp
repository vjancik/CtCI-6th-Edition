#include <iostream>
#include <string>

using namespace std;

class Permutation {
    //ACSII implementation
    bool permutation;
    public:
        Permutation (string str, string perm) {
            if (str.length() != perm.length()) {
                permutation = false;
                return;
            }

            int char_freq[255] = {0};
            for (int i = 0; i < str.length(); ++i) {
                int val = str[i] + 128;
                char_freq[val] += 1;
            }
            for (int i = 0; i < perm.length(); ++i) {
                int val = perm[i] + 128;
                char_freq[val] -= 1;
            }
            for (int i = 0; i < 255; ++i) {
                if (char_freq[i] != 0) {
                    permutation = false;
                    return;
                }
            }

            permutation = true;
        };
        bool isPermutation () {
            return permutation;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING1 STRING2" << endl <<
        "Determine if STRING1 is a permutation of STRING2." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 3 ) {
        printUsage(argv[0]);
        return 1;
    }

    Permutation str(argv[1], argv[2]);
    if (str.isPermutation())
        cout << "Strings are permutations." << endl;
    else
        cout << "String aren't permutations." << endl;

    return 0;
}
