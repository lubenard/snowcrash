# Level01

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

On peut voir dans le fichier /etc/passwd que la ligne concernant flag01 est différente des autres.

En effet, a la place d'un 'x', (qui représente le fait que le mot de passe soit stocké hashé dans /etc/shadow), il y a un mot de passe.

```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Celui ci ne fonctionne pas, ce n'est donc pas un mot de passe écrit en dur.

Dans les anciennes versions de Linux, le mot de passe n'était pas hashé mais crypté en utilisant la fonction crypt() (https://www.man7.org/linux/man-pages/man3/crypt.3.html)

John the Ripper est capable de casser ce genre de fichier.

Il suffit de copier le fichier /etc/passwd sur une machine ou John The Ripper est installé, puis de lancer:

```
john passwd
```

Il donne ainsi la ligne suivante:

```
flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash
```

Le mot de passe pour le compte du flag01 est donc abcdefg

Une fois connecté sur flag01, il suffit de lancer getflag pour récupérer le flag

## Le flag
Le flag pour se connecter au flag01
```
abcdefg
```
