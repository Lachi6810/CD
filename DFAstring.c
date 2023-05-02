#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int q = 0, prev_q;
    for (int i = 0; i < strlen(str); i++) {
        if(str[i]!='a' && str[i]!='b' && str[i]!='c'){
            printf("Invalid string\n");
            return 0;
        }
        prev_q = q;
        switch(q) {
            case 0 : q = (str[i] == 'a') ? 1 : 0;
                     break;
            case 1 : q = (str[i] == 'b') ? 2 : (str[i] == 'a') ? 1 : 0;
                     break;
            case 2 : q = (str[i] == 'c') ? 3 : (str[i] == 'a') ? 1 : 0;
                     break;
            case 3 : q = (str[i] == 'a') ? 1 : 0;
                     break;
        }
        printf("q%d--%c-->q%d\n", prev_q, str[i], q);
    }
    if (q == 3) 
        printf("Accepted\n");
    else 
        printf("Not accepted\n");
    return 0;
}
