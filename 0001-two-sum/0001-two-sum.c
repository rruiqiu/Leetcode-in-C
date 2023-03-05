/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}
//n*logn average case using sort technique then applying binary search
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int new_arr[numsSize];
    *returnSize = 2;
    for(int i=0;i<numsSize;i++){
        new_arr[i] = nums[i];
    }
    qsort(nums, numsSize, sizeof(*nums), compare);
    int first_index = 0;
    //sorting will break the original loop
    //how to solve without breaking the origin loop
    for(int i=0;i<numsSize;i++){
        printf("%d",new_arr[i]);
    }
    
    int last_index = numsSize - 1;
    int *arr = (int*)calloc(2,sizeof(int));
    int first_value, second_value;
    *returnSize = 2;
    while(first_index <= last_index){
        int curr_sum = nums[first_index]+nums[last_index];
        if(curr_sum == target){
            first_value = nums[first_index];
            second_value = nums[last_index];
            break;
        }
        
        if(curr_sum < target){
            first_index++;
        }else{
            last_index--;
        }
    }
    int det = 1;
    if(first_value == second_value){
        for(int i=0;i<numsSize;i++){
            if(new_arr[i]==first_value){
               arr[0]=i;
                break;
            }

        }
        for(int i=numsSize-1;i>=0;i--){
            if(new_arr[i]==second_value){
                arr[1]=i;
                return arr;
            }
        }
    }
    
    for(int i=0;i<numsSize;i++){
        if(new_arr[i]==first_value){
            arr[0] = i;
        }
        if(new_arr[i]==second_value){
            arr[1] = i;
        }
    }
    
    
    
    return arr;
}