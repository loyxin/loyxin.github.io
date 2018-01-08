# decltype
返回值 decltype(表达式)

[返回值的类型是表达式参数的类型]

这个可也用来决定表达式的类型，就像Bjarne暗示的一样，如果我们需要去初始化某种类型的变量，`auto`是最简单的选择，但是如果我们所需的类型不是一个变量，例如返回值这时我们可也试一下`decltype`。
```
int add(int x,int y){
    return x+y;
}
int main(){
    double i=0;
    decltype(i) a; // double
    decltype(add()) b; //int 注意括号。不带括号就是函数指针了。
}
```
需要说明，decltype仍然是编译期行为，add()函数不会真正执行，只是利用它推导了类型。


需要注意的是，auto不能用来声明函数的返回值。但如果函数有一个尾随的返回类型时，auto是可以出现在函数声明中返回值位置。这种情况下，auto并不是告诉编译器去推断返回类型，而是指引编译器去函数的末端寻找返回值类型。

```
template<typename U, typename V>
auto foo(U u, V v) -> decltype(u*v){
    return u*v;
}
```
# auto

编译器会根据值的类型，推导出autob变量。类型的推导是在编译期就完成的，仍是静态类型，和脚本语言不同。实际上是一个语法糖。但由于C++对模板的大量使用，一个变量的类型有时过于复杂难以写出，这样的语法糖是必要的。

### auto+引用
```
int i = 0;
int& r = i;
auto a = r; // type of a?
a = 10;
cout<<i<<endl; // value of i?
```
直观上感觉，r是i的引用，a自然也会推导出int&这个类型。但实际上，r只是i的别名，a类型的推导结果还是int。于是，对a的修改和i无关，结果输出0。如果想推导出引用，需要这样
```
auto& a = r; // auto& a = i也可以
```
### auto+const
还有一点，auto会忽略顶层的const。
```
const int i = 0;
auto a = i; // a: int
audo b = &i // b: const int*
```
其中，a是普通的int, 因为i是const int，auto把顶层的const忽略了。b是const int*, 这个可以这样看，const int*实际上是“(const int)*”（当然代码不能这样写），const不是顶层修饰符了，就没有忽略。

如果想得到推导出一个const类型，需要
```
const auto a = i; // a: const int
```
另外，decltype和auto不同，它不会忽略引用和顶层const修饰。
```
const int i=0;
int j=0, &r = j;
decltype(i) a; //const int
decltype(r) b; //int& 
```
最后，比较特别的是，如果decltype里面的表达式被包含在括号中，视为对表达式求值的类型。
```
decltype((i)) a;//error: a is int& and must be initialized
```
对i求值返回的是int&




