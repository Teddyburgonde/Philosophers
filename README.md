🚧 En construction... Derniere mises a jour 25/03/2024



![roro](https://github.com/Teddyburgonde/Philosophers/assets/93845046/4dfa0811-9aca-46a9-8900-45aab9c0fe5f)

Vous voulez finir ce projet aussi rapidement que la vitesse des voitures de rocket league ? 
SUIVEZ CE README ! =)




# Philosophers

C'est quoi un thread ? 

- Un thread est une suite logique d'instructions qui peuvent être exécutées simultanément avec d'autres threads sur un processeur.
Dans philosophers on doit utiliser plusieurs thread.

- Un thread est composé de :
      - Un id
      - Un compteur
      - Un ensemble de registre
      - Une stack 

Comment crée un thread :

<img width="700" alt="Capture d’écran 2024-03-25 à 00 09 03" src="https://github.com/Teddyburgonde/Philosophers/assets/93845046/5233d90d-2480-4d07-b328-68a526074dcc">

```C
#include <pthread.h>
#include <stdio.h>

void	*ft_write_word(void *data)
{
	printf("salut");
}

int	main()
{	
	// declaration d'un thread
	pthread_t	thread1;

	// il prends en arguments
	pthread_create(&thread1, NULL, ft_write_word, NULL);
	
	
	pthread_join(thread1, NULL);
}

```


Les avantages d'utiliser les thread ? 

	- La reactivité : permet a un programme de continuer meme si une parti est bloqué.
	- Partage de ressource : permet a l'application d'avoir plusieurs types d'activité differents
	- Economy : Partage les ressources et donc c'est plus economique en ressources
	- L'utilisation d'architectures multi-processeurs : permet que les taches s'execute en meme temps


















Les fonctions : ✅

- memset : elle permet de remplir une zone mémoire, avec une valeur specifique.
void *memset(void *ptr, int value, size_t num);


- fork: Crée un nouveau processus en dupliquant le processus appelant. Le processus fils a une copie exacte de l'espace d'adressage du parent.
pid_t fork(void);


- kill: Envoie un signal à un processus ou à un groupe de processus.
int kill(pid_t pid, int sig);


- exit: Termine l'exécution du processus en cours.
void exit(int status);


- pthread_create: Crée un nouveau thread dans un processus.
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);


- pthread_detach: Détache un thread, ce qui permet au système de libérer automatiquement les ressources lorsque le thread se termine.
int pthread_detach(pthread_t thread);


- pthread_join: Attend la fin de l'exécution d'un thread.
int pthread_join(pthread_t thread, void **retval);


- usleep: Met le thread en attente pendant un certain nombre de microsecondes.
int usleep(useconds_t usec);


- gettimeofday: Récupère le temps écoulé depuis l'époque dans une structure timeval.
int gettimeofday(struct timeval *tv, struct timezone *tz);


- waitpid: Suspend l'exécution du processus appelant jusqu'à ce qu'un processus fils spécifié se termine.
pid_t waitpid(pid_t pid, int *status, int options);


sem_open: Ouvre ou crée un sémaphore nommé.
sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);


sem_close: Ferme un sémaphore.
int sem_close(sem_t *sem);


sem_post: Incrémente la valeur d'un sémaphore.
int sem_post(sem_t *sem);


sem_wait: Décrémente la valeur d'un sémaphore et bloque si la valeur est négative.
int sem_wait(sem_t *sem);


sem_unlink: Supprime un sémaphore nommé.
int sem_unlink(const char *name);


Definition : ✅

Chaque philosophe est un thread, et chaque fourchette est un mutex.



Semaphore : ✅    

	Un sémaphore est un mécanisme de synchronisation utilisé dans la programmation multithread et multiprocessus pour contrôler l'accès concurrent à des ressources partagées. Son rôle principal est de réguler l'accès à une ressource partagée entre plusieurs threads ou processus en imposant des règles d'accès.    

mutex : ✅
	C'est un mecanisme de synchronisation qui evite que deux thread s'execute en meme temps.

	
A faire : 


Regarder les 3 videos : ❌
  - Introduction to threads https://www.youtube.com/watch?v=LOfGJcVnvAk ✅
  - Introduction To Threads (pthreads) https://www.youtube.com/watch?v=ldJ8WGZVXZk ✅
  - Short introduction to threads (pthreads) https://www.youtube.com/watchv=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2 ❌

2. regarder la video de Jamshidbek Ergashev
https://www.youtube.com/watch?v=UGQsvVKwe90

3. Lire le read me de amyplant  
https://github.com/iciamyplant/Philosophers/tree/master 

4. Lire le Readme de Romain ❌



Divers : 

Un Philosophe peut faire trois choses :  
  - Manger
  - Dormir
  - Penser

Pour manger il doit choisir deux fourchettes (celle devant lui et une autre a sa droite ou a sa gauche.
Le nombre de fourchette est egal au nombre de philosophes.


Un processus peut avoir plusieurs threads , une tache pour chaque threads.
Chaque thread a sa sa pile et ses propres registres.
Chaque thread a access au code , la data et les fichiers. 


Footer ✅
Page Tean : ❌
