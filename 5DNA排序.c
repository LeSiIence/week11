//dna����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void cal(int* p, char str[], int n);
void bubble_sort1(char str[][51], int m, int chao[]);

int main5()
{
	int n = 0, m = 0;//m��n��
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		
		
		char str[101][51] = { 0 };
		int chao[101];
		int* p = chao;
		//����dna����
		for (int i = 0; i < m; i++)
		{
			scanf("%s", str[i]);
		}

		//���������
		for (int i = 0; i < m; i++)
		{
			cal(&chao[i], str[i], n);
			
		}

		//��ð������
		bubble_sort1(str, m, chao);
		
		
		for (int i = 0; i < m; i++)
		{
			printf("%s\n", str[i]);
		}
		printf("********************\n");

	}
	

	return 0;
}

void cal(int* p, char str[], int n)
{
	int chao1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (str[i] > str[j])
			{
				chao1++;
			}
		}
	}

	*p = chao1;
	
	return;
}

void bubble_sort1(char str[][51], int m, int chao[])
{
	char temp[51] = { 0 };
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < m - i - 1; j++)
		{
			if (chao[j] > chao[j + 1])
			{
				//�������Ҷ�
				int temp_chao = chao[j];
				chao[j] = chao[j + 1];
				chao[j + 1] = temp_chao;

				//������Ӧ�ַ���
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
		}
	}
	return;
}

//����һάָ�����������ַ���
