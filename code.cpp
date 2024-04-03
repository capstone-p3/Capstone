#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <climits>
#include<ctime>
#include <cstdlib> // for rand()

using namespace std;

// Structure to represent an entry gate queue
struct EntryGateQueue
{
    list<int> attendees; // Linked list to store attendees in the queue
};

// Function to estimate the wait time for the last person in a queue
int estimateWaitTime(int queueLength, int p)
{
    return queueLength * p;
}
 int last_gate_entry=0;
// Function to arrange attendees evenly among the gates
void arrangeAttendees(vector<EntryGateQueue> &queues, int M)
{
    int numGates = queues.size();
    cout<<numGates<<endl;
    int attendeesPerGate = M / numGates;
    int remainingAttendees = M % numGates;

    for (int i = 0; i < numGates; ++i)
    {
        queues[i].attendees.clear();

        for (int j = 0; j < attendeesPerGate; ++j)
        {
            queues[i].attendees.push_back(i + 1);
        }
    }
    if (remainingAttendees==0)last_gate_entry=numGates;
    // Distribute remaining attendees evenly among the gates
   int i;
    for ( i = 0; i < remainingAttendees; ++i)
    {
        queues[i].attendees.push_back(i + 1);
       
    
    }
     if(last_gate_entry==0)
        last_gate_entry=i;
}
void remainningattendees(vector<EntryGateQueue>& queues,int M,int n){
    int c=last_gate_entry;
    for (int i=M/2;i<M;i++){
        if (c== n)c=0;
        cout<<"attendee number "<<i+1<<" go to the gate number "<<c+1<<endl;
        queues[c].attendees.push_back(i + 1);
        c++;

        
    }

}
int random_gate(int N){
      
       return (rand() % N);
}

int main()
{
    srand(time(nullptr));
    int N, M, p; // N: number of entry gates, M: total number of attendees, p: time for a single attendee to enter any gate
    cout << "Enter the number of entry gates: ";
    cin >> N;
    cout << "Enter the total number of attendees: ";
    cin >> M;
    cout << "Enter the time for a single attendee to enter any gate (in minutes): ";
    cin >> p;

    // Initialize entry gate queues
    vector<EntryGateQueue> queues(N);

    // Randomly assign M/2 attendees to each gate
    for (int i = 0; i < M / 2; ++i)
    {
        int gateNumber = random_gate(N);
        queues[gateNumber].attendees.push_back(i + 1);
    }

    // Display the time for the last attendee to        enter each gate after arranging the first M/2 attendees randomly
    cout << "Time for the last attendee to enter each gate after arranging the first M/2 attendees randomly:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "Gate " << (i + 1) << ": " << estimateWaitTime(queues[i].attendees.size(), p) << " minutes" << endl;
    }

    // Arrange attendees evenly among the gates
    arrangeAttendees(queues, M / 2);

    // Display the time for the last attendee to enter each gate after arranging
    cout << "Time for the last attendee to enter each gate after arranging the first M/2 attendees evenly:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "Gate " << (i + 1) << ": " << estimateWaitTime(queues[i].attendees.size(), p) << " minutes" << endl;
    }

    cout<<"for remaining M/2 attendees"<<endl;
    remainningattendees(queues,M,N);

    return 0;
}
