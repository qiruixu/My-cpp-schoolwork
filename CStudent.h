/*设计一个学生类CStudent，其结构如下：
私有数据成员No（学号），Name（姓名），DegChinese（语文成绩），DegMaths（数学成绩），DegEnglish（英语成绩），两个数据成员Sum（总分）和Num（人数）；
重载构造函数，实现对类实例对象的带参数初始化和无参数初始化；
公有成员函数SetData（）；实现键盘随机输入对数据成员赋值；
公有成员函数Display（）；实现屏幕输出对数据成员；
公有成员函数Average（）；用于计算学生个人平均分；*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>


#define OK 1
#define ERROR 0

using namespace std;
class CStudent{
    private:
    string No;
    string Name;
    int DegChinese,DegMaths,DegEnglish;
    int Sum,Num;

    public:
    CStudent(){
        No="";
        Name="";
        DegChinese=0;
        DegMaths=0;
        DegEnglish=0;
        Sum=0;
        Num=0;
    }
    CStudent(string no,string name,int degChinese,int degMaths,int degEnglish){
        No=no;
        Name=name;
        DegChinese=degChinese;
        DegMaths=degMaths;
        DegEnglish=degEnglish;
        Sum=DegChinese+DegMaths+DegEnglish;
        Num++;
    }
    //析构函数
    ~CStudent(){
    }
    //用于外部访问各成绩
    int getChinese(){
        return DegChinese;
    }
    int getMaths(){
        return DegMaths;
    }
    int getEnglish(){
        return DegEnglish;
    }
    //接收学生成绩信息
    int setDate(){
    cout<<"请输入学生学号：";
    cin>>No;
    cout<<"请输入学生姓名：";
    cin>>Name;
    cout<<"请输入学生语文成绩：";
    cin>>DegChinese;
    cout<<"请输入学生数学成绩：";
    cin>>DegMaths;
    cout<<"请输入学生英语成绩：";
    cin>>DegEnglish;
    Sum=DegChinese+DegMaths+DegEnglish;
    Num++;
    return OK;
    }
    //输出学生各科成就
    int Display(){
    cout<<left;
    cout<<setw(8)<<No;
    cout<<setw(10)<<Name;
    cout<<setw(8)<<DegChinese;
    cout<<setw(8)<<DegMaths;
    cout<<setw(8)<<DegEnglish;
    cout<<setw(8)<<Average();
    return OK;
    }
    //计算学生个人平均分
    double Average(){
    return Sum/3.0;
    }
};
