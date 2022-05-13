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

void SelectionSort(DaySo a[], int n){
	int lowindex;
	int lowkey;
	for(int i = 0; i <= n - 2; i ++){
		lowkey = a[i].soNguyen;
		lowindex = i;
		for(int j = i + 1; j <= n - 1; j ++){
			if(a[j].soNguyen < lowkey){
				lowkey = a[j].soNguyen;
				lowindex = j;
			}
		}
		Swap(&a[i], &a[lowindex]);
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
21
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
	SelectionSort(a, n);
	inDuLieu(a, n);
	
}



