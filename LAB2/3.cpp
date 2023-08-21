#include <stdio.h>

int s_box_1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int substitution(char *data, int s_box[4][16]) {
    int row = (data[0] - '0') * 2 + (data[5] - '0');
    int col = (data[1] - '0') * 8 + (data[2] - '0') * 4 + (data[3] - '0') * 2 + (data[4] - '0');
    return s_box[row][col];
}

int main() {
    char input_data[] = "100011";
    int output = substitution(input_data, s_box_1);
    printf("output: %04d\n", output);
    return 0;
}

