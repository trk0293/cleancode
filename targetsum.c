nclude<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b){
return(*(int*)a-*(int*)b);
}

void tSum(int* arr,int size,int sum){
int i=0,j=size-1;
qsort(arr,size,sizeof(int),cmpfunc);
while(i<size && j>0){
if(*(arr+i)+*(arr+j) > sum)j--;
else if(*(arr+i)+*(arr+j) < sum)i++;
else{
printf("Element found");
printf("Two elements are %d and %d \n",*(arr+i),*(arr+j));
i++;j--;
}
}
return ;
}


//driver function
int main(int argc,const char* argv[]){
int i,size,sum;
printf("Enter the size of the array\n");
scanf("%d",&size);
printf("Enter target sum\n");
scanf("%d",&sum);
int* arr = (int*)malloc(sizeof(int)*size);
printf("Enter the elements \n");
for(i=0;i<size;i++)scanf("%d",&arr[i]);
tSum(arr,size,sum);
return 0;
}
