//日期距离
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int m1, d1, y1;
int m2, d2, y2;

int yearjg(int yr);
int rulejg(int a, int b, int c, int label);
int dayofyr(int m3, int d3, int y3);

int main()//mmddyy yymmdd
{
	int a = 0, b = 0, c = 0;
	while (scanf("%d/%d/%d", &a, &b, &c) != EOF)
	{
		//printf("%d %d %d\n", a, b, c);

		//判断是否符合mmddyy 规则一
		int index1 = rulejg(a, b, c, 1);

		//判断是否符合yymmdd 规则二		
		int index2 = rulejg(b, c, a, 2);

		//printf("index1 %d,index2 %d\n", index1, index2);
		//printf("********************************\n");

		//若符合两条规则
		int m, d, y;
		char monthname[20] = { 0 };
		int result = 0;
		if (index1 == 1 && index2 == 1)
		{
			int temp1 = dayofyr(m1, d1, y1);
			int temp2 = dayofyr(m2, d2, y2);
			
			//printf("1:%d 2:%d\n", temp1, temp2);
			if (y1 > y2)//大的年份放后面
			{
				int temp;
				temp = y1;
				y1 = y2;
				y2 = temp;
				temp = d1;
				d1 = d2;
				d2 = temp;
				temp = m1;
				m1 = m2;
				m2 = temp;
				temp = temp1;
				temp1 = temp2;
				temp2 = temp;

			}
			else if (y1 == y2)
			{
				if (temp1 > temp2)
				{
					result = temp1 - temp2;
				}
				else
				{
					result = temp2 - temp1;
				}
			}
			
			//计算差值
			if (y1 != y2)
			{
				for (int i = y1; i < y2; i++)
				{
					result += 365;
					if (yearjg(i))
					{
						result++;
					}
				}
				result = result + temp2 - temp1;
			}
			if (result != 0)
			{
				printf("%d\n", result);
			}
			
		}
		if(index1 == 1)
		{
			m = m1; d = d1; y = y1;
		}
		else if (index2 == 1)
		{
			m = m2; d = d2; y = y2;
		}
		if (!(index1 == 1 && index2 == 1)||result == 0)
		{
			switch (m)
			{
			case 1:
				strcpy(monthname, "January");
				break;
			case 2:
				strcpy(monthname, "February");
				break;
			case 3:
				strcpy(monthname, "March");
				break;
			case 4:
				strcpy(monthname, "April");
				break;
			case 5:
				strcpy(monthname, "May");
				break;
			case 6:
				strcpy(monthname, "June");
				break;
			case 7:
				strcpy(monthname, "July");
				break;
			case 8:
				strcpy(monthname, "August");
				break;
			case 9:
				strcpy(monthname, "September");
				break;
			case 10:
				strcpy(monthname, "October");
				break;
			case 11:
				strcpy(monthname, "November");
				break;
			case 12:
				strcpy(monthname, "December");
				break;
				
			}
			printf("%s %d, %d", monthname, d, y);
		}

	}

	return 0;
}

int yearjg(int yr)
{
	int jg = 1;
	yr = yr + 2000;
	if (yr % 4 != 0)
	{
		jg = 0;
	}
	else if (yr % 100 == 0 && yr % 400 != 0)
	{
		jg = 0;
	}
	//printf("%d\n", jg);
	return jg;
}

int rulejg(int a, int b, int c,int label)
{
	//判断是否符合mmddyy 

	int dayofmonth = 0;
	int index = 1;
	if (a > 0 && a <= 12)
	{
	}
	else
	{
		index = 0;
	}
	yearjg(c);
	switch (a)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		dayofmonth = 31;
		break;
	case 4:case 6:case 9:case 11:
		dayofmonth = 30;
		break;
	case 2:
		dayofmonth = 28;
		if (yearjg(c))
		{
			dayofmonth++;
		}
		break;
	}
	if (b > 0 && b <= dayofmonth)
	{
	}
	else
	{
		index = 0;
	}

	//printf("%d\n", index1);
	
	if (index && label == 1)
	{
		m1 = a; d1 = b; y1 = c + 2000;
		//printf(" rule1 match:month %d,date %d,yr %d\n", m1, d1, y1);
		
	}
	else if(index && label == 2)
	{
		m2 = a; d2 = b; y2 = c + 2000;
		//printf("rule2 match:month %d,date %d,yr %d\n", m2, d2, y2);
	}
	
	return index;
}

int dayofyr(int m3, int d3, int y3)
{
	int count = 0, dayofmonth = 0;
	for (int i = 1; i < m3; i++)
	{
		switch (i)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			dayofmonth = 31;
			break;
		case 4:case 6:case 9:case 11:
			dayofmonth = 30;
			break;
		case 2:
			dayofmonth = 28;
			if (yearjg(y3))
			{
				dayofmonth++;
			}
			break;
		}
		count += dayofmonth;
	}
	count += d3;
	return count;
}