构造函数不能是虚函数
C++默认编写的函数
默认构造、复制构造、析构、赋值运算符
拒绝自动生成的函数
私有化拷贝构造和赋值运算符；

不能既是模板又是虚函数

作用域
在函数里面的就是函数里面的，在函数括号之外的就是全局的，除非加　static 

const 对象　文件内有效，要多文件必须，　extern const int 

普通引用可以修改引用对象，对常量的引用，不可以修改引用对象

引用分为常量引用和变量
  

struct 在第一个限定符之前默认是public的
class 在第一个限定符之前默认是private的

用mutable修饰的成员永远不会是const ，即使出现在const函数中

最好令构造函数初始值的顺序与成员声明的顺序一致，而且如果有可能的话，尽量避免使用某些成员初始化其他成员。

指针和引用的区别：引用总是指向某个对象，所以定义引用的时候没初始化是错误的；对引用进行赋值改变的是指向的对象的值，而不是让该引用指向另外的对象。 

operator=返回*this的引用
允许连续赋值。
operator=处理自我赋值
注意资源的释放顺序。
```cpp
Widge& WIdget::operator=(const Widget& rhs)
{
if(this == &rhs) return *this;
delete pd;
pd = new Bitmap(*rhs.pd);
return *this;
}
```

new-delete同型成对
[]的出现与否要对应起来，即使使用了typedef重命名了数组类型。

延后变量定义式
不要提前定义，直到使用改变量的前一刻为之；
针对循环内的对象需要根据构造析构与赋值的成本，以及可维护性进行权衡。


声明一个纯虚函数的目的是为了**让派生类只继承函数接口**。
声明一个虚函数的目的是**让派生类继承该函数的接口和缺省实现**。
声明一个非虚函数的目的是**为了令派生类继承函数的接口及一份强制性实现**

http://www.jianshu.com/p/1ddbbc139ba8

http://www.cnblogs.com/tianyajuanke/archive/2012/11/29/2795131.html

> 绝对不要以多态方式处理数组

array[i] 其实是一个指针算术表达式的简写，它代表的其实是 *(array+i)，array是一个指向数组起始处的指针。在 for 里遍历 array 时，必须要知道每个元素之间相差多少内存，而编译器则根据传入参数来计算得知为 sizeof(B)，而如果传入的是派生类数组对象，它依然认为是 sizeof(B)，除非正好派生类大小正好与基类相同，否则运行时会出现错误。但是如果我们设计软件的时候，不要让具体类继承具体类的话，就不太可能犯这种错误。（理由是，一个类的父类一般都会是一个抽象类，抽象类不存在数组）

char * a[M];  这是指针数组

char (*a)[N];  这是一个指针，这个指针指向N个char元素，即指向数组的指针，其实就是一个指针。

```cpp
class point2d{
	public:
		point2d(float x = 0.0, float y = 0.0){
			x = x;//局部变量隐藏 this->x就可以引入了
			y = y;//成员函数默认有this,所以引入成员变量时通过this,最好在函数体引用this->x
			// x(x),y(y),一样编译成功，功能正确
		};
		float Getx() {return x;}
		float Gety() {return y;}
	private:
		float x , y;
};

```

b = 20;
		
			printf("a = %d, b = %d, Min: %d \n", b = 20;
		
			printf("a = %d, b = %d, Min: %d \n", 


说明：使用时要注意宏的副作用，能加上括号的地方一定不能少

```cpp
struct Node
{
	int size;
	char data[0];
};
```

`data`编译成一个`char*`类型指针