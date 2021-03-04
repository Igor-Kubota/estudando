// Nome : Igor eiki ferreira Kubota
// ra : 19.02466-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void lerstring();


int main(){
    char s1[MAX], s2, s3, s4;
    int i;
    printf("Digite a mensagem: ");


    lerstring(s1);

	for(i = 0; s1[i] != '\0'; ++i){
		s2 = s1[i];
		s3 = s1[i];
        if (s2>= 'a' && s2 <= 'z'){
            s2 = s2 + 3;

            if (s2 > 'z')
                s2 = s2 - 26;

        }
        if (s2>= 'A' && s2 <= 'Z'){
            s2 = s2 + 3;

            if (s2 > 'Z')
                s2 = s2 - 26;

        }
            s1[i] = s2;

	}

    printf("mensagem codificada: %s\n",s1);

    return 0;
}




void lerstring(char s[]){
    setbuf(stdin,0);
    fgets(s, MAX, stdin);
    if (s[strlen(s)-1]=='\n')
        s[strlen(s)-1] = '\0';
}









