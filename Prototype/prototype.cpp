#include <iostream>
#include <string>

using namespace std;

class Item{
    protected:
        string nome;
        int raridade;
    public:
        Item(string Nome, int Raridade): nome(Nome), raridade(Raridade){}
        Item(const Item& It) : nome(It.nome), raridade(It.raridade){}
        virtual ~Item() = default;

        virtual Item* clonar() = 0;
        virtual void usar() = 0;

};

class Cura : public Item{
    public:
        Cura(string Nome, int Raridade) : Item(Nome, Raridade){}
        Cura(const Cura& It) : Item(It){}

        Item* clonar() override{
            return new Cura(*this);
        }
         void usar() override{
            cout << "10 pontos de vida almentados" << endl;
         }
};

class Agilidade : public Item{
    public:
        Agilidade(string Nome, int Raridade) : Item(Nome, Raridade){}
        Agilidade(const Agilidade& It) : Item(It){}

        Item* clonar() override{
            return new Agilidade(*this);
        }
        void usar() override{
        cout << "Agilidade adiquirida, mais 10 pontos almentados" << endl;
        }
};

int main(){

        Item* PocaoCura = new Cura("Pocao de cura", 2);
        Item* PocaoAgilidade = new Agilidade("Pocao de agilidade", 3);

        Item* bandagem = PocaoCura->clonar();
        Item* espinafre = PocaoAgilidade->clonar();

        PocaoCura->usar();
        PocaoAgilidade->usar();
        bandagem->usar();
        espinafre->usar();

    delete PocaoCura;
    delete PocaoAgilidade;
    delete bandagem;
    delete espinafre;

    return 0;
}