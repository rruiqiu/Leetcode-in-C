/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //return format [nums[i],nums[j],nums[k]]
    //could have more than one solution
    //and notice the solutino set must not contain duplicate triplets, which means it could have different orders
    //fix one point, then do the two sum problem for the rest two
    qsort(nums,  numsSize, sizeof(int), comparator);
    int size = 0;
    //int **arr = 0;
    int capacity = 50000;
    int **arr = malloc(capacity * sizeof(int *));
    //-4-1-1012
//    for(int i=0;i< numsSize;i++){
//        printf("%d",nums[i]);
//    }
    //now the problem is to fix repetive elements
    for(int i=0;i<numsSize;i++){
        int first_index = i+1;
        int last_index = numsSize-1;
        int target = 0 - nums[i];
        while(first_index < last_index){
            int temp = nums[first_index]+nums[last_index];
            if(temp > target){
                last_index--;
            }else if(temp < target){
                first_index++;
            }else{
                size++;
                //arr = realloc(arr,(size)*sizeof(int*)); // this would also work for a space criticial envrionment. but right now we are looking for performance, then use this
                arr[size-1] = (int*)malloc(3*sizeof(int));
                arr[size-1][0]=nums[i];
                arr[size-1][1]=nums[first_index];
                arr[size-1][2]=nums[last_index];
                while(++first_index < last_index && nums[first_index] == nums[first_index-1]){}
                while(first_index < --last_index && nums[last_index] == nums[last_index+1]){}
            }
        }
        //O(n), won't take too much time
        while(i<numsSize-1 && nums[i] == nums[i+1]){
            i++;
        }
    }
    *returnSize = size;
    *returnColumnSizes = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = 3;
    } 
    //now how do we determine if the same array appeared before?
    return arr;
}

