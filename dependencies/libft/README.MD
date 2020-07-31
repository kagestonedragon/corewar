# Libft

The aim of this project is to code a C library regrouping usual functions that you’ll be allowed to use in all your other projects.

<p align="left">
  <img src="images/cat.jpg" width="20%" alt="fun"/>
</p>

### Libc functions

I re-code a set of the libc functions, as defined in their `man`.

* `memset`
* `bzero`
* `memcpy`
* `memccpy`
* `memmove`
* `memchr`
* `memcmp`
* `strlen`
* `strdup`
* `strcpy`
* `strncpy`
* `strcat`
* `strncat`
* `strlcat`
* `strchr`
* `strrchr`
* `strstr`
* `strnstr`
* `strcmp`
* `strncmp`
* `atoi`
* `isalpha`
* `isdigit`
* `isalnum`
* `isascii`
* `isprint`
* `toupper`
* `tolower`

### Additional functions

I code a set of functions that are either not included in the libc, or included in a different form.

* `ft_memalloc` — allocates (with malloc(3)) and returns a “fresh” memory area. The memory allocated is initialized to 0. If the allocation fails, the function returns NULL.
  * `Prototype`:      <b>void * ft_memalloc(size_t size);</b>
  * `Param. #1`:      The size of the memory that needs to be allocated.
  * `Return value`:   The size of the memory that needs to be allocated.
  * `Libc functions`: malloc(3)
 
* `ft_memdel` — takes as a parameter the address of a memory area that needs to be freed with free(3), then puts the pointer to NULL.
  * `Prototype`:      <b>void ft_memdel(void **ap);</b>
  * `Param. #1`:      A pointer’s address that needs its memory freed and set to NULL.
  * `Return value`:   None.
  * `Libc functions`: free(3).
  
* `ft_strnew` — allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’. Each character of the string is initialized at ’\0’. If the allocation fails the function returns NULL.
  * `Prototype`:      <b>char * ft_strnew(size_t size);</b>
  * `Param. #1`:      The size of the string to be allocated.
  * `Return value`:   The string allocated and initialized to 0.
  * `Libc functions`: malloc(3)
  
* `ft_strdel` — takes as a parameter the address of a string that need to be freed with free(3), then sets its pointer to NULL.
  * `Prototype`:      <b>void ft_strdel(char **as);</b>
  * `Param. #1`:      Takes as a parameter the address of a string that need to be freed with free(3), then sets its pointer to NULL.
  * `Return value`:   The string’s address that needs to be freed and its pointer set to NULL.
  * `Libc functions`: free(3).

* `ft_strclr` — sets every character of the string to the value ’\0’.
  * `Prototype`:      <b>void ft_strdel(char **as);</b>
  * `Param. #1`:      The string that needs to be cleared.
  * `Return value`:   None.
  * `Libc functions`: None.

* `ft_striter` — <b>void ft_striter(char *s, void (*f)(char *));</b> Applies the function f to each character of the string passed as argument. Each character is passed by address to f to be modified if necessary.
  * `Prototype`:      <b>void ft_striter(char *s, void (*f)(char *));</b>
  * `Param. #1`:      The string to iterate.
  * `Param. #2`:      The function to apply to each character of s.
  * `Return value`:   None.
  * `Libc functions`: None.

* `ft_striteri` — applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.
  * `Prototype`:      <b>void ft_striteri(char *s, void (*f)(unsigned int, char *));</b>
  * `Param. #1`:      The string to iterate.
  * `Param. #2`:      The function to apply to each character of s and its index.
  * `Return value`:   None.
  * `Libc functions`: None.

* `ft_strmap` — applies the function f to each character of the string given as argument to create a “fresh” new string (with malloc(3)) resulting from the successive applications of f.
  * `Prototype`:      <b>char * ft_strmap(char const *s, char (*f)(char));</b>
  * `Param. #1`:      The string to map.
  * `Param. #2`:      The function to apply to each character of s.
  * `Return value`:   The “fresh” string created from the successive applications of f.
  * `Libc functions`: malloc(3)

* `ft_strmapi` — applies the function f to each character of the string passed as argument by giving its index as first argument to create a “fresh” new string (with malloc(3)) resulting from the suc- cessive applications of f.
  * `Prototype`:      <b>char * ft_strmapi(char const *s, char (*f)(unsigned int, char));</b>
  * `Param. #1`:      The string to map.
  * `Param. #2`:      The function to apply to each character of s and its index.
  * `Return value`:   The “fresh” string created from the successive applications of f.
  * `Libc functions`: malloc(3)

* `ft_strequ` — lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.
  * `Prototype`:      <b>int ft_strequ(char const *s1, char const *s2);</b>
  * `Param. #1`:      The first string to be compared.
  * `Param. #2`:      The second string to be compared.
  * `Return value`:   1 or 0 according to if the 2 strings are identical or not.
  * `Libc functions`: None.

* `ft_strnequ` — lexicographical comparison between s1 and s2 up to n characters or until a ’\0’ is reached. If the 2 strings are identical, the function returns 1, or 0 otherwise.
  * `Prototype`:      <b>int ft_strnequ(char const *s1, char const *s2, size_t n);</b>
  * `Param. #1`:      The first string to be compared.
  * `Param. #2`:      The second string to be compared.
  * `Param. #3`:      The maximum number of characters to be compared.
  * `Return value`:   1 or 0 according to if the 2 strings are identical or not.
  * `Libc functions`: None.
  
* `ft_strsub` — lexicographical comparison between s1 and s2 up to n characters or until a ’\0’ is reached. If the 2 strings are identical, the function returns 1, or 0 otherwise.
  * `Prototype`:      <b>char * ft_strsub(char const *s, unsigned int start, size_t len);</b>
  * `Param. #1`:      The string from which create the substring.
  * `Param. #2`:      The start index of the substring.
  * `Param. #3`:      The size of the substring.
  * `Return value`:   The substring.
  * `Libc functions`: malloc(3)

* `ft_strjoin` — allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’, result of the concatenation of s1 and s2. If the allocation fails the function returns NULL.
  * `Prototype`:      <b>char * ft_strjoin(char const *s1, char const *s2);</b>
  * `Param. #1`:      The prefix string.
  * `Param. #2`:      The suffix string.
  * `Return value`:   The “fresh” string result of the concatenation of the 2 strings.
  * `Libc functions`: malloc(3)
  
* `ft_strtrim` — allocates (with malloc(3)) and returns a copy of the string given as argument without whitespaces at the beginning or at the end of the string. Will be considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces at the beginning or at the end, the function returns a copy of s. If the allocation fails the function returns NULL.
  * `Prototype`:      <b>char * ft_strtrim(char const *s);</b>
  * `Param. #1`:      The string to be trimed.
  * `Return value`:   The “fresh” trimmed string or a copy of s.
  * `Libc functions`: malloc(3)
  
* `ft_strsplit` — allocates (with malloc(3)) and returns an array of “fresh” strings (all ending with ’\0’, including the array itself) obtained by spliting s using the character c as a delimiter. If the allocation fails the function returns NULL.
  * `Prototype`:      <b>char ** ft_strsplit(char const *s, char c);</b>
  * `Param. #1`:      The string to split.
  * `Param. #2`:      The delimiter character.
  * `Return value`:   The array of “fresh” strings result of the split.
  * `Libc functions`: malloc(3), free(3)

* `ft_itoa` — allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’ representing the integer n given as argument. Negative numbers must be supported. If the allocation fails, the function returns NULL.
  * `Prototype`:      <b>char * ft_itoa(int n);</b>
  * `Param. #1`:      The integer to be transformed into a string.
  * `Return value`:   The string representing the integer passed as argument.
  * `Libc functions`: malloc(3)

* `ft_putchar` — outputs the character c to the standard output.
  * `Prototype`:      <b>void ft_putchar(char c);</b>
  * `Param. #1`:      The character to output.
  * `Return value`:   None.
  * `Libc functions`: write(2).

* `ft_putstr` — outputs the string s to the standard output.
  * `Prototype`:      <b>void ft_putstr(char const *s);</b>
  * `Param. #1`:      The string to output.
  * `Return value`:   None.
  * `Libc functions`: write(2).
  
* `ft_putendl` — outputs the string s to the standard output followed by a ’\n’.
  * `Prototype`:      <b>void ft_putendl(char const *s);</b>
  * `Param. #1`:      The string to output.
  * `Return value`:   None.
  * `Libc functions`: write(2).

* `ft_putnbr` — outputs the integer n to the standard output.
  * `Prototype`:      <b>void ft_putnbr(int n);</b>
  * `Param. #1`:      The integer to output.
  * `Return value`:   None.
  * `Libc functions`: write(2).
  
* `ft_putchar_fd` — outputs the char c to the file descriptor fd.
  * `Prototype`:      <b>void ft_putchar_fd(char c, int fd);</b>
  * `Param. #1`:      The character to output.
  * `Param. #2`:      The file descriptor.
  * `Return value`:   None.
  * `Libc functions`: write(2).
  
* `ft_putstr_fd` — outputs the string s to the file descriptor fd.
  * `Prototype`:      <b>void ft_putstr_fd(char const *s, int fd);</b>
  * `Param. #1`:      The string to output.
  * `Param. #2`:      The file descriptor.
  * `Return value`:   None.
  * `Libc functions`: write(2).
  
* `ft_putendl_fd` — outputs the string s to the file descriptor fd followed by a ’\n’.
  * `Prototype`:      <b>void ft_putendl_fd(char const *s, int fd);</b>
  * `Param. #1`:      The string to output.
  * `Param. #2`:      The file descriptor.
  * `Return value`:   None.
  * `Libc functions`: write(2).
  
* `ft_putnbr_fd` — outputs the integer n to the file descriptor fd.
  * `Prototype`:      <b>void ft_putnbr_fd(int n, int fd);</b>
  * `Param. #1`:      The integer to print.
  * `Param. #2`:      The file descriptor.
  * `Return value`:   None.
  * `Libc functions`: write(2).

### Bonus functions

<p>The following functions will allow you to manipulate your lists more easilly.</p>
<p>Structure:</p>

```c
typedef struct   s_list{
void             *content;
int              content_size;
struct s_list    *next;
}                t_list;
```

* `ft_lstnew` — allocates (with malloc(3)) and returns a “fresh” link. The variables content and content_size of the new link are initialized by copy of the parameters of the function. If the parameter content is nul, the variable content is initialized to NULL and the variable content_size is initialized to 0 even if the parameter content_size isn’t. The variable next is initialized to NULL. If the allocation fails, the function returns NULL.
  * `Prototype`:      <b>t_list * ft_lstnew(void const *content, size_t content_size);</b>
  * `Param. #1`:      The content to put in the new link.
  * `Param. #2`:      The size of the content of the new link.
  * `Return value`:   The new link.
  * `Libc functions`: malloc(3), free(3)
  
* `ft_lstdelone` — takes as a parameter a link’s pointer address and frees the memory of the link’s content using the function del given as a parameter, then frees the link’s memory using free(3). The memory of next must not be freed under any circumstance. Finally, the pointer to the link that was just freed must be set to NULL (quite similar to the function ft_memdel in the mandatory part).
  * `Prototype`:      <b>void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));</b>
  * `Param. #1`:      The address of a pointer to a link that needs to be freed.
  * `Return value`:   None.
  * `Libc functions`: free(3)
  
* `ft_lstdel` — Takes as a parameter the adress of a pointer to a link and frees the memory of this link and every successors of that link using the functions del and free(3). Finally the pointer to the link that was just freed must be set to NULL (quite similar to the function ft_memdel from the mandatory part).
  * `Prototype`:      <b>void ft_lstdel(t_list **alst, void (*del)(void *, size_t));</b>
  * `Param. #1`:      The address of a pointer to the first link of a list that needs to be freed.
  * `Return value`:   None.
  * `Libc functions`: free(3)

* `ft_lstadd` — adds the element new at the beginning of the list.
  * `Prototype`:      <b>void ft_lstadd(t_list **alst, t_list *new);</b>
  * `Param. #1`:      The address of a pointer to the first link of a list.
  * `Param. #2`:      The link to add at the beginning of the list.
  * `Return value`:   None.
  * `Libc functions`: None.
  
* `ft_lstiter` — iterates the list lst and applies the function f to each link.
  * `Prototype`:      <b>void ft_lstiter(t_list *lst, void (*f)(t_list *elem));</b>
  * `Param. #1`:      A pointer to the first link of a list.
  * `Param. #2`:      The address of a function to apply to each link of a list.
  * `Return value`:   None.
  * `Libc functions`: None. 
  
* `ft_lstmap` — Iterates a list lst and applies the function f to each link to create a “fresh” list (using malloc(3)) resulting from the successive applications of f. If the allocation fails, the function returns NULL.
  * `Prototype`:      <b>t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));</b>
  * `Param. #1`:      A pointer’s to the first link of a list.
  * `Param. #2`:      The address of a function to apply to each link of a list.
  * `Return value`:   The new list.
  * `Libc functions`: malloc(3), free(3).
