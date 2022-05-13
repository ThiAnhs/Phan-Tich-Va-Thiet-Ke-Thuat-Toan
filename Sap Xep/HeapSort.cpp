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

void PushDow(DaySo a[], int first, int last){
	int r = first;
	while(r <= (last - 1) / 2){
		if(last == 2*r + 1){
			if(a[r].soNguyen > a[last].soNguyen) Swap(&a[r], &a[last]);
			r = last;
		}
		else if((a[r].soNguyen > a[2 * r + 1].soNguyen && ( a[2*r + 1].soNguyen <= a[2*r + 2].soNguyen))){
			Swap(&a[r], &a[2*r + 1]);
			r = 2*r + 1;
		}
		else if((a[r].soNguyen > a[2 * r + 2].soNguyen && ( a[2*r + 2].soNguyen < a[2*r + 1].soNguyen))){
			Swap(&a[r], &a[2*r + 2]);
			r = 2*r + 2;
		}
		else r = last;
	}
}

void HeapSort(DaySo a[], int n){
	for(int i = (n - 2) / 2; i >= 0; i --){
		PushDow(a, i, n - 1);

	}
	for(int i =  n - 1; i >= 2; i --){
		Swap(&a[0], &a[i]);
		PushDow(a, 0, i - 1);
	}
	Swap(&a[0], &a[1]);
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
	HeapSort(a, n);
	inDuLieu(a, n);
	
}


