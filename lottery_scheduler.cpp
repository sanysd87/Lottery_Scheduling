#include <iostream>
#include <vector>   //uses vector to store the processes
#include <ctime>    //uses time aspect to ensure increased randomness

class process   //process class as per assignment requirement(s)
{
public:
    int pid;    //process identifier pid 
    int tickets;    //number of tickets bought by customer

    process(int id, int num_tickets) : pid(id), tickets(num_tickets) {}     //initializer list
};

class scheduler     //scheduler class as per assignment requirements
{
private:
    std::vector<process> processes;     //vector to store processes
    int total_tickets = 0;

public:
    void add_process(process p) {
        //function that adds processes with push_back and also updates total tickets
        processes.push_back(p);
        total_tickets += p.tickets;
    }

    process* next_process() {
        //this member function determines which process wins randomly
        int winning_ticket = std::rand() % total_tickets + 1;
        int curr_ticket = 0;

        //loop below iterates through the processes, summing up process tickets to find a ticket whos process contains the winning ticket
        for (process& process : processes) {
            curr_ticket += process.tickets;
            if (curr_ticket >= winning_ticket) {
                return &process;
            }
        }
        return nullptr;     //just in case no process is found (should not happen) 
    }

    //First Come First Serve scheduling method
    //process* next_process_fcfs() {
    //    if (!processes.empty()) {   //if condition checking if vector is empty
    //        //returns a pointer to the front of the process
    //        return &processes.front();
    //    }
    //    return nullptr;
    //}
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));      //generates a number with current time involved so that numbers are different each time run

    scheduler scheduler;        //creates an instance of the scheduler

    //adds the three processes to the scheduler
    scheduler.add_process(process(1, 33));
    scheduler.add_process(process(2, 26));
    scheduler.add_process(process(3, 29));

    // Using FCFS scheduling
    //process* next_process_fcfs = scheduler.next_process_fcfs();

    /*if (next_process_fcfs != nullptr) {
        std::cout << "process " << next_process_fcfs->pid << " is selected by FCFS." << std::endl;
    }*/

    //selects the next process and winner of the lottery
    process* next_process = scheduler.next_process();

    if (next_process != nullptr) {      //if condition ensuring if next_process returns nullptr, it won't go through
        std::cout << "process " << next_process->pid << " wins the lottery!" << std::endl;      //prints which process wins
    }

    return 0;
}
