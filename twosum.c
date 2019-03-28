
Note: The returned array must be malloced, assume caller calls free().
 */
# define maxval 10000

int cmpfunc(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int* create_index(int* dup_nums, int numSize){
    int i=0;
    int* index_array = (int*)malloc(sizeof(int)*numSize);
    for(i=0;i<numSize;i++){
        index_array[i] = dup_nums[i];
    }
    return index_array;
}
void find_index(int** num_index,int* dup_nums,int numSize, int val_1,int val_2){
    int i=0,k=0,f=0,temp=0;
    i=0;f=0;
    while(i<numSize){
        if(f==0 && (*(dup_nums+i)==val_1)){ 
            *(*(num_index))=i;
            i++;
            f=1;
            continue;
        }
        if(*(dup_nums+i)==val_2) {
            *(*num_index+1) = i;
             i++;
            continue;
        }
        i++;
    }
    if(*(*(num_index))>*(*num_index+1)){
        temp = *(*(num_index));
        *(*(num_index)) = *(*num_index+1);
        *(*num_index+1) = temp;
    }
    return;
}
//Assuming maximum value in array is 10000. Next update will be done in one pass by checking hash_arr[target-*(nums+i)] while creating hash.
int* twoSum(int* nums, int numsSize, int target) {
    int i=0,j=numsSize-1,k=0;
    int* dupNums = create_index(nums,numsSize);
    int* nums_index = (int*)malloc(sizeof(int)*2);
    /* For negitive numbers hash does not work.E.g : [-3,4,3,90]
    int* nums_index = (int*)malloc(sizeof(int)*2);
    int* hash_arr = (int*)calloc(maxval,sizeof(int));
    for(i=0;i<numsSize;i++)hash_arr[*(nums+i)]=i;
    for(i=0;i<numsSize;i++){if(hash_arr[target-*(nums+i)])break;}
    nums_index[0]=i;nums_index[1]=hash_arr[target-*(nums+i)];
    */
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    while(j>i){
        if(*(nums+i)+*(nums+j)==target)break;
        else if(*(nums+i)+*(nums+j)>target) j--;
        else i++;
    }
    find_index(&nums_index,dupNums, numsSize,*(nums+i),*(nums+j));
    return nums_index;
}
