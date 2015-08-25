#include <iostream>
#include <string>

using namespace std;

class Rotation {
    //ACSII implementation
    bool rotation;
    public:
        Rotation (string str1, string str2) {
            string str = str1+str1;
            size_t found = str.find(str2);
            if (str1.length() == str2.length() && found != string::npos)
                rotation = true;
            else
                rotation = false;
        };
        bool isRotation () {
            return rotation;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING1 STRING2" << endl <<
        "Determine if STRING2 is a rotation of STRING1." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 3 ) {
        printUsage(argv[0]);
        return 1;
    }

    Rotation str(argv[1], argv[2]);
    if (str.isRotation())
        cout << "String 2 is a rotation of string 1." << endl;
    else
        cout << "String 2 is not a rotation of string 1." << endl;

    return 0;
}
