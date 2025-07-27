#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class HashTable {
public:
    static const int SIZE = 10;
    node* table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    // Hash Function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Create new node
    node* createNode(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    // Insert data into hash table
    void insert(int key) {
        int index = hashFunction(key);
        node* newnode = createNode(key);

        if (table[index] == NULL) {
            table[index] = newnode;
        } else {
            node* temp = table[index];
            while (temp->next != NULL) {
                if (temp->data == key) return; // Avoid duplicate
                temp = temp->next;
            }
            if (temp->data != key) // Final check before inserting at end
                temp->next = newnode;
        }
    }

    // Search key
    bool search(int key) {
        int index = hashFunction(key);
        node* temp = table[index];

        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // Display hash table
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(20);
    ht.insert(5);

    ht.display();

    int searchKey = 25;
    if (ht.search(searchKey)) {
        cout << searchKey << " found in the table." << endl;
    } else {
        cout << searchKey << " not found in the table." << endl;
    }

    return 0;
}

