#include <stdio.h>
#include <string.h>

int parity_drop[56] = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
};

int compression[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

void des(char *data, int *paritydrop, int *compress, int round) {
    char result[65];
    result[64] = '\0';

    for (int i = 0; i < 56; i++) {
        result[i] = data[paritydrop[i] - 1];
    }

    char first_28[29], second_28[29];
    strncpy(first_28, result, 28);
    first_28[28] = '\0';
    strncpy(second_28, result + 28, 28);
    second_28[28] = '\0';

    while (round <= 16) {
        if (round == 1 || round == 2 || round == 9 || round == 16) {
            char temp = first_28[0];
            for (int i = 0; i < 27; i++) {
                first_28[i] = first_28[i + 1];
            }
            first_28[27] = temp;

            temp = second_28[0];
            for (int i = 0; i < 27; i++) {
                second_28[i] = second_28[i + 1];
            }
            second_28[27] = temp;
        } else {
            char temp1 = first_28[0];
            char temp2 = first_28[1];
            for (int i = 0; i < 26; i++) {
                first_28[i] = first_28[i + 2];
            }
            first_28[26] = temp1;
            first_28[27] = temp2;

            temp1 = second_28[0];
            temp2 = second_28[1];
            for (int i = 0; i < 26; i++) {
                second_28[i] = second_28[i + 2];
            }
            second_28[26] = temp1;
            second_28[27] = temp2;
        }

        char total_56[57];
        strcpy(total_56, first_28);
        strcat(total_56, second_28);

        for (int i = 0; i < 48; i++) {
            result[i] = total_56[compress[i] - 1];
        }

        printf("round: %d = %s\n", round, result);
        round++;
    }
}

int main() {
    char data[] = "1100110100000000110011001111111111110001101010101111000010101010";
    int round = 1;
    des(data, parity_drop, compression, round);
    return 0;
}

