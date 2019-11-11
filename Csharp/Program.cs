using System;

namespace Csharp {
    class Program {
        static void Main (string[] args) {
            // //练习1：
            // //输入一个数字6
            // //让程序依次输出以下内容
            // /*
            //     0+6=6
            //     1+5=6
            //     2+4=6
            //     3+3=6
            //     4+2=6
            //     5+1=6
            //     6+0=6
            // */
            // System.Console.Write("请输入一个值：");
            // int num = int.Parse(Console.ReadLine());
            // for (int i = 0; i <= num; i++)
            // {
            //         System.Console.WriteLine("{0} + {1} = {2}", i, num - i, num);
            // }

            // //练习2：
            // //循环录入5个人的年龄并计算平均年龄，
            // //如果录入的数据出现负数或大于100的数，立即停止输入并报错。
            // System.Console.WriteLine ("请输入5个人的年龄进行计算");
            // int sum = 0;

            // bool b = true; //设置一个标志
            // for (int i = 0; i < 5; i++) {
            //     System.Console.Write ("请输入第{0}个人的年龄：", i + 1);
            //     try {
            //         int age = int.Parse (Console.ReadLine ());

            //         if (age >= 0 && age <= 100) {
            //             sum += age;
            //         } else {
            //             b = false;
            //             System.Console.WriteLine ("请输入正确的年龄！！！");
            //             break;
            //         }
            //     } catch {
            //         System.Console.WriteLine ("输入年龄不正确，程序退出！！！");
            //         b = false;
            //         break;
            //     }
            // }

            // if (b) {
            //     System.Console.WriteLine ("5个人的平均年龄是{0}", sum / 5);
            // }

            // //练习3：
            // //1~100之间的整数相加，得到累加值值大于20的当前数
            // //（比如：1+2+3+4+5+6=21 ，输出6

            // int sum = 0;
            // for (int i = 0; i < 20; i++)
            // {
            //     sum += i;
            //     if (sum >= 20)
            //     {
            //         System.Console.WriteLine("加到{0}的时候，总和大于了20", i);
            //         break;
            //     }
            // }
            


            // //练习四：
            // //找出100以内的所有素数
            // //素数/质数：只能被1和这个数字本身整除

            // //分析：
            // /*
            //     1、最小的质数为2
            //     2、首先使用for循环遍历2~100的数字
            //     3、然后需要将第j个数字分别与前面的数字进行取余操作，检验
            //         是否能被前面的数字整除。
            // */
            // for (int i = 2; i < 100; i++)
            // {
            //     bool b = true;      //标记
            //     for (int j = 2; j < i; j++)
            //     {
            //         if (i % j == 0)
            //         {
            //             b = false;
            //             break;     //除尽说明不是质数，就没有再往下取余的必要
            //         }
            //     }

            //     if (b)
            //     {
            //         System.Console.Write(i + "\t");
            //     }
            // }



             
            
        }
    }
}