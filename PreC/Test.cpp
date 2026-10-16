#include<iostream>

using namespace std;

int main()
{
	int x = 9, y = 9;
	for (int i = 1;i <= x;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			printf("%d*%d=%d ", j, i,j*i);
		}
		printf("\n");
	}
}