bool isValid(char * s){
    //( ) -> 40, 41
    //{ } -> 123,125
    //[ ] -> 91,93
    if(strlen(s)==0){
        return 0;
    }
    char a[50000] = {0};
    int index = 0;
    for(int i=0;i<strlen(s);i++){
        /*
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.
        */
        if(s[i] == 40 || s[i] == 123 || s[i] == 91){
            a[index] = s[i];
            index++;
        }else{
            if(index == 0){
                return 0;
            }
            if((s[i]- a[index-1] == 1) || (s[i] - a[index-1] == 2)  ){
                index--;
            }else{
                return 0;
            }
        }
        //how to determine if the bracket is contained within another bracket
    }
    if(index==0){
        return 1;
    }
    return 0;
}