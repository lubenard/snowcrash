# Level02

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

Le fichier level02 est un fichier portant l'extension pcap.

Pcap est un format de fichier contenant des échanges réseau.

Il faut donc utiliser wireshark pour exploiter ce fichier.

En ouvrant le fichier en hexadécimal, on peut voir le mot 'login' ainsi que 'password' contenu dedans.
clic droit, follow stream, show in hexdump --> permet de voir facilement le code hexa du mdp

En appliquant le filtre 'data.data && ip.src== 59.233.235.218' et en regardant entre les packets 22 et 85, on peut voir que la partie data des packets contient (une lettre a chaque fois): 

levelX ft_wandr...NDRel.L0L

On peut alors supposer que c'est des identifiants et mots de passe vu plus haut.

login:    levelX
Password: ft_wandr...NDRel.L0L

Seulement, ce mot de passe ne fonctionne pas.

En regardant de plus près le contenu en hexa, on peut voir la charactère 'xterm'. On peut alors penser a une connection ssh.

En regardant de plus près les characteres étant des '.', on s'appercoit alors que c'est la traduction hexadécimale du charactère 'delete' (Code ascii 127)

Si on supprime les 3 dernières lettres, on obtient alors: ft_waNDReL0L

## Le flag

Le flag pour se connecter a flag02
```
ft_waNDReL0L
```