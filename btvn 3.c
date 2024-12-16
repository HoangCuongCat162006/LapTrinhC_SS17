#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int countWords(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char str[100], newStr[100];
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");

        printf("Nhap lua chon (1-7): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                break;

            case 2:
                reverseString(str);
                printf("Chuoi dao nguoc: %s\n", str);
                break;

            case 3:
                printf("So luong tu trong chuoi: %d\n", countWords(str));
                break;

            case 4:
                printf("Nhap vao chuoi khac: ");
                fgets(newStr, sizeof(newStr), stdin);
                newStr[strcspn(newStr, "\n")] = '\0';
                if (strlen(newStr) < strlen(str)) {
                    printf("Chuoi khac ngan hon chuoi ban dau.\n");
                } else if (strlen(newStr) > strlen(str)) {
                    printf("Chuoi khac dai hon chuoi ban dau.\n");
                } else {
                    printf("Hai chuoi co do dai ngang nhau.\n");
                }
                break;

            case 5:
                toUpperCase(str);
                printf("Chuoi in hoa: %s\n", str);
                break;

            case 6:
                printf("Nhap vao chuoi khac de them vao: ");
                fgets(newStr, sizeof(newStr), stdin);
                newStr[strcspn(newStr, "\n")] = '\0';
                strcat(str, newStr);
                printf("Chuoi sau khi them: %s\n", str);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}

