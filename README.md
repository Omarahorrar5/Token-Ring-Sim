Ce TP implémente un système de communication inter-processus utilisant un mécanisme de Token Ring. L'objectif est de synchroniser plusieurs processus en passant un jeton (token) autour d'une boucle de processus.


Objectifs du TP:

1. Créer une structure en anneau de N processus.

2. Synchroniser les processus en utilisant un jeton unique qui circule entre eux.

3. Assurer que chaque processus reçoit le jeton, effectue une tâche, puis passe le jeton au prochain processus.




Fichier Principal:

Token.c : Contient le code C pour l'implémentation du Token Ring.




Fonctionnalités Clés:

Pipes : Utilisés pour la communication entre les processus.

Fork : Création de processus fils pour former l'anneau.

Synchronisation par Jeton : Le jeton est passé d'un processus à l'autre pour synchroniser les actions.




Déroulement du Programme

Initialisation : Création de N pipes pour la communication entre les processus.

Création de Processus : Chaque processus est créé via fork().

Communication : Chaque processus ferme les pipes inutiles et utilise les pipes restants pour lire et écrire le jeton.

Passage du Jeton : Le jeton est lu, une action est effectuée (affichage du jeton), puis le jeton est passé au prochain processus.

Arrêt : Le processus s'arrête lorsque le jeton revient à 0.

