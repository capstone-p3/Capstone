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

int random_gate(int N) {
  static int gates[N]; 
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
    int N, p;  // N: number of entry gates, p: time for a single attendee to enter any gate
    // Initialize entry gate queues
    vector<EntryGateQueue> queues(N);

   
    return 0;
}
