#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Printer
{
    string user;
    int priority;
    string time;
    Printer *next;
};

class Queue
{
private:
    Printer *front;
    Printer *rear;

public:
    Queue();
    ~Queue();
    void queue(const string &user, int priority);
    void print();
    void display_history();
};
