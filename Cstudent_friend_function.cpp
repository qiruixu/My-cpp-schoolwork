/*第Ⅰ题：基本练习
设计一个学生类CStudent，其结构如下：
私有数据成员Name（学生姓名）、Degree（成绩）；
构造函数对数据成员初始化；
设计一个友元函数Display(CStudent&)；输出成绩的等级：>=90为优秀；80～89为良好；70～79为中等；60～69为及格；< 60为不及格；
输出结果如下：
姓名	成绩	等级
Mary	78	中等
Jack	93	优秀
Mike	54	不及格
John	88	良好
*/
#include <iostream>
using namespace std;

class CStudent{
    private:
            string Name;
            int Degree;
            string Level;
    public: 
            CStudent();
            CStudent(string name,int degree);
            friend void Display(CStudent &stu);  //Display为CStudent的友元函数
};

CStudent::CStudent(){
    string Name = "";
    int Degree = 0;
    string Level = "";
}
CStudent::CStudent(string name,int degree){
    Name = name;
    Degree = degree;
    Level = "";
}

void Display(CStudent &stu){
    if (stu.Degree >= 90){
        stu.Level = "优秀";
    }
    else if(stu.Degree >= 80){
        stu.Level = "良好";
    }
    else if(stu.Degree >= 70){
        stu.Level = "中等";
    }
    else if(stu.Degree >= 60){
        stu.Level = "及格";
    }
    else{
        stu.Level = "不及格";
    }
    cout<<stu.Name<<"\t"<<stu.Degree<<"\t"<<stu.Level<<endl;
}

int main(){
    CStudent stu1("Mary",78);
    CStudent stu2("Jack",93);
    CStudent stu3("Mike",54);
    CStudent stu4("John",88);

    cout<<"姓名\t成绩\t等级"<<endl;
    cout<<"-----------------------------"<<endl;
    Display(stu1);
    Display(stu2);
    Display(stu3);
    Display(stu4);
    
    return 0;
}