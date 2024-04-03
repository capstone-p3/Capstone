#include <iostream>
#include <algorithm>
#include <list> // for linked list STL
#include <vector> // for creating vector of stucture

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

int main()
{
    int N, p;  // N: number of entry gates, p: time for a single attendee to enter any gate
    // Initialize entry gate queues
    vector<EntryGateQueue> queues(N);

   
    return 0;
}
