# Écosystème

Ce projet est une simulation en C++ d'un écosystème basique.

## Installation

Ce projet utilise la librarie graphique SFML.
Pour installer SFML sur Linux :
```bash
sudo apt-get install libsfml-dev
```
Pour les autres OS, voir la documentation [ici](https://www.sfml-dev.org/tutorials/2.5/#getting-started).

Pour créer l'exécutable, il suffit d'entrer la commande `make`.

## Lancement

Sur Linux, il faut lancer l'exécutable `ecosystem.out`.
```bash
./ecosystem.out
```

## Fonctionnement

- Les animaux sont représentés par des cercles. Au début de la simulation, des lapins et des renards sont placés aléatoirement sur la fenêtre. Le rayon de leur cercle est aléatoire, choisi dans une plage de valeurs. Les animaux ont une quantité définie de points de vie (**à définir**).

- De plus, une certaine quantité de nourriture est répartie sur la fenêtre. La nourriture est aussi représentée par un cercle.

- À chaque regénération de la fenêtre (voir *framerate*), les animaux se déplacent pseudo-aléatoirement en utilisant le *Perlin noise*. Leurs points de vie diminuent d'une quantité définie (**à définir**). Voici les interactions entre les entités :

    * **Quand un lapin rencontre de la nourriture**, le lapin mange la nourriture. La nourriture est regénérée à un autre endroit de la fenêtre et le lapin gagne une certaine quantité de points de vie (**à définir**).
    * **Quand un renard rencontre un lapin**, le renard mange le lapin avec une certaine probabilité (**à définir**). Le renard gagne alors une quantité de points de vie, et le lapin disparaît.
    * **Quand un lapin rencontre un autre lapin**, un nouveau lapin naît avec une certaine probabilité (**à définir**).
    * **Quand un renard rencontre un autre renard**, un nouveau renard naît avec une certaine probabilité (**à définir**).
    * **Quand un animal n'a plus de points de vie**, il meurt et disparaît de la fenêtre.

## Tâches

- [x] Créer la fenêtre de simulation
- [x] Définir les classes pour les animaux
- [x] Gérer le déplacement des animaux
- [x] Définir la classe pour la nourriture
- [ ] Gérer les interactions entre les entités
- [x] Ajouter sur la fenêtre les statistiques de la simulation (nombre d'animaux, timer)
- [ ] Gérer la customisation de la simulation
- [x] Pouvoir faire pause, accélérer, ralentir la simulation
- [x] Pouvoir générer un graphe de la simulation avec le nombre d'animaux en fonction du temps

## Références

- [The Nature of Code - Daniel Schiffman](https://natureofcode.com/book/chapter-9-the-evolution-of-code/#913-ecosystem-simulation)
- [Coding Adventure: Simulating an Ecosystem](https://www.youtube.com/watch?v=r_It_X7v-1E)
- [Simulation de la sélection naturelle](https://www.youtube.com/watch?v=0ZGbIKd0XrM)
- [SFML Documentation](https://www.sfml-dev.org/documentation/2.5.1/index.php)
- [Perlin Noise](https://en.wikipedia.org/wiki/Perlin_noise)

## Auteur

Quentin Deschamps
