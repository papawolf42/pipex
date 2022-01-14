# Libft

> Your very first own library

in 42, we should implement our own library for use throughout following projects.

Progress record of the this project



## 🔗 List of Functions

#### Part. 1

 [`memset`](https://github.com/papawolf42/Libft/blob/master/src/ft_memset.c) [`bzero`](https://github.com/papawolf42/Libft/blob/master/src/ft_bzero.c) [`memcpy`](https://github.com/papawolf42/Libft/blob/master/src/ft_memcpy.c) [`memccpy`](https://github.com/papawolf42/Libft/blob/master/src/ft_memccpy.c) [`memmove`](https://github.com/papawolf42/Libft/blob/master/src/ft_memmove.c) [`memchr`](https://github.com/papawolf42/Libft/blob/master/src/ft_memchr.c) [`memcmp`](https://github.com/papawolf42/Libft/blob/master/src/ft_memcmp.c) [`strlen`](https://github.com/papawolf42/Libft/blob/master/src/ft_strlen.c) [`strlcpy`](https://github.com/papawolf42/Libft/blob/master/src/ft_strlcpy.c) [`strlcat`](https://github.com/papawolf42/Libft/blob/master/src/ft_strlcat.c) [`strchr`](https://github.com/papawolf42/Libft/blob/master/src/ft_strchr.c) [`strrchr`](https://github.com/papawolf42/Libft/blob/master/src/ft_strrchr.c) [`strnstr`](https://github.com/papawolf42/Libft/blob/master/src/ft_strnstr.c) [`strncmp`](https://github.com/papawolf42/Libft/blob/master/src/ft_strncmp.c) [`atoi`](https://github.com/papawolf42/Libft/blob/master/src/ft_atoi.c) [`isalpha`](https://github.com/papawolf42/Libft/blob/master/src/ft_isalpha.c) [`isdigit`](https://github.com/papawolf42/Libft/blob/master/src/ft_isdigit.c) [`isalnum`](https://github.com/papawolf42/Libft/blob/master/src/ft_isalnum.c) [`isascii`](https://github.com/papawolf42/Libft/blob/master/src/ft_isascii.c) [`isprint`](https://github.com/papawolf42/Libft/blob/master/src/ft_isprint.c) [`toupper`](https://github.com/papawolf42/Libft/blob/master/src/ft_toupper.c) [`tolower`](https://github.com/papawolf42/Libft/blob/master/src/ft_tolower.c) [`calloc`](https://github.com/papawolf42/Libft/blob/master/src/ft_calloc.c) [`strdup`](https://github.com/papawolf42/Libft/blob/master/src/ft_strdup.c)

#### Part.2

 [`substr`](https://github.com/papawolf42/Libft/blob/master/src/ft_substr.c) [`strjoin`](https://github.com/papawolf42/Libft/blob/master/src/ft_strjoin.c) [`strtrim`](https://github.com/papawolf42/Libft/blob/master/src/ft_strtrim.c) [`split`](https://github.com/papawolf42/Libft/blob/master/src/ft_split.c) [`itoa`](https://github.com/papawolf42/Libft/blob/master/src/ft_itoa.c) [`strmapi`](https://github.com/papawolf42/Libft/blob/master/src/ft_strmapi.c) [`putchar_fd`](https://github.com/papawolf42/Libft/blob/master/src/ft_putchar_fd.c) [`putstr_fd`](https://github.com/papawolf42/Libft/blob/master/src/ft_putstr_fd.c) [`putendl_fd`](https://github.com/papawolf42/Libft/blob/master/src/ft_putendl_fd.c) [`putnbr_fd`](https://github.com/papawolf42/Libft/blob/master/src/ft_putnbr_fd.c)

#### Bonus

 [`lstnew`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstnew.c) [`lstadd_front`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstadd_front.c) [`lstsize`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstsize.c) [`lstlast`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstlast.c) [`lstadd_back`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstadd_back.c) [`lstdelone`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstdelone.c) [`lstclear`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstclear.c) [`lstiter`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstiter.c) [`lstmap`](https://github.com/papawolf42/Libft/blob/master/src/ft_lstmap.c)



## 🧪 Test program

[`Libftest`](https://github.com/jtoty/Libftest) by jtoty

[`libft_war-machine`](https://github.com/ska42/libft-war-machine)<sub id="a1">[[1]](#f1)</sub> by ska42

[`libft-unit-test`](https://github.com/alelievr/libft-unit-test) by alelievr



## 📜 Solving process

1. Read man page first. ([`FreeBSD manual`](https://www.freebsd.org/cgi/man.cgi))
2. Googling, including koeran.
3. See Slack, Discord, Stackoverflow.
4. Ask peers on kakaotalk.
5. Scratch coding simply
6. Conceive a test case, ponder how to deal with Undefined Behavior
7. Run 3 test programs
   - If it fail, go back to 5.
8. Record what felt and learned.



## References

### 👿 Undefined Behavior

- [C/C++의 undefined behavior](https://www.secmem.org/blog/2020/01/17/c-c++-and-ub/) by evenharder
- [With Undefined Behavior, Anything is Possible](https://raphlinus.github.io/programming/rust/2018/08/17/undefined-behavior.html) by Raph Levien
- [Undefined behavior](https://en.wikipedia.org/wiki/Undefined_behavior) from wikipedia

***



### 📂 Makefile

- [Make 사용 가이드](https://modoocode.com/311) from 모두의 코드
- [Make manual](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents) from GNU
  - [Variable](https://www.gnu.org/software/make/manual/html_node/Variables-Simplify.html#Variables-Simplify)
  - [Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html#Implicit-Variables)
  - [Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)
  - [Patterns Match](https://www.gnu.org/software/make/manual/html_node/Pattern-Match.html#Pattern-Match)
  - [Archive](https://www.gnu.org/software/make/manual/html_node/Archives.html#Archives)

***

<sub><b id="f1">[[1]](#a1)</b> War Machine is a forked version of Libftest, differ test cases slightly, can not test the bonus function properly on current version(2020.10).</sub>

