#include<stdio.h>
int partition(int arr[],int high,int low){
	int pivot = arr[high];
	int i = low - 1;
	
	for(int j = low;j<high;j++){
		if(arr[j]<= pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} 
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int pivotindex = partition(arr,low,high);
		quickSort(arr,low,pivotindex-1);
		quickSort(arr,pivotindex-1,high);
	}
}

void printArray(int arr[],int SIZE){
	for(int i=0;i<SIZE;i++){
		printf("%d",arr[i]);
		printf("/n");
	}
}

int main(){
	int arr[] = {10,7,8,9,1,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,n-1);
	printf("Sorted Array:");
	printArray(arr,n);
	return 0;
}
