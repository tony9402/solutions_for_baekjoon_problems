#include<stdio.h>

void CAL(int i);

int Cnt = 0;
int num[1000] = { 0 };

int main()
{
	int input_num;

	scanf("%d", &input_num);
	num[0] = input_num / 10;
	num[1] = input_num % 10;
	CAL(2);

	return 0;
}

void CAL(int i)
{
	if (num[i-1] == num[1] && num[i - 2] == num[0] && i > 2) {
		printf("%d", Cnt);
	}
	else {
		num[i] = (num[i - 1] + num[i - 2]) % 10;
		Cnt += 1;
		CAL(i + 1);
	}
}
