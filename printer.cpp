#include "printer.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue()
{
    while (front)
    {
        Printer *temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::queue(const string &user, int priority)
{

    time_t now = time(0);
    string time = ctime(&now);

    Printer *job = new Printer;
    job->user = user;
    job->priority = priority;
    job->time = time;
    job->next = nullptr;

    if (!front)
    {
        front = rear = job;
    }
    else
    {
        rear->next = job;
        rear = job;
    }
}

void Queue::print()
{
    if (!front)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Printer *high_job = front;
    Printer *prev_job = nullptr;
    Printer *current_job = front;

    while (current_job->next)
    {
        if (current_job->next->priority > high_job->priority)
        {
            high_job = current_job->next;
            prev_job = current_job;
        }
        current_job = current_job->next;
    }

    if (prev_job)
    {
        prev_job->next = high_job->next;
    }
    else
    {
        front = high_job->next;
    }

    cout << " User - " << high_job->user << ", Priority - " << high_job->priority << endl;

    delete high_job;
}

void Queue::display_history()
{
    cout << "History:" << endl;

    Printer *current_job = front;
    while (current_job)
    {
        cout << "User - " << current_job->user << ", Priority - " << current_job->priority << ", Time - " << current_job->time;
        current_job = current_job->next;
    }
}
