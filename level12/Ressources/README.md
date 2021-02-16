# Level12

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

Le seul fichier présent dans le home est un fichier Perl.

Le script possède une bit SUID.

Il récurère les paramètres d'une requete (Avec CGI, un module perl) et les parse avec des regex.

Le script récupère deux paramètres: x et y.

Il applique une regex a x qui transforme toute les lettres minuscules en majuscules (```tr/a-z/A-Z/```)

Il applique une seconde regex a x qui trim la chaine.

Il cherche ensuite une occurence a x dans le fichier /tmp/xd (```egrep "^$xx" /tmp/xd 2>&1```)

Comme le script mets toutes les lettres en majuscule, nous ne pouvons pas executer de commandes, ni de cibler des dossiers particulers.

La seule solution reste d'utiliser les wildcards (http://www.linfo.org/wildcard.html)

Les backquotes servent a executer une commande avant (Un peu comme un subshell)

https://unix.stackexchange.com/questions/27428/what-does-backquote-backtick-mean-in-commands

Nous devons encadrer les backquote afin qu'il n'execute pas la commande avant le curl, mais bien dans le fichier perl

```
echo "getflag > /tmp/test" > /tmp/HEY
chmod +x /tmp/HEY
curl localhost:4646?x='`/*/HEY`'
cat /tmp/test
```

## Le flag

Le flag lu est celui utilisable pour se connecter a level13
