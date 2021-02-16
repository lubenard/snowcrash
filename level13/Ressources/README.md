# Level13

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

On peut voir qu'il y a un executable.
Quand on le lance, il affiche etre lance avec l'uid 2043, et non 4242.

On comprend qu'il faut alors changer l'UID pour acceder au token.

En lancant strings sur le fichier, on peut apercevoir une chaine de charactères
etrange, qui ressemble a un flag, mais en testant cette chaine, on s'apercoit
qu'elle est fausse.

en decompilant le program, on voit qu'il recupere l'UID avec getuid, la stock
dans une variable puis compare avec 4242. Si les deux valeurs sont differentes,
alors le programme quitte.

Il regardant le code en assembleur, on peut voir qu'il stocke la valeur du
retour de getuid() dans eax, un registre.

On peut contourner ce comportement en utilisant GDB.

Quand on essaie d'acceder aux variables locales en utilisant

```
info locals
```

gdb dit ne pas trouver de table locale.

Il faut en vérité utiliser:

```
info register
```
On peut alors modifier la valeur dans le registre en utilisant 

```
set $eax = 4242
```

Le flag est revélé

## Le flag

Le flag lu est celui utilisable pour se connecter a level14