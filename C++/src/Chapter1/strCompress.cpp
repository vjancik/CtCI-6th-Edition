#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Compressed {
    //ACSII implementation
    string compressed;
    public:
        Compressed (string str) {
            ostringstream compressedStream;
            int countConsecutive = 0;
            for (unsigned int i = 0; i < str.length(); ++i) {
               ++countConsecutive;
               if (str[i] != str[i+1] || i == str.length() - 1) {
                   compressedStream << str[i] << countConsecutive;
                   countConsecutive = 0;
               }
            }
            compressed = (str.length() <= compressedStream.str().length()) ? str : compressedStream.str();
        };
        string toString() {
            return compressed;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING" << endl <<
        "Returns the compressed version of STRING, if shorter, if not, the original." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 2 ) {
        printUsage(argv[0]);
        return 1;
    }

    Compressed compstr(argv[1]);
    cout << compstr.toString() << endl;

    return 0;
}
