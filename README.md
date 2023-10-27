# Simulateur d'Écosystème IoT pour la Surveillance de la Qualité de l'Air

## Description

Ce projet offre un simulateur dédié à la modélisation d'un écosystème IoT axé sur la surveillance de la qualité de l'air. Il se compose de plusieurs classes essentielles, notamment la classe Server, Sensor, et Scheduler.

## Fonctionnement

L'écosystème fonctionne de manière harmonieuse en suivant ces étapes :

1. **Capteurs Multiples :** Divers capteurs, tels que ceux dédiés à la lumière, à la température, à l'humidité et au son, sont intégrés dans le simulateur.

2. **Scheduler :** La classe Scheduler joue un rôle central en rassemblant les données provenant de ces capteurs. Elle coordonne l'ensemble du processus en préparant les informations pour l'envoi ultérieur.

3. **Serveur Intelligent :** Équipé d'un algorithme intégré, le serveur prend en charge l'orchestration de l'envoi des données des capteurs. Il optimise la communication en organisant les données à des intervalles de temps diversifiés, offrant ainsi une efficacité accrue.

## Classes Principales

### 1. Server

La classe Server représente le cerveau du système, coordonnant la réception et l'envoi des données. Son algorithme intégré assure une gestion intelligente des informations pour une utilisation efficace des ressources.

### 2. Sensor

La classe Sensor encapsule les différents types de capteurs présents dans l'écosystème. Chaque capteur est spécialisé dans la collecte d'une dimension particulière de données liées à la qualité de l'air.

### 3. Scheduler

La classe Scheduler agit comme un planificateur central, organisant la collecte et la préparation des données des capteurs avant de les transmettre au serveur. Elle optimise le processus pour une communication fluide et efficace.

## Comment Utiliser

1. **Paramètres du programme :** Pour utiliser le projet, vous avez deux options de paramètres.

   ```bash
   nom_du_programme true true
   ```
Le premier paramètre gère l'écriture dans les fichiers logs, et le deuxième gère l'affichage dans la console.

## Comment Compiler et Implémenter le Projet
### Compilation sur Windows avec g++

1. **Prérequis :** Assurez-vous d'avoir g++ (le compilateur C++) installé sur votre système.

2. **Téléchargement du Code Source :** Clonez le dépôt GitHub dans votre terminal.

   ```bash
   git clone https://github.com/votre-utilisateur/simulateur-iot
   ```

3. **Accéder au Répertoire :** Naviguez vers le répertoire du projet.

   ```bash
   cd simulateur-iot
   ```

4. **Compilation :** Utilisez g++ pour compiler le code source.

   ```bash
   g++ -o simulateur main.cpp Sensor.cpp Scheduler.cpp Server.cpp
   ```

5. **Exécution :** Exécutez le programme généré.

   ```bash
   simulateur
   ```

### Compilation sur Linux avec g++

1. **Prérequis :** Assurez-vous d'avoir g++ installé sur votre système.

2. **Téléchargement du Code Source :** Clonez le dépôt GitHub dans votre terminal.

   ```bash
   git clone https://github.com/votre-utilisateur/simulateur-iot
   ```

3. **Accéder au Répertoire :** Naviguez vers le répertoire du projet.

   ```bash
   cd simulateur-iot
   ```

4. **Compilation :** Utilisez g++ pour compiler le code source.

   ```bash
   g++ -o simulateur main.cpp Sensor.cpp Scheduler.cpp Server.cpp
   ```

5. **Exécution :** Exécutez le programme généré.

   ```bash
   ./simulateur
   ```

Ces instructions sont basées sur l'hypothèse que vos fichiers sources sont main.cpp, Sensor.cpp, Scheduler.cpp, et Server.cpp. Si les noms de vos fichiers sont différents, assurez-vous de les ajuster lors de la compilation. Explorez le simulateur IoT en C++ et testez ses fonctionnalités sur votre plateforme préférée!
