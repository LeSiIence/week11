//中值滤波
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int bubble_sort(int arr[], int w);

int main4()
{
	int w, n;
	while (scanf("%d", &w) != EOF)
	{
		scanf("%d", &n);

		//写入待处理序列
		int arr[1000] = { 0 };
		int result[1000] = { 0 };
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			result[i] = arr[i];
		}

		//错误判断
		if (w % 2 == 0||w>n)
		{
			printf("ERROR\n");
			continue;
		}

		//取出窗口,在窗口内排序
		int window[1000] = { 0 };
		for (int i = 0; i < n - w+1; i++)
		{
			for (int j = 0; j < w; j++)
			{
				window[j] = arr[i + j];
			}
			int mid = bubble_sort(window, w);
			//printf("%d", mid);
			result[i + w / 2] = mid;
		}


		//输出结果数组
		for (int i = 0; i < n; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\n");
		
		
		
	}
	//printf("111");
	return 0;
}

int bubble_sort(int window[], int w)//排序并返回中值
{
	int temp;
	for (int i = 0; i < w - 1; i++)
	{
		for (int j = 0; j < w - i - 1; j++)
		{
			if (window[j] > window[j + 1])
			{
				temp = window[j];
				window[j] = window[j + 1];
				window[j + 1] = temp;
			}
		}
	}
	return window[w / 2];
}