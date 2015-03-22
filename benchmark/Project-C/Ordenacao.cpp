#include "Header.h"

void shellsort(int vetor[], int tamanho){
	int elem, i, j, gap, k;
	int a[5] = { 9, 5, 3, 2, 1 };
	for (k = 0; k < 5; k++){
		gap = a[k];
		for (i = gap; i < tamanho; i++){
			elem = vetor[i];
			for (j = i - gap; (j >= 0) && (elem < vetor[j]); j = j - gap){
				vetor[j + gap] = vetor[j];
			}
			vetor[j + gap] = elem;
		}
	}
}
void shellsortdesc(int vetor[], int tamanho){
	int elem, i, j, gap, k;
	int a[5] = { 9, 5, 3, 2, 1 };
	for (k = 0; k < 5; k++){
		gap = a[k];
		for (i = gap; i< tamanho; i++){
			elem = vetor[i];
			for (j = i - gap; (j >= 0) && (elem>vetor[j]); j = j - gap){
				vetor[j + gap] = vetor[j];
			}
			vetor[j + gap] = elem;
		}
	}
}
void shellsort2(int vetor[], int tamanho, int incremento[], int teto){
	int i, j, gap, k, elem;

	for (k = 0; k < teto; k++){
		gap = incremento[k];
		for (i = gap; i < tamanho; i++){
			elem = vetor[i];
			for (j = i - gap; (j >= 0) && (elem < vetor[j]); j = j - gap){
				vetor[j + gap] = vetor[j];
			}
			vetor[j + gap] = elem;
		}
	}
}
void shellsort2desc(int vetor[], int tamanho, int incremento[], int teto){
	int i, j, gap, k, elem;

	for (k = 0; k < teto; k++){
		gap = incremento[k];
		for (i = gap; i<tamanho; i++){
			elem = vetor[i];
			for (j = i - gap; (j >= 0) && (elem>vetor[j]); j = j - gap){
				vetor[j + gap] = vetor[j];
			}
			vetor[j + gap] = elem;
		}
	}
}
void selectionsort(int vet[], int TAM){
	int i, Min, aux, j;

	for (i = 0; i < TAM - 1; i++){
		Min = i;
		for (j = i + 1; j < TAM; j++){
			if (vet[j] < vet[Min]){
				aux = vet[Min];
				vet[Min] = vet[j];
				vet[j] = aux;
			}
		}
	}
}
void selectionsortdesc(int vet[], int TAM){
	int i, Min, aux, j;

	for (i = 0; i < TAM - 1; i++){
		Min = i;
		for (j = i + 1; j<TAM; j++){
			if (vet[j] > vet[Min]){
				aux = vet[Min];
				vet[Min] = vet[j];
				vet[j] = aux;
			}
		}
	}
}

void PreencheVetorRandom(int vet[], int tam){
	for (int i = 0; i < tam; i++)
		vet[i] = rand();
}
void PreencheVetorCrescente(int vet[], int tam){
	for (int i = 0; i < tam; i++)
		vet[i] = i;
}
void PreencheVetorDecrescente(int vet[], int tam){
	for (int i = 0; i < tam; i++)
		vet[i] = tam - i;
}
void MostraVetor(int vet[], int tam){
	for (int i = 0; i < tam; i++)
	{
		cout << "\n " << vet[i];
	}
}
double calculaTempo(clock_t Ticks[]){
	return (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
}
void IniciaCronometro(clock_t Ticks[]){
	Ticks[0] = clock();
}
void FinalizaCronometro(clock_t Ticks[]){
	Ticks[1] = clock();
}

void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;

	tmp = (int*)malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}

	mid = vecSize / 2;

	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] <= vec[j]) {
			tmp[k] = vec[i++];
		}
		else {
			tmp[k] = vec[j++];
		}
		++k;
	}

	if (i == mid) {
		while (j < vecSize) {
			tmp[k++] = vec[j++];
		}
	}
	else {
		while (i < mid) {
			tmp[k++] = vec[i++];

		}
	}

	for (i = 0; i < vecSize; ++i) {
		vec[i] = tmp[i];
	}

	free(tmp);
}
void mergeSort(int vec[], int vecSize) {
	int mid;

	if (vecSize > 1) {
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
}
void heapsort(int a[], int n)
{
	int i = n / 2, pai, filho, t;
	while (true)
	{
		if (i > 0)
		{
			i--;
			t = a[i];
		}
		else
		{
			n--;
			if (n == 0)
				return;
			t = a[n];
			a[n] = a[0];
		}

		pai = i;

		//Primeiro será feita a comparação com o filho da esquerda.
		filho = i * 2;

		while (filho < n)
		{
			//Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
			if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
				filho++;
			if (a[filho] > t)
			{
				a[pai] = a[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else
				break;
		}
		a[pai] = t;
	}
}
void gnomesort(int vet[], int size){
	int i, tmp;
	for (i = 1; i < size;){
		if (vet[i - 1] <= vet[i])
			++i;
		else{
			tmp = vet[i];
			vet[i] = vet[i - 1];
			vet[i - 1] = tmp;
			--i;
			if (i == 0)
				i = 1;
		}
	}
}
void insertionsort(int vetor[], int tamanho){
	int i, j, elem;
	for (i = 1; i < tamanho; i++){
		elem = vetor[i];
		for (j = i - 1; (j >= 0) && (elem < vetor[j]); j--){
			vetor[j + 1] = vetor[j];
		}
		vetor[j + 1] = elem;
	}
}
void insertionsortdesc(int vetor[], int tamanho){
	int i, j, elem;
	for (i = 1; i< tamanho; i++){
		elem = vetor[i];
		for (j = i - 1; (j >= 0) && (elem>vetor[j]); j--){
			vetor[j + 1] = vetor[j];
		}
		vetor[j + 1] = elem;
	}
}
void quicksort(int *v, int esq, int dir){
	int i, j, pivo, aux;
	i = esq;
	j = dir;
	pivo = v[(i + j) / 2];
	//Particionando o Vetor
	do {
		while (v[i] < pivo && i < dir) { i++; }
		while (v[j] > pivo && j > esq) { j--; }
		if (i <= j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);

	if (esq < j) quicksort(v, esq, j);
	if (dir > i) quicksort(v, i, dir);
}
void bubblesort(int vetor[], int tamanho){
	int i, j, aux = 0;
	for (i = tamanho - 1; i > 0; i--){
		for (j = 0; j < i; j++) {
			if (vetor[j] > vetor[j + 1]) {
				int temp;
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}

}
void bubblesortdesc(int vetor[], int tamanho){
	int i, j, aux = 0;
	for (i = tamanho - 1; i > 0; i--){
		for (j = 0; j < i; j++) {
			if (vetor[j] < vetor[j + 1]) {
				int temp;
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}

}


void OrdenacaoMain(){
	int tam = 15000;
	int vet[15000];
	int	vet2[15000];
	double resultado = 0;
	int vezes = 10;
	clock_t Ticks[2];

	/* -------------------------------------
	Vetor Random
	------------------------------------- */
	cout << "-------------------------------------------------------\n";
	cout << "   Ordenacao de vetores preenchidos randomicamente \n";
	cout << "-------------------------------------------------------\n";

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		bubblesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Bubble Sort       | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		insertionsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Insertion Sort    | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		quicksort(vet, 0, tam - 1);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Quick Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		mergeSort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Merge Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		gnomesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Gnome Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorRandom(vet, tam);
		IniciaCronometro(Ticks);
		heapsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo HeapSort          | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	cout << "\n\n";

	/* -------------------------------------
	  Vetor Decrescente
	  ------------------------------------- */
	cout << "-------------------------------------------------------\n";
	cout << "   Ordenacao de vetores preenchidos em ordem crescente \n";
	cout << "-------------------------------------------------------\n";

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		bubblesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Bubble Sort       | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		insertionsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Insertion Sort    | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		quicksort(vet, 0, tam - 1);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Quick Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		mergeSort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Merge Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		gnomesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Gnome Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorCrescente(vet, tam);
		IniciaCronometro(Ticks);
		heapsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo HeapSort          | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	cout << "\n\n";

	/* -------------------------------------
	Vetor Crescente
	------------------------------------- */
	cout << "-------------------------------------------------------\n";
	cout << " Ordenacao de vetores preenchidos em ordem descrescente \n";
	cout << "-------------------------------------------------------\n";

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		bubblesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Bubble Sort       | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		insertionsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Insertion Sort    | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		quicksort(vet, 0, tam - 1);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Quick Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		mergeSort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Merge Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		gnomesort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo Gnome Sort        | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	for (int i = 0; i < vezes; i++){
		PreencheVetorDecrescente(vet, tam);
		IniciaCronometro(Ticks);
		heapsort(vet, tam);
		FinalizaCronometro(Ticks);
		resultado += calculaTempo(Ticks);
	}
	cout << "Metodo HeapSort          | Tempo gasto: " << resultado / vezes << " ms.\n";
	resultado = 0;

	cout << "\n\n";

}