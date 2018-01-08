一个简单的例子
```cpp
#include <algorithm>  
#include <cmath>  
  
void abssort(float* x, unsigned n) {  
    std::sort(x, x + n,  
        // Lambda expression begins  
        [](float a, float b) {  
            return (std::abs(a) < std::abs(b));  
        } // end of lambda expression  
    );  
}  
  
```
![](https://i-msdn.sec.s-msft.com/dynimg/IC251606.jpeg)

- lambda-introducer （捕获字段）
- lambda-parameter-declaration-list （变量列表）
- mutable-specification （捕获的变量可否修改）
- exception-specification （异常设定）
- lambda-return-type-clause （返回类型）
- compound-statement （函数体）

捕获字段

```
[&total, factor]
[&, factor]
[=, &total]
```

使用捕获列表
一个lambda可以出现在一个函数中，使用其局部变量，但他只能使用那些明确指名的变量。
一个lambda通过将局部变量包含在其捕获列表中指出将来会使用这些变量。

如果想要修改sz就需要在参数列表后面加上mutable关键字

lambda为了适应形如一元谓词函数想要传递两个参数出现的，它也有许多不适应的地方，比如函数语句很大的情况下等等。
c++11引入了bind函数来解决这个问题。
头文件#include <functional>
可以把bind函数看作一个通用的函数适配器，它接受一个可调用的对象，生成一个新的可调用的对象来适应原有的参数列表。

```
auto check = bind(check_size, _1, 6); //_1表示check_size的第一个参数,比如是字符串s,第二个参数固定为6。

int add1(int a, int b, int c, int d, int f)  
{  
    return a+b+c+d+f;  
}  
int a,b,d;  
    cin >> a >> b >> d;  
    //bind将add1绑定到f上面，除了_1和_2需要我们传参。  
    auto f = bind(add1, a, b, std::placeholders::_1, d, std::placeholders::_2);   
    //调用f()，参数是(1,1)传递给_1和_2。  
    //等价于调用add1(a,b,_1,d,_2);  
```