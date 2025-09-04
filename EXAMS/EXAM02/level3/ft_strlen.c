int	ft_strlen(char *str){
int i=0;
while(str[i])
	i++;
return i;
}
#include <stdio.h>
int main (){
	char tab[]="amine";
printf("%d\n" ,ft_strlen(tab));
return 0;
}
