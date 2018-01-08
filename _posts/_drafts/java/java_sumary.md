# java_sumary
javadoc 文档生成器
javap 反编译

公有类名字必须和文件名一致，最多里面有一个公有类

`main` 必须是 `public static void`

常量也可以先声明，再赋值，但是只能赋值一次，`final` 不能修改引用，但是可以修改值，但是`int`这些不可以

`float` 跟上 `F`

finalize 析构函数 将对象命名成 null

拥有抽象类的必须声明抽象类， 类方法不可以声明成抽象

接口 每一个方法变量都是 `abstract` 方法为`public abstract`, 变量为`final static public ` 必须初始化

X^2 为取反

多参量的原理是数组

`throws` 函数声明异常
`throw` 抛出异常

在本节的最后部分，我们将学习源文件的声明规则。当在一个源文件中定义多个类，并且还有import语句和package语句时，要特别注意这些规则。

一个源文件中只能有一个public类

一个源文件可以有多个非public类

源文件的名称应该和public类的类名保持一致。例如：源文件中public类的类名是Employee，那么源文件应该命名为Employee.java。

如果一个类定义在某个包中，那么package语句应该在源文件的首行。

如果源文件包含import语句，那么应该放在package语句和类定义之间。如果没有package语句，那么import语句应该在源文件中最前面。

import语句和package语句对源文件中定义的所有类都有效。在同一源文件中，不能给不同的类不同的包声明。
