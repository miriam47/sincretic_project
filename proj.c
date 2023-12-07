#include <stdio.h>
#include <stdlib.h>

//definirea unei structuri pentru un nod al arborelui
struct Nod{
	int key;
	struct Nod *stang;
	struct Nod *drept;
};

//definirea unei structuri pentru adaugarea unui nod nou
struct Nod *Nod_nou(int key)
{
	struct Nod *nod = (struct Nod*)malloc(sizeof(struct Nod));
	nod->key = key;
	nod->stang = nod->drept = NULL;
	return nod;
}

int main()
{
	//definirea unui arbore
	struct Nod *radacina = Nod_nou(16);	//radacina arborelui

	//definirea arborelui pe nivele
	//nivelul 1
	radacina->stang = Nod_nou(21);
	radacina->drept = Nod_nou(10);

	/*
			16
		   /  \
		  21   10
	*/

	//nivelul 2
	radacina->stang->stang = Nod_nou(19);
	radacina->stang->drept = Nod_nou(35);
	radacina->drept->stang = Nod_nou(12);
	radacina->drept->drept = Nod_nou(45);

	/*
			16
		   /  \
		  21   10
		 / \   / \
	   19  35 12  45
	*/

	//nivel 3
	radacina->stang->stang->stang = Nod_nou(6);
	radacina->drept->drept->drept = Nod_nou(9);

	/*
			16
		   /  \
		  21   10 
		 / \   / \
	   19  35 12  45
	   /           \
	  6             9
	*/

	//afisarea valorilor nodurilor
	printf("Radacina: %d\n", radacina->key);
	printf("Subarborele stang al radacinii: %d\n", radacina->stang->key);
	printf("Subarborele drept al radacinii: %d\n", radacina->drept->key);

	return 0;
}