[toc]

# Java 学习笔记

## Java 程序基本结构

类名要求：

- 类名必须以英文字母开头，后接字母，数字和下划线的组合
- 习惯以大写字母开头

## 变量和数据类型

基本数据类型

- 整数类型： byte（1字节）、short（2字节）、int（4字节）、long（8字节）
- 浮点数类型： float（4字节）、double（8字节）
- 字符类型： char（2字节）
- 布尔类型：boolean（JVM内部会把`boolean` 表示为4字节整数）

```java
long l=90000000000000000000000L;	//long型的结尾需要加L
```

- 引用类型（类似C/C++ 中的指针）（字符串类型`String`就是引用类型）

- 常量（在变量声明前加上`final` 修饰符）

    ```java
    final double PI=3.14;
    final double r=5.0;
    ```

`var`关键字：类似与C++中的`auto` ,编译器自动推断变量的类型

## 浮点运算

溢出：整数运算在除数为`0`时会报错，而浮点数运算在除数为`0`时，不会报错，但会返回几个特殊值 

+ `NaN`表示Not a Number
+ `Infinity`表示无穷大
+ `-Infinity`表示负无穷大

## 输入与输出

输出：

- ```java
    System.out.print();		//直接输出不换行
    ```

- ```java
    System.out.println();	//输出并换行
    ```

- ```java
    System.out.printf();	//格式化输出
    ```

输入：

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // 创建Scanner对象
        System.out.print("Input your name: "); // 打印提示
        String name = scanner.nextLine(); // 读取一行输入并获取字符串
        System.out.print("Input your age: "); // 打印提示
        int age = scanner.nextInt(); // 读取一行输入并获取整数
        System.out.printf("Hi, %s, you are %d\n", name, age); // 格式化输出
    }
}

```

## 面向对象基础

### 构造方法

### 方法重载（Overload）

### 继承

Java 中使用 `extends` 关键字来实现继承

```java
class Person {
    private String name;
    private int age;
    
    public String getName {...}
    public void setName {...}
    public int getAge {...}
    public void setAge {...}
}

class Student extends Person {
    //不需要重复定义name和age字段/方法
    //只需要定义新增的score字段/方法
    private score;
    
    public int getScore {...}
    public void setScore {...}
}
```

**注意：子类自动获得了父类的所有字段，严禁定义与父类重名的字段！**

一个类有且只有一个父类，只有`Object`类特殊，它没有父类

子类无法访问父类的`private`字段或者`private`方法，但可以访问`protected`字段或方法

#### `super`关键字

`super`关键字表示父类。子类引用父类的字段时，可以用`super.filedname`（也可以不用）

但是，在子类的构造方法中，如果父类没有默认的构造方法，子类就必须显示调用`super()`并给出参数。

子类**不会继承**任何父类的构造方法

### 阻止继承（从Java15开始）

正常情况下，只要某个class没有`final`修饰符，那么任何类都可以从改class继承。从Java15开始，允许使用`sealed`修饰class，并通过`permits`明确写出能够从该class继承的子类名称。

```java
public sealed class Shape permits Rect, Circle, Triangle {
    ...
}
```

### 向上转型

把子类型安全的变为父类类型的赋值，被称为向上转型（upcasting）。向上转型实际上是把一个子类型安全的变为更加抽象的父类型。

### 向下转型

与向上转型相反，如果把一个父类类型强制转型为子类类型，就是向下转型（downcasting)。例如:

```java
Person p1 = new Student();	//upcasting
Person p2 = new Person();
Student s1 = (Student)p1; //ok
Student s2 = (Student)p2;	//runtime error ! ClassCastException
```

**不能把父类变成子类，因为子类功能比父类多，多的功能无法凭空变出来。**

向下转型失败时，Java虚拟机会报`ClassCastExpertion`

为避免向下转型出错，Java提供了`instanceof`操作符，可以先判断一个实例是不是某种类型。

对于`instanceof`运算符，如果变量所指向的实例是指定类型或者是这个类型的子类，则判断为true。否则为false。

如果变量为`null`,那么对任何`instanceof`的判断都是false

```java
Person p = new Person();
System.out.println(p instaceof Person);	//true
System.out.println(p instaceof Student); //false

Student s = new Student();
Syetem.out.println(s instanceof Perons);	//true;
System.out.println(s instanceof Student);	//true;

Student s1 = null;
System,out,println(s1 instanof Student);	//false;
```

### 多态

在继承关系中，子类如果定义了一个与父类方法签名完全相同的方法，被称为**覆写（Override）**

在覆写的方法前加上`@override`可以让编译器帮助检查是否进行了正确的覆写。希望进行覆写，但是不小心写错了方法签名，编译器会报错。（`@override`不是必须的）

**Java的实例方法调用时基于运行时的实际类型的动态调用，而非变量的声明类型。**这个非常重要的特性在面向对象编程中被称为**多态（Polymorphic）**

多态是指，**针对某个类型的方法调用，其真正执行的方法取决于运行时实际类型的方法**。

---

#### Object方法

所有的class最终都继承自`Object`,而`Object`定义了几个重要的方法：

- `toString()`:把instance输出为`String`
- `equals()`:判断两个instance是否逻辑相等；
- `hashCode()`：计算一个instance的哈希值

---

在子类的覆写方法中，如果要调用父类的被覆写的方法，可以通过`super`来调用，例如：

```java
class Person {
    protected String name;
    public String hello() {
        return "Hello, " + name;
    }
}

Student extends Person{
	@override
    public String hello() {
		//调用父类的hello()方法
        return super.hello() + "!";
    }
}
```

---

#### final

继承可以允许子类覆写父类的方法。如果一个父类不允许子类对他的某个方法进行覆写，可以把该方法标记为`final`。用`final`修饰的方法不能被`Override`:

```java
class Person {
    protected String name;
    public final String hello() {
        return "Hello, " + name;
    }
}

Student extends Person{
	// compile error :不允许覆写
    @override
    public String hello() {
    }
}
```

如果一个类不希望任何其他类继承自他，那么可以把这各类本身标记为`final`。用`final`修饰的类不能被继承。

```java
final class Person{
    protected String name;
}

//compile error: 不允许继承
class Student extends Person {
}
```

可以在构造方法中初始化final字段，这样可以保证实例一旦被创建，其`final`字段就不可修改。

```java
class Person {
    public final String name;
    public Person(name) {
        this.name = name;
    }
}
```

---

### 抽象类

如果父类的方法泵神不需要实现任何功能，仅仅是为了定义方法签名，目的是让子类去覆写他，那么，可以把父类的方法声明为抽象方法。

```java
abstract class Person {
    public abstract void run();
}
```

把一个方法声明为`abstract`，表示他是一个抽象方法，本身没有实现任何方法语句。因为这个抽象方法本身时无法执行的，所以Person类也无法被实例化。

一个非抽象类中不能含有抽象方法，只有抽象类中才能有抽象方法。

**使用`abstract`修饰的类就是抽象类**，我们无法实例化一个抽象类。

因为抽象类本身被设计成只能用于被继承，因此，**抽象类强迫子类实现其定义的抽象方法**，否则编译会报错。**抽象方法实际上相当于定义了"规范"**

例如：`Person`类定义了抽象方法`run()`，那么在实现子类`Student`的时候就必须覆写`run（）`方法。

#### 面向抽象编程

面向抽象编程的本质就是：

- 上层的代码只定义规范
- 不需要子类就可以实现业务逻辑（正常编译）
- 具体的业务逻辑有不同的子类实现，调用者并不关心

---

### 接口

在抽象类中，抽象方法本质上时定义接口规范：即规定高层类的接口，从而保证所有子类都有相同的接口实现。

如果一个抽象类没有字段，所有方法都是抽象方法，例如：

```java
abstract class Person {
    public abstract void run();
    public abstract String getName();
}
```

就可以把改抽象类改写为接口：`interface`。

在Java中，使用`interface`可以声明一个接口

```java
interface Person {
    void run();
    String getName();                   
}
```

`interface`中没有字段，只有方法。并且接口定义的所有方法默认都是`public abstract`的，所以这两个修饰符不需要写出来。

当一个具体的类去实现一个`interface`时，需要使用`implements`关键字

```java

interface Person {
    void run();
    String getName();
}

class Student implements Person {
    private String name;
    
    public Student(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println(this.name + "run");
    }

    @Override
    public String getName() {
        return this.name;
    }
}
```

default方法：

在接口中可以定义`default`方法，`default`方法的目的是，当我们需要给接口新增一个方法时，会涉及到修改全部子类。如果新增的是`default`方法，那么子类就不必全部修改，只需要在需要覆写的地方去覆写新增方法。

```java
package com.company;

public class Main {
    public static void main(String[] args) {
        Person p = new Student("Xiao ming");
        p.run();
    }
}

interface Person {
    String getName();
    //default 方法
    default void run() {
        System.out.println(getName() + "run");
    }
    //
}

class Student implements Person {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}
```

`default`方法无法访问字段，而抽象类的普通方法可以访问实例字段。

---



**一个类可以实现多个`interface`**

```java
class Student implements Person, Hello {
	...
}
```

---

#### 抽象类与接口的区别

|            | abstract class        | interface                   |
| ---------- | --------------------- | --------------------------- |
| 继承       | 只能extends 一个class | 可以implements多个interface |
| 字段       | 可以定义实例字段      | 不能定义实例字段            |
| 抽象方法   | 可以定义抽象方法      | 可以定义抽象方法            |
| 非抽象方法 | 可以定义非抽象方法    | 可以定义default方法         |



---

#### 接口继承

一个`interface`可以继承字另一个`interface`。`interface`继承自`interface`使用`extends`,它相当于扩展了接口的方法。

```java
interface Hello {
    void hello();
}

interface Person extends Hello {
    void run();
    String getName();
}
```

---

### 静态字段和静态方法

用`static`修饰的字段，称为静态字段：`static field`（相当于C/C++中的静态变量）

实例字段在每个实例中都有自己的一个独立“空间”，但是静态字段只有一个共享“空间”，所有实例都会共享该字段。

**推荐用类名来访问静态字段**，可以把静态字段理解为描述`class`本身的字段（非实例字段）

```java
//number 是Person类的静态字段
Person.number = 99;
System.out.println(Person.number);
```

#### 静态方法

用`static`修饰的方法称为静态方法。调用实例方法必须通过一个实例变量，二调用静态方法则不需要实例变量，通过类名就可以调用。静态方法类似其他编程语言的函数。

```java
public class Main() {
    public static void main(String[] args) {
        Person.setNumber(99);
        System.out.println(Person.number);
    }
}

class Person {
    public static int number;
    
    public static void setNumber(int value) {
        number = value;
    }
}
```

因为静态方法属于`class`而不属于实例，因此，静态方法内部，**无法访问this变量，也无法访问实例字段，他只能访问静态字段**。

静态方法经常用于工具类，如：

- Arrays.sort()
- Math.random()

#### 接口的静态字段

`interface`不能定义实例字段，但可以定义静态字段，并且静态字段必须为`final`类型。

### 包

Java定义了一种名字空间，称之为包：`package`。一个类总是属于某个包，类名只是一个简写，真正的完整类名是`包名.类名`。

JVM只看完整类名，因此，只要包名不同，类就不同。

包可以时多层结构，用`.`隔开。例如:`java.util`

#### 包作用域

位于同一个包的类，可以访问包作用域的字段和方法，不用`public` `protected` `private` 修饰的**字段**和**方法**就是包作用域

#### import

如果有两个`class`名称相同，例如，`mr.jun.Arrays`和`java.util.Arrays`，那么只能`import`其中一个，**另一个必须写完整类名**

### 作用域

#### public

定义为`public`的`class`、`interface`可以不其他任何类访问。

定义为`public`的`field`、`method`可以被其他类访问，前提是首先有访问`class`的权限；

#### private

定义为private的`field`和`method`无法被其他类访问。`private`访问权限被限定在`class`内部，而且与方法声明顺序无关。推荐把`private`方法放到后面。

定义在一个`class`内部的`class`称为嵌套类（`nested class`）

Java支持嵌套类，如果一个类内部还定义了嵌套类，那么，**嵌套类有访问`private`的权限。**

#### protected

`protected`作用于继承关系。定义`protected`的字段和方法可以被子类访问，以及子类的子类。

#### package

包作用域是指一个类允许访问同一个package的没有`public`、`private`修饰的`class`，以及没有`public`、`protected`、`private`修饰的字段和方法。

包没有**父子关系**

#### 局部变量

#### final

作用

- 用`final`修饰`class`可以阻止被继承
- 用`final`修饰`method`可以阻止被子类覆写
- 用`final`修饰`field`可以阻止被重新赋值
- 用`final`修饰局部变量可以阻止被重新赋值

#### 最佳实践

- 如果不确定是否需要`public`，就不声明为`public`,尽可能减少对外暴露的字段和方法
- 把方法定义为`package`权限有助于测试，因为测试类和被测试类只要位于同一个`package`，测试代码就可以访问被测试类的`package`权限方法
- 一个`.java`文件只能包含一个`public`类，但可以包含多个非`public`类。如果有`public`类，文件名必须和`public`类的名字相同。

### 内部类

有一种类，他被定义在另一个类的内部，被称为内部类（Inner Class）

```java
class Outer {
 	class Inner {
        //定义了一个 Inner Class
    }   
}
```

使用方法如下：

```java
public class Main {
    public static void main(String[] args) {
        Outer outer = new Outer("Nested");
        Outer.Inner inner = outer.new Inner();
        inner.hello();
    }
}

class Outer {
    private String name;

    Outer(String name) {
        this.name = name;
    }

    class Inner {
        void hello() {
            System.out.println("Hello" + Outer.this.name);
        }
    }
}
```

**要实例化一个`Inner`，我们必须首先创建一个`Outer`实例，然后，调用`Outer`实例的`new`来创建`Inner`实例**

**`Inner Class`可以修改`Outer Class`的`private`字段**

#### 匿名类（Anonymous Class）

匿名类也可以访问`Outer Class`的`private`字段和方法。

之所以要定义匿名类，是因为在这里我们通常不关心类名，比直接定义`Inner Class`可以少写很多代码

#### 静态内部类（Static Nested Class）

静态内部类与`Inner Class`类似，但是使用`static`修饰。

他是一个完全独立的类，因此无法引用`Outer.this`，但他可以访问`Outer`的`private`静态字段和静态方法

### classpath 和 jar

`classpath`是JVM用到的一个环境变量，它用来指示JVM如何搜索`class`

`classpath`是一组目录的集合，它设置的搜索路径与操作系统相关

- Windows上，用`;`分隔，带空格的目录用`""`括起来，如下：

    ```
    C:\work\project\bin;C:\shared;"D:\My Documents\project\bin"
    ```

- 在Linux系统上，用`:`分隔，如下：

    ```
    /usr/shared:/usr/local/bin:/home/zhaosiqi/bin
    ```

#### jar包

jar包实际上就是一个zip格式的压缩文件，而jar包相当于目录

### 模块

---

## Java核心类

### 字符串和编码

#### String

比较字符串是否相等要使用`equals()`方法，而不能用`==`

要忽略大小写比较，要使用`equalsIgnoreCase()`方法

