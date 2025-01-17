# Level09

[ENGLISH version](README_EN.md)

## Comment récuperer le flag

Le level 9 contient deux fichier.

1 executable et 1 fichier token

L'executable est un fichier SUID.

Le fichier token est accessible en écriture mais illisible.

L'executable fonctionne de la sorte:

 - Il prend un argument en paramètre et un seul.
 - Il fait une rotation des lettres en fonction de leur position dans le mot:
    Exemple: aaa -> abc.
    Le premier   a ne change pas car il est a l'index 0 du mot.
    Le second    a devient b car il est a l'index 1
    Le troisième a devient c car il est a l'index 2

Repasser le fichier token dans l'executable ne donne rien de concluant.

On peut supposer que l'executable a permis d'encoder le fichier, et que c'est a nous de le decoder.

En faisant un petit programme en C, on peut passer le fichier token, et obtenir une réponse lisible.

```
cd /tmp
gcc decrypt.c
cd ~/
/tmp/a.out $(cat token)
```

Ce qui nous donne le token suivant: f3iji1ju5yuevaus41q1afiuq

## Le flag

```
f3iji1ju5yuevaus41q1afiuq
```

Ce token permet de se connecter au flag09 et de récuperer le token pour le level 10