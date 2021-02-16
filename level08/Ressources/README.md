# Level08

[ENGLISH version](README_EN.md)

## Comment récuperer le flag

On peut voir que le level08 possède un SUID.

Il y a également un fichier token qui n'est lisible que par flag08.

En décompilant level08, on s'appercoit que le programme utilise strstr pour voir si le deuxieme argument contient le mot "token".

Si c'est le cas, il quitte. 

Il suffit alors de faire une redirection de fichier.

```
ln -s $PWD/token /tmp/abc
./level08 /tmp/abc
```

On récupère alors: quif5eloekouj29ke0vouxean

## Le flag
```
quif5eloekouj29ke0vouxean
```

En utilisant ce token, on peut se connecter a flag08, et lancer getflag pour récuperer le flag