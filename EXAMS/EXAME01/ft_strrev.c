#include <stdio.h>
char    *ft_strrev(char *str){
int i=0;
int j=0;
char tmp;
while(str[j]!= '\0')
	j++;
j--;
while(i<j){
tmp=str[i];
str[i]=str[j];
str[j]=tmp;
i++;
j--;
}
return (str);
}
int main() {
	char str[]="amine";
printf ("%s\n",ft_strrev(str));
return 0;
}
