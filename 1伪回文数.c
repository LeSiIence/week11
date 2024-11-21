//Î±»ØÎÄÊý
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main1()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char s[100] = { 0 };
		scanf("%s", s);
		int len = strlen(s);
		int count = 0;
		int hflen = len / 2;
		for (int i = 0; i < hflen; i++)
		{
			if (s[i] != s[len - i - 1])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}