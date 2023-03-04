/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count1s(int num){
    int count = 0;
    while (num != 0) {
        if ((num & 1) > 0) {
            count++;
        }
        num = num >> 1;
    }
    return count;
 }

int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int *arr = malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<=(n);i++)
    {
        arr[i] = count1s(i);
    }
    return arr;
}

