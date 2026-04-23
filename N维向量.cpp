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
将此推广到n维         
*/
#include <iostream>

#define OK 1
#define ERROR 0

using namespace std;

class NVector {
private:
    int n;       // 维度
    int* data;   // 分量数组

public:
    NVector(int size);
    NVector(int size, int arr[]);
    NVector(const NVector &other);  //新增了复制构造函数
    void display();
    int get(int index);
    NVector Add(const NVector &ob2);
    NVector Sub(const NVector &ob2);
    int Mult(const NVector &ob2);
};
//初始化为0
NVector::NVector(int size) {
    n = size;
    data = new int[n];
    for (int i = 0; i < n; i++)
        data[i] = 0;
}
//用数组元素填充分量
NVector::NVector(int size, int arr[]) {
    n = size;
    data = new int[n];
    for (int i = 0; i < n; i++)
        data[i] = arr[i];
}
//新增了复制构造函数
NVector::NVector(const NVector &other) {
    n = other.n;
    data = new int[n];
    for (int i = 0; i < n; i++)
        data[i] = other.data[i];
}
//输出
void NVector::display() {
    cout << "(";
    for (int i = 0; i < n; i++) {
        cout << data[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << ")";
}
//访问
int NVector::get(int index) {
    if (index >= 0 && index < n)
        return data[index];
    else{
    cout<<"超出维度范围！"<<endl;
    return ERROR;
    }
}
//运算
NVector NVector::Add(const NVector &ob2) {
    if (n != ob2.n) {
        cout << "向量必须是同一维度的！" << endl;
        return ERROR;
    }
    NVector result(n);
    for (int i = 0; i < n; i++)
        result.data[i] = data[i] + ob2.data[i];
    return result;
}

NVector NVector::Sub(const NVector &ob2) {
    if (n != ob2.n){
        cout << "向量必须是同一维度的！" << endl;
        return ERROR;
    }
    NVector result(n);
    for (int i = 0; i < n; i++)
        result.data[i] = data[i] - ob2.data[i];
    return result;
}

int NVector::Mult(const NVector &ob2) {
    if (n != ob2.n){
        cout << "向量必须是同一维度的！" << endl;
        return ERROR;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
        result += data[i] * ob2.data[i];
    return result;
}


int main() {
    int n;
    cout << "请输入向量的维度：" ;
    cin >> n;

  
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    cout << "请输入第一个向量的分量：";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "请输入第二个向量的分量：";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    NVector v1(n, arr1);
    NVector v2(n, arr2);

    cout << "v1: "; v1.display(); cout << endl;
    cout << "v2: "; v2.display(); cout << endl;

    NVector sum = v1.Add(v2);
    NVector sub = v1.Sub(v2);
    int mult = v1.Mult(v2);

    cout << "v1 + v2: "; sum.display(); cout << endl;
    cout << "v1 - v2: "; sub.display(); cout << endl;
    cout << "v1 · v2: " << mult << endl;

    return 0;
}