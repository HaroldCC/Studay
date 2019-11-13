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

#define Maxpage 20  //�������ҳ����
#define Maxblock 10 //��������������

int Pages[Maxpage]; //��ҵ

int page = 0; //ͳ����ҵ����

void InitBlocks(int Blocks[], int page, int block) //��ʼ���ڴ��
{
    for (int i = 0; i < block; i++)
    {
        Blocks[i] = 0;
    }

    cout << "***********************************�ڴ���ʼ��Ϊ***********************************";
    cout << endl;

    for (int j = 0; j < page; j++)
    {
        for (int i = 0; i < block; i++) //��ʾ��ʼ������ڴ��
        {
            cout << Blocks[i] << "  ";
        }
        cout << endl;
    }
    cout << "**********************************����һ���ָ���*******************************************\n";
}

void ShowInfo(void)
{
    cout << "################################################�洢��֮ҳ���û��㷨ģ��#############################################################\n";
    cout << endl;
    cout << "                                          1���Ƚ��ȳ�ҳ���û��㷨(FIFO)\n";
    cout << "                                          2��������δʹ���㷨(LRU)\n";
    cout << endl;
    cout << "##############################################�������ѡ����Ҫģ����㷨#############################################################\n";
}

void ReadPages(int *pages) //��ȡ�ļ��е���ҵ
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
        finput >> Pages[page]; //���ļ��ж�ȡ���Ľ���洢��Pages[]������
        page++;
    }

    finput.close();
}

void FIFO(int Pages[], int Blocks[], int page, int block)
{

    cout << "�����Ƚ��ȳ�ҳ���û��㷨(FIFO)�Ľ��Ϊ��\n";

    int max_stay = 0, count = 0; //max_stay:��ǰҳ��פ�����ʱ�䣬 count:ͳ��ҳ���û�����

    int get = -1, flag = -1, max_block_num = -1; //get:������Ƿ�ȴ�ע����ҳ��(-1����)
    //flag:��ǵ�ǰ����Ƿ���ע���ڴ棨-1����
    //max_block_num:פ���ڴ�ʱ�����ҳ�����������
    int time[Maxblock];
    for (int i = 0; i < page; i++)
    {
        time[i] = 0;
    }

    for (int i = 0; i < page; i++)
    {
        for (int j = 0; j < block; j++) //�п��������ʱҳ��ֱ��ע���ڴ���п�
        {
            if (Blocks[j] == 0)
            {
                get = j; // �����j����פ����ҳ��
                break;
            }
        }

        for (int j = 0; j < block; j++) //���������ͬ��ҳ��
        {
            if (Blocks[j] == Pages[i]) //�����j��ҳ���뵱ǰ���������ڴ��ҳ����ͬ
            {
                flag = j;
                break;
            }
        }

        for (int j = 0; j < block; j++) // �ҵ�פ���ڴ���ʱ����õ�ҳ���û���
        {
            if (time[j] > max_stay)
            {
                max_stay = time[j];
                max_block_num = j; // max_block_num��ǵ�ǰ����������ҳ��פ��ʱ�����
            }
        }

        if (flag == -1) //��������ͬҳ��
        {
            if (get != -1) //����鼴��פ����ҳ��
            {
                Blocks[get] = Pages[i]; //����ҳ��
                time[get] = 0;			//��ǰ��������¼�ʱ

                for (int j = 0; j <= get; j++) //��פ��ҳ���פ��ʱ���1
                {
                    time[j]++;
                }

                get = -1;
            }
            else //ҳ������û������max_block_num���������פ��ʱ����õ�
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
        else //������ҳ�������flag���������ҳ����ͬ
        {
            for (int j = 0; j < block; j++)
            {
                time[j]++;
            }
            flag = -1;
        }

        cout << "��" << i + 1 << "��ҳ���û�:\n";
        for (int j = 0; j < block; j++) //���������е�ҳ��פ�����
        {
            cout << Blocks[j] << "   ";
        }
        cout << endl;
    }

    if (page > block)
        count = count + block;
    cout << "\n############################################\nȱҳ�жϴ���Ϊ��" << count << endl;
    cout << "ȱҳ��Ϊ��" << (double)count / (double)page << endl;
    cout << "************************************��Ҳ��һ���ָ���************************************************\n";
}

void LRU(int *Pages, int *Blocks, int page, int block) //LRUҳ���û��㷨
{
    cout << "������δʹ��ҳ���û��㷨���Ϊ:\n";

    int count = 0; //ȱҳ����

    bool flag;       //ȱҳ��־

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
            flag = false;                  //ȱҳ��־flag
            count++;
        }
        else
        {
            flag = true;
        }

            for (int j = q; j > 0; j--)       //��̭���ȵ����ҳ��
            {
                Blocks[j] = Blocks[j - 1];
            }
            Blocks[0] = Pages[i];

        cout << "��" << i + 1 << "��ҳ���û���\n";
        for (int j = 0; j < block; j++)
        {
            cout << Blocks[j] << "   ";
        }
        cout << endl;
    }
    cout << "\n############################################\nȱҳ�жϴ���Ϊ��" << count << endl;
    cout << "ȱҳ��Ϊ��" << (double)count / (double)page << endl;
    cout << "************************************�⻹��һ���ָ���************************************************\n";
}

int main(int argc, char *argv[])

{
    int Blocks[Maxblock];

    ReadPages(Pages);
    ShowInfo();
    cout << "������Ҫģ����㷨����ǰ�Ĵ���:";
    char choice;
    cin >> choice;
    while (choice != 'q')
    {
        cout << "���������������";
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

        cout << "�Ƿ�Ҫ��������ģ�⣿(����������ţ�q�˳�����";
        cin >> choice;
    }

    return 0;
}
