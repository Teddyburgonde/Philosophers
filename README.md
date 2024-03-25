> [!IMPORTANT]
🚧 En construction... Derniere mises a jour 26/03/2024 à 17h10.



![roro](https://github.com/Teddyburgonde/Philosophers/assets/93845046/4dfa0811-9aca-46a9-8900-45aab9c0fe5f)

Les voitures de Rocket league vont vite ... 

Lisez mon Readme et vous terminerez si vite ce projet que vous aurez l'impression que les voitures de Rocket league sont lente :)

# **Philosophers**

## **C'est quoi un thread ?**

- Un thread est une suite logique d'instructions qui peuvent être exécutées simultanément avec d'autres threads sur un processeur.
- Les threads permettent de faire du multi-tache comme l'utilisation de processus parent et enfant, mais bien moins exigeant au niveau de la mémoire. Un thread ne copie pas le programme du parent, mais exécute seulement la fonction qui lui est donnée. Les threads sont généralement utilisés pour effectuer de petite tache. Un processus parent peut avoir plusieurs threads.

- Un thread est composé de :
  
  	- Un id
	- Un compteur
	- Un ensemble de registre
 	- Une stack 

## **Comment crée un thread ?**

```C
#include <pthread.h>
#include <stdio.h>

void	*ft_write_word(void *data)
{
	printf("salut\n");
	return (NULL);
}

int	main()
{	
	// declaration d'un thread
	pthread_t	thread1;

	// il prends en arguments :

	// 1. Un pointeur vers une variable de type pthread_t (c'est un identifiant)
	// 2. Un pointeur vers une structure pthread_attr_t mais on en a pas donc on met NULL 
	// 3. C'est un pointeur vers une fonction, la fonction doit accepter un argument de type void*
	// 4. c'est l'argument de la fonction ft_write_word mais la on en a pas donc on met NULL
	pthread_create(&thread1, NULL, ft_write_word, NULL);
	
	// on affiche l'identifiant de thread1
	printf("Main: Creation du premier thread [%lu]\n", (unsigned long)thread1);

	// avec cette fonction on attends que thread1 se termine puis quand il est terminer
	// le main peut prendre fin.
	// essayer le avec ou sans cette ligne vous pourez voir la difference.
	pthread_join(thread1, NULL);

	// permet de libérer les ressources du thread mais empêche de synchroniser plusieurs thrads
	// a l'aide de pthread_join.
	pthread_detach(thread1);
}
```
##  **Compilation**
Ne pas oublier de rajouter -lpthread 
```
gcc -Wall -Werror -Wextra -lpthread main.c
```
## **C'est quoi un Mutex ?**

- C'est un mecanisme de synchronisation qui evite que deux thread s'execute en meme temps.

![Screenshot from 2024-03-25 17-08-12](https://github.com/Teddyburgonde/Philosophers/assets/93845046/8415d620-a47f-467a-a5d3-0b80702586fd)

- On peut penser à un mutex comme au verrou de la porte des toilettes. Un thread vient le verrouiller pour indiquer que les toilettes sont occupées. Les autres threads devront alors attendre patiemment que la porte soit déverrouillée avant de pouvoir accéder aux toilettes à leur tour.

## **Comment crée un mutex ?**































# Les fonctions : ✅

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
  - 

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
