#include <unistd.h>
int main(){
int i=1;
int c;
while(i<=9){
	c=i+'0';
write(1,&c,1);
i=i+2;
}
return 0;
}
