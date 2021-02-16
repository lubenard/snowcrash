# Level05

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

En se connectant sur le login du level05, on voit ce message apparaitre: "You have new mail."

La commande mail n'existe pas.

En regardant les variables d'environnement, on peut voir une variable d'environnement nommée MAIL qui contient '/var/mail/level05'

en ouvrant /var/mail/level05, on peut voir la ligne suivante 

```
'*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05'
```

C'est une ligne de cron, reconnaissable aux étoiles au début (voir https://www.linuxtricks.fr/wiki/cron-et-crontab-le-planificateur-de-taches)

Toutes les 2 minutes, /usr/sbin/openarenaserver est lancé avec comme si c'était l'utilisateur flag05 (avec le -)

le script /usr/sbin/openarenaserver est le suivant:

```
for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

Il lance le contenu des fichiers dans un bash.

Il suffit alors de faire:

```
echo "getflag > /tmp/pass" > /opt/openarenaserver/getflag
```

puis d'attendre 2 minutes. 

On voit alors apparaitre dans le fichier /tmp/pass le flag.

## Le flag

Le flag lu est celui utilisable pour se connecter a level06