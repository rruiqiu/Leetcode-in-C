/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    //1<= index1 < index2 <= numbers.length
    // the given array in sorted order
    // return two indices
    // exactly one solution
    // cant use the same element twice
    int *arr = malloc(2 * sizeof(int));
    // an idea was start from the back, cuz larger was incorrect since we are looking for sum, so it has to be equal to
    *returnSize = 2;

    // for(int i=0;i<numbersSize;i++){
    //     for(int j=i+1;j<numbersSize;j++){
    //         if(numbers[j] == (target-numbers[i])){
    //             arr[0] = i+1;
    //             arr[1] = j+1;
    //             return arr;
    //         }
    //     }
    // }

    //how to reduce time complexity ?
    // use binary search to make it O(nlogn)
    //how to perform?
    //first is loop through the array
    //perform binary seach on the current array
    //and if found return, else continue
    //how to reduce this complexity
    // for(int i=0;i<numbersSize;i++){
    //     int find_num = target - numbers[i];
    //     int first_index = i+1;
    //     int last_index = numbersSize - 1;
    //     while(first_index <= last_index){
    //         int median = (last_index + first_index)/ 2;
    //         if(numbers[median] == find_num){
    //             arr[0] = i+1;
    //             arr[1] = median+1;
    //             return arr;
    //         }
    //         if(numbers[median] < find_num){
    //             first_index = median + 1;
    //         }else{
    //             last_index = median - 1;
    //         }
    //     }
    // }
    //apply the same concept of binary search, but this time reduce time complexity to O(n)
    int lower_index = 0;
    int last_index = numbersSize - 1;
    while(lower_index <= last_index){
        int current_num = numbers[lower_index] + numbers[last_index];
        if(current_num == target){
            arr[0] = lower_index + 1;
            arr[1] = last_index + 1;
            return arr;
        }
        if(current_num < target){
            lower_index ++;
        }else{
            last_index--;
        }
    }

    
    //an idea comes up, if we can shrink it into more easier way


    return 0;
}