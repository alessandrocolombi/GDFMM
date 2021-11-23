# GDFMM
R package for Group Dependent Finite Mixture Models

# species branch
This branch is for the development of the finite species sampling model. 

# Note
Ho clonato la il nuovo branch della repo in una cartella diversa da dove avevo GDFMM. Ho usato
```shell
$ git clone -b species git@github.com:alessandrocolombi/GDFMM.git
```
Se entro con git bash nella cartella e faccio git status, mi dice che è up to date anche se non lo è. Infatti facendo 
```shell
$ git pull
```
o aprendo il .Rproj con R e facendo pull con quella freccia, è andato tutto bene. Ora ho modificato il README in locale
e da R vedo che segna il pulsando per fare commit e push del README. Andato bene!<br/>
Comunque da git bash, se vado sulla cartella originale GDFMM posso fare 
```shell
$ git checkout species
```
per andare sul branch delle specie.
