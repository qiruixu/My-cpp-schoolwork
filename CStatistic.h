/*设计一个统计类CStatistic，其结构如下：
私有数据成员Nums（学生人数），AveChinese（语文总评成绩），AveMaths（数学总评成绩），AveEnglish（英语总评成绩），StuArray（学生对象数组）；
公有静态成员函数Average（）；用于计算全班平均分；
公有成员函数Sort（）；实现学生对象数组中的对象按照平均分（从高到低）排序；
公有成员函数Display（）；实现屏幕输出对数据成员；*/
#pragma once
#include <iostream>
#include"CStudent.h"
using namespace std;
class CStatistic{
private:
    int Nums;
    double AveChinese,AveMaths,AveEnglish;
    CStudent StuArray[100];
    
public:  
    CStatistic(){
        Nums=0;
        AveChinese=0.0;
        AveMaths=0.0;
        AveEnglish=0.0;
    }
    CStatistic(int nums,double aveChinese,double aveMaths,double aveEnglish,CStudent stuArray[]){
        Nums=nums;
        AveChinese=aveChinese;
        AveMaths=aveMaths;
        AveEnglish=aveEnglish;
        for(int i=0;i<nums;i++){
            StuArray[i]=stuArray[i];
        }
    }
    //析构函数
    ~CStatistic(){
    }
    //拷贝学生个人成绩
    int SetData(CStudent students[],int n){
        Nums=n;
        for(int i=0;i<n;i++){
            StuArray[i]=students[i];
        }
        return OK;
    }
    //计算各科平均分
    static int Average(CStatistic &statistic){
        double sumChinese=0.0,sumMaths=0.0,sumEnglish=0.0;
        for(int i=0;i<statistic.Nums;i++){
            sumChinese+=statistic.StuArray[i].getChinese();
            sumMaths+=statistic.StuArray[i].getMaths();
            sumEnglish+=statistic.StuArray[i].getEnglish();
        }
        statistic.AveChinese=sumChinese/statistic.Nums;
        statistic.AveMaths=sumMaths/statistic.Nums;
        statistic.AveEnglish=sumEnglish/statistic.Nums;
        return OK;
    }
    //按总分平均分排序
    int Sort(){
        for(int i=0;i<Nums-1;i++){
            for(int j=0;j<Nums-i-1;j++){
                if(StuArray[j].Average()<StuArray[j+1].Average()){
                    CStudent temp=StuArray[j];
                    StuArray[j]=StuArray[j+1];
                    StuArray[j+1]=temp;
                }
            }
        }
        return OK;
    }
    //输出排序后学生各科成绩
    int DisplayStudents(){
        for(int i=0;i<Nums;i++){
            StuArray[i].Display();
            cout<<(i+1)<<endl;
        }
        return OK;
    }
    //输出各科平均分
    int Display(){
        cout<<"总评\t\t";
        printf("%.2f\t",AveChinese);
        printf("%.2f\t",AveMaths);
        printf("%.2f\t",AveEnglish);
        printf("%.2f\t",(AveChinese+AveMaths+AveEnglish)/3.0);    
        return OK;
    }
    
};