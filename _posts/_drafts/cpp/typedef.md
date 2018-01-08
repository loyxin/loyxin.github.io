## typedef
#### 用途一：
定义一种类型的别名，而不只是简单的宏替换。可以用作同时声明指针型的多个对象。
#### 用途二:
用在旧的C代码中，帮助struct。以前的代码中，声明struct新对象时，必须要带上struct，即形式为： struct 结构名对象名，如：
```cpp
typedef struct tagPOINT
{
    int x;

    int y;
}POINT;

POINT p1; // 这样就比原来的方式少写了一个struct
```
#### 用途三：
用`typedef`来定义与平台无关的类型。

比如定义一个叫 REAL 的浮点类型，在目标平台一上，让它表示最高精度的类型为：

```
typedef long double REAL;
```

在不支持 long double 的平台二上，改为：

```
typedef double REAL;
```

在连 double 都不支持的平台三上，改为：

```
typedef float REAL;
```

也就是说，当跨平台时，只要改下 typedef 本身就行，不用对其他源码做任何修改。

标准库就广泛使用了这个技巧，比如size_t。另外，因为typedef是定义了一种类型的新别名，不是简单的字符串替换，所以它比宏来得稳健。

## typeid
在c++中，typeid用于返回指针或引用所指对象的实际类型。

typeid是C++的关键字之一，等同于sizeof这类的操作符。typeid操作符的返回结果是名为type_info的标准库类型的对象的引用（在头文件typeinfo中定义

标准C++的一个新特征是RTTI（Run-Time Type Information运行时类型信息），它为程序在运行时确定对象类型，提供了一种标准方法。在标准C++中，有三个支持RTTI的元素：
`dynamic_cast` `typeid` 
```cpp
#include <iostream>
#include<typeinfo>
using namespace std;

class Base {};
class Derived: public Base {};

int main()
{
    Base b, *pb;
    pb = NULL;
    Derived d;

    cout << typeid(int).name() << endl
         << typeid(unsigned).name() << endl
         << typeid(long).name() << endl
         << typeid(unsigned long).name() << endl
         << typeid(char).name() << endl
         << typeid(unsigned char).name() << endl
         << typeid(float).name() << endl
         << typeid(double).name() << endl
         << typeid(string).name() << endl
         << typeid(Base).name() << endl
        << typeid(b).name()<<endl
         << typeid(pb).name()<<endl
         << typeid(Derived).name() << endl
         << typeid(d).name()<<endl
         << typeid(type_info).name() << endl;

    return 0;
}
```
