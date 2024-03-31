> [!IMPORTANT]
🚧 **En construction... Derniere mises a jour 31/03/2024 à 17h10.**

<h1 align="center"><b>Philosophers</b></h1>
<h2 align="center"><b>Guide pas à pas</b></h2>

<p align="center">
	<img src="https://github.com/Teddyburgonde/Philosophers/assets/93845046/87d4052f-671f-42fa-a379-2d2268b7ae75" alt="diner" />
</p>

## **C'est quoi un thread ?**

- Un thread est une suite logique d'instructions qui peuvent être exécutées simultanément avec d'autres threads sur un processeur.
- Les threads permettent de faire du multi-tache comme l'utilisation de processus parent et enfant, mais bien moins exigeant au niveau de la mémoire. Un thread ne copie pas le programme du parent, mais exécute seulement la fonction qui lui est donnée. Les threads sont généralement utilisés pour effectuer de petite tache. Un processus parent peut avoir plusieurs threads.

- Un thread est composé de :
  
  	- Un id
	- Un compteur
	- Un ensemble de registre
 	- Une stack 

## **Comment créer un thread ?**

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

## **Comment créer un mutex ?**

```C
int	main(void)
{	
	// Déclaration d'un mutex
	pthread_mutex_t	mutex;

	// Deux paramettre : 

	// 1. Le mutex qu'on veut initialiser
	// 2. Un pointeur vers des attributs spécifiques pour le mutex.
	// on en a pas donc on met NULL
	// La fonction pthread_mutex_init renvoie toujours 0.
	pthread_mutex_init(&mutex, NULL);
	return (0);
}
```
## **Verrouiller un mutex**

```C
int	main(void)
{
	pthread_mutex_lock(&nameofmutex);
	return (0);
}
```

## **Déverouiller un mutex**
```C
int	main(void)
{
	pthread_mutex_unlock(&nameofmutex);
	return (0);
}
```
## **Détruire un mutex**
```C
int	main(void)
{
	pthread_mutex_destroy(&nameofmutex);
	return (0);
}
```

## **Pourquoi doit t'on détruire un mutex ?**

```
Quand on crée un mutex on alloue de la mémoire donc pour éviter les fuites de mémoire il faut la liberer.
```

## Comprendre l'importance du mutex 

```c
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

void	*print1(void *mutex)
{
	int	i;
	char	str[] = "Hello 42";

	i = 0;
	pthread_mutex_lock(mutex);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	pthread_mutex_unlock(mutex);
}

void  *print2(void *mutex)
{
	int    i;
	char  str[] = "Bye 42";

	i = 0;
	pthread_mutex_lock(mutex);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	pthread_mutex_unlock(mutex);
}

int  main(void)
{
	pthread_t  t1;
	pthread_t  t2;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, print1, &mutex);
	pthread_create(&t2, NULL, print2,  &mutex);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);

	return (0);
}
```

resultat :

```
Hello 42
Bye 42%
```

Maintenant sans utiliser le mutex 

```c
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

void	*print1(void *mutex)
{
	int	i;
	char	str[] = "Hello 42";

	i = 0;
	//pthread_mutex_lock(mutex);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	//pthread_mutex_unlock(mutex);
}

void  *print2(void *mutex)
{
	int    i;
	char  str[] = "Bye 42";

	i = 0;
	//pthread_mutex_lock(mutex);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	//pthread_mutex_unlock(mutex);
}

int  main(void)
{
	pthread_t  t1;
	pthread_t  t2;
	//pthread_mutex_t	mutex;

	//pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, print1, NULL);
	pthread_create(&t2, NULL, print2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	//pthread_mutex_destroy(&mutex);

	return (0);
}
```

resultat : 

```
Bye 42Hello 42
```

et si vous lancez avec valgrind : 
```
valgrind --tool=helgrind ./a.out
```
Erreur sans mutex : 

```
==1153466== ---Thread-Announcement------------------------------------------
==1153466== 
==1153466== Thread #3 was created
==1153466==    at 0x499C9F3: clone (clone.S:76)
==1153466==    by 0x499D8EE: __clone_internal (clone-internal.c:83)
==1153466==    by 0x490B6D8: create_thread (pthread_create.c:295)
==1153466==    by 0x490C1FF: pthread_create@@GLIBC_2.34 (pthread_create.c:828)
==1153466==    by 0x4853767: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x10938B: main (in /nfs/homes/tebandam/Desktop/training/a.out)
==1153466== 
==1153466== ---Thread-Announcement------------------------------------------
==1153466== 
==1153466== Thread #2 was created
==1153466==    at 0x499C9F3: clone (clone.S:76)
==1153466==    by 0x499D8EE: __clone_internal (clone-internal.c:83)
==1153466==    by 0x490B6D8: create_thread (pthread_create.c:295)
==1153466==    by 0x490C1FF: pthread_create@@GLIBC_2.34 (pthread_create.c:828)
==1153466==    by 0x4853767: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x10936E: main (in /nfs/homes/tebandam/Desktop/training/a.out)
==1153466== 
==1153466== ----------------------------------------------------------------
==1153466== 
==1153466== Possible data race during write of size 1 at 0x52A4191 by thread #3
==1153466== Locks held: none
==1153466==    at 0x4859796: mempcpy (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x4902664: _IO_new_file_xsputn (fileops.c:1235)
==1153466==    by 0x4902664: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
==1153466==    by 0x48ECFC9: outstring_func (vfprintf-internal.c:239)
==1153466==    by 0x48ECFC9: __vfprintf_internal (vfprintf-internal.c:1593)
==1153466==    by 0x48D779E: printf (printf.c:33)
==1153466==    by 0x1092E3: print2 (in /nfs/homes/tebandam/Desktop/training/a.out)
==1153466==    by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x490BAC2: start_thread (pthread_create.c:442)
==1153466==    by 0x499CA03: clone (clone.S:100)
==1153466==  Address 0x52a4191 is 1 bytes inside a block of size 1,024 alloc'd
==1153466==    at 0x484A919: malloc (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x48F5BA3: _IO_file_doallocate (filedoalloc.c:101)
==1153466==    by 0x4904CDF: _IO_doallocbuf (genops.c:347)
==1153466==    by 0x4903F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
==1153466==    by 0x48EE3DB: __vfprintf_internal (vfprintf-internal.c:1517)
==1153466==    by 0x48D779E: printf (printf.c:33)
==1153466==    by 0x109245: print1 (in /nfs/homes/tebandam/Desktop/training/a.out)
==1153466==    by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==1153466==    by 0x490BAC2: start_thread (pthread_create.c:442)
==1153466==    by 0x499CA03: clone (clone.S:100)
==1153466==  Block was alloc'd by thread #2
==1153466== 

```

Cette erreur signifie que les threads essai d'ecrire dans la memoire en meme temps donc cela pose probleme. 

## gettimeofday

Il affiche le temps écoulé depuis le 01/01/1970(l'époque Unix) à maintenant. 

```c
void	example_1()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return ;
	printf("%ld seconds\n", time.tv_sec);
	printf("%ld microseconds\n", time.tv_usec);
}
int	main()
{
	example_1();
}
```


## ft _usleep

- Comme chaque philosophe(thread) ne peut pas manger en meme temps , cela sert a faire attendre les autres philosophe.
- usleep return 0 en cas de success et -1 en cas d'erreur.
- Elle prends en paramettre le temps en microsecondes. 

On doit coder son propre usleep pour avoir un temps plus précis :

```c
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
```



## Etape 1 : Parsing

## Analyse de Input 

```
./philosophers 5 800 200 200 7
5 — Le nombre de philosophes
800 — Le moment où un philosophe mourra s'il ne mange pas
200 — Le temps qu'il faut à un philosophe pour manger
200 — Le temps qu'il faut à un philosophe pour dormir
7 Nombre de fois que tous les philosophes doivent manger avant de terminer le programme ** argument facultatif
```

Un Input correct doit ressembler a ceci : 
```
./philosophers 5 800 200 200 7
```
Errors :
```
- On doit avoir entre 4 a 5 arguments ( si on ne compte pas le ./a.out) ni plus ni moins. (Le dernier argument est facultatif) sinon error.
- C'est que des chiffres , sinon error.
- Si l'argument est vide "" , error.
- tous les arugments doivent etre superieur a 0 sauf le nombre de repas que chaque philo doit manger (voir en dessous) sinon error.
- Si argv[1] est suppérieur à 200 , error.
```
## Etape 2 : Création des structures 

Dans le sujet on nous dit qu'il faut :
number_of_philosophers
time_to_die time_to_eat
time_to_sleep
number_of_times_each_philosopher_must_eat
🚧🚧🚧🚧🚧🚧
```c
typedef struct{
	// pthread_t		thread;

	// Chaque philosophe possède un numéro allant de 1 ànombre_de_philosophes.
	int	number_of_philosophers;
	int number_of_times_each_philosopher_must_eat;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	//pthread_mutex_t	*r_fork;
	//pthread_mutex_t	*l_fork;
	
} t_philo;
```

Créé une boucle : 

```
- qui se brisera dès que le drapeau mort sera à 1 (un philo est mort).
- Ils mangerons.
- Ils dormirons.
- Ils penserons.
Le philo pense -> print “X is thinking” (X is the philo number)
Le philo dort -> utiliser ft_usleep et print "X is sleeping"
Le philo mange -> lock la fourchette droite print "X is eating" + lock la fourchette gauche print "X is eating"
Ensuite, il mangera à nouveau en utilisant ft_usleep et alors seulement il laissera tomber les fourchettes en déverrouillant les verrous
```

🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧

Sources : 

- Introduction to threads -> https://www.youtube.com/watch?v=LOfGJcVnvAk ✅
- Introduction To Threads (pthreads) -> https://www.youtube.com/watch?v=ldJ8WGZVXZk ✅
- Readme amyplant -> https://github.com/iciamyplant/Philosophers/tree/master ✅
- Readme de Romain -> https://github.com/Romain-ItAllDepends/Tronc-commun/blob/main/PHILOSOPHERS/README.md ✅
- Video de Jamshidbek Ergashev -> https://www.youtube.com/watch?v=UGQsvVKwe90 ❌
- Explication du projet par Medium -> https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2 ✅


✅
❌
