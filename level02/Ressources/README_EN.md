# Level02

[FRENCH version](README.md)

## How to recover the flag

The level02 file is a file with the extension pcap.

Pcap is a file format containing network exchanges.

You can use wireshark to exploit this file.

When opening the file in hexadecimal, you can see the word 'login' and 'password' contained in it.
right click, follow stream, show in hexdump. It allows you to easily see the hexa code of the password.

By applying the filter 'data.data && ip.src== 59.233.235.218' and looking between packets 22 and 85, we can see that the data part of the packets contains (one letter each time): 

```
levelX ft_wandr...NDRel.L0L
```

We can then assume that they are usernames and passwords as seen above.

```
login: levelX
Password: ft_wandr...NDRel.L0L
```

Only, this password does not work.

A closer look at the hexa content shows the character 'xterm'. We can then think of an ssh connection.

If we look closer at the characters being '.', we can see that it is the hexadecimal translation of the character 'delete' (Ascii code 127).

If we delete the last 3 letters, we get: ft_waNDReL0L

## The flag

The flag to connect to flag02
```
ft_waNDReL0L
```