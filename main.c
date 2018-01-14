#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define dlugosc_dziennika 30
#define szerokosc_dziennika 30
#define dlugosc_listy 10
#define szerokosc_listy 30
#define dlugosc_slownika 6
#define szerokosc_slownika 30

int indeks = 0;
int dziennikObecnosci[dlugosc_dziennika] = {0};
int i = 0;
int j = 0;
int k = 0;
int jot = 0;
int h = 0;
int d = 0;
int dlugosc = 0;
int p = 0;
int r = 0;
char spacja = 0;
int siadloA = 0;
int siadloB = 0;
int siadloC = 0;
int liczbaLiterowek = 0;
int liczbaDopuszczalnychLiterowek = 3;

int main(){

	char dziennik[dlugosc_dziennika][szerokosc_dziennika] = {{0},}; //tablice pochodzą oczywiscie z pliku
	char dziennik2[dlugosc_dziennika][szerokosc_dziennika] = {{0},}; //tablice pochodzą oczywiscie z pliku
	char lista[dlugosc_listy][szerokosc_listy] = {{0},}; //tablice pochodzą oczywiscie z pliku
	char slownik[dlugosc_slownika][szerokosc_slownika] = {{0},};

    //Wczytywanie dziennika
	FILE* file_1 = fopen("dziennik.txt", "r");
	char line_1[1024];
	int i=0;
	int j=0;
	if(file_1!=0) {
		char line_1[szerokosc_dziennika];
		while(fgets(line_1, szerokosc_dziennika,file_1)) {
			for(j=0;j<szerokosc_dziennika;j++){
                if(line_1[j] == '\r'|| line_1[j] == '\n'){
                    break;
                }
                    dziennik[i][j] = line_1[j];
					dziennik2[i][j] = line_1[j];
			}
			i++;
		}
	}
	else printf("BLAD");
	//Testowe wyświetlanie
	printf("-----Dziennik:-----\n");
	for(i=0;i<dlugosc_dziennika;i++){
			printf("%s\n",dziennik[i]);  //dziennik
	}
	printf("\n");
	fclose(file_1);
	//Koniec Wczytywanie Dziennika

	//Wczytywanie listy
	FILE* file_2 = fopen("lista.txt", "r");
	char line_2[1024];
	int il=0;
	int jl=0;
	if(file_2!=0) {
		char line_2[szerokosc_listy];
		while(fgets(line_2, szerokosc_listy,file_2)) {
			for(jl=0;jl<szerokosc_listy;jl++){
                if(line_2[jl] == '\r' || line_2[jl] == '\n'){
                    break;
                }
				lista[il][jl] = line_2[jl];
			}
			il++;
		}
	}
	else printf("BLAD");
	//Testowe Wyświetlanie
	printf("\n-----Lista:-----\n");
	for(il=0;il<dlugosc_listy;il++){
			printf("%s\n",lista[il]);   //lista
	}
	printf("\n");
	fclose(file_2);
	//Koniec wczytywania listy

	//Wczytywanie slownika
    FILE* file_3 = fopen("slownik.txt", "r");
    char line_3[1024];
    int is = 0;
    int js = 0;
    if (file_3 != 0) {
        char line_3[szerokosc_slownika];
        while (fgets(line_3, szerokosc_slownika, file_3)) {
            for (js = 0; js<szerokosc_slownika; js++) {
                if(line_3[js] == '\r' || line_3[js] == '\n'){
                    break;
                }
                slownik[is][js] = line_3[js];
            }
            is++;
        }
    }
    else printf("BLAD");
    //Testowe wyświetlanie
    printf("-----Slownik:-----\n");
    for (is = 0; is<dlugosc_slownika; is++) {
        printf("%s\n", slownik[is]);  //slownik
    }
    printf("\n");
    fclose(file_3);
    //Koniec Wczytywanie Slownika

    	//ZAMIANA NA MALE LITERY
		for(i = 0; i < dlugosc_listy; i++ ) {	
			for (k = 0; k < szerokosc_listy ; k++) {
	    		lista[i][k] = tolower(lista[i][k]);
			}
		}
		for (j = 0; j < dlugosc_dziennika; j++) {
			for (k = 0; k < szerokosc_dziennika; k++) {
    			dziennik[j][k] = tolower(dziennik[j][k]);
			}
		}

		for (j = 0; j < dlugosc_slownika; j++) {
			for (k = 0; k < szerokosc_slownika; k++) {
    			slownik[j][k] = tolower(slownik[j][k]);
			}
		}

	//GLOWNA PETLA
	for(i = 0; i < dlugosc_listy; i++ ) {//dla kazdej pozycji z listy
		
		indeks = 0;
		siadloA = 0;
		siadloB = 0;
		siadloC = 0;

    //Funkcja A
		for(j=0; j < szerokosc_listy; j++) {
            if (strcmp(lista[i], dziennik[j]) == 0) {
                indeks = j; //pozycja z dziennik dopasowana do listy
				siadloA = 1; //gdy znalazlem
                if(dziennikObecnosci[indeks] == 0) {
					dziennikObecnosci[indeks] = 1;
					printf("\n Osoba: %s zostala znaleziona w dzienniku jako osoba: %s.",lista[i],dziennik[j]);
					printf("\n Osoba ta znajduje sie w dzienniku na miejscu: %d.\n",indeks+1);
				}
                else {	
					printf("\n Osoba: %s jest juz na tej liscie.\n", lista[i]);
                	printf("----------------------------------------------------");
				}
                break;
            }
        } //koniec funkcji a

		if (siadloA == 1) {
	    	printf("----------------------------------------------------");
		} 
        else if (siadloA == 0) {
			siadloB=0;
	     	//Funkcja B
	        //PRZESZUKIWANIE POD KATEM LITEROWEK
	    	for (j = 0; j < dlugosc_dziennika; j++) {
	    		for(k = 0; k < szerokosc_dziennika; k++) {
	    			if (lista[i][k] != dziennik[j][k]) {
	    				liczbaLiterowek += 1;
	    			}
	    		}
	    		//ZAPYTANIE O DOPASOWANIE DO POZYCJI Z DZIENNIKA
	    		if (liczbaLiterowek < liczbaDopuszczalnychLiterowek && liczbaLiterowek !=0) { //czyli max 2 literowki
					char odpowiedz;					
					printf("\n Czy chcesz dopasowac %s do: %s",lista[i],dziennik[j]);
					printf("\n    (WPISZ t JESLI TAK)  ");
					scanf(" %c", &odpowiedz);

					if (odpowiedz == 't') {
						indeks = j;
						if(dziennikObecnosci[indeks] == 0){		
							dziennikObecnosci[indeks] = 1;
							printf("\n Osoba ta znajduje sie w dzienniku na miejscu: %d.\n", indeks+1);
							printf("----------------------------------------------------");
						}
						else { 
							printf("\n Ta osoba jest juz na tej liscie.\n");
							printf("----------------------------------------------------");
						}
						siadloB=1;
						break;
					}
					else {
						indeks = 0;
						siadloB=0;
						printf("\n Nie znaleziono osoby :( przejde do nastepnej funkcji \n");
					}

				}
				// gdy (liczbaLiterowek > liczbaDopuszczalnychLiterowek) - siadloB=0
				liczbaLiterowek = 0;
	    	} 	//koniec funkcji b

			if (siadloB==0) { 
				//FUNKCJA C

				//rozdzielanie wyrazow
				int licznik_i = 0; int licznik_j = 0; int licznik_l = 0;
				char imie_dziennik[dlugosc_dziennika][szerokosc_dziennika] = {{0},};
				char nazwisko_dziennik[dlugosc_dziennika][szerokosc_dziennika] = {{0},};
				char imie[szerokosc_listy] = {0,};
				char nazwisko[szerokosc_listy] = {0,};
				char imie_slownik[dlugosc_slownika][szerokosc_slownika] = {{0},};
				char zdrobnienie_slownik[dlugosc_slownika][szerokosc_slownika] = {{0},};

				while (!isspace(lista[i][licznik_i]) && licznik_i<szerokosc_listy) {
					imie[licznik_i] = lista[i][licznik_i];
					licznik_i++;
				}

				int licznik_nazwisko = 0;
				for (licznik_j = licznik_i+1; licznik_j < szerokosc_listy; licznik_j++) {
					if (lista[i][licznik_j] == 0) {
						break;
					}
					nazwisko[licznik_nazwisko] = lista[i][licznik_j];
					licznik_nazwisko++;
				}

				int licznik_dziennik = 0;
				int licznik_nazwisko_dziennik = 0;
				for (licznik_dziennik = 0; licznik_dziennik < dlugosc_dziennika; licznik_dziennik++) {
					licznik_l = 0;
					while (!isspace(dziennik[licznik_dziennik][licznik_l]) && licznik_l < szerokosc_dziennika) {
						imie_dziennik[licznik_dziennik][licznik_l] = dziennik[licznik_dziennik][licznik_l];
						licznik_l++;
					}

					licznik_nazwisko_dziennik = 0;
					for (jot = licznik_l+1; jot < szerokosc_dziennika; jot++) {
						nazwisko_dziennik[licznik_dziennik][licznik_nazwisko_dziennik] = dziennik[licznik_dziennik][jot];
						licznik_nazwisko_dziennik++;
					}
				}

				int licznik_slownik = 0;
				int licznik_zdrobnienie_slownik = 0;
				for (licznik_slownik = 0; licznik_slownik < dlugosc_slownika; licznik_slownik++) {
					licznik_l = 0;
					while (!isspace(slownik[licznik_slownik][licznik_l]) && licznik_l < szerokosc_slownika) {
						imie_slownik[licznik_slownik][licznik_l] = slownik[licznik_slownik][licznik_l];
						licznik_l++;
					}

					licznik_zdrobnienie_slownik = 0;
					for (jot = licznik_l+1; jot < szerokosc_slownika; jot++) {
						zdrobnienie_slownik[licznik_slownik][licznik_zdrobnienie_slownik] = slownik[licznik_slownik][jot];
						licznik_zdrobnienie_slownik++;
					}
				}

				//sprawdzam czy imie to skrot np. m. i dopasowuje do nazwiska
				if (licznik_i < 3) {
					for (d = 0; d < dlugosc_dziennika; d++) {
						if (strcmp(nazwisko,nazwisko_dziennik[d]) == 0 && imie[0]==imie_dziennik[d][0]) {
							indeks = d;
							siadloC = 1;
							if(dziennikObecnosci[indeks] == 0) {
								dziennikObecnosci[indeks] = 1;
								printf("\n Osoba: %s %s zostala znaleziona w dzienniku jako osoba: %s.\n", imie,nazwisko,dziennik[d]);
								printf("\n Osoba ta znajduje sie w dzienniku na miejscu: %d.\n",indeks+1);
								printf("----------------------------------------------------");
							}
							else { 
								printf("\n Osoba %s %s jest juz na tej liscie.\n", imie, nazwisko);
								printf("----------------------------------------------------");
							}                                    
							break;
						}
					}
				}
				//sprawdzam czy nazwisko to skrot np. m. i dopasowuje do imienia
				else if (licznik_nazwisko < 3) {
					for (d = 0; d < dlugosc_dziennika; d++) {
						if (strcmp(imie,imie_dziennik[d]) == 0 && nazwisko[0]==nazwisko_dziennik[d][0]) {
							indeks = d;
							siadloC = 1;
							if(dziennikObecnosci[indeks] == 0) {
								dziennikObecnosci[indeks] = 1;
								printf("\n Osoba: %s %s zostala znaleziona w dzienniku jako osoba: %s.\n", imie,nazwisko,dziennik[d]);
								printf("\n Osoba ta znajduje sie w dzienniku na miejscu: %d.\n",indeks+1);
								printf("----------------------------------------------------");
							}
							else { 
								printf("\n Osoba %s %s jest juz na tej liscie.\n", imie, nazwisko);
								printf("----------------------------------------------------");
							}
							break;
						}
					}
				}
				else {
					int a = 0;
					int b = 0;
					int zdrobnienie = 0;
					char imie_bez_zdrobnienia[szerokosc_slownika] = {0,};
					for (a = 0; a < dlugosc_slownika; a++) {
							if (strcmp(imie,zdrobnienie_slownik[a]) == 0) {
								zdrobnienie = 1;
								break;
							}
					}

					if (zdrobnienie==1) {
						for (b = 0; b < dlugosc_slownika; b++) {
							imie_bez_zdrobnienia[b] = imie_slownik[a][b];
						}
						int c = 0;
						for (c = 0; c < dlugosc_dziennika; c++){
							if (strcmp(imie_bez_zdrobnienia,imie_dziennik[c]) == 0 && strcmp(nazwisko,nazwisko_dziennik[c]) == 0) {
								indeks = c;
								siadloC = 1;
								if(dziennikObecnosci[indeks] == 0) {
									dziennikObecnosci[indeks] = 1;
									printf("\n Osoba: %s %s zostala znaleziona w dzienniku jako osoba: %s.\n", imie,nazwisko,dziennik[c]);
									printf("\n Osoba ta znajduje sie w dzienniku na miejscu: %d.\n",indeks+1);
									printf("----------------------------------------------------");
								}
								else { 
									printf("\n Ta osoba jest juz na tej liscie.\n");
									printf("----------------------------------------------------");
								} 
								break;
							}
						}
					}
					else {
							siadloC = 0;
							indeks = 0;
					}
				}
				if (siadloC == 0) {

					printf("\nNie mozemy dopasowac do dziennika: %s.",lista[i]);
					printf("\n Wyswietlimy dziennik, wybierz numer wiersza w ktorym znajduje sie dana osoba, lub wypisz 0 jezeli jej nie odnajdujesz: \n");

					for(j = 0; j < dlugosc_dziennika; j++) {
						printf("%d. %s\n",j+1,dziennik2[j]);  //dziennik
					}
					printf("\n");
					scanf( "%d", &indeks );

					if (indeks==0) {
						printf("\n Ta osoba nie znajduje sie w dzienniku\n");
						printf("----------------------------------------------------");
						indeks = 0; 
					}
					else if (indeks>=1 && indeks<=dlugosc_dziennika) { 
						indeks=indeks-1; //bo wczesniej dodalismy 1, aby wyswietlac 1-30 (w rzeczywistosci jest 0-29)
						if(dziennikObecnosci[indeks] == 0) {
							dziennikObecnosci[indeks] = 1;
							printf("\n Osoba z listy znajduje sie w dzienniku na %d pozycji: %s.\n",indeks+1,dziennik[indeks]);
						}
						else {
							printf("\n Ta osoba jest juz na tej liscie.\n");
						}
						printf("----------------------------------------------------");
					}					
					else { 
						printf("\nzle wpisales liczbe :(");
						indeks = 0; 
					}
				}

			}	//koniec funkcji c
    	} //koniec funkcji b i c
 	}

	printf("\n\nMiejsca w dzienniku zidentyfikowane: ");
	for(k=0;k<dlugosc_dziennika;k++)
		printf("%d",dziennikObecnosci[k]);

 	FILE * fp;
    fp = fopen("obecnosci.txt", "w");
    for(i = 0; i < dlugosc_dziennika; i++) { // rozmiar dziennika
    	fprintf(fp, "\n%d. %s obecnosc: %d\n-------", i+1,dziennik2[i],dziennikObecnosci[i]);
    }
	fclose(fp);
	printf("\n\n--------------------- WPISANO OBECNOSCI DO DZIENNIKA ----------------------- \n");
	printf("\nWcisnij enter, aby wyjsc.\n");
	getchar();
    getchar();
}