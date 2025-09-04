int    count_alen(char *str){
int i=0;
while(str[i]){
if(str[i] == 'a'){
		i++;
		return i;
		}
i++;
}
return i;
}
#include <stdio.h>
int main(){
char tab[]="minea";
printf("%d\n" ,count_alen(tab));
return 0;
}
