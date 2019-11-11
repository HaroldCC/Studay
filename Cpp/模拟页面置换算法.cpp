/*************************************************************************
    > File Name       : 模拟页面置换算法.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-11 14:34:36
 ************************************************************************/
#include<iostream>
#include<fstream>           //操纵文件头文件

using namespace std;

const int Pagemax = 20;            //页面号数量
const int Blockmax = 10;           //物理块数量

int Pages[Pagemax];            //作业
int Blocks[Blockmax];          //物理块

int pos = 0;                   //读取文件中数字的个数

//显示提示信息
void ShowInfo(void)
{
	cout << "################################################存储器之页面置换算法模拟#############################################################\n";
	cout << endl;
	cout << "                                          1、先进先出页面置换算法(FIFO)\n";
	cout << "                                          2、最近最久未使用算法(LRU)\n";
	cout << endl;
	cout << "##############################################输入代号选择你要模拟的算法#############################################################\n";
}

void  ReadPages(void)                        //读取文件中的作业
{
	ifstream finput;
	finput.open("./1.txt");
	if (!finput.is_open())
	{
		cout << "文件未打开，程序终止！" << endl;	
		exit(EXIT_FAILURE);
	}

	while (!finput.eof())
	{
		finput >> Pages[pos];                   //将文件中读取到的结果存储在Pages[]数组中
		pos++;
	}

	finput.close();
}

bool IsIn( int page)                    //判断当前页面是否在内存中
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
	double lose_page_rate = 0.0;              //缺页次数和缺页率

	for (int i = 0; i < pos; i++)
	{
		cout << Pages[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < pos; i++)                         //循环读入作业
	{
			for (int j = 0; j < block; j++)                   //为作业分配物理块
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
	cout << "FIFO算法的缺页次数为" << lose_page_time << endl;
	cout << "缺页率为：" << lose_page_rate << endl;
}

void LRU()
{

}

void ShowMemory()                                 //显示内存中的作业
{

}

int main(int argc,char *argv[])
{
	 ReadPages();
     ShowInfo();
	 cout << "输入你要模拟的算法名字前的代号:" ;
	 char choice;
	 cin >> choice;
	 while (choice != 'q')
	 {
		cout << "输入物理块数量：";
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

		cout << "是否要继续进行模拟？(继续输入代号，q退出）："; 
		cin >> choice;
	 }

	 cout << "结束模拟！！！" << endl;
    return 0;
}

