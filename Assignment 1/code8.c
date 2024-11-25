// Run the following code segments and point out the differences if any,
// code =4
// if (code = = 4) printf("bonus");
// else printf("penalty");
// .........................................
// code =4
// if (code = 4) printf("bonus");
// else printf("penalty");

#include <stdio.h>

int main(){
    //Segment 1
    int code = 4;
        if (code == 4){
            printf("bonus\n");
        }else{
            printf("penalty\n");
        }
    //Segment 2
        if (code = 4){
            printf("bonus\n");
        }else{
            printf("penalty\n");
        }
    return 0;
}