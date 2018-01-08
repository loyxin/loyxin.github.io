用javac编译了一个M.java文件， 然后用java M执行，可是出现了下面这个错误
```java
Exception in thread "main" java.lang.UnsupportedClassVersionError: M : Unsupported major.minor version 51.0
　　　　at java.lang.ClassLoader.defineClass1(Native Method)
　　　　at java.lang.ClassLoader.defineClass(ClassLoader.java:643)
　　　　at java.security.SecureClassLoader.defineClass(SecureClassLoader.java:142)
　　　　at java.net.URLClassLoader.defineClass(URLClassLoader.java:277)
　　　　at java.net.URLClassLoader.access$000(URLClassLoader.java:73)
　　　　at java.net.URLClassLoader$1.run(URLClassLoader.java:212)
　　　　at java.security.AccessController.doPrivileged(Native Method)
　　　　at java.net.URLClassLoader.findClass(URLClassLoader.java:205)
　　　　at java.lang.ClassLoader.loadClass(ClassLoader.java:323)
　　　　at sun.misc.Launcher$AppClassLoader.loadClass(Launcher.java:294)
　　　　at java.lang.ClassLoader.loadClass(ClassLoader.java:268)
　　　　Could not find the main class: M. Program will exit.
```
`javac` 和` java`版本不一致的问题，在`Linux`下， 执行 `java -version` 和 `javac -version`可以查看它们的版本信息。

通过比较，找出是`java`还是`javac`的版本不一致， 然后在命令行下执行 `sudo update-alternatives --config java/javac`,  选择列表中相对应的版本进行手动更新。


有时java源程序中package设置不当也会导致上述错误。
1. 在java源文件开头没有包声明语句 package your_package; 
D:\jtest> javac J_Hello.java
```

D:\jtest> java J_Hello
Hello, the Java world!
```
2. 在java源文件开头有包声明语句 package your_package; 
```
D:\jtest>javac J_Hello1.java

D:\jtest>java J_Hello1
Error: Could not find or load main class J_Hello1
```
错误原因：
编译含有包声明语句的java源程序文件的格式是：
    javac -d your_path your_class.java
此命令能在 your_path/your_package/ 下生成 your_class.class。

上面的命令中没有-d选项，javac会在当前目录下生成J_Hello1.class（没有报错）。
但是执行java命令，会因为找不到class而出错。

解决方法：
- 在当前目录下手工创建com/mypkg/test目录，将移动J_Hello1.class到该目录下。
- 用 javac -d . J_Hello1.java 编译，将直接生成./com/mypkg/test/J_Hello1.class。 
```
D:\jtest>javac -d . J_Hello1.java

D:\jtest>Java com.mypkg.test.J_Hello1

Hello, the java world!
```