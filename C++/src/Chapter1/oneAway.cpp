#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Diff {
    //ACSII implementation
    int oneAway;
    public:
        Diff (string str1, string str2) {
            if (abs((int)(str1.length() - str2.length())) > 1) {
                oneAway = 2;
                return;
            }
            string s1 = str1.length() < str2.length() ? str1 : str2;
            string s2 = str1.length() < str2.length() ? str2 : str1;
            
            unsigned int index1 = 0, index2 = 0;
            bool foundDiff = false;
            while (index2 < s2.length() && index1 < s1.length()) {
                if (s1[index1] != s2[index2]) {
                    if (foundDiff) {
                        oneAway = 2;
                        return;
                    }
                    foundDiff = true;
                    if (s1.length() < s2.length()) {
                        ++index2;
                    } else {
                        ++index1; ++index2;
                    }
                } else {
                    ++index1; ++index2;
                }
            }
            if (!foundDiff && s1.length() == s2.length())
                oneAway = 0;
            else
                oneAway = 1;
        }
        int isOneAway () {
            return oneAway;
        }

};

void printUsage (char* progName) {
    cout << "Usage: " << progName << " STRING1 STRING2" << endl <<
        "Determine if STRING1 is one edit distance away from STRING2." << endl;
}

int main (int argc, char* argv[]) {
    if (argc < 3 ) {
        printUsage(argv[0]);
        return 1;
    }

    Diff str(argv[1], argv[2]);
    if (str.isOneAway()==2)
        cout << "Strings are more than one edit distance away from each other." << endl;
    else if (str.isOneAway()==1)
        cout << "Strings are one edit distance away from each other." << endl;
    else
        cout << "Strings are identical." << endl;

    return 0;
}
