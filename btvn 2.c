#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inputString(char **str) {
    char temp[100];
    printf("Nhap vao chuoi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    *str = (char *)malloc(strlen(temp) + 1);
    strcpy(*str, temp);
}

void printString(char *str) {
    printf("Chuoi ban nhap la: %s\n", str);
}

int countLetters(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countDigits(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int countSpecialChars(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi \n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi và in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoát\n");
        printf("Chon chuc nang (1-6): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                if (str != NULL) {
                    printString(str);
                } else {
                    printf("Chua co chu cai de in.\n");
                }
                break;
            case 3:
                if (str != NULL) {
                    int letterCount = countLetters(str);
                    printf("So luong chu cai trong chuoi: %d\n", letterCount);
                } else {
                    printf("Chua co chuoi de dem.\n");
                }
                break;
            case 4:
                if (str != NULL) {
                    int digitCount = countDigits(str);
                    printf("So luong chu cai trong chuoi: %d\n", digitCount);
                } else {
                    printf("Chua co chuoi de dem.\n");
                }
                break;
            case 5:
                if (str != NULL) {
                    int specialCharCount = countSpecialChars(str);
                    printf("So luong ky tu dac biet trong chuoi: %d\n", specialCharCount);
                } else {
                    printf("Chua co chuoi de dem.\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le,vui long chon lai\n");
        }
    } while (choice != 6);

    free(str);
    return 0;
}

