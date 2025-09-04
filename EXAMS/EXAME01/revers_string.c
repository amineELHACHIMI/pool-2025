char *revers_string(char *str){
int i=0;
int j=0;
char tmp;
while(str[j] != '\0')
j++;
j--;
while(i < j){
tmp=str[i];
str[i]=str[j];
str[j]=tmp;
j--;
i++;
}
return str;
}
#include <stdio.h>
int main (){
char str[]="amine";
printf("%s\n",revers_string(str));
return 0;
}

