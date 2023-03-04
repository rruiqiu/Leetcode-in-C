int hammingWeight(uint32_t n) {
    int count = 0;
    //why we can't use n | 0, cuz it won't set the other bits to zero it will look like 0b000000000 which will give the origin value, not we want, so use & to get the first digit
    for(int i=0;i<32;i++){
        
        if((n & 1) == 1){
            count++;
        }
        n >>= 1;
    }
    return count;
}