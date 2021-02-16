# Level 00

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

En se connectant sur le level00, on peut voir qu'il n'y a aucun fichier specifique au level.

On peut chercher tous les fichiers appartenant a flag00 avec la commande

```
find / -user flag00
```

La commande retourne 2 fichiers:

```
/usr/sbin/john
/rofs/usr/sbin/john
```

Les deux fichier contiennent la même chaine de charactères:

```
cdiiddwpgswtgt
```

Le fait que le fichier s'appelle john peut faire penser a John The Ripper, mais cela n'a pas l'air d'être un format dechiffrable par John.

Les charactères étant seulement alphabétiques, cela peut faire penser a un ROT 13, ou un chiffrement de César.

Le rot 13 n'a pas l'air de fonctionne, mais en le passant dans un chiffrement de césar (https://www.dcode.fr/chiffre-cesar), avec l'option: Tester tous les décallages possibles, on peut voir que le premier résultat est: nottoohardhere

Le mot de passe est bien valide pour se connecter au user flag00

## Le flag

Le flag pour se connecter au flag00
```
nottoohardhere
```