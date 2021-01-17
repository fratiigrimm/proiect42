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
		nrSali = 10;
	}

	cinema(char* _codLocatie, string _nume, char* _adresa, int _nrSali) : idCinema(++id) {
		this->codLocatie = new char[strlen(_codLocatie) + 1];
		strcpy_s(codLocatie, strlen(_codLocatie) + 1, _codLocatie);
		this->nume = _nume;
		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(adresa, strlen(_adresa) + 1, _adresa);
		this->nrSali = _nrSali;
	}

	cinema(const cinema& c) : idCinema(c.idCinema) {
		this->codLocatie = new char[strlen(c.codLocatie) + 1];
		strcpy_s(codLocatie, strlen(c.codLocatie) + 1, c.codLocatie);
		this->nume = c.nume;
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
		this->nrSali = c.nrSali;
	}

	~cinema() {
		delete[] codLocatie;
		delete[] adresa;
	}

	cinema& operator=(const cinema& c) {
		this->codLocatie = new char[strlen(c.codLocatie) + 1];
		strcpy_s(codLocatie, strlen(c.codLocatie) + 1, c.codLocatie);
		this->nume = c.nume;
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(adresa, strlen(c.adresa) + 1, c.adresa);
		this->nrSali = c.nrSali;
		return *this;
	}

	friend ostream& operator<<(ostream& out, cinema c) {
		out << "ID: " << c.idCinema << endl;
		out << "Cod Locatie: " << c.codLocatie << endl;
		out << "Nume Cinematograf: " << c.nume << endl;
		out << "Adresa: " << c.adresa << endl;
		out << "Numar sali: " << c.nrSali << endl;
		return out;
	}

	int getNrSali() {
		return nrSali;
	}

	string getNume() {
		return nume;
	}

	void setNrSali(int _nrSali) {
		if (_nrSali < 0) {
			cout << "Error ! Numarul de sali nu poate fi negativ ..." << endl;
		}
		else {
			nrSali = _nrSali;
		}
	}

	void setAdresa(char* _adresa) {
		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);
	}
};

class sala {
private:
	const int idSala;   // numarul de sala
	int nrLocuriTotal;
	int* locuri; // vector int alocat dinamic in functie de numarul de locuri
	bool isOcupat;  // verifica la emiterea biletului daca locul este ocupat
	static int id;
public:
	sala() : idSala(++id) {
		nrLocuriTotal = 100;
		locuri = NULL;
		isOcupat = false;
	}
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

void Meniu(cinema c) {
	cout << "***   Aplicatie POO v1 ***" << endl;
	cout << "**************************" << endl;
	cout << "***** Bine ati venit la cinema " << c.getNume() << " ******** " << endl;
	cout << endl << endl << endl;
	cout << "1. Rezervare " << endl;
	cout << "2. Program filme " << endl;
	cout << "3. Detalii cinematograf " << endl;
	cout << endl;
	cout << "Alegeti? 1, 2 sau 3" << endl;
	int alegere = 0;
	cin >> alegere;
	if (alegere == 1) {
		cout << "Under construction ... "<< endl;
	}
	if (alegere == 2) {
		cout << "Under construction ... " << endl;
	}
	if (alegere == 3) {
		cout << endl;
		cout << c << endl;
	}
	else
	{
		cout << "Error ! Alegere invalida" << endl;
	}
}

int main() {
	char idLocatie[4] = "AB2";
	char adresa[20] = "Bd. Magheru nr. 101";
	cinema c(idLocatie, "Scala", adresa, 2);
	Meniu(c);
}