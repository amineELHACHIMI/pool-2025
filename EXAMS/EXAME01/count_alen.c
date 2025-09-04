int    count_alen(char *str){
int i=0;
while(str[i]!= '\0'){
	if(str[i]=='a')
		return i;
i++;
}
return i;
}
#include <stdio.h>
int main (){
	char *str="wertqwerta";
printf("%d",count_alen(str));
return 0;
}
