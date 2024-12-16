#include<stdio.h>
#include<stdlib.h>
void MENU();
void AddAllElement(int **arr, int *n);
void PrintArray(int *arr, int *n);
int Sum(int *arr, int *n);
void FindMax(int *arr, int *n);

int main(){
    int choice;
    int *arr = NULL;
    int n = 0;
    while (choice != 6){
    	MENU();
    	printf("Lua chon cua ban: ");
    	scanf("%d",&choice);
    	switch (choice){
    		case 1:{
    			AddAllElement(&arr,&n);
				break;
			}
			case 2:{
				PrintArray(arr,n);
				break;
			}
			case 3:{
				printf("Do dai mang: %d",n);
				break;
			}
			case 4:{
				int Tong = Sum(arr,n);
				printf("Tong cac phan tu trong mang la: %d",Tong);
				break;
			}
			case 5:{
                FindMax(arr,n);
				break;
			}
			case 6:{
				printf("Thoat chuong trinh\n");
				break;
			}
			default:{
				printf("Lua chon khong hop le\n");
				break;
			}
		}
	}
    
	return 0;
}

MENU(){
	printf("\n\n---------MENU---------\n\n");
	printf("1.Nhap vao so phan tu va tung phan tu\n");
	printf("2.Hien thi cac phan tu trong mang\n");
	printf("3.Tinh do dai mang\n");
	printf("4.Tinh tong cac phan tu trong mang\n");
	printf("5.Hien thi phan tu lon nhat\n");
	printf("6.Thoat\n\n");
}
AddAllElement(int **arr, int *n){
	printf("Hay nhap so phan tu cua mang: ");
	scanf("%d",n);
	if(n < 1){
		printf("So phan tu khong hop le\n");
		n = 0;
	}
	else{
		*arr = (int *)malloc((*n) * sizeof(int));
		for (int i = 0;i < *n;i++){
			printf("Phan tu thu %d = ",i + 1);
			scanf("%d",(*arr) + i);
    	}
	}
}
PrintArray(int *arr,int *n){
	if(n == 0){
		printf("Mang dang trong\n");
	}
	else{
		printf("Mang: ");
		for (int i = 0;i < n;i++){
			printf("%d ",*(arr + i));
		}
	}
}
Sum(int *arr, int *n){
	if(n == 0){
		printf("Mang dang trong\n");
	}
	else{
		int Tong;
		for (int i = 0;i < n;i++){
			Tong += *(arr + i);
		}
		return Tong;
	}
}
FindMax(int *arr, int *n){
	if(n == 0){
		printf("Mang dang trong\n");
	}
	else{
		int Max = *(arr + 0);
		for (int i = 0;i < n;i++){
			if(*(arr + i) > Max){
				Max = *(arr + i);
			}
		}
		printf("Phan tu lon nhat trong mang la: %d",Max);
	}
}
