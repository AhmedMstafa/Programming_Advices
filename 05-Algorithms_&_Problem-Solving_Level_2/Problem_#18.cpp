#include <iostream>
#include <string>
using namespace std;

string ReadText(string Message) {
    string Text;
    do
    {
        cout << Message << endl;
        getline(cin, Text);
    } while (Text.length() <= 0);
        return Text;
}


string EncryptText(string Text,short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }

    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++) {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }

    return Text;
}





int main()
{
    short EncryptionKey = 2;
    string Text = ReadText("Please Enter Text: ");
    string TextAfterEncrption = EncryptText(Text,EncryptionKey);
    string TextAfterDecryption = DecryptText(TextAfterEncrption,EncryptionKey);
    cout << "Text After Encrption : " << TextAfterEncrption << "\n";
    cout << "Text After Decryption : " << TextAfterDecryption << "\n";
    return 0;
}
