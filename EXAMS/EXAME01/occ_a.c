int occ_a(char *str){
int i=0;
int j=0;
while(str[i]!= '\0'){
	if(str[i] == 'A')
		j++;
i++;
}
return j;
}
#include <stdio.h>
int main(){
	char *str="ABAHAB";
printf ("%d\n",occ_a(str));
return 0;
}
