int findKthPositive(int* arr, int arrSize, int k){
    int count = 0;
    int index = 0;
    for(int i=1;i<=5000;i++){
        //1,2,3,4,5,6,7
        //2,3,4,7,11
        //1,5,6,8,9
        if(index <= arrSize-1 && arr[index]==i){
            index++;
        }else{
            count++;
        }
        
//         //excedding the array size
//         if(index > arrSize-1){
//             count++;
//         }else{
            
//         }
        
        
        if(count == k){
            return i;
        }
    }
    return 0;
}