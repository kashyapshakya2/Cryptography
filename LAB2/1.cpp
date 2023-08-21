#include <stdio.h>
#include <string.h>

int initail_p_box[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int final_p_box[] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,  
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

void initail_final(const char *data, const int *p_box, char *result) {
    int i;
    for (i = 0; i < 64; i++) {
        result[i] = data[p_box[i] - 1];
    }
    result[i] = '\0';   
}

int main() {
    char input_data[] = "1100000100100011010001010110011110001001101010111100110111101111";
    printf("Initail data: %s\n", input_data);

    char final_data[65];   
    initail_final(input_data, initail_p_box, final_data);
    printf("Final data is: %s\n", final_data);

    char inital_data[65];  
    initail_final(final_data, final_p_box, inital_data);
    printf("Converting same output to inital data: %s\n", inital_data);

    return 0;
}

