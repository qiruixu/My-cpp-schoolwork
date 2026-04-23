/*第Ⅱ题：基本练习
设计一个学生类CStudent，其结构如下：
私有数据成员Name（学生姓名）、Degree（成绩）、Level[7]（成绩等级）；
构造函数对数据成员初始化；
设计一个CStudents的友元类CProcess，其结构包含两个成员函数：
void Transform(CStudent& s)；实现对s的数据成员Level的判断其成绩的等级，：>=90为优秀；80～89为良好；70～79为中等；60～69为及格；< 60为不及格；
void Display(CStudent& s)输出s成绩的等级；
输出结果如下：
姓名	成绩	等级
Mary	78	中等
Jack	93	优秀
Mike	54	不及格
John	88	良好*/
#include <iostream>
#include <string.h>
using namespace std;
//CStudent类
class CStudent{
    private:
            string Name;
            int Degree;
            char Level[7];
    public: 
            CStudent();
            CStudent(string name,int degree);
            friend class CProcess;   //CProcess为CStudent的友元类
};
//CProcess类
class CProcess{
    public:
            void Transform(CStudent& s);
            void Display(CStudent& s);

};

CStudent::CStudent(){
    string Name = "";
    int Degree = 0;
    char Level[7] = "";
}
CStudent::CStudent(string name,int degree){
    Name = name;
    Degree = degree;
    Level[7] = 0;
}

void CProcess::Transform(CStudent& s){
    if(s.Degree >= 90){
        strcpy(s.Level,"优秀");}
    else if(s.Degree >= 80){
        strcpy(s.Level,"良好");}
    else if(s.Degree >= 70){
        strcpy(s.Level,"中等");}
    else if(s.Degree >= 60){
        strcpy(s.Level,"及格");}
    else 
        strcpy(s.Level,"不及格");

}
void CProcess::Display(CStudent& s){
    cout<<s.Name<<"\t"<<s.Degree<<"\t"<<s.Level<<endl;
}

int main(){
    CStudent s1("Mary",78);
    CStudent s2("Jack",93);
    CStudent s3("Mike",54);
    CStudent s4("John",88);
    cout<<"姓名\t成绩\t等级"<<endl;
    cout<<"-----------------------------"<<endl;
    CProcess process;
    process.Transform(s1);
    process.Display(s1);

    process.Transform(s2);
    process.Display(s2);

    process.Transform(s3);
    process.Display(s3);
    
    process.Transform(s4);
    process.Display(s4);

}