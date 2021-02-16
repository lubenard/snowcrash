# Level05

[FRENCH version](README.md)

## How to get the flag

When logging in on the level05 login, you will see this message: "You have new mail."

The mail command does not exist.

Looking at the environment variables, we can see an environment variable named MAIL which contains '/var/mail/level05'.

by opening /var/mail/level05, you can see the following line 

```
'*/2 * * * * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

It is a cron line, recognizable by the stars at the beginning (see https://www.linuxtricks.fr/wiki/cron-et-crontab-le-planificateur-de-taches).

Every 2 minutes, /usr/sbin/openarenaserver is launched with as if it were the user flag05 (with the -)

the /usr/sbin/openarenaserver script is the following:

```
for i in /opt/openarenaserver/*; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

It launches the contents of the files in a bash.

We can do:

```
echo "getflag > /tmp/pass" > /opt/openarenaserver/getflag
```

then wait 2 minutes. 

The flag will then appear in the /tmp/pass file.

## The flag

The flag read is the one that can be used to connect to level06.