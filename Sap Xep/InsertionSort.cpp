#include <stdio.h>

typedef struct {
	int soNguyen;
	float soThuc;
}DaySo;

void Swap(DaySo *x, DaySo *y){
	DaySo temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void InsertionSort(DaySo a[], int n){
	for(int i = 1; i <= n - 1; i ++){
		int j = i;
		while(j > 0 && a[j].soNguyen < a[j - 1].soNguyen){
			Swap(&a[j], &a[j - 1]);
			j --;
		}
	}
}

void docDuLieu(DaySo a[], int *n){
	int i = 0;
	FILE *f;
	f = fopen("D:\\data.txt", "r");
	if(f != NULL){
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].soNguyen, &a[i].soThuc);
			i++;
		}
	}
	else printf("Loi");
	fclose(f);
	*n = i;
}

void inDuLieu(DaySo a[], int n){
	for(int i = 0; i < n; i ++){
		printf("%d %.2f", a[i].soNguyen, a[i].soThuc);
		printf("\n");
	}
}

int main(){
	int n;
	DaySo a[100000];
	docDuLieu(a, &n);
	inDuLieu(a, n);
	
	printf("\nSap Xep Theo So Nguyen\n");
	InsertionSort(a, n);
	inDuLieu(a, n);
	
}


