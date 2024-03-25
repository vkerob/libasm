
# libasm

Rewrite the following functions from the libc in x86_64 assembly.

## prototypes

```c
size_t  strlen(const char *s);                          // man 3 strlen
char    *strcpy(char *dest, const char *src);           // man 3 strcpy
int     strcmp(const char *s1, const char *s2);         // man 3 strcmp
ssize_t write(int fd, const void *buf, size_t count);   // man 2 write
ssize_t read(int fd, void *buf, size_t count);          // man 2 read
char *strdup(const char *s);                            // man 3 strdup
```


## Running project/Tests

If you only want libasm.a, execute this command:

```bash
  make
```

To run basic tests, execute these commands:

```bash
  make test
  ./test
```
For further testing, go to my tester: https://github.com/vkerob/libasmTester.git
## Documentation

[x86-64 Reference Sheet](https://people.kth.se/~dbro/x86-64-ref-sheet.pdf)

