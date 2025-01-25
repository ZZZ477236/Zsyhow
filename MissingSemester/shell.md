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
存储可执行文件？

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




