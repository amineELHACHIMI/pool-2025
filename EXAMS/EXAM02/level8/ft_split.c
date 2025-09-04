#include <unistd.h>

int main(void)
{
char tab[][10] = {{"absc"},{"kadir"},{"something"}};

write(1, &tab[2][1], 1);

}
