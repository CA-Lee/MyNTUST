Syllabus
===

- midterm & final
    - hand-writing test
- ask for leave before, or will get zero when quiz be given.
- Slides will be put on Moodle.

What's 程式語言
---

`=`: assign (not **equal**)

```
a = b + c; => compiler =>   mov b,r1
                            mov c,r2
                            add r1,r2
                            mov r2,a
```

Compilers:
- Dev-C++ (We are gonna use it.)
- Code blocks
- Visual Studio

IDE: **I**ntegrated **D**evelopment **E**nvironment

First Program - Hello World
---

> **NEVER LIVE CODE**

Do not use Dev-C++ 4.9.9.2, use 5.11 or later

It's gcc (~~**G**NU **C** **C**ompiler~~ **G**NU **C**ompiler **C**ollection) inside the Dev-C++.

Chapter 2
===

A Simple C Program: Printing a Line of Text
---

```
#include <stdio.h>
int main( void )
{
    printf( "Welcome to C!\n" );
}
```

- `stdio`: **ST**an**D**ar **I**nput **O**utput header.
- `.h`: **H**eader file.
- `void` is not necessary at here.
- `printf`: print text to standard output (Default is screen).
- The return value of `main()` will be passed to OS.
- `return 0;` is not necessary now, compiler will help to add it.

Other special characters:
- `//` is origined from C++, the original comment aign is `/*...*/`.
- `#`: preprocessor
- `\a`: alert. Produces a sound or visible alert.

Why we teach / learn C ?
---

> Because most of language nowaday is base on C style. If you aquried to programming in C, you can easily switch to other languages. 

Another Simple C Program: Adding Two Integers
---

```
#include <stdio.h>

int main(){
    int i1; // Declare
    int i2; // Declare

    printf("Enter first int\n");
    scanf("%d", &i1 );
    
    printf("Enter second int\n");
    scanf("%d", &i2 );

    int sum;
    sum = i1 + i2;

    printf("Sum is %d\n", sum);
}
```

`scanf`
- Standard input method.
- First argument: string of **conversion specifiers**. 
- Second argument: an **address** for put the value that user entered. Use `&` (**address operator**) to get the address of a variable.
- `scanf` was declared **unsafe** now. ([ref.]())

Conversion specifiers ([ref.](https://flaviocopes.com/c-conversion-specifiers/)):
- `%d`: in decimal interger.
- `%b`: in binary.
- `%x`: in hexadecimal.
- `%g`: float number in decimal format or exponential format depending on the value. (Double numbers should use `%lg`)

The newer C allow users to declare variable **anywhere** before using it, while old C asks users to declare variable at the start of the function.

Datatypes with their length:
| Datatype | Length (in byte)          |
| -------- | ------------------------- |
| char     | 1                         |
| short    | 2                         |
| int      | 4                         |
| long     | 4,8 (Depends on compiler) |
| longlong | 8                         |
| float    | 4                         |
| double   | 8                         |

> ref. The IEEE Standard for Floating-Point Arithmetic (IEEE 754) ([en](https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/) [ch](https://zh.wikipedia.org/wiki/IEEE_754))

ASCII: **A**merican **S**tandard **C**ode for **I**nformation **I**nterchange

`==` take precedence over `=`.

Chapter 3
Structured Program Development in C
===

Algorithms
---

An algorithm is a **procedure** for solving a problem in terms of the **actions** to be executed, and the **order** in which these actions are to be executed.

Control Structures
---

Begin/End Symbol: oval  
Connector Symbol: circle

C has only seven control statements,including one sequence structure, three selection structure, and three repetition structure. All of them are single-entry/single-exit.

| Structure  | syntax        |
| ---------- | ------------- |
| Sequence   | action states |
| Selection  | if            |
|            | if ... else   |
|            | switch        |
| repetition | for           |
|            | while         |
|            | do ... while  |

Format String
===

> ref. https://en.wikipedia.org/wiki/Printf_format_string#Format_placeholder_specification

```
%[parameter][flags][width][.precision][length]type
```
> For `printf()` function, if you replace the *width* and / or the *precision* number by a `*` , then you must specify the number at the next argument.

**Parameter**
- `n$` : *n* is a number, in order to select the *n*th argument after the format string.

**Flags**
- `-` : left-align the output.
- `+` : show the positive sign or negative sign in front of number.
- `(space)` : Prepends a space for positive signed-numeric types.
- `0` : use `0` instead of `(space)` to fill the width.
- `'` : apply the thousand grouping separator.
- `#`
  - For `g` and `G` : preserve trailing zeros.
  - For `f`, `F`, `e`, `E`, `g`, `G` : the output always contains a decimal point.
  - For `o`, `x`, `X` : prepended `0`, `0x`, `0X`, respectively, to non-zero numbers.

> Allow multiple flags in one format string.

**Width**

- `n` : *n* is a number, specifies the **minimum** width of the output.

**Precision**

- `n`
  - For floating point numeric types: specifies the number of digits right of the decimal point.
  - For others: specifies the **maximum** width of the output.

**Length**

- `hh` : a `char` size integer.
- `h` : a `short` size integer.
- `l`
  - For integers: a `long` size integer.
  - For floating points: a `double` size argument.
- `ll` : a `long long` size integer.
- `L` : a `long double` size argument.

**Type**

- `%c` in scanf() will cause `enter` problem.

期末專題
===

- 最多兩人一組
- 期中後公布
- 寫程式

How to enter the `EOF`
===

Windows systems: `Ctrl + z`  
UNIX-like systems: `Ctrl + d`

ASCII of frequent used constants
===

> ref. https://www.ascii-code.com/  
> ref. https://en.wikipedia.org/wiki/Control_character

> `EOF` is not an ASCII. It's a return value of `scanf()` , it actually is -1.  
> ref. https://stackoverflow.com/questions/7622699/what-is-the-ascii-value-of-eof-in-c  
> ref. https://en.wikipedia.org/wiki/End-of-file

- `0` : 48, 0x30.
- `A` : 65, 0x41.
- `a` : 97, 0x61.
- `\n` : newline, aka. `LF` , 10, 0xA.
- `\r` : return to start of line, aka. `CR` , 13, 0x0D.
- `\b` : move the cursor backward, aka. `BS` , 8, 0x8.
- `\0` : null, the end character of string, aka. `NUL` , 0, 0x0.
- `\t` : tab, aka. `HT` , 9, 0x9.
- `\a` : **MAKE NOISES** , aka. `BEL` , 7, 0x7.

Storage Classes
===

Use before variable declaration.

```
[specifiers] [type] [name] ;
```
`type`: `int`, `double` and so on...
`name`: Name of a variable

- `auto`
  - The default.
  - Create when: be defined
  - Exist when: in block (`{}`)
  - Destroy on: exit block
- `register`
  - Store the value in computer registers
  - Automatic initialize to 1
  - If no register available, compiler may ignore it.
- `extern`
  - *Let a variable globalize*
  - Mean this variable is declared otherwhere.
  - Local variable should be declared with `static`
  - Global variable have `extern` by default.
- `static`
  - The initializer in declaration only execute once before teminating.
  - Create when: before program begin
  - Exist when: in block (`{}`)
  - Destroy on: program terminated
  - Static array will be initialized to 0 by default.

Avoid to use global variable
---

- 造成記憶體整理困難
- 程式會變得沒有組織

Recursive
===

Fibonacci series
---

`F(n)` will call about $2^n - 1$ times of `F()`

Array
===

Declaration
---

- If the number of elements in the array initialize block is less than the size of array, program will automatic set the indeclared elements as `0` .
  - `int n[5] = {0}`
    - result in `{ 0, 0, 0, 0, 0}`
  - `int n[5] = {1}`
    - result in `{ 1, 0, 0, 0, 0}`

Midterm
===

- 可以帶一張 A4 手寫筆記
- 交卷才能出去上廁所
- 考 7 - 10 題