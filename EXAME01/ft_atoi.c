int	ft_atoi(char *str){
	int i=0;
	int s=1;
	int res=0;
while(str[i]!= '\0'&& str[i]>=9 && str[i]<=13 || str[i]== ' ')
	i++;
while(str[i]=='-'||str[i]=='+'){
	if(str[i]=='-')
s*=-1;
i++;
}
while(str[i]>='0'&& str[i]<='9'){
res=res*10+(str[i]-'0');
	i++;
}

return res*s;
}
#include <stdio.h>
int main() {
    char *s = "   \t\n  -12345abc";
    printf("Converted: %d\n", ft_atoi(s)); // Should print: -12345
    return 0;
}

