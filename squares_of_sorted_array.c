#include<stdio.h>
#include<stdlib.h>
// algo
int* algo(int* arr, int size, int return_size){
int i=0,j=0,k=0,temp_index=0;int* temp_arr;
int* tmp_arr=(int*)malloc(sizeof(int)*size);
//step-1 : Divide negitive and positive sub-arrays
for(i=0;i<size;i++)if(*(arr+i)!>0)i++;
//merge while comparing element square. 
j=i-1;k=i;
while(j>=0 && k<size){
if(*(arr+j)*(*(arr+j))>*(arr+k)*(*(arr+k))){
tmp_arr[temp_index]=*(arr+k)*(*(arr+k));
k++;
}
if(*(arr+j)*(*(arr+j))<=*(arr+k)*(*(arr+k))){
tmp_arr[temp_index]=*(arr+j)*(*(arr+j);
j--;
}
temp_index++;
}
//attach rest of elements
while(j>0){
tmp_arr[temp_index]=*(arr+j)*(*(arr+j));
temp_index++;
}
while(k<size){
tmp_arr[temp_index]=*(arr+k)*(*(arr+k));
temp_index++;
}
return tmp_arr;
}

//driver program
int main(int argc, const char* argv[]){
int i=0;int size;int return_size;
int* arr = (int*)malloc(sizeof(int)*size);
printf("Enter the size of the array:\n");
scanf("%d",&size);
printf("Enter the elements \n");
for(i=0;i<size;i++)scanf("%d",arr[i]);
int* sort_arr = algo(arr,size,return_size);
for(i=0;i<size;i++)
printf("%d",sort_arr[i]);
return 0;
}
