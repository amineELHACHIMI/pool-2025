int occ_a(char *str){
int i=0;
int j=0;
while(str[i]){
if(str[i]=='A')
	j++;
i++;
}
return (j);
}
#include <stdio.h>
int main(){
char tab[]="cvbn";
printf("%d\n" ,occ_a(tab));
return 0;
}
