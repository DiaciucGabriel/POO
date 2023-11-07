#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Casa {
private:
    std::string firmaConstructie;
    std::string adresa;
    int numarEtaje;
    int numarApartamente;

public:
    Casa(const std::string& firma, const std::string& adresa, int etaje, int apartamente)
        : firmaConstructie(firma), adresa(adresa), numarEtaje(etaje), numarApartamente(apartamente) {}

    // Funcție pentru setarea datelor
    void seteazaDate(const std::string& firma, const std::string& adresa, int etaje, int apartamente) {
        firmaConstructie = firma;
        this->adresa = adresa;
        numarEtaje = etaje;
        numarApartamente = apartamente;
    }

    // Funcție pentru modificarea datelor
    void modificaDate(const std::string& firma, const std::string& adresa, int etaje, int apartamente) {
        if (!firma.empty())
            firmaConstructie = firma;
        if (!adresa.empty())
            this->adresa = adresa;
        if (etaje > 0)
            numarEtaje = etaje;
        if (apartamente > 0)
            numarApartamente = apartamente;
    }

bool operator<(const Casa& altaCasa) const {
    if (adresa == altaCasa.adresa) {
        // Sortăm după numărul de etaje în caz de adrese egale
        return numarEtaje < altaCasa.numarEtaje;
    }
    // Sortăm mai întâi după adresa în ordine alfabetică
    return adresa < altaCasa.adresa;
}

    // Funcții pentru acces la date
    std::string getFirmaConstructie() const {
        return firmaConstructie;
    }

    std::string getAdresa() const {
        return adresa;
    }

    int getNumarEtaje() const {
        return numarEtaje;
    }

    int getNumarApartamente() const {
        return numarApartamente;
    }
};

int main() {
    // Exemplificare
    Casa casa1("Firma1", "Strada A", 4, 8);
    Casa casa2("Firma2", "Strada B", 2, 10);
    Casa casa3("Firma3", "Strada C", 190, 12);
    Casa casa4("Firma4", "Strada A", 1, 12);
    Casa casa5("Firma5", "Strada B", 1, 10);

    // Vector de case
    std::vector<Casa> caseVec;
    caseVec.push_back(casa1);
    caseVec.push_back(casa2);
    caseVec.push_back(casa3);
    caseVec.push_back(casa4);
    caseVec.push_back(casa5);

    // Sortăm vectorul de case
    std::sort(caseVec.begin(), caseVec.end());

    // Afișăm casele în ordinea sortată
    std::cout << "Casele sortate dupa numarul de etaje + adresa:\n";
    for (const auto& casa : caseVec) {
        std::cout << "Firma de constructie: " << casa.getFirmaConstructie()
                  << ", Adresa: " << casa.getAdresa()
                  << ", Numar etaje: " << casa.getNumarEtaje()
                  << ", Numar apartamente: " << casa.getNumarApartamente() << "\n";
    }

    return 0;
}
