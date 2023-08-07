#include <iostream>
using namespace std;

string encrypt(string text, int key)
{
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + key - 65) % 26 + 65);
        else
            result += char(int(text[i] + key - 97) % 26 + 97);
    }
    return result;
}

string decrypt(string text, int key)
{
    return encrypt(text, 26 - key);  

int main()
{
    string text;
    int key;
    cout << "Enter plain text: ";
    cin >> text;
    cout << "Enter Key: ";
    cin >> key;
    cout << "\nPlain text: " << text;
    cout << "\nKey: " << key;

    string cipherText = encrypt(text, key);
    cout << "\nCipher text: " << cipherText;

    string decryptedText = decrypt(cipherText, key);
    cout << "\nDecrypted text: " << decryptedText;

    return 0;
}

