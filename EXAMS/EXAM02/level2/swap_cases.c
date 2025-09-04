char *swap_cases(char *str){
int i=0;
int j=0;
char tmp;
while(str[j])
	j++;
j--;
while(str[i]&& i<j){
tmp=str[i];
str[i]=str[j];
str[j]=tmp;
i++;
j--;
}
return (str);
}
#include <stdio.h>
int main (){
	char tab[]="ABCDE";
	printf("%s\n",swap_cases(tab));
	return 0;
}
