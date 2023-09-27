#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class List {
private:
    int count;
    Node *head;

public:
    List() {
        count = 0;
        head = nullptr;
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void push(int data) {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        if (isEmpty()) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }

        count++;
    }



    void removeDuplicates() {
        if (head == nullptr) {
            return;
        }

        Node *current = head;

        while (current != nullptr) {
            Node *runner = current;

            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node *duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                    count--;
                } else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }

    void reverse() {
        if (head == nullptr) {
            return;
        }

        // Aponta para o topo da lista
        Node *current = head;

        Node *previous = nullptr;
        Node *next = nullptr;

        while (current != nullptr) {
            // Guarda o próximo nó
            next = current->next;

            // Inverte o ponteiro do nó atual
            current->next = previous;

            // Atualiza os ponteiros
            previous = current;

            // Atualiza o nó atual
            current = next;
        }

        // Atualiza o topo da lista
        head = previous;
    }

    void print() {
        Node *current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void splitIntoTwo(List &list1, List &list2) {
        if (head == nullptr || count == 0) {
            // Lista original vazia, não há nada para dividir.
            return;
        }

        int initial_size = count;
        int new_size = initial_size / 2;

        Node *current = head;
        Node *previous = nullptr;

        // Percorre até a metade da lista
        int count = 0;
        while (count < new_size) {
            previous = current;
            current = current->next;
            count++;
        }

        // Divide a lista
        if (previous != nullptr) {
            // Atualiza o próximo do último nó da primeira lista para nullptr
            previous->next = nullptr;

            // Configura a cabeça da segunda lista
            list2.head = current;
            list2.count = initial_size - new_size;
        } else {
            // Se a primeira lista for vazia, ajusta apenas a segunda lista
            list2.head = current;
            list2.count = initial_size;
        }

        // Configura a cabeça e o tamanho da primeira lista
        list1.head = head;
        list1.count = new_size;

        // Limpa a lista original
        head = nullptr;
        count = 0;
    }
};

int main() {
    List list;
    List list1;
    List list2;


    list.push(1);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(5);
    list.push(5);
    list.push(5);

    cout << "Tamanho da lista: " << list.size() << endl;
    cout << "Lista antes de ser filtrada:" << endl;
    list.print();

    list.removeDuplicates();

    cout << endl;

    cout << "Tamanho da lista: " << list.size() << endl;
    cout << "Lista depois de ser filtrada:" << endl;
    list.print();

    cout << endl;

    list.reverse();

    cout << "Lista depois de ser invertida:" << endl;
    list.print();

    cout << endl;

    list.splitIntoTwo(list1, list2);

    cout << "Lista 1:" << endl;
    list1.print();

    cout << endl;

    cout << "Lista 2:" << endl;
    list2.print();

    cout << endl;

    return 0;
}