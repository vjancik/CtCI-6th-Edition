#include <iostream>
#include <string>

using namespace std;

class URL {
    //ACSII implementation
    string url;
    public:
        URL (string str) {
            int new_length = 0;
            for (unsigned int i = 0; i < str.length(); ++i) {
                if (str[i] == ' ') new_length+=3;
                else               new_length+=1;
            }
            url.resize(new_length);
            for (unsigned int i = 0, j = 0; i < str.length(); ++i, ++j) {
                if (str[i] == ' ') {
                    url[j] = '%'; url[j+1] = '2'; url[j+2] = '0';
                    j+=2;
                } else {
                    url[j] = str[i];
                }
            }
        };
        string toString() {
            return url;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING" << endl <<
        "Returns the STRING with all spaces replaced by '%20'." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 2 ) {
        printUsage(argv[0]);
        return 1;
    }

    URL url(argv[1]);
    cout << url.toString() << endl;

    return 0;
}
