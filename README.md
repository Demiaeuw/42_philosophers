# 42 Philosopher
Description

Le projet Philosopher est une implémentation du célèbre problème des philosophes et des baguettes, utilisé pour illustrer les problèmes de synchronisation dans les systèmes d'exploitation. Ce projet vise à simuler des philosophes qui mangent, pensent et dorment, tout en respectant des contraintes liées à l'utilisation de ressources partagées (les baguettes).

L'objectif principal de ce projet est de démontrer l'utilisation correcte des threads, des mutex et de la gestion de la concurrence.
Fonctionnalités

    Simulation de philosophes mangeant, pensant et dormant.
    Gestion des ressources partagées (baguettes) avec des mutex pour éviter les conditions de course.
    Threads pour chaque philosophe simulé.
    Support pour plusieurs paramètres d'entrée : nombre de philosophes, temps avant la faim, temps pour manger, etc.

## Installation

Pour compiler et exécuter ce projet, vous devez disposer de make et de gcc installés sur votre machine.

1. Clonez le dépôt :

```bash

git clone https://github.com/Demiaeuw/42_philosophers.git
```

2. Accédez au répertoire du projet :

```bash

cd 42_philosophers
```

3. Compilez le projet en utilisant make :

```bash

make
```

4. Exécutez le programme avec les arguments souhaités (par exemple) :

```bash

./philo 5 800 200 200
```

## Usage

Le programme accepte les arguments suivants :

./philo [nombre de philosophes] [temps avant la faim] [temps pour manger] [temps pour dormir] [nombre de repas (optionnel)]

Exemple :

```bash

./philo 5 800 200 200 5
```

nombre de philosophes : Le nombre de philosophes à simuler.
temps avant la faim : Le temps en millisecondes qu'un philosophe peut attendre avant de devoir manger.
temps pour manger : Le temps en millisecondes qu'un philosophe met pour manger.
temps pour dormir : Le temps en millisecondes qu'un philosophe met pour dormir.
nombre de repas (optionnel) : Le nombre de repas qu'un philosophe doit consommer avant la fin de la simulation.

Si le dernier paramètre n'est pas fourni, la simulation continue jusqu'à ce qu'un philosophe meure.
Exemple d'exécution

```bash

$ ./philo 5 800 200 200
Philosophe 1 pense.
Philosophe 2 mange.
Philosophe 3 dort.
...
```

## Dépendances

Le projet n'utilise aucune bibliothèque externe en dehors des bibliothèques standard du C.

## Contributeurs

[Adrien Cabarbaye](https://github.com/Demiaeuw)

## Licence

Ce projet est sous la licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus d'informations.
