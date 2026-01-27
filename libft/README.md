*This project has been created as part of the 42 curriculum by khhammou.*

## Description

Libft is a C library created to replicate and extend standard C functions.  
The goal of this project is to:

- Gain a deeper understanding of C fundamentals such as memory management, pointers, and data structures.
- Implement common functions from the C standard library like "ft_strlen", "ft_strchr", "ft_memcpy", etc.
- Create a personal library that can be reused in future projects.

Additionally, the bonus part extends the library to support **linked lists**, providing functions to create, modify, iterate, and delete nodes in a dynamic list.


## Instructions

### Compilation

- Run "make" to compile all mandatory functions into "libft.a".
- Run "make bonus" to include the linked list bonus functions.
- Run "make fclean" to remove object files and the library.
- Run "make re" to rebuild everything from scratch.

### Usage

- Include "libft.h" in your project.
- Link the library with your program using "-L" and "-l" flags in gcc.  
  Example (conceptually):  
<!-- gcc main.c -L. -lft -->
compiles main.c into main.o, links mian.o with all functions in libft.a -L. to look in curr dir but could be -L~/libft to look in ~/libft for libraries -lft looks for libft.a
- Make sure to handle memory management properly when using functions that allocate memory.
Example usage:
#include "libft.h"
#include <stdio.h>

int main()
{
    char *s = "Hello 42!";
    printf("Length: %zu\n", ft_strlen(s)); // using ft_strlen from libft
    return 0;
}
to compile it do gcc main.c -L. -lft then ./a.out and violaa
-l which library to link (without lib prefix or .a suffix) so compiler looks for librarie ending in ft basically
Or simply do gcc main.c libft.a!(works only if you know the lib's path)

## Resources

- Official C documentation: https://man7.org/linux/man-pages/  
- Tutorials on C memory management and pointers: Various online references.  
- 42 curriculum subject sheets for function specifications.

### AI Usage

AI assistance was used **only for conceptual explanations** of linked list functions, Makefile logic, and project structuring.  
No actual function code was directly copied; all implementations are my own work.
