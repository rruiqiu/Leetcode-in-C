int singleNumber(int* nums, int numsSize){
    int findnum = 0;
    for(int i=0;i<numsSize;i++){
        findnum ^= nums[i];
    }
    return findnum;
}