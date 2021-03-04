#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int a = 0;
    int b = 0;
    int s = 0;


    while( i < 51 ){
        if (a%2 == 0){
            s = a + s;
            a = a + 1;
            i = i + 1;
        }
        else
            a = a + 1;

    }
    printf("%i",s);


    return 0;
}
