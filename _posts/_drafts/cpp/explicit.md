
# C++的 explicit关键字
explicit用来防止由构造函数定义的隐式转换.

effective c++中说：被声明为explicit的构造函数通常比其non-explicit兄弟更受欢迎。因为它们禁止编译器执行非预期（往往也不被期望）的类型转换。除非我有一个好理由允许构造函数被用于隐式类型转换，否则我会把它声明为explicit。我鼓励你遵循相同的政策。

c++中的explicit关键字用来修饰类的构造函数，表明该构造函数是显式的

如果c++类的构造函数有一个参数，那么在编译的时候就会有一个缺省的转换操作：将该构造函数对应数据类型的数据转换为该类对象，如下面所示：

```
class MyClass
{
public:
MyClass( int num );
}
....
MyClass obj = 10; //ok,convert int to MyClass
```
在上面的代码中编译器自动将整型转换为MyClass类对象，实际上等同于下面的操作：
```
MyClass temp(10);
MyClass obj = temp;
```
上面的所有的操作即是所谓的"隐式转换"。

如果要避免这种自动转换的功能，我们该怎么做呢？嘿嘿这就是关键字`explicit`的作用了，将类的构造函数声明为"显示"，也就是在声明构造函数的时候前面添加上`explicit`即可，这样就可以防止这种自动的转换操作，如果我们修改上面的`MyClass`类的构造函数为显示的，那么下面的代码就不能够编译通过了，如下所示：=
```
class MyClass
{
public:
explicit MyClass( int num );
}
........
MyClass obj = 10; //err,can't non-explict convert
```
