//3字串跨度
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main3()
{
	char s[301] = { 0 }, s1[11] = { 0 }, s2[11] = { 0 };
	scanf("%s %s %s", s, s1, s2);
	int len = strlen(s), len1 = strlen(s1), len2 = strlen(s2);
	int found1 = 0, found2 = 0, boundary1r = 0, boundary2l = 0;
	for (int i = 0; i < len; i++)//从前往后查找s1
	{
		int p = 0;
		while (s[i] != s1[p])
		{
			i++;
			if (i >= len)
			{
				break;
			}
		}
		while (s[i] == s1[p])
		{
			i++;
			p++;
			if(p == len1)
			{
				found1 = 1;
				boundary1r = i - 1;
				break;
			}
		}

		//printf("%d", boundary1r);//dubug

		if (found1 == 1|| i >= len)
		{
			break;
		}		
	}

	for (int i = len - 1; i > 0; i--)//从后往前查找s2
	{
		int p = len2 - 1;
		while (s[i] != s2[p])
		{
			i--;
			if (i <=0)
			{
				break;
			}
		}
		while (s[i] == s2[p])
		{
			i--;
			p--;
			if (p == 0)
			{
				found2 = 1;
				boundary2l = i + 1;
				break;
			}
		}
		//printf("%d", boundary2l);//dubug
		if (found2 == 1|| i <= 0)
		{
			break;
		}
		
	}
	int result = boundary2l - boundary1r - 2;
	
	if (found1 == 1 && found2 == 1) 
	{		
		if (result >= 0)
		{
			printf("%d\n", result);
		}
		
		else//若有ef ab 使result<0，没有else 没有输出
		{
			printf("-1\n");
		}
	}
	
	else
	{
		printf("-1\n");
	}
	
	return 0;
}