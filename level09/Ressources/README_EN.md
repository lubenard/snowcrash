# Level09

[FRENCH version](README.md)

## How to get the flag

Level 9 contains two files.

1 executable and 1 token file

The executable is a SUID file.

The token file is writable but unreadable.

The executable works this way:

 - It takes one argument in parameter and only one.
 - It rotates the letters according to their position in the word:
    Example: aaa -> abc.
    The first a does not change because it is at index 0 of the word.
    The second a becomes b because it is at index 1.
    The third a becomes c because it is at index 2.

Replaying the token file in the executable does not give anything conclusive.

We can assume that the executable has encoded the file, and that it is up to us to decode it.

By making a small program in C, we can pass the token file, and get a readable answer.

```
cd /tmp
gcc decrypt.c
cd ~/
/tmp/a.out $(cat token)
```

This gives us the following token: f3iji1ju5yuevaus41q1afiuq

## The flag

```
f3iji1ju5yuevaus41q1afiuq
```

This token allows you to connect to flag09 and get the token for level 10.