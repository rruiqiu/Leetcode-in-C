int findKthPositive(int* arr, int arrSize, int k){
    int count = 0;
    int index = 0;
    for(int i=1;i<=2000;i++){
        //1,2,3,4,5,6,7
        //2,3,4,7,11
        //1,5,6,8,9
        if(index <= arrSize-1 && arr[index]==i){ //notice the running precendence of the && from left to right, so it won't cuz any errors
            index++;
        }else{
            count++;
        }
        
        if(count == k){
            return i;
        }
    }
    return 0;
}