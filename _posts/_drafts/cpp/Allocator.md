每个 C++程序员都已经知道动态内存分配：写下`new X`来分配内存和创建一个X类型的新对象，写下`delete p`来销毁`p`所指的对象并归还其内存。你有理由认为`allocator`会使用`new`和`delete`－－但它们没有。（C++标准将`::operatornew()`描述为“`allocation function`”，但很奇怪，`allocator`并不是这样的。）

有关`allocator`的最重要的事实是它们只是为了一个目的：封装STL容器在内存管理上的低层细节。你不应该在自己的代码中直接调用`allocator` 的成员函数，除非正在写一个自己的STL容器。你不应该试图使用`allocator`来实现`operatornew[]`；这不是`allocator`该做的。如果你不确定是否需要使用`allocator`，那就不要用。

`allocator`是一个类,有着叫`allocate()`和`deallocate()`成员函数（相当于`malloc`和`free`）。它还有用于维护所分配的内存的辅助函数和指示如何使用这些内存的`typedef`（指针或引用类型的名字）。如果一个STL容器使用用户提供的`allocator`来分配它所需的所有内存(预定义的STL容器全都能这么做；他们都有一个模板参数，其默认值是`std::allocator`)，你就能通过提供自己的`allocator`来控制它的内存管理。

这种柔性是有限制的：仍然由容器自己决定它将要申请多少内存以及如何使用它们。在容器申请更多的内存时，你能控制它调用那个低层函数，但是你不能通过使用`allocator`来让一个`vector`行动起来像一个`deque`一样。虽然如此，有时候，这个受限的柔性也很有用。比如，假设你有一个特殊的`fast_allocator`，能快速分配和释放内存（也许通过放弃线程安全性，或使用一个小的局部堆），你能通过写下`std::list<T, fast_allocator<T> >`而不是简单的`std::list<T>`来让标准的list使用它。

如果这看起来对你很陌生，那就对了。没有理由在常规代码中使用allocator的。


`allocator`类是C++的一个模板，它提供类型化的内存分配以及对象的分配和撤销。 

`allocator`类将对象分配和对象构造分开。当`allocator`对象分配内存的时候，它会分配适当大小并排列成保存给定类型对象的空间。 

`allocator`提供如下几种操作： 

```cpp
allocator<T> a; //定义名为a的allocator对象，可以分配内存或构造T类型的对象。 
a.allocate(n); //分配原始的构造内存以保存T类型的n个对象. 
a.deallocate( p, n ) //释放内存，在名为p的T*指针中包含的地址处保存T类型的n个对象。 
a.construt( p, t ) //在T*指针p所指向的内存中构造一个新元素。运行T类型的复制构造函数用t初始化该对象 
a.destroy(p)// 运行T*指针p所指向的对象的析构函数。
```