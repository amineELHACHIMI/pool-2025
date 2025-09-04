#include <unistd.h>
void put_str(char *str){

	int i=0;
	while(str[i]){
		write(1,&str[i],1);
		i++;
	}
}

void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void	english_numbers(int num)
{
	int		d;
	int		r;

	char	*ones[] = {"", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen","nineteen"};

	char	*tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty","seventy", "eighty", "ninety"};

	d = 0;
	r = 0;
	if (num < 0)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	ft_putnbr(num);
	write (1," : ",3);
	if (num == 0)
	{
		write(1, "zero\n", 5);
		return ;
	}
	if (num >= 100)
	{
		d = num / 100;
		put_str(ones[d]);
		write(1, " ",1);
		write(1, "hundred", 7);
		num = num % 100;
		if(num != 0)
			write(1," ",1);
	}
	if (num >= 20)
	{
		d = num / 10;
		r = num % 10;
		put_str(tens[d]);
		if (r != 0){
			write(1," ",1);
			put_str(ones[r]);
		}
	}
	else if (num > 0)
	{
		put_str(ones[num]);
	}
	write(1, "\n", 1);
}
int main (){
english_numbers(-10);
return 0;
}
