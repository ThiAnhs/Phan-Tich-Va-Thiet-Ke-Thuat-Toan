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

int FindPivot(DaySo a[], int i, int j){
	int firstKey;
	int k;
	k = i + 1;
	firstKey = a[i].soNguyen;
	while((k <= j && ( a[k].soNguyen == firstKey))){
		k ++;
	}
	if(k > j) return -1;
	else if(a[k].soNguyen < firstKey) return k;
	else return i;
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
 
int Partition(DaySo a[], int i, int j, int pivot){
	int L, R;
	L = i;
	R = j;
	while(L <= R){
		while(a[L].soNguyen <= pivot) L ++;
		while(a[R].soNguyen > pivot) R--;
		if(L < R) Swap(&a[L], &a[R]);
	}
	return L;
}

void inDuLieu(DaySo a[], int n){
	for(int i = 0; i < n; i ++){
		printf("%3d %5d %8.2f",i, a[i].soNguyen, a[i].soThuc);
		printf("\n");
	}
}

void QuickSort(DaySo a[], int i, int j){
	int pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a, i, j);
	if(pivotindex != -1){
		pivot = a[pivotindex].soNguyen;
		k = Partition(a, i, j, pivot);
		QuickSort(a, i, k - 1);
		QuickSort(a, k, j);
	}
}

int main(){
	int n;
	DaySo a[100000];
	docDuLieu(a, &n);
	inDuLieu(a, n);
	
	printf("\nSap Xep Theo So Nguyen\n");
	QuickSort(a, 0, n - 1);
	inDuLieu(a, n);
	
}


