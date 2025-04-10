<div align="center"> 
    <h1 style="front-size: 50px;color: #34495e;">Shell</h1>
</div>

---

## 介绍

Shell 是操作系统的外壳程序，它负责用户与操作系统之间的交互。它可以让用户输入命令，并执行相应的操作。

Shell 通常分为两大类：

1. 交互式 Shell：用户通过键盘输入命令，Shell 立即执行并返回结果。
2. 批处理 Shell：用户通过脚本文件输入命令，Shell 一次性执行所有命令，并返回结果。

常见的 Shell 包括：

1. Bourne Shell（/bin/sh）：最初的 Unix Shell，现在大部分系统都使用它。
2. C Shell（/bin/csh）：C 语言编写的 Shell。
3. Korn Shell（/bin/ksh）：贝尔实验室开发的 Shell。
4. Bash（/bin/bash）：GNU 项目开发的 Shell，是 Linux 和 macOS 系统默认的 Shell。

---

# 第一讲 Shell 基础

## 一·常用命令

### 目录切换

- `cd`：切换当前目录。
- `cd..`：切换到上级目录。
- `cd ~`：切换到用户主目录。
- `cd -`：切换到上次所在目录。
- `$env:Path | $env:path -split ';'`：查看环境变量 Path。
- `which echo`：类unix 第一个路径
- `where echo`:windows  所有的‘文件’位置 
- ` pwd`: 显示当前目录的绝对路径。
- `cd /d/code/`: 切换到指定目录。change directory to D:\code\
- `.`: 当前页面
- `..`: 上一级目录
- `ls`: 显示当前目录下的文件和目录。
- `ls -l`: 显示详细信息。
- `ls -a`: 显示隐藏文件。
- `ls -la`: 显示详细信息和隐藏文件。
- `ls -r`: 逆序显示文件和目录。
- `ls -R`: 递归显示目录下的所有文件和目录。
- `ls -lh`: 以可读方式显示文件大小。
- `ls -lt`: 以时间戳排序显示文件和目录 
- `ls --help`: 查看 ls 命令的帮助。
- `mkdir`: 创建目录。
- `rmdir`: 删除目录。
- `mv`: 移动或重命名文件或目录。两个路径参数
- `cp`: 复制文件或目录。
- `rm`: 删除文件 不会递归删除
- `rm -f`: 强制删除文件
- `rm -i`: 交互式删除文件
- `rm -r`: 递归删除目录。
- `rm -rf`: 强制递归删除目录。
- `ln`: 创建链接。
- `ln -s`: 创建软链接。
- `touch`: 创建空文件。
- `cat`: 显示文件内容。
- `man`: 查看命令的帮助。 man ls
- `which`: 查看命令的位置。
- `clear`: 清屏。
- `|`: 管道命令。
- `>`：重定向输出。
- `>>`：追加重定向输出。
- `<`：重定向输入。
- `|`：管道命令 左边程序的输出作为右边程序的输入。
- `&&`：逻辑与。
- `||`：逻辑或。
- `expr`：表达式求值。
- `test`：文件测试。
- `exit`：退出当前 Shell。
- `logout`：退出当前用户会话。
- `history`：显示历史命令。
- `alias`：设置命令别名。
- `unalias`：删除命令别名。
- `jobs`：显示当前后台任务。
- `fg`：将后台任务提到前台。
- `bg`：将后台任务放到后台。
- `kill`：杀死进程。
- `killall`：杀死所有进程。
- `nohup`：运行命令不挂断。
- `wait`：等待子进程结束。
- `head`: 显示文件开头内容。
- `tail`: 显示文件末尾内容。-n1 --line=1
- `sed`: 文本处理工具。
- `awk`: 文本处理工具。
- `sort`: 排序工具。
- `uniq`: 去重工具。
- `tee`: 写入文件并输出

  
## 二·**函数传参**

- `$#`：传递给脚本或函数的参数个数。
- `$@`：传递给脚本或函数的所有参数。
- `$1`：传递给脚本或函数的第一个参数。
- `$2`：传递给脚本或函数的第二个参数。

#### 传参方式
1. data
- 无参 调用data函数输出日期和时间
2. echo hello world| echo "hello world"
以空格作为分隔

## 三·环境变量（environment variable）
存储可执行文件？(bin)

## shell的意义
- 脚本语言
- 自动化任务
- 交互式环境
  
   ### 交互式环境
  输入流与输出流均指向终端，输入来自键盘，输出至终端，shell可以改变输入输出流的指向，从而实现交互式环境。
    -`< file > file` : 重定向输入输出流，将文件作为输入流，将输出流重定向到文件。
    ```
    echo "hello world" > hello.txt
    cat hello.txt # cat读取文件
    cat < hello.txt #shell标准读入文件传给cat 更适合管道和重定向
    ls -l | tail -n1 # 管道命令
    cat <ls.txt | tail -n1 # 管道命令
    cat <hello.txt > hello2.txt # 重定向
    ```
## ROOT 权限super user
#### 如何使用：
sudo || do as su || #

#### 什么情况下使用
  sys中改写亮度 linux
  ```
  sudo su -c "echo 100 > /sys/class/backlight/intel_backlight/brightness"
  ```
或者
  ```
  echo 100  | sudo tee /sys/class/backlight/intel_backlight/brightness
  ```
 - `sudo su`: 切换到超级用户模式，输入密码后可执行超级用户命令。
 - `sudo su -c "命令"`: 切换到超级用户模式，并执行命令。
 - `sudo su -l`: 切换到超级用户模式，并保持登录状态。


# 第二讲 shell 脚本和工具
  
- `''` 和 `""` 的区别: ''原样输出 ""解析变量
  ```
  echo "in $(pwd)"
- `vim`: 文本编辑器
  ```
  vim mcd.sh
  i 进入插入模式
  :w 保存文件
  :q 退出文件
  :q! 强制退出（不保存）
  :wq 保存并退出
  ```
- `$`: 
    -`$0`: 脚本名称
    - `$1` 到 `$9`: 脚本的参数
    - `$#`: 参数个数
    - `$*`: 所有参数
    - `$@`: 所有参数
    - `$$`: 当前进程的 PID
    - `$?`: 上一个命令的退出状态码
    - `$_`: 上一个命令的最后一个参数
    - `$!`: 上一个后台进程的 PID
    - `$()`: 获取命令的输出 变量名存储 ||字符串中命令替换

- `source` : 文件名 当前shell中执行文件 等同于./
- `$@`: "$@" 把每个参数当作字符串，传递给其他命令 $@空格为分隔符传输
  
- `通配符`: ls *.sh || ls project?
- `{}`: mkdir {a,b}  touch {a,b}/{x,y}.txt  笛卡尔积
- 
- '<(命令)' : 命令替换 将命令的输出作为参数传递给其他命令
  ``` 
  cat <(ls)<((ls ..))
  ```得到当前目录和父目录
- 'shebang': 如python 对于大多数系统: #!/usr/bin/env python3
  ```
    可以： ./aa.py a b c
    否则： python aa.py a b c
  ```
- 使用tldr ：下载node.js  命令行 npm install -g tldr
- grep : 文本搜索工具 grep -R foobar 目录中搜foobar 返回文件名和所在行 
- `find` : 文件搜索工具 
  find . -name "*.sh" 搜索当前目录下所有以 .sh 结尾的文件  
  find . -path '**/test/*.py' - type f 搜索当前目录下所有以.py 结尾的文件
  find. -path '**/test/*.py' -type f -exec python {} \; 搜索当前目录下所有以.py 结尾的文件并执行python
  find . -name "*.tmp" -exec rm {} \; 删除当前目录下所有以.tmp 结尾的文件
  locate: 文件搜索工具 更快 但是需要更新数据库
- 'ripgrep': 文件搜索工具 更快 但是需要安装
  rg "import numpy" -t py -C 5 /d/code
                    type   上下文行数
  rg -u --files-without-match "^#\!!" -t sh
  搜索当前working directory下所有.sh文件，不包含以#!开头的行
  - `history` : 查看历史命令
   history | grep "ls" 搜索历史命令中包含ls的命令
  - `Ctrl R` : 搜索历史命令
  -`fzf`: 交互式搜索工具
  cat example.sh | fzf
  快速目录列表
  - `tree`: 目录树
# Vim

#### 模式选择
- `i`: 插入模式 insert
- `r`: 替换模式 replace
- `v`: 可视模式 visual
- `V`|`shift v`: 可视行模式 visual line
- `ctrl v`: 块选择模式 block select
- `esc`: 退出模式
- `:`: 命令模式 command line
- `w`: 写入文件 write
- `q`: 退出文件 quit
- `q!`: 强制退出文件 quit force
- `wq`: 写入并退出文件 write quit
- `wq!`: 强制写入并退出文件 write quit force
  
#### 移动操作
- `h`: 左移光标 left
- `j`: 下移光标 down
- `k`: 上移光标 up
- `l`: 右移光标 right
- `w`: 右移一个单词 word
- `b`: 左移一个单词 word
- `e`: 右移到单词末尾 word end
- `0`: 左移到行首 line beginning
- `$`: 右移到行尾 line end
- `^`: 左移到行首 line beginning
- `G`: 跳转到文件末尾 go to end of file
- `gg`: 跳转到文件开头 go to beginning of file

#### 编辑操作
- `gg=G`: 格式化文件 format file
- `cc`: 删除当前行并进入插入模式 delete current line and enter insert mode
- `cw`: 删除当前单词并进入插入模式 delete current word and enter insert mode
- `ce`: 删除当前单词末尾并进入插入模式 delete current word end and enter insert mode
-  删除
- `d`: 删除选中内容 delete selected content
- `D`: 删除当前行到行尾 delete to end of line
- `dd`: 删除当前行 delete
- `dw`: 删除当前单词 delete word
- `d$`: 删除当前行到行尾 delete to end of line
- `d0`: 删除当前行到行首 delete to beginning of line
- 复制
- `yy`: 复制当前行 copy
- `粘贴 `:paste
- `u`: 撤销 undo
- `Ctrl r`: 重做 redo


#### 搜索操作
- `n`: 下一个匹配 next
- `N`: 上一个匹配 previous
- `/`: 搜索 search
- `?`: 反向搜索 reverse search
- `*`: 搜索当前单词 search current word
- `#`: 反向搜索当前单词 reverse search current word
- `%`: 匹配括号 match parentheses
  

#### 计数符
- `2dw`: 删除两个单词 delete two words
- `2dd`: 删除两行 delete two lines
- `2j`: 下移两行 down two lines
- `2k`: 上移两行 up two lines
- `3w`: 右移三个单词 right three words
 
#### 窗口管理
- `:sp`     - Split window horizontally（水平分屏）
- `:vsp`    - Split window vertically（垂直分屏）
- `Ctrl + w + w` - Switch between windows（在窗口间切换）
- `Ctrl + w + h/j/k/l` - Move to left/down/up/right window（移动到左/下/上/右窗口）
- `Ctrl + w + q` - Close current window（关闭当前窗口）
- `Ctrl + w + o` - Close all other windows（关闭其他窗口）
- `Ctrl + w + =` - Equalize window sizes（均衡窗口大小）

#### 多文件操作
- `:e filename`  - Open file（打开文件）
- `:bnext (bn)`  - Next buffer（切换到下一个缓冲区）
- `:bprevious (bp)` - Previous buffer（切换到上一个缓冲区）
- `:bd`          - Close current buffer（关闭当前缓冲区）
- `:ls` or `:buffers` - List all buffers（列出所有缓冲区）
- `:tabnew filename` - Open file in new tab（在新标签页打开文件）
- `gt`           - Go to next tab（切换到下一个标签页）
- `gT`           - Go to previous tab（切换到上一个标签页）
- `:tabclose`    - Close current tab（关闭当前标签页）
- `:tabonly`     - Close all other tabs（关闭其他所有标签页）

#### 代码缩进与格式化
- `>>`      - Indent right（右移缩进）
- `<<`      - Indent left（左移缩进）
- `=`       - Auto-align format（自动对齐格式化）

```
# vim 配置：
touch ~/.vimrc
set ai
set number
set showmatch
set showmode
set showcmd
set warn
set ruler
set scrolloff=6
set tabstop=4
set wrap
set shiftwidth=4
set softtabstop=4
set backspace=2
set cursorline
set hlsearch
syntax enable
syntax on
set autoindent
set smartindent
```

#### 搜索与替换
- `:%s/old/new/g`  - Replace all occurrences of "old" with "new"（全局替换 old -> new）
- `:%s/old/new/gc` - Replace with confirmation（替换时逐个确认）

#### 宏录制（Macros）
- `qa`      - Start recording macro in register 'a'（开始录制宏到 `a` 寄存器）
- `q`       - Stop recording（停止录制）
- `@a`      - Run macro stored in register 'a'（运行 `a` 寄存器中的宏）
- `@@`      - Repeat last executed macro（重复上次执行的宏）

