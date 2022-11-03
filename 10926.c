#include<stdio.h>
#include<string.h>
int main(){
    char inputstr[50];
    scanf("%s",&inputstr);
    char surprise[]="??!";
    strcat(inputstr,surprise);

    printf("%s",inputstr);
}