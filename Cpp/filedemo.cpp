/*************************************************************************
    > File Name       : filedemo.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-11 19:01:04
 ************************************************************************/
#include<iostream>
#include<fstream>

using namespace std;

int num[20] = {0};
int pos = 0;

void readfile(void)
{
	ifstream finput;
	finput.open("./1.txt");

	if (!finput.is_open())
	{
		cout << "Can't open the file!";
		exit(EXIT_FAILURE);
	}

	while (!finput.eof())
	{
		finput >> num[pos];
		pos++;
	}

	finput.close();
}

void LRU(int* Pages, int* Blocks, int page, int block)
{
	int re_used = 0, cont = 0;        //re_used:最近使用的作业； count：统计页面置换次数


	//get:物理块是否等待注入新页面(-1：否)                                                              
	//flag:标记当前序号是否已注入内存（-1：否）
	//used_block_num:最近使用过的页面的物理块序号
	int get = -1, flag = -1, used_clock_num = -1;

	int recentUsed[Maxblock];
	for (int i = 0; i < page; i++)
	{
		recentUsed[i] = 0;
	}
	
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < block; j++)
		{
			if (Blocks[j] == 0)
			{
				get = j;
				break;
			}
			
		}

		for (int j = 0; j < block; j++)
		{
			if (Blocks[j] == Pages[i])
			{
				flag = j;
				break;
			}
		}
		
		for (int j = 0; j < block; i++)
		{
			if (page == Blocks[j])
			{
				re_used = Blocks[j];
				
			}
			
		}
		
	}
	
}

int main(int argc,char *argv[])
{
	for (int i = 0; i < pos; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

     readfile();

	 for (int i = 0; i < pos; i++)
	 {
		 cout << num[i] << " ";
	 }
	 cout << endl;
	system("pause");
    return 0;
}

