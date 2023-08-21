#include <stdio.h>
#include <string.h>

int expansion_p_box[] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

void expansion(const char *data, const int *p_box, char *result) {
    int i;
    for (i = 0; i < 48; i++) {
        result[i] = data[p_box[i] - 1];
    }
    result[i] = '\0';   
}

int main() {
    char data[] = "01111010000101111010000101111010";
    printf("Data: %s\n", data);

    char expand_data[49];   
    expansion(data, expansion_p_box, expand_data);
    printf("Expanded data: %s\n", expand_data);
    printf("Length of expanded data: %zu\n", strlen(expand_data));

    return 0;
}

