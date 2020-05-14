#include<stdio.h>
#include<queue>
#include<string>
#include<cstring>
#include<iostream>
#include<typeinfo>

/**
 * 猫狗队列
 * https://www.nowcoder.com/practice/8a7e04cff6a54b7095b94261d78108f5?tpId=101&tqId=33168&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
 */

using namespace std;

class Pet {
private:
    int id;
public:
    Pet(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    virtual ~Pet() {

    }
};

class Cat : public Pet {
public:
    Cat(int id) : Pet(id) {

    }
};

class Dog : public Pet {
public:
    Dog(int id) : Pet(id) {

    }
};

class MyPet {
private:
    int timestamp;
    Pet *pet;
public:
    MyPet(int timestamp, string type, int id) {
        this->timestamp = timestamp;
        if (type == "cat")
            this->pet = new Cat(id);
        else
            this->pet = new Dog(id);
    }

    int getTimeStamp() {
        return timestamp;
    }

    Pet *getPet() {
        return pet;
    }
};

queue<MyPet *> catQueue, dogQueue;

void pollCat() {
    while (!catQueue.empty()) {
        MyPet *myPet = catQueue.front();
        cout << "cat " << myPet->getPet()->getId() << endl;
        catQueue.pop();
    }
}

void pollDog() {
    while (!dogQueue.empty()) {
        MyPet *myPet = dogQueue.front();
        cout << "dog " << myPet->getPet()->getId() << endl;
        dogQueue.pop();
    }
}

void pollAll() {
    while (!catQueue.empty() && !dogQueue.empty()) {
        MyPet *myPet = NULL;
        if (catQueue.front()->getTimeStamp() < dogQueue.front()->getTimeStamp()) {
            myPet = catQueue.front();
            catQueue.pop();
        } else {
            myPet = dogQueue.front();
            dogQueue.pop();
        }
        Pet *pet = myPet->getPet();
        if (typeid(Cat) == typeid(*pet))
            cout << "cat ";
        else
            cout << "dog ";
        cout << pet->getId() << endl;
    }
    pollCat();
    pollDog();
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    string o;
    string type;
    int id;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> o;
        if (o == "add") {
            cin >> type >> id;
            MyPet *myPet = new MyPet(cur++, type, id);
            if (type == "cat") {
                catQueue.push(myPet);
            } else {
                dogQueue.push(myPet);
            }
        } else if (o == "pollDog")
            pollDog();
         else if (o == "pollCat")
            pollCat();
         else if (o == "pollAll")
            pollAll();
         else if (o == "isDogEmpty") {
            if (dogQueue.empty()) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (o == "isCatEmpty") {
            if (catQueue.empty()) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            if (dogQueue.empty() && catQueue.empty()) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}