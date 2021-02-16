# Level04

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

Le fichier level04.pl est un fichier de Perl Script

Il possède aussi un setuid

On peut voir en commentaire qu'un serveur apache2 tourne a l'addresse localhost:4747

Ce peut etre confirmé par le fait qu'on puisse s'y connecter avec telnet:

```
telnet localhost 4747
``` 

ainsi qu'avec les taches du système: 

```
ps -aux | grep apache2
```
Le script utiise CGI, et lit les arguments donnés

On peut faire une injection de paramètre.

CGI lit les arguments key=value. (voir https://www.perlmonks.org/bare/?node_id=241223)

On peut voir que dans le script, CGI attend un paramètre 'x'

En utilisant les sous shell, on peut afficher ce que l'on veut.

Example:

```
curl localhost:4747?x='$(getflag)'
```

## Le flag

Le flag lu est celui utilisable pour se connecter a level05