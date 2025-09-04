int    ft_strcmp(char *s1, char *s2){
	int i=0;
while(s1[i]!='\0'){
	if(s1[i] != s2[i])
		return (s1[i]-s2[i]);
i++;
}
return 0;
}
#include <stdio.h>
int main(){
	char *s1="abd";
	char *s2="abc";
printf("%d\n",ft_strcmp(s1,s2));
return 0;
}
