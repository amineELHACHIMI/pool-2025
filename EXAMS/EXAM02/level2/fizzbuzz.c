#include <unistd.h>
int main (){
	int c=0;;
	int nb=1;
while(nb <= 100){
	if(nb % 4 == 0 && nb % 7 == 0 )
		write(1, "buzzfizz\n", 9);
	else if(nb % 4 ==0)
		write(1,"buzz\n",5);

	else if (nb % 7 ==0)
		write(1, "fizz\n",5);
	else if(nb == 100)
		write(1,"100\n",4);

	else{
		if(nb< 10){
			c=nb + '0';
		write(1,&c,1);
		write(1,"\n",1);
		}
		else{
		c=(nb / 10)+'0';
		write(1,&c,1);
		c=(nb%10)+'0';
		write(1,&c,1);
		write(1,"\n",1);
	}
	}
	nb++; 
}
return 0;
}
