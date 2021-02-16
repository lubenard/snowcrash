# Level13

[FRENCH version](README.md)

## How to recover the flag

You can see that there is an executable.
When we launch it, it displays being launched with uid 2043, and not 4242.

We understand that we must then change the UID to access the token.

By launching strings on the file, we can see a string of characters
Strange, which looks like a flag, but when testing this chain, we can see that it's a
that it is false.

by decompiling the program, we can see that it recovers the UID with getuid, the stock
in a variable and then compares with 4242. If the two values are different,
then the program quits.

Looking at the assembler code, we can see that it stores the value of the
return of getuid() in eax, a register.

We can bypass this behavior by using GDB.

When we try to access local variables using

```
info locals
```

gdb says it can't find a local table.

You actually have to use:

```
info register
```
The value in the register can then be changed using 

```
set $eax = 4242
```

The flag is revealed

## The flag

The flag read is the one that can be used to connect to level14.