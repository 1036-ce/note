[toc]

## awk 内置变量

- NF ： 表示当前行的字段数，因此`$NF`就表示最后一个字段，`$(NF - 1)`代表倒数第二个字段
- NR：表示当前处理的是第几行
- FILENAME：当前文件名
- FS：字段分隔符，默认是空格和制表符
- RS：行分隔符，用于分隔每一行，默认是换行符
- OFS：输出字段的分隔符，用于打印时分隔字段，默认为空格
- ORS：输出记录的分隔符，用于打印时分隔记录，默认为换行符
- OFMT：数字输出的格式，默认为`%.6g`

## awk内置函数

- toupper()
- tolower()
- length()
- substr()
- sin()：正弦函数
- cos()
- sqrt()
- rand()：随机数

## awk条件

```awk
awk '条件 动作' 文件名
```

条件可以是正则表达式，也可以是其他

## awk  if语句

```awk
awk -F ':' '{if ($1 > "m") print $1; else print "---"}' demo.txt
```

