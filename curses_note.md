## 函数

- `initscr()` ：确定终端类型，做初始化工作

- `cbreak()`：禁用缓冲并使键入的输入立即可用

- `nocbreak()`：关闭

- `raw()`：关闭特殊字符处理

- `noraw()`：

- `noecho()`：关闭回显，因此用户输入不会显示在屏幕上

- `curs_set()`：设置光标的外观

    - 0 为不可见
    - 1 为 正常光标
    - 2为高可见模式（终端不一定支持）

- `nodelay()`：通过设置`bf`，指定窗口为延迟模式还是非延迟模式

    ```c
    int nodelay(WINDOW *win, bool bf);
    //调用
    nodelay(stdscr, TRUE);
    ```

- `move()`：移动光标

    ```c
    move(10, 30);	//移动到第10行第30列
    ```

- `addstr(s)`：在当前光标位置输出一个字符串

- `addch(c)`：类似`addstr()`输出一个字符

- `erase()`：在屏幕的每个位置写空白字符

- `clear()`：调用内置终端命令清空屏幕，它比erase()更快。

- `printw(fmt...)`：类似`printf()`的格式化输出

- `mvaddch(row, col, ch)`：移动到指定位置输出字符

- `mvaddstr(row, col, str)`：与`mvaddch`类似

- `refersh()`使输出的字符对用户可见

- `int box(WINDOW *win_ptr, chtype vertical, chtype horizontal)`

    围绕窗口绘制方框

- `border()`：box的升级版，需要提供8个参数，分别表示上下左右和4个拐角的字符

- `insch(c)`：插入一个字符， 已有字符后移

- `insertln（）`：插入空白行

- `delch()`：删除字符

- `deleteln()`删除空白行

- `clrtoeol()`：从当前删除到行尾

- `clrtobot()`：删除当前位置的右下部分

- `beep()`：终端响铃

- `flash()`：闪烁

- 键盘输入（与stdio中的函数类似）

    - `getch()`
    - `getstr(char *s)`
    - `getnstr(char *s, int number)` ：建议使用
    - `scanw(fmt...)`：与`scanf()`类似
    - `timeout(delay)`：
        - `delay < 0`时，无限延迟等待输入
        - `delay == 0`时，不等待输入
        - `delay > 0`时，在`0 ~ delay`毫秒内等待输入，超过就不等待
    - `notimeout()`

- 窗口（`curses`支持在一个物理屏幕上显示多个窗口）

    - `WINDOW *newwin(int lines, int cols, int start_y, int start_c)`：创建从（start_x, start_y）开始的大小为lines * cols的窗口，若所有参数为0，则大小同当前窗口
    - `delwin(WINDOW *win)`：销毁创建的窗口，千万不要删除`stdscr`和`curscr`
    - `mvwin(win, y, x)`：移动窗口
    - `wrefresh(win)`
    - `wclear(win)`
    - `werase(win)`
    - `touchwin(win)`：指定该窗口已改变，使得在下次调用`refresh()`时，也刷新该窗口
    - `scrollok(win, bool flag)`：指定是否允许窗口卷屏
    - `scroll(win)`：把窗口内容上卷一行
    - `wbkgd(win, c)`：设置窗口背景均为字符`c`
        - `wnoutrefresh()`：确定终端的哪些部分可能需要更新
        - `doupdate()`：向终端发生命令以执行任何需要的改变，两者通常同时使用。

- 子窗口

    - `WINDOW *subwin(WINDOW *parent, int lines, int cols, int start_y, int start_x)` ：创建子窗口
    - `delwin(win)`：销毁子窗口

- keypad模式

    - `keypad(WINDOW *win, bool keypad_on)`：keypad_on为TRUE时，启用，此时读键盘操作能够得到方向键、小键盘、Insert、Home

- 彩色显示

    - `has_colors`：检查是否支持彩色显示
    - `start_colors`：启用彩色模式，初始化一些数据结构
    - `init_color(num, r, g, b)`：定义支持RGB格式的颜色，该颜色用数字num表示，r、g、b的取值范围为(0 ~ 1000)表示相应的颜色强度，num的取值范围是(0-255)
    - `int init_pair(shor pair_number, short foreground, short background)`    ：初始化pair_number号颜色组合
    - `int COLOR_PAIR(int pair_number)`：  对pair_number号颜色组合作为属性来访问（用于前面的attr函数）
    - `int pair_content(short pair_number, short *foreground, short *background)`    ：获取已定义的颜色组合信息

- 字符属性（指对字符设置加粗，反色显示等）

    预定义的属性（`A_BLINK, A_BOLD, A_DIM, A_REVERSE, A_STANDOUT,A_UNDERLINE`）

    - `attron(attr)`：启用属性
    - `attroff(attr)`：关闭属性
    - `attrset(attr)`
    - `standout()`
    - `standend()`：这两个表示更加通用的强调模式，通常映射为反白显示

## 全局变量

- `LINES`：当前屏幕的函数
- `COLS`：当前屏幕的列数

## 功能键

使用`getch()`来获取数据，并将这些数据保存在`int`变量中而不是保存在`char`变量中，这是因为功能键的值超过最大的`char`值，不必需要知道功能键的具体数值，他们被定位为宏，在[这个页面](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html)查看。

- `keypad(win, TRUE)`：允许使用功能键