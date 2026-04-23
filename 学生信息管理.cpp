/*设计一个学生类CStudent，其结构如下：
私有数据成员No（学号），Name（姓名），DegChinese（语文成绩），DegMaths（数学成绩），DegEnglish（英语成绩），两个数据成员Sum（总分）和Num（人数）；
重载构造函数，实现对类实例对象的带参数初始化和无参数初始化；
公有成员函数SetData（）；实现键盘随机输入对数据成员赋值；
公有成员函数Display（）；实现屏幕输出对数据成员；
公有成员函数Average（）；用于计算学生个人平均分；
2．设计一个统计类CStatistic，其结构如下：
私有数据成员Nums（学生人数），AveChinese（语文总评成绩），AveMaths（数学总评成绩），AveEnglish（英语总评成绩），StuArray（学生对象数组）；
公有静态成员函数Average（）；用于计算全班平均分；
公有成员函数Sort（）；实现学生对象数组中的对象按照平均分（从高到低）排序；
公有成员函数Display（）；实现屏幕输出对数据成员；
3．主函数设计要求：
定义一个指向CStatistic对象的指针pStatistic，实现对象的初始化或赋值；
输出格式如下：
学号	姓名	语文	数学	英语	平均分	名次
0181109	Phillise	90	90	90	90	1
0181119	Jack	    85	85	85	85	2
0181123	Mary	    80	85	75	80	3
0181213	Jerry	    75	70	80	75	4
0181111	Mike	    75	65	70	70	5
0181221	Tom  	    65	60	55	60	6
总评		   78.33	75.83	77.5	77.5	*/

#include <iostream>
#include"CStudent.h"
#include"CStatistic.h"
#include<iomanip>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0

int main(){
    string no,name;
    int degChinese,degMaths,degEnglish;
    //double aveChinese,aveMaths,aveEnglish;

    ifstream fp("../data.txt");
    if(!fp){
        cout<<"无法打开文件！"<<endl;
        return ERROR;
    }
    //分配内存存储学生对象
    CStudent *students=new CStudent[100];
    CStatistic *pStatistic=new CStatistic();
    
    int n=0;
    //读取
    while(fp>>no>>name>>degChinese>>degMaths>>degEnglish){
        students[n]=CStudent(no,name,degChinese,degMaths,degEnglish);
        n++;
    }
    fp.close();

    pStatistic->SetData(students,n);

    pStatistic->Sort();

    cout << "学号\t姓名\t  语文    数学    英语   平均分  名次" << endl;
    pStatistic->DisplayStudents();
    
    CStatistic::Average(*pStatistic);
    pStatistic->Display();
    //释放内存
    delete[] students;
    delete pStatistic;
    return OK;  
}

