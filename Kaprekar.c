#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void Entier_Tab(int n, int tab[]){
	
	for(int i=3;i>=0;i--){
		tab[i] = n%10;
		n /= 10;
	}
}

int Tab_Entier(int tab[]){
	int res=0;
	for(int i=0;i<4;i++){
		res = res*10+tab[i];
	}

	return res;
}

int Tab_Entier_Inverse(int tab[]){
	int res=0;
	for(int i=3;i>=0;i--){
		res = res*10+tab[i];
	}

	return res;
}

void Tab_Ord_Cr(int org[]){
	int t;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(org[j]<=org[i]){
				t = org[j];
				org[j] = org[i];
				org[i] = t;
			}
		}
	}
}

void affiche_tab(int tab[]){

	for(int i=0;i<4;i++){
		printf("%d\t", tab[i]);
	}
	printf("\n");


}

void Point_Fix(int n, int suite[]){

	int s = 0;
	int big,sml;
	
	while(s != n){
		s=n;
		Entier_Tab(n,suite);	
		affiche_tab(suite);
		Tab_Ord_Cr(suite);
		affiche_tab(suite);
	
		big = Tab_Entier(suite);
        	printf("Le grand est : %d \n", big);	
		sml = Tab_Entier_Inverse(suite);
		printf("Le petit est : %d \n", sml);

		n = big - sml;
		printf("La difference est donc : %d \n", n);
	}

	printf("Le point fix est donc : %d \n", n);

}

int init_nbr(){
	int tab[4];
	srand(time(NULL));
	for(int i=0;i<4;i++){
		tab[i] = rand()%10;
		for(int j=0;j<i;j++){
			if(tab[i] == tab[j]){
				i--;
			}
		}
	}

	return Tab_Entier(tab);
}

void Point_Fix_Ale(int suite[]){

	int s = 0;
	int big,sml;
	int n = init_nbr();
	
	while(s != n){
		s=n;
		Entier_Tab(n,suite);	
		affiche_tab(suite);
		Tab_Ord_Cr(suite);
		affiche_tab(suite);
	
		big = Tab_Entier(suite);
        	printf("Le grand est : %d \n", big);	
		sml = Tab_Entier_Inverse(suite);
		printf("Le petit est : %d \n", sml);

		n = big - sml;
		printf("La difference est donc : %d \n", n);
	}

	printf("Le point fix est donc : %d \n", n);

}

int main(){
	
	int suite[4];	
	Point_Fix_Ale(suite);
}
