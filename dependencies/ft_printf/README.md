# ft_printf

Regardless of the programming language considered, the `printf` function,(or its equivalents) is always highly useful. 
The main reason is the ease of its formatting, and the support of diverse types in variable numbers. 
Some variations even propose to be able to write the resulting string of characters either in a file descriptor or in a particular stream. 
Some also propose to recall this string without printing it. In short, undeniably, printf is a vital function.

```c
int    ft_printf(char *format, ...);
```

<b>%[flags][width][.precision][length]type</b>

### What is done

* `Flags field`
  * `-` — left-align the output of this placeholder
  * `+` — prepends a plus for positive signed-numeric types. positive = `+`, negative = `-`
  * ` ` — prepends a space for positive signed-numeric types. positive = ` `, negative = `-`. This flag is ignored if the `+` flag exists
  * `0` — when the 'width' option is specified, prepends zeros for numeric types
  * `#` — for `f`, `F`, `e`, `E`, `g`, `G` types, the output always contains a decimal point, for `o`, `x`, `X` types, the text `0`, `0x`, `0X`, respectively, is prepended to non-zero numbers

* `Width field`
* `Precision field`
* `Length field`
  * `hh` — for integer types, causes `printf` to expect an int-sized integer argument which was promoted from a `char`.
  * `h` — for integer types, causes `printf` to expect an int-sized integer argument which was promoted from a `short`.
  * `l` — for integer types, causes `printf` to expect a `long`-sized integer argument
  * `ll` — for integer types, causes `printf` to expect a `long long`-sized integer argument
  * `L` — for floating point types, causes `printf` to expect a `long double` argument
  * `z` — for integer types, causes `printf` to expect a `size_t`-sized integer argument
  
* `Types`
  * `%` — prints a literal % character
  * `d` — `int` as a signed integer.
  * `i` — `int` as a signed integer.
  * `u` — print decimal `unsigned int`.
  * `f` — `double` in normal (fixed-point) notation
  * `F` — `double` in normal (fixed-point) notation
  * `x` — `unsigned int` as a hexadecimal number
  * `X` — `unsigned int` as a hexadecimal number
  * `o` — `unsigned int` in octal
  * `s` — null-terminated string
  * `c` — `char` (character)
  * `p` — `void *` (pointer to void) in an implementation-defined format
  * `r` — color output (google ANSI Code)
 
