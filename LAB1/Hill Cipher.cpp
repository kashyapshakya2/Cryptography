#include <iostream>
#include <cmath>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

void getKeyMatrix(string key, int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k = (k + 1) % key.length();
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    int x, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void decrypt(int messageMatrix[][1], int keyMatrix[][3], int cipherMatrix[][1]) {
    int modInverseKey[3][3];
    int determinant = 0;
    int inverseDet = 0;
    int adj[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cofactor = (keyMatrix[(j + 1) % 3][(i + 1) % 3] * keyMatrix[(j + 2) % 3][(i + 2) % 3]) -
                           (keyMatrix[(j + 1) % 3][(i + 2) % 3] * keyMatrix[(j + 2) % 3][(i + 1) % 3]);
            adj[i][j] = cofactor;
            determinant += keyMatrix[i][j] * cofactor;
        }
    }
    
    determinant = (determinant % 26 + 26) % 26;
    inverseDet = modInverse(determinant, 26);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            modInverseKey[i][j] = (adj[i][j] * inverseDet) % 26;
        }
    }
    
    int x, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            messageMatrix[i][j] = 0;

            for (x = 0; x < 3; x++) {
                messageMatrix[i][j] += modInverseKey[i][x] * cipherMatrix[x][j];
            }

            messageMatrix[i][j] = (messageMatrix[i][j] % 26 + 26) % 26;
        }
    }
}

void HillCipher(string message, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int numRows = (message.length() + 2) / 3;
    int messageVector[3][1];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < 1; j++) {
            if (i * 3 + j < message.length()) {
                messageVector[i][j] = (message[i * 3 + j]) % 65;
            } else {
                messageVector[i][j] = 0;
            }
        }
    }

    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    int messageMatrix[3][1];
    decrypt(messageMatrix, keyMatrix, cipherMatrix);

    string EncryptedText;
    for (int i = 0; i < numRows; i++) {
        EncryptedText += cipherMatrix[i][0] + 65;
    }

    string DecryptedText;
    for (int i = 0; i < numRows; i++) {
        DecryptedText += messageMatrix[i][0] + 65;
    }

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Text: " << EncryptedText << endl;
    cout << "Decrypted Text: " << DecryptedText << endl;
}

int main() {
    string message, key;

    cout << "Enter the message: ";
    cin >> message;

    cout << "Enter the key: ";
    cin >> key;

    HillCipher(message, key);

    return 0;
}

