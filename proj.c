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

//functie pentru parcurgerea in inordine a arborelui
void inordine(struct Nod* nod, int *vector, int *n)
{
	if(nod != NULL)
	{
		inordine(nod->stang, vector, n);
		vector[*n] = nod->key;
		(*n)++;

		inordine(nod->drept, vector, n);
	}
}

//functie pentru parcurgerea in preordine a arborelui
void preordine(struct Nod* nod)
{
	if(nod != NULL)
	{
		printf("%d ", nod->key);

		//traversarea subarborelui stang
		preordine(nod->stang);

		//traversarea subarborelui drept
		preordine(nod->drept);
	}
}

//afisarea arborelui pe nivele
void afisare(struct Nod *nod, int nivel)
{
	int i;

	if(nod != NULL)
	{
		afisare(nod->drept, nivel+1);

		for(i=0; i<nivel; i++)
			printf("	");

		printf("%d\n", nod->key);

		afisare(nod->stang, nivel+1);
	}
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
	
	printf("Afisare arbore: \n");
	afisare(radacina, 0);

	int vector[100]; //folosit pentru a stoca valorile din arborele care este parcurs in inordine
	int n = 0;	//nr de elemente (dupa ce se va apela functia, se va stoca in n nr de elemente din arbore)
	int i;

	inordine(radacina, vector, &n);

	printf("Parcurgerea in inordine: \n");
	for(i=0; i<n; i++)
		printf("%d ", vector[i]);
	printf("\n\n");


	printf("Parcurgere in preordine: \n");
	preordine(radacina);


	return 0;
}