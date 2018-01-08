# some class api
## vector
### construction method
- public Vecctor()
empty vector
- public Vector(int initialCapacity)
- public Vector(int initialCapacity, int capacityIncrement)
### the operation of the object
#### member variable
- protected int capacity Increment
- protected int elementCount
- protected Object elementData[] 
element save buffer
#### add element
- addElement(Object obj)
add the last of vector
- insertElementAt(Object obj, int index)
obj insert at index, original index >= the index will +1
#### delete element
- setElementAt(object obj, int index)
at the index object will be override,
- removeElement(Object obj)
第一个遇到的 object 会被删除, 后面的都不上来
- removeElementAt(int index)
- removeAllElements()
#### search
- Object elementAt(int index)
- boolean contains(Object obj)
- int indexof(object obj,int start_index)
begin at start_index return the index of first obj
- int lastIndexOf(Object obj, int start_index)
从后往前搜索,从 start_index 开始
#### other method
- int size()
- int capacity() 
- firstElement()
- lastElement()
- steSize()
- trimToSize()
将 Vector 的容量下调到最小