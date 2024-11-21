//µ•¥ —≠ª∑”““∆
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main2()
{
	int n = 0, m = 0;	
	scanf("%d %d", &n, &m);	
	char s[101][100] = { 0 };
	//char *p = s[0];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	
	m = m % n;
	for (int i = n - m; i < n; i++)
	{
		
		printf("%s ", s[i]);
	}

	for (int i = 0; i < n - m; i++)
	{
		printf("%s ", s[i]);
	}
	printf("\n");
	return 0;
}