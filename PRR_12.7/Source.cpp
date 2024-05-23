#include <iostream>
#include <fstream>
#include <cmath>
#include "Windows.h"

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SList {
public:
    Node* head;

    SList() {
        head = nullptr;
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool isSquareOrCube(int n) {
    int root = round(sqrt(n));
    int root2 = round(cbrt(n));
    return root * root == n || root2 * root2 * root2 == n;
}

SList createListFromFile(const string& filename) {
    SList numbers;
    ifstream file(filename);
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

SList createSquareCubeList(const SList& numbers) {
    SList result;
    Node* temp = numbers.head;
    while (temp != nullptr) {
        if (isSquareOrCube(temp->data)) {
            result.push_back(temp->data);
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    SList numbers = createListFromFile("text.txt");
    cout << "Вхідний список: ";
    numbers.print();
    SList squareCubeNumbers = createSquareCubeList(numbers);
    cout << "Вихідний список: ";
    squareCubeNumbers.print();
    return 0;
}