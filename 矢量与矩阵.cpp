/*1.定义一个矢量类Vector，其结构如下：
私有数据成员int x,y; 表示二维矢量的两个分量
构造函数实现初始化数据成员
输出数据成员函数 void display( );
类外访问数据成员函数
          int getx( );
          int gety( );
功能成员函数实现矢量加、减、乘运算
          Vector Add(const Vector &ob2 );
          Vector Sub(const Vector &ob2 );
          int Mult(const Vector &ob2 );
2.在Vector 类的基础上，定义矩阵类Matrix（2*2阶），其结构如下：
私有数据成员Vector lefttop, righttop, leftbottom, rightbottom; 表示2*2阶矩阵的四个元素。
（提示：也可以采用子对象数组来实现Vector MatrixArray[2][2];）
构造函数实现初始化数据成员
输出数据成员函数 void display( );
类外访问数据成员函数
          Vector GetVector(int i, int j);  // i, j为矩阵元素的下标MatrixArray[i][j]
功能成员函数实现矢量加、减、乘运算*/

#include<iostream>

using namespace std;

//构建向量类
class Vector{
    private:
        int x,y;

     public:
        Vector();
        Vector(int x,int y);
        void display();
        int getx();
        int gety();
        Vector Add(const Vector &ob2);
        Vector Sub(const Vector &ob2);
        int Mult(const Vector &ob2);
};

//矩阵类
class Matrix{
    private:
        Vector MatrixArray[2][2];

    public:
        Matrix();
        Matrix(Vector lefttop, Vector righttop,Vector leftbottom,Vector rightbottom);
        void display();
        Vector GetVector(int i,int j);
        Matrix Add(const Matrix &ob2);
        Matrix Sub(const Matrix &ob2);
        int Mult(const Matrix &ob2);
};

//构造向量
Vector::Vector(){
    x=0;
    y=0;
}

Vector::Vector(int x1,int y1){
    x=x1;
    y=y1;
}

//输出
void Vector::display(){
    cout<< "(" << x << "," << y <<")";
}

//访问
int Vector::getx(){
    return x;
}

int Vector::gety(){
    return y;
}

//运算
Vector Vector::Add(const Vector &ob2){
    return Vector(x+ob2.x,y+ob2.y);
}

Vector Vector::Sub(const Vector &ob2){
    return Vector(x-ob2.x,y-ob2.y);
}

int Vector::Mult(const Vector &ob2){
    return (x*ob2.x + y*ob2.y);
}

//矩阵构建
Matrix::Matrix(){
    MatrixArray[0][0]=Vector(0,0);
    MatrixArray[0][1]=Vector(0,0);
    MatrixArray[1][0]=Vector(0,0);
    MatrixArray[1][1]=Vector(0,0);
}
Matrix::Matrix(Vector lefttop, Vector righttop,Vector leftbottom,Vector rightbottom){
    MatrixArray[0][0]=lefttop;
    MatrixArray[0][1]=righttop;
    MatrixArray[1][0]=leftbottom;
    MatrixArray[1][1]=rightbottom;
}

//输出
void Matrix::display(){
    MatrixArray[0][0].display();
    cout<<"  ";
    MatrixArray[0][1].display();
    cout<<endl;
    MatrixArray[1][0].display();
    cout<<"  ";
    MatrixArray[1][1].display();
    cout<<endl;
}

//访问
Vector Matrix::GetVector(int i,int j){
    return MatrixArray[i][j];
}

//运算
Matrix Matrix::Add(const Matrix &ob2){
    Vector a=MatrixArray[0][0].Add(ob2.MatrixArray[0][0]);
    Vector b=MatrixArray[0][1].Add(ob2.MatrixArray[0][1]);
    Vector c=MatrixArray[1][0].Add(ob2.MatrixArray[1][0]);
    Vector d=MatrixArray[1][1].Add(ob2.MatrixArray[1][1]);
    return Matrix(a,b,c,d);
}

Matrix Matrix::Sub(const Matrix &ob2){
    Vector a=MatrixArray[0][0].Sub(ob2.MatrixArray[0][0]);
    Vector b=MatrixArray[0][1].Sub(ob2.MatrixArray[0][1]);
    Vector c=MatrixArray[1][0].Sub(ob2.MatrixArray[1][0]);
    Vector d=MatrixArray[1][1].Sub(ob2.MatrixArray[1][1]);
    return Matrix(a,b,c,d);
}
//点乘
int Matrix::Mult(const Matrix &ob2){
    int result=0;
    result += MatrixArray[0][0].Mult(ob2.MatrixArray[0][0]);
    result += MatrixArray[0][1].Mult(ob2.MatrixArray[0][1]);
    result += MatrixArray[1][0].Mult(ob2.MatrixArray[1][0]);
    result += MatrixArray[1][1].Mult(ob2.MatrixArray[1][1]);
    return result;
    
}
//
int main(){
    int a, b, c, d;
    Vector v1, v2, v3(3,4), v4(5,6);        //提前定义了v3，v4；v1，v2用户自定义

    cout << "请输入第一个向量(x y)：";
    cin >> a >> b;
    v1 = Vector(a, b);  

    cout << "请输入第二个向量(x y)：";
    cin >> c >> d;
    v2 = Vector(c, d);  

    cout<<"v1:";
    v1.display();
    cout<<endl;
    cout<<"v2:";
    v2.display();
    cout<<endl;
    
    
    cout<<"矢量形式："<<endl;                           //矢量只做了v1和v2的运算
    cout<<"和："<<"("<<v1.Add(v2).getx()<<","<<v1.Add(v2).gety()<<")"<<endl;
    cout<<"差："<<"("<<v1.Sub(v2).getx()<<","<<v1.Sub(v2).gety()<<")"<<endl;
    cout<<"积："<<v1.Mult(v2)<<endl;
    cout<<endl;

    cout<<"v3:";
    v3.display();
    cout<<endl;
    
    cout<<"v4:";
    v4.display();
    cout<<endl;

    Matrix m1(v1, v2, v3, v4);
    Matrix m2(v2, v1, v4, v3); 
    
    cout<<endl<<"矩阵 m1："<<endl;
    cout<<"v1 v2"<<endl;
    cout<<"v3 v4"<<endl;
    m1.display();

    cout<<endl<<"矩阵 m2："<<endl;
    cout<<"v2 v1"<<endl;
    cout<<"v4 v3"<<endl;
    m2.display();

    cout<<endl<<"矩阵相加："<<endl;
    m1.Add(m2).display();

    cout<<endl<<"矩阵相减："<<endl;
    m1.Sub(m2).display();

    cout<<endl<<"矩阵点乘结果："<<m1.Mult(m2)<<endl;

    return 0;
}