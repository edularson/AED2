struct no {
	int info;
	no *link;
};

no *inicializaPilha(no *L) {
	return NULL;
}

void imprimePilha(no *L) {
	no *P;
	P = L;	
	
	printf("\n Imprime PILHA: \n");	
	while(P != NULL) {
		cout << P->info << " ";	
		P = P->link;
	}	
}

no *PUSH(no *L, int x) {
	no *N;

	N = new no;
	N->info = x;

    N->link = L;
	
	L = N;
	return (L);
}

no *POP(no *L, int *n) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		AUX = L;
		L = L->link;
		delete AUX;
	}
	else{
		*n = 0;
	}
	return (L);
}

