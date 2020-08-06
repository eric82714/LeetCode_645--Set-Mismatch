/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *arg1, const void *arg2){
    return  (*(int *)arg1 - *(int *)arg2);
}

int sum_vector(int* nums, int numsSize, bool set){
    int res = 0;
        
    for(int i = 0; i < numsSize; i++){ 
        if(set && i > 0 && *(nums+i) == *(nums+(i-1))) continue;  
        res += *(nums+i);
    }
        
    return res;
}
    
int sum(int n){
    int res = 0;        
    for(int i = 1; i < n+1; i++) res += i;
    return res;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int length = numsSize;
    qsort(nums, length, sizeof(int), compare);
    int total = sum_vector(nums, length, false);
    int unique = sum_vector(nums, length, true);
    int* result = malloc(*returnSize * sizeof(int));
    *(result+0) = total - unique;
    *(result+1) = sum(length) - unique;
    return result;
}
