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

- `clear()`：清除整个屏幕，在下次调用`refresh`时可以重现原文

- `printw(fmt...)`：类似`printf()`的格式化输出

- `mvaddch(row, col, ch)`：移动到指定位置输出字符

- `mvaddstr(row, col, str)`：与`mvaddch`类似

- `refersh()`使输出的字符对用户可见

- `int box(WINDOW *win_ptr, chtype vertical, chtype horizontal)`

    围绕窗口绘制方框

- `insch(c)`：插入一个字符， 已有字符后移

- `insertln（）`：插入空白行

- `delch()`：删除字符

- `deleteln()`删除空白行

- `beep()`：终端响铃

- `flash()`：闪烁

- 键盘输入（与stdio中的函数类似）

    - `getch()`
    - `getstr(char *s)`
    - `getnstr(char *s, int number)` ：建议使用
    - `scanw(fmt...)`：与`scanf()`类似

- 窗口（`curses`支持在一个物理屏幕上显示多个窗口）

    - `WINDOW *newwin(int lines, int cols, int start_y, int start_c)`：创建从（start_x, start_y）开始的大小为lines * cols的窗口
    - `delwin(WINDOW *win)`：销毁创建的窗口，千万不要删除`stdscr`和`curscr`
    - `mvwin(win, y, x)`：移动窗口
    - `wrefresh(win)`
    - `wclear(win)`
    - `werase(win)`
    - `touchwin(win)`：指定该窗口已改变
    - `scrollok(win, bool flag)`：指定是否允许窗口卷屏
    - `scroll(win)`：把窗口内容上卷一行

- 子窗口

    - `WINDOW *subwin(WINDOW *parent, int lines, int cols, int start_y, int start_x)` ：创建子窗口
    - `delwin(win)`：销毁子窗口

- keypad模式

    - `keypad(WINDOW *win, bool keypad_on)`：keypad_on为TRUE时，启用，此时读键盘操作能够得到方向键、小键盘、Insert、Home

- 彩色显示

    - `has_colors`：检查是否支持彩色显示
    - `start_colors`：启用彩色模式
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