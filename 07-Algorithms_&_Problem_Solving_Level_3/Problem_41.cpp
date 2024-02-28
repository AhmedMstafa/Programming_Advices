#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String?\n";
    getline(cin, S);
    return S;
}



void Splice(string S1, string Delim, string arr[100], short &Length) {
    string sWord = "";
    short pos = 0;
    while((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            Length++;
            arr[Length - 1] = sWord;
        }
        S1.erase(0, (pos + Delim.length()));
    }

    if (S1 != "")
        Length++;
        arr[Length - 1] = S1;
}

string RevesedString(string S1) {
    string Array[10];
    short Length = 0;
    string Delim = " ";
    Splice(S1, Delim, Array, Length);
    string S2 = "";
    for (short i = 0; i < Length; i++) {
        S2 += Array[Length - i - 1] + Delim;
    }
    return S2.substr(0, (S2.length() - Delim.length()));
}


vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    string sWord = "";
    short pos = 0;
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);

        S1.erase(0, (pos + Delim.length()));
    }

    if (S1 != "")
        vString.push_back(S1);

    return vString;
}

string ReverseWordsInString(string S1) {
    vector<string> vString;
    string S2 = "";

    vString = SplitString(S1, " ");

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin()) {
        --iter;
        S2 += *iter + " ";
    }

    return S2.substr(0, (S2.length() - 1));

}

int main()
{
    string S1 = ReadString();
    cout << "String after reversing words:\n";
    cout << RevesedString(S1);
    
    cout << "\nProgramming Advices :\n";
    cout << RevesedString(S1);
}
