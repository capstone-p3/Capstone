#include <iostream>
#include <algorithm>
#include <list> // for linked list STL
#include <vector> // for creating vector of stucture
#include <cstdlib> // for random function

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



// remainning m/2 attendees arrangement
void remainningattendees(vector<EntryGateQueue> &queues, int M, int n)
{
    int c = last_gate_entry;
    for (int i = M / 2; i < M; i++)
    {
        if (c == n)
            c = 0;
        cout << "attendee number " << i + 1 << " go to the gate number " << c + 1 << endl;

        queues[c].attendees.push_back(i + 1);

        c++;
    }
}

int random_gate(int N, int M) {
   int gates[N]; 
  for (int i = 0; i < N; ++i) {
    gates[i] = i + 1; 
  }

  int numAttendees = M / 2;
  for (int i = 0; i < numAttendees; ++i) {
    int j = rand() % (i + 1); // generate random numbers between 0 and i
    if (j < i) {
      swap(gates[i], gates[j]); 
    }
  }
  return gates[numAttendees - 1]; 
}

int main()
{
    int N, p, M;  // N: number of entry gates, p: time for a single attendee to enter any gate, M: totsl umber of attendees
    // Initialize entry gate queues
    cin >> N >> p >> M ;
    
    vector<EntryGateQueue> queues(N);

      // Randomly assign M/2 attendees to each gate
    for (int i = 0; i < M / 2; ++i)
    {
        int gateNumber = random_gate(N,M);
        queues[gateNumber].attendees.push_back(i + 1);
    }


     // Display the time for the last attendee to enter each gate after arranging the first M/2 attendees randomly
    cout << "Time for the last attendee to enter each gate after arranging the first M/2 attendees randomly:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << "Gate " << (i + 1) << ": " << estimateWaitTime(queues[i].attendees.size(), p) << " minutes" << endl;
    }

    return 0;
}
