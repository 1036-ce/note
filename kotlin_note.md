[toc]

# Kotlin 基础语法

## 可变长参数函数

函数的编程参数可以用`vararg`关键字进行标识

## 函数定义

```kotlin
fun sum(a: Int, b: Int): Int {	//Int参数， 返回值Int
    return a + b;
}
```

`Unit`相当于`void`

## lambda 

```kotlin
fun main(args: Array<String>) {
    val sumLambda: (Int,Int) -> Int = {x,y -> x+y}
    println(sumLambda(1,2))
}
```

## 定义常量与变量

### 定义变量

`var`

### 定义常量

`val`

## NULL检查机制

字段后加`!!`抛出异常，字段后加`?`表示可为空，或者配合`?:`做空判断处理

```kotlin
//类型后面加?表示可为空
var age: String? = "23" 
//抛出空指针异常
val ages = age!!.toInt()
//不做处理返回 null
val ages1 = age?.toInt()
//age为空返回-1
val ages2 = age?.toInt() ?: -1
```

## 类型检测及自动类型转换

使用`is`（`!is`）运算符检测一个表达式是否是某类型的一个实例

```kotlin
if (obj is String)
	// do something
```

#### 区间

```kotlin
for (i in 1..4) print(i) // 输出“1234”

for (i in 4..1) print(i) // 什么都不输出

if (i in 1..10) { // 等同于 1 <= i && i <= 10
    println(i)
}

// 使用 step 指定步长
for (i in 1..4 step 2) print(i) // 输出“13”

for (i in 4 downTo 1 step 2) print(i) // 输出“42”


// 使用 until 函数排除结束元素
for (i in 1 until 10) {   // i in [1, 10) 排除了 10
     println(i)
}
```



# kotlin 基本数据类型

## 数组

数组的两种创建方式：

- 使用`arrayof`
- 使用工厂函数

```kotlin
fun main(args: Array<String>) {
    //[1,2,3]
    val a = arrayOf(1, 2, 3)
    //[0,2,4]
    val b = Array(3, { i -> (i * 2) })

    //读取数组内容
    println(a[0])    // 输出结果：1
    println(b[1])    // 输出结果：2
}
```

# kotlin 条件控制

可以把IF表达式的结果赋值给一个变量

```kotlin
val max = if (a > b) {
    print("Choose a")
    a
} else {
    print("Choose b")
    b
}

val a = 12
val b = 23
val c = if (a > b) a else b
    
```

## when 表达式

when类似其他语言的switch操作符，else相当于default，可以把多个分支条件放在一起，用逗号分隔。

```kotlin
when (x) {
    1 -> print("x == 1")
    2 -> print("x == 2")
    else -> { // 注意这个块
        print("x 不是 1 ，也不是 2")
    }
}
```

when可以不带参数

```kotlin
when {
    x.isOdd() -> print("x is odd")
    x.isEven() -> print("x is even")
    else -> print("x is funny")
}
```

# Kotlin 循环控制

## Break和Continue 标签

```kotlin
loop@ for (i in 1..100) {
    for (j in 1..100) {
        if (...) break@loop
    }
}
```

## 隐式标签

使用隐式标签从lambda表达式中返回,该标签与接受该lambda的函数同名

```kotlin
fun foo() {
    ints.forEach {
        if (it == 0) return@forEach
        print(it)
    }
}
```

# 类

## getter 和 setter

`getter`和`setter`都是可选的，使用变量时调用`getter`，为变量赋值时调用`setter`，`getter`和`setter`都可以自己定义

```kotlin
class Person {
    var lastName: String = "zhao"
        get() = field.uppercase()	//set为默认

    var no: Int = 100
    	//get为默认
        set(value) {
            field = if(value < 10) value else -1
        }
    var height: Float = 145.4f
        private set					//不允许赋值
    								//get为默认
}
```

`lateinit`提供延迟初始化

```kotlin
class Runoob constructor(name: String) {	//主构造器
    var url: String = "http://www.runoob.com"
    var country: String = "CN"
    var siteName = name

    init {	//初始化代码，在类对象被创建时执行
        println("初始化网站名：${name}")
    }

    fun printTest() {
        println("我是类的函数")
    }
}

fun main(args: Array<String>) {
    val runoob = Runoob("菜鸟教程")
    println(runoob.siteName)
    println(runoob.url)
    println(runoob.country)
    runoob.printTest()
}
```

## 次构造函数

```kotlin
class Person { 
    constructor(parent: Person) {
        parent.children.add(this) 
    }
}
```

如果类有主构造函数，每个次构造函数都要，或直接或间接通过另一个次构造函数代理主构造函数。在同一个类中代理另一个构造函数使用 this 关键字。
