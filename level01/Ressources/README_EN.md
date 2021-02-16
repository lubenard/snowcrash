# Level01

[FRENCH version](README.md)

## How to recover the flag

We can see in the /etc/passwd file that the line concerning flag01 is different from the others.

Indeed, instead of an 'x', (which represents the fact that the password is stored hashed in /etc/shadow), there is a password.

```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

This one doesn't work, so it is not a hard written password.

In older versions of Linux, the password was not hashed but encrypted using the crypt() function (https://www.man7.org/linux/man-pages/man3/crypt.3.html)

John the Ripper is able to break this kind of file.

Just copy the /etc/passwd file to a machine where John The Ripper is installed and run:

```
john passwd
```

It gives the following line:

```
flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash
```

The password for the flag01 account is:

```
abcdefg
```

Once connected to flag01, just run getflag to retrieve the flag

## The flag

The flag to connect to flag01

```
abcdefg
```