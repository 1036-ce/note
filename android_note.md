[toc]

#### 设置字体颜色

```kotlin
btn.setTextColor(Color.RED)		//设置按钮字体颜色为红色
```

#### 设置按钮是否可用

```kotlin
btn.isEnabled = true 
```

####  设置icon总是显示

```kotlin
//要写在MainActivity内部 
override fun onOptionsItemSelected(item: MenuItem): Boolean {
        super.onOptionsItemSelected(item)
        when(item.itemId){
            R.id.mnuAbout->tvInfo.text="About"
            R.id.mnuEdit->tvInfo.text="Edit"
            R.id.mnuExit->finish()
            R.id.mnuNew->tvInfo.text="New"
            R.id.mnuOpen->tvInfo.text="Open"
            R.id.mnuSave->tvInfo.text="Save"
        }
        return true
    }
```

#### 给按钮加上图标

```kotlin
使用按钮的 drawableTop 属性
```



#### 上下文菜单的创建

```kotlin

class MainActivity : AppCompatActivity() {

    lateinit var tvInfo:TextView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        tvInfo = findViewById(R.id.textView)
        registerForContextMenu(tvInfo)
    }

    override fun onCreate(savedInstanceState: Bundle?, persistentState: PersistableBundle?) {
        super.onCreate(savedInstanceState, persistentState)
        setContentView(R.layout.activity_main)
        registerForContextMenu(tvInfo)
    }

    override fun onCreateContextMenu(
        menu: ContextMenu?,
        v: View?,
        menuInfo: ContextMenu.ContextMenuInfo?
    ) {
        super.onCreateContextMenu(menu, v, menuInfo)
        menuInflater.inflate(R.menu.context_menu,menu)
    }

    override fun onContextItemSelected(item: MenuItem): Boolean {
        val info = when(item.itemId) {
            R.id.A -> "A"
            R.id.B -> "B"
            R.id.C -> "C"
            else -> "D"
        }
        tvInfo.text = info
        return true
    }
}

```

####  盒子模型

- view 支持padding，但是不支持margin
- ViewGroup支持padding和margin

#### dp与sp

布局通常使用`dp`，字体通常使用`sp`

#### 按名字引用颜色

在代码中使用xml颜色常量

```k
getResources().getcolor(R.color.`颜色常量名`)
```

#### 控件组的显示与隐藏

设置组的`visisility`属性，就能承租的显示和隐藏相应的控件

- View.GONE：表示让这组控件从屏上“消失”，不再占用屏幕上的任何位
    置，它的“空间”被释放了，其他控件可以抢占它的“地盘”。
- View.INVISIBLE：表示让这组件控件“隐身”（或者说是“透明”），表示让这组件控件“隐身”（或者说是“透明”），
    它只是“看不见”而己，它的地盘还“留着”，其它控件不能用。
- 它只是“看不见”而己，它的地盘还“留着”，其它控件不能用。

```kotlin
 		btn.setOnClickListener {
            if (grp.visibility == View.VISIBLE) {
                (it as Button).text = "显示成组控件"
                grp.visibility = View.GONE
            } else {
                grp.visibility = View.VISIBLE
                (it as Button).text = "隐藏成组控件"
            }
        }
```

#### 主动销毁Activity

调用Activity的`finish()`方法，这只会销毁当前的`Activity`，使用`exitProcess(0)`销毁所有`Activity`

#### 固定手机屏幕为竖屏

在AndroidManifest文件中，`activity`标签下加入如下

```xml
android:screenOrientatio="portrait" //固定竖屏
android:screenOrientatio="landscape" //固定横屏
```
