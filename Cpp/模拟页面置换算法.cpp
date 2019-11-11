/*************************************************************************
    > File Name       : ģ��ҳ���û��㷨.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-11 14:34:36
 ************************************************************************/
#include<iostream>
#include<fstream>           //�����ļ�ͷ�ļ�

using namespace std;

const int Pagemax = 20;            //ҳ�������
const int Blockmax = 10;           //���������

int Pages[Pagemax];            //��ҵ
int Blocks[Blockmax];          //�����

int pos = 0;                   //��ȡ�ļ������ֵĸ���

//��ʾ��ʾ��Ϣ
void ShowInfo(void)
{
	cout << "################################################�洢��֮ҳ���û��㷨ģ��#############################################################\n";
	cout << endl;
	cout << "                                          1���Ƚ��ȳ�ҳ���û��㷨(FIFO)\n";
	cout << "                                          2��������δʹ���㷨(LRU)\n";
	cout << endl;
	cout << "##############################################�������ѡ����Ҫģ����㷨#############################################################\n";
}

void  ReadPages(void)                        //��ȡ�ļ��е���ҵ
{
	ifstream finput;
	finput.open("./1.txt");
	if (!finput.is_open())
	{
		cout << "�ļ�δ�򿪣�������ֹ��" << endl;	
		exit(EXIT_FAILURE);
	}

	while (!finput.eof())
	{
		finput >> Pages[pos];                   //���ļ��ж�ȡ���Ľ���洢��Pages[]������
		pos++;
	}

	finput.close();
}

bool IsIn( int page)                    //�жϵ�ǰҳ���Ƿ����ڴ���
{
	for (int i = 0; i < Pagemax; i++)
	{
		if (Blocks[i] == page)
		{
			return true;
		}
	}
	return false;
}

void FIFO(/*int *pages, int *blocks,*/ int block)
{
	int lose_page_time = 0;
	double lose_page_rate = 0.0;              //ȱҳ������ȱҳ��

	for (int i = 0; i < pos; i++)
	{
		cout << Pages[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < pos; i++)                         //ѭ��������ҵ
	{
			for (int j = 0; j < block; j++)                   //Ϊ��ҵ���������
			{	

				if (!IsIn(Pages[i]))

				{

					Blocks[j] = Pages[i];
				

					
					lose_page_time++;
				
				}
				else 

					continue;


			}
	}
	lose_page_rate = lose_page_time / pos;
	cout << "***********************************************************************************************\n";
	cout << "FIFO�㷨��ȱҳ����Ϊ" << lose_page_time << endl;
	cout << "ȱҳ��Ϊ��" << lose_page_rate << endl;
}

void LRU()
{

}

void ShowMemory()                                 //��ʾ�ڴ��е���ҵ
{

}

int main(int argc,char *argv[])
{
	 ReadPages();
     ShowInfo();
	 cout << "������Ҫģ����㷨����ǰ�Ĵ���:" ;
	 char choice;
	 cin >> choice;
	 while (choice != 'q')
	 {
		cout << "���������������";
		int block;
		cin >> block;

		if (choice == '1')
		{
			FIFO(block);
		}

		if (choice  == '2')
		{
			LRU();
		}

		cout << "�Ƿ�Ҫ��������ģ�⣿(����������ţ�q�˳�����"; 
		cin >> choice;
	 }

	 cout << "����ģ�⣡����" << endl;
    return 0;
}

