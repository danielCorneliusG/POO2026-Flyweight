#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Item {
    private:
        string nome;
        int peso;
    public:
        Item(string Nome, int Peso) : nome(Nome), peso(Peso) {}
        virtual ~Item() = default;

        string getNome() {
            return this->nome;
        }
        int getPeso() {
            return this->peso;
        }
};

class Personagem {
    private:
        string nome;
        int nivel;
        vector<Item*> inventario;
    public:
        Personagem(string Nome, int Nivel) : nome(Nome), nivel(Nivel) {}
        virtual ~Personagem() = default;

        string getNome() { return this->nome; }
        int getNivel()   { return this->nivel; }

        void adicionarItem(Item* i) {
            inventario.push_back(i);
        }

        vector<Item*> getInventario() {
            return inventario;
        }
};

// ── Interface Iterator ────────────────────────────────────
class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual Personagem* next() = 0;
        virtual ~Iterator() = default;
};

// ── Iterator concreto ───────────────────────────────────────────
class IteratorRpg : public Iterator {
    private:
        vector<Personagem*>& personagens;
        size_t indicePersonagem = 0;
    public:
        IteratorRpg(vector<Personagem*>& Vector) : personagens(Vector) {}

        bool hasNext() override {
            return indicePersonagem < personagens.size();
        }

        Personagem* next() override {
            return personagens[indicePersonagem++];
        }
};


class Rpg {
    private:
        vector<Personagem*> personagens;
    public:
        void adicionarPersonagem(Personagem* p) {
            personagens.push_back(p);
        }

        Iterator* criarIterator() {
            return new IteratorRpg(personagens);
        }
};


int main() {
    Rpg rpg;

    Personagem* p1 = new Personagem("Aragorn", 10);
    p1->adicionarItem(new Item("Espada", 5));
    p1->adicionarItem(new Item("Escudo", 8));

    Personagem* p2 = new Personagem("Gandalf", 99);
    p2->adicionarItem(new Item("Cajado", 3));

    rpg.adicionarPersonagem(p1);
    rpg.adicionarPersonagem(p2);

    Iterator* it = rpg.criarIterator();

    while (it->hasNext()) {
        Personagem* p = it->next();
        cout << p->getNome() << " (nivel " << p->getNivel() << ")\n";

        for (Item* item : p->getInventario()) {
            cout << "  | " << item->getNome()
                 << " (peso " << item->getPeso() << ")\n";
        }
    }

    delete it;
    return 0;
}