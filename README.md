> [!IMPORTANT]
> **En construction** 🚧
**Dernière mise à jour 08/05/2024 à 00h06.**

<h1 align="center"><b>Philosophers</b></h1>
<h2 align="center"><b>Guide pas à pas :+1:</b></h2>

<p align="center">
	<img src="https://github.com/Teddyburgonde/Philosophers/assets/93845046/87d4052f-671f-42fa-a379-2d2268b7ae75" alt="diner" />
</p>

## Différences entre programme , processus et thread ?

- Un programme est une suite d'nstructions que le developpeur dit à l'ordinateur de faire.
- Le processus c'est l'exécution du programme.
- Les threads c'est les actions et l'avantage avec les threads c'est qu'on peut faire plusieurs actions à la fois,
cela permet de gagner en rapidité , en fluidité , gere mieux utilisation de la mémoire ...etc.

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
- Pour éviter les leaks. 

## L'importance des mutex ! 

- Si on ne creer pas de mutex les deux thread vont par exemple vouloir écrire en meme temps dans la mémoire
et cela provoque des data races. 

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

Voici mon .h

```c
typedef struct s_data{
	pthread_mutex_t		is_dead_mutex;
	int	number_of_philosophers;
	int	meals_nb;
	int	is_dead;
	//int finished;
	t_philo	*philo; 
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		printf_mutex;
}	t_data;

typedef struct s_philo{
	
	t_data				*data;
	pthread_t			thread_id;
	int					id_philo;
	int					eat_cont;
	int					status;
	int					eating;
	long int			last_time_eaten;
	pthread_mutex_t	lock; 
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;
```

## Etape 3 : Initialisation des structures 

🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧 EN CONSTRUCTION 🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧

## Etape 4 : La routine des philosphers 

- Ils mangent
- ils dorments
etc... 



## Visualizer

```
https://nafuka11.github.io/philosophers-visualizer/
```
Deux philosophes ne doivent pas manger en même temps :

![Screenshot from 2024-03-31 18-01-29](https://github.com/Teddyburgonde/Philosophers/assets/93845046/8194a3f9-a9db-41c3-bec5-cfdbdb336907)


Sources : 

- Introduction to threads -> https://www.youtube.com/watch?v=LOfGJcVnvAk 
- Introduction To Threads (pthreads) -> https://www.youtube.com/watch?v=ldJ8WGZVXZk 
- Readme amyplant -> https://github.com/iciamyplant/Philosophers/tree/master 
- Readme de Romain -> https://github.com/Romain-ItAllDepends/Tronc-commun/blob/main/PHILOSOPHERS/README.md 
- Video de Jamshidbek Ergashev -> https://www.youtube.com/watch?v=UGQsvVKwe90 ❌  29m00
- Explication du projet par Medium -> https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2 
- https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788
- https://medium.com/swlh/the-dining-philosophers-problem-solution-in-c-90e2593f64e8
- https://nafuka11.github.io/philosophers-visualizer/ 



