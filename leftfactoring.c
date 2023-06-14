#include<stdio.h>
#include<string.h>
void main()  {
    char input[100],l[50],r[50],temp[10],tempprod[20],productions[25][50];
    int i=0,j=0,flag=0,consumed=0;
    printf("Enter the productions: ");
    scanf("%1s->%s",l,r);
    printf("%s",r);
    while(sscanf(r+consumed,"%[^|]s",temp) == 1 && consumed <= strlen(r))  
    {
        if(temp[0] == l[0])  
        {
            flag = 1;
            sprintf(productions[i++],"%s'->%s%s'",l,temp+1,l);
        }
        else
            sprintf(productions[i++],"%s->%s%s'",l,temp,l);
        consumed += strlen(temp)+1;
    }
    if(flag == 1)  
    {
        sprintf(productions[i++],"%s'->ε",l);
        printf("The productions after eliminating Left Recursion are:\n");
        for(j=0;j<i;j++)
            printf("%s\n",productions[j]);
    }
    else
        printf("The Given Grammar has no Left Recursion");
}


/*

Enter the productions: E->E+E|T
E+E|TThe productions after eliminating Left Recursion are:
E'->+EE'
E->TE'
E'->ε
=====================================
Enter the productions: A->Ab|aB|Ac|ac
Ab|aB|Ac|acThe productions after eliminating Left Recursion are:
A'->bA'
A->aBA'
A'->cA'
A->acA'
A->ε

*/
