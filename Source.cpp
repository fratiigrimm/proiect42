#include <iostream>
using namespace std;

// toate id-urile sunt constante int autoincrementabile
/* un cinema (clasa cinema) are un numar de sali (clasa sala), in care ruleaza filme (clasa film),
	clientii (clasa client) cumpara un bilet (clasa bilet) ..
                                 */ 

enum rating {
	general,
	parental,  //acord parental
	restricted,
	xx
};

class cinema {
private:
	const int idCinema;
	char* codLocatie;  // alfanumeric, unic
	string nume;
	char* adresa;
	int nrSali;
	static int id;
public:
	cinema(): idCinema(++id) {
		codLocatie = NULL;
		nume = "";
		adresa = NULL;
		nrSali = 0;
	}
};

class sala {
private:
	const int idSala;   // numarul de sala
	int nrLocuriTotal;
	int* locuri; // vector int alocat dinamic in functie de numarul de locuri
	bool isOcupat;  // verifica la emiterea biletului daca locul este ocupat
	static int id;
};

class film {
private:
	const int idFilm;
	string numeFilm;
	rating ratingFilm;
	sala* sali; //???   vector alocat dinamic de sali - salile in care ruleaza un film
	int* oreRulare; // vector int alocat dinamic (ex: 10 13 17)
	static int id;
public:
	film():idFilm(id) {
		numeFilm = "";
		ratingFilm = general;
		oreRulare = NULL;
	}
};

class client {
private:
	const int idClient;
	string nume;
	int age;   // pentru verificare access in functie de rar
	bool hasCard;  // pentru aplicare discount la emiterea biletului
	static int id;
};

class bilet : public cinema, film, client, sala {   // informatiile din bilet se preiau din toate clasele precedente (nume film, nr Sala etc)
private:
	const int idBilet;
	int ziEmitere;
	int lunaEmitere;
	static int anEmitere; // va fi doar 2021
	int rand;
	int loc;
	float pret;
	static int id;
	// pentru afisarea datei pe bilet se vor concatena zi+luna+an
};

int cinema::id = 0;
int film::id = 10;
int sala::id = 0;
int client::id = 1000;
int bilet::id = 100;
int bilet::anEmitere = 2021;

int main() {

}