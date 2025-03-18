<div align="center">
    <h1 style="font-family: 黑体; color: red;">汇编语言</h1>
</div>

---

# 引言
##### 课程工具：

1.汇编器：masm6.15
2.调试器：ollydbg
3.Dev-C++
(https://sourceforge.net/projects/orwelldevcpp/);

##### 为什么要学习汇编语言？

Ø 写出运行速度更快的代码

Ø 写出更安全的代码

Ø 有助于深入理解计算机系统

Ø 具备以二进制代码为师的能力

Ø 舒缓学习高级语言不适感
##### 要素
操作码 目的操作数，源操作数 
操作码：体现指令的语义，即指令所要完成的操作；
操作数：指令操作的对象。包括常数、内存地址、
或寄存器。
##### 反汇编指令：
-a, --archive-headers	显示归档文件（archive）头信息
-f, --file-headers	显示整个文件的头部信息
-p, --private-headers	显示特定对象格式的文件头内容
-P, --private=OPT,OPT...	显示特定对象格式的详细内容
-h, --[section-]headers	显示段（section）头部信息
-x, --all-headers	显示所有头部信息
-d, --disassemble	反汇编可执行部分的汇编代码
-D, --disassemble-all	反汇编所有部分的汇编代码
-S, --source	将源代码与反汇编代码混合显示
-s, --full-contents	显示请求段的完整内容
-g, --debugging	显示目标文件中的调试信息
-e, --debugging-tags	以 ctags 风格显示调试信息
-G, --stabs	以原始形式显示 STABS 调试信息
-W[lLiaprmfFsoRt] 或 --dwarf[=选项]	显示 ELF 可执行文件中的 DWARF 调试信息
-t, --syms	显示符号表内容
-T, --dynamic-syms	显示动态符号表内容
-r, --reloc	显示文件中的重定位项
-R, --dynamic-reloc	显示动态重定位项
@<file>	从 <file> 读取选项
-v, --version	显示当前工具的版本号
-i, --info	列出支持的对象文件格式和架构
-H, --help	显示帮助信息
##### 指定反汇编格式
 objdump -S -d -M intel main.o

 下列 i386/x86-64 特定的反汇编器选项在使用 **-M** 开关时可用（使用逗号分隔多个选项）：
  x86-64      Disassemble in 64bit mode
  i386        Disassemble in 32bit mode
  i8086       在 16 位模式下反汇编
  att         用 AT&T 语法显示指令
  intel       用 Intel 语法显示指令

  
  ![编译流程](../AssemblyLanguage/img/1.png)
##### 使用gcc自带的objdump反汇编过程
- 'gcc -c -g -o hello.o hello.c':
  -c: 只编译，不链接，生成目标文件（.o）
  -g: 生成调试信息
  -o: 指定输出文件
- 'objdump -s -d hello.o > hello.s':
  -s: 显示目标文件中的所有段
  -d: 反汇编目标文件中的代码