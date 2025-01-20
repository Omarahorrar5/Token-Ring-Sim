Ce TP implémente un système de communication inter-processus utilisant un mécanisme de Token Ring. L'objectif est de synchroniser plusieurs processus en passant un jeton (token) autour d'une boucle de processus.


Objectifs du TP:

1. Créer une structure en anneau de N processus.

2. Synchroniser les processus en utilisant un jeton unique qui circule entre eux.

3. Assurer que chaque processus reçoit le jeton, effectue une tâche, puis passe le jeton au prochain processus.




Fichier Principal:

Token.c : Contient le code C pour l'implémentation du Token Ring.




Fonctionnalités Clés:

1. Pipes : Utilisés pour la communication entre les processus.

2. fork : Création de processus fils pour former l'anneau.

3. Synchronisation par Jeton : Le jeton est passé d'un processus à l'autre pour synchroniser les actions.




Déroulement du Programme

1. Initialisation : Création de N pipes pour la communication entre les processus.

2. Création de Processus : Chaque processus est créé via fork().

3. Communication : Chaque processus ferme les pipes inutiles et utilise les pipes restants pour lire et écrire le jeton.

4. Passage du Jeton : Le jeton est lu, une action est effectuée (affichage du jeton), puis le jeton est passé au prochain processus.

5. Arrêt : Le processus s'arrête lorsque le jeton revient à 0.

