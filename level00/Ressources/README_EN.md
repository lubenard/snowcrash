# Level 00

[FRENCH version](README.md)

## How to get the flag

By logging in to level00, you can see that there are no files specific to the level.

You can search for all the files belonging to flag00 with the command

```
find / -user flag00
```

The command returns 2 files:

```
/usr/sbin/john
/rofs/usr/sbin/john
```

Both files contain the same string of characters:

```
cdiiddwpgswtgt
```

The fact that the file is called john may make you think of John The Ripper, but it doesn't seem to be a format that can be deciphered by John.

The characters are only alphabetical, so it may look like ROT 13, or Caesar encryption.

ROT 13 doesn't seem to work, but by passing it in a Caesar encryption (https://www.dcode.fr/chiffre-cesar), with the option: Test all possible shifts, we can see that the first result is: nottoohardhere. (with a shift of +15)

The password is valid to connect to user flag00.

## The flag

The flag to connect to flag00
```
nottoohardhere
```
