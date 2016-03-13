#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	struct change
	{
		int total;
		int coin_500;
		int coin_100;
		int coin_50;;
		int coin_10;
	};

	struct change money;
	printf("return money : ");
	scanf("%d",&money.total);

	money.coin_500 = money.total/500;
	money.total %= 500;
	money.coin_100 = money.total/100;
	money.total %= 100;
	money.coin_50 = money.total/50;
	money.total %= 50;
	money.coin_10 = money.total/10;
	
	printf("500 = %d\n",money.coin_500);
	printf("100 = %d\n",money.coin_100);
	printf("50 = %d\n",money.coin_50);
	printf("10 = %d\n",money.coin_10);
	
	return 0;
}
