bool isPalindrome(char * s){
//reads the same forward and backward
//one pointer at the front
//one pointer at the back
//loop thourgh, only capture the valid pointer

//an algorithm first check if the current is a valid alphbateic char, if yes,
//then store as the temp
//then check inversly if it is, then store as another temp,
//finally compare these two temps if they are the same
//one way is first find the num of alphavetic appearnce
//then we can based on these /2 and start from the first and last,
//filter out each unnecessay array during or 
    int last_index = strlen(s)-1;
    int first_index = 0;
    char temp1 = 0;
    char temp2 = 0;
    int count = 0;

    //indexing is actually wrong i guess cuz can't really find the middle 
    while(first_index <= last_index){
        if(temp1 == 0){
            if(s[first_index] >= 97 && s[first_index] <= 122){
                temp1 = s[first_index];
                // count--;
                first_index ++;
            }else if(s[first_index] >= 65 && s[first_index] <= 90){
                temp1 = s[first_index]+32;
                // count--;
                first_index ++;
            }else if(s[first_index]>=48 && s[first_index] <= 57){
                temp1 = s[first_index];
                first_index ++;
            }
            else{
                first_index ++;
                // temp1 = 0;
            }
        }

        if(temp2 == 0){
            if(s[last_index] >= 97 && s[last_index] <= 122){
                temp2 = s[last_index];
                count--;
                last_index--;
            }else if(s[last_index] >= 65 && s[last_index] <= 90){
                temp2 = s[last_index] + 32;
                // count--;
                last_index--;
            }else if(s[last_index]>=48 && s[last_index] <= 57){
                temp2 = s[last_index];
                last_index--;
            }else{
                last_index--;
                // temp2 = 0;
            }
        }
        //0P
        //hanlde problem when the first index increasing while zero
        //the second index have values
        //won't come to this line and will end
        if(temp1!= 0 && temp2!=0){
            if(temp1 == temp2){
                temp1 = 0;
                temp2 = 0;
            }else{
                return 0;
            }
        }
    }
    // if(temp1 != temp2){
    //     return 0;
    // }
    return 1;
}