/*************************************************************************
    > File Name       : FifoLru.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-11-12 14:46:21
 ************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

#define Maxpage 20  //定义最大页面数
#define Maxblock 10 //定义最大物理块数

int Pages[Maxpage]; //作业

int page = 0; //统计作业数量

void InitBlocks(int Blocks[], int page, int block) //初始化内存块
{
    for (int i = 0; i < block; i++)
    {
        Blocks[i] = 0;
    }

    cout << "***********************************内存块初始化为***********************************";
    cout << endl;

    for (int j = 0; j < page; j++)
    {
        for (int i = 0; i < block; i++) //显示初始化后的内存块
        {
            cout << Blocks[i] << "  ";
        }
        cout << endl;
    }
    cout << "**********************************这是一条分割线*******************************************\n";
}

void ShowInfo(void)
{
    cout << "################################################存储器之页面置换算法模拟#############################################################\n";
    cout << endl;
    cout << "                                          1、先进先出页面置换算法(FIFO)\n";
    cout << "                                          2、最近最久未使用算法(LRU)\n";
    cout << endl;
    cout << "##############################################输入代号选择你要模拟的算法#############################################################\n";
}

void ReadPages(int *pages) //读取文件中的作业
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
        finput >> Pages[page]; //将文件中读取到的结果存储在Pages[]数组中
        page++;
    }

    finput.close();
}

void FIFO(int Pages[], int Blocks[], int page, int block)
{

    cout << "采用先进先出页面置换算法(FIFO)的结果为：\n";

    int max_stay = 0, count = 0; //max_stay:当前页面驻留最久时间， count:统计页面置换次数

    int get = -1, flag = -1, max_block_num = -1; //get:物理块是否等待注入新页面(-1：否)
    //flag:标记当前序号是否已注入内存（-1：否）
    //max_block_num:驻留内存时间最长的页面的物理块序号
    int time[Maxblock];
    for (int i = 0; i < page; i++)
    {
        time[i] = 0;
    }

    for (int i = 0; i < page; i++)
    {
        for (int j = 0; j < block; j++) //有空闲物理块时页面直接注入内存空闲块
        {
            if (Blocks[j] == 0)
            {
                get = j; // 物理块j即将驻入新页面
                break;
            }
        }

        for (int j = 0; j < block; j++) //查找序号相同的页面
        {
            if (Blocks[j] == Pages[i]) //物理块j中页面与当前期望调入内存的页面相同
            {
                flag = j;
                break;
            }
        }

        for (int j = 0; j < block; j++) // 找到驻留内存中时间最久的页面置换出
        {
            if (time[j] > max_stay)
            {
                max_stay = time[j];
                max_block_num = j; // max_block_num标记当前序号物理块中页面驻留时间最久
            }
        }

        if (flag == -1) //不存在相同页面
        {
            if (get != -1) //物理块即将驻入新页面
            {
                Blocks[get] = Pages[i]; //存入页面
                time[get] = 0;			//当前物理块重新计时

                for (int j = 0; j <= get; j++) //已驻入页面的驻留时间加1
                {
                    time[j]++;
                }

                get = -1;
            }
            else //页面调度置换，序号max_block_num的物理块是驻留时间最久的
            {
                Blocks[max_block_num] = Pages[i];
                time[max_block_num] = 0;
                for (int j = 0; j < Maxblock; j++)
                {
                    time[j]++;
                }
                max_block_num = -1;
                max_stay = 0;

                count++;
            }
        }
        else //待调入页面与序号flag的物理块中页面相同
        {
            for (int j = 0; j < block; j++)
            {
                time[j]++;
            }
            flag = -1;
        }

        cout << "第" << i + 1 << "次页面置换:\n";
        for (int j = 0; j < block; j++) //输出物理块中的页面驻入情况
        {
            cout << Blocks[j] << "   ";
        }
        cout << endl;
    }

    if (page > block)
        count = count + block;
    cout << "\n############################################\n缺页中断次数为：" << count << endl;
    cout << "缺页率为：" << (double)count / (double)page << endl;
    cout << "************************************这也是一条分割线************************************************\n";
}

void LRU(int *Pages, int *Blocks, int page, int block) //LRU页面置换算法
{
    cout << "最近最久未使用页面置换算法结果为:\n";

    int count = 0; //缺页次数

    bool flag;       //缺页标志

    int q;
    for(int i = 0; i < page; i++)
    {
        q = 0;
        while ((Pages[i] != Blocks[q]) && (q != block) )
        {
            q++;
        }
        if (q == block)
        {
            flag = false;                  //缺页标志flag
            count++;
        }
        else
        {
            flag = true;
        }

            for (int j = q; j > 0; j--)       //淘汰最先调入的页面
            {
                Blocks[j] = Blocks[j - 1];
            }
            Blocks[0] = Pages[i];

        cout << "第" << i + 1 << "次页面置换：\n";
        for (int j = 0; j < block; j++)
        {
            cout << Blocks[j] << "   ";
        }
        cout << endl;
    }
    cout << "\n############################################\n缺页中断次数为：" << count << endl;
    cout << "缺页率为：" << (double)count / (double)page << endl;
    cout << "************************************这还是一条分割线************************************************\n";
}

int main(int argc, char *argv[])

{
    int Blocks[Maxblock];

    ReadPages(Pages);
    ShowInfo();
    cout << "输入你要模拟的算法名字前的代号:";
    char choice;
    cin >> choice;
    while (choice != 'q')
    {
        cout << "输入物理块数量：";
        int block;
        cin >> block;

        InitBlocks(Blocks, page, block);

        if (choice == '1')
        {
            FIFO(Pages, Blocks, page, block);
        }

        if (choice == '2')
        {
            LRU(Pages, Blocks, page, block);
        }

        cout << "是否要继续进行模拟？(继续输入代号，q退出）：";
        cin >> choice;
    }

    return 0;
}
