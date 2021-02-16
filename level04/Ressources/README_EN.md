# Level04

[FRENCH version](README.md)

## How to get the flag

The file level04.pl is a Perl Script file.

It also has a setuid

We can see in the commentary that an apache2 server is running at localhost:4747.

This can be confirmed by the fact that you can connect to it with telnet:

```
telnet localhost 4747
``` 

as well as with the system tasks:

```
ps -aux | grep apache2
```

The script uses CGI, and reads the given arguments

A parameter injection can be made.

CGI reads the arguments key=value. (see https://www.perlmonks.org/bare/?node_id=241223)

We can see that in the script, CGI waits for a 'x' parameter.

By using the sub-shells, you can display whatever you want.

For example:

```
curl localhost:4747?x='$(getflag)'.
```

## The flag

The flag read is the one that can be used to connect to level05.