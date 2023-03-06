int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0;
    //[7,3,5,1,6,4]
    
    //start with index 1
    //max = [1]-[0]
    //first pointer move the right for each i and compare the max, if greater, update 
    //second pointer track the smallest pointer before the fisrt pointer
    int firstpointer = prices[0];
    for(int i=1;i<pricesSize;i++){
        if(prices[i] - firstpointer > maxProfit){
            maxProfit = prices[i]- firstpointer;
        }
        if(firstpointer > prices[i]){
            firstpointer = prices[i];            
        }
    }
    return maxProfit;
}