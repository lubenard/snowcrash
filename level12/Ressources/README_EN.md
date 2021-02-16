# Level12

[FRENCH version](README.md)

## How to get the flag

The only file present in the home is a Perl file.

The script has a SUID bit.

It scans the parameters of a request (with CGI, a perl module) and parse them with regex.

The script gets two parameters: x and y.

It applies a regex to x which transforms all lowercase letters into uppercase letters (``tr/a-z/A-Z/````).

It applies a second regex a x that trim the chain.

It then looks for an occurrence a x in the /tmp/xd file (``egrep "^$xx" /tmp/xd 2>&1``)

As the script capitalizes all letters, we cannot execute commands, nor can we target particular folders.

The only solution is to use wildcards (http://www.linfo.org/wildcard.html).

Backquotes are used to execute a command before (a bit like a subshell).

https://unix.stackexchange.com/questions/27428/what-does-backquote-backtick-mean-in-commands

We need to frame the backquote so that it does not execute the command before the curl, but in the perl file

```
echo "getflag > /tmp/test" > /tmp/HEY
chmod +x /tmp/HEY
curl localhost:4646?x='`/*/HEY``
cat /tmp/test
```

## The flag

The flag read is the one that can be used to connect to level13.

Translated with www.DeepL.com/Translator (free version)
