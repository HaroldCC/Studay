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

