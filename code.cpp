#include <iostream>
#include <vector>
#include <list> // for use link list 
#include <cmath>
#include <ctime>
#include <climits> // for INT_MAX
#include <cstdlib> // for random function

using namespace std;

// Structure to represent an entry gate queue with additional information
struct EntryGateQueue {
  list<int> attendees; // Linked list to store attendees in the queue
  int estimatedWaitTime; // Estimated wait time for the last person in the queue (in minutes)
};

// Function to estimate the wait time for the last person in a queue
int estimateWaitTime(int queueLength, int p) {
  return queueLength * p;
}

// Function to suggest the queue with the shortest estimated wait time
int suggestShortestQueue(const vector<EntryGateQueue>& queues) {
  int shortestQueue = 0;
  int shortestWaitTime = INT_MAX; // Initialize with a large value
  for (int i = 0; i < queues.size(); ++i) {
    if (queues[i].estimatedWaitTime < shortestWaitTime) {
      shortestQueue = i;
      shortestWaitTime = queues[i].estimatedWaitTime;
    }
  }
  return shortestQueue;
}

// For arrange the first M/2 attendees in random gates
int random_gate(int N)
{
    return (rand() % N);
}

int main() {
  srand(time(nullptr)); // seeds the random number generator with the current time, ensuring different sequences of random numbers

  int N, M, p; // N: number of entry gates, M: total number of attendees, p: time for a single attendee to enter any gate
  cout << "Enter the number of entry gates: ";
  cin >> N;
  cout << "Enter the total number of attendees: ";
  cin >> M;
  cout << "Enter the time for a single attendee to enter any gate (in minutes): ";
  cin >> p;

  // Initialize entry gate queues with estimated wait time set to 0 initially
  vector<EntryGateQueue> queues(N);
  for (int i = 0; i < N; ++i) {
    queues[i].estimatedWaitTime = 0;
  }

  // Randomly assign M/2 attendees to each gate

  for (int i = 0; i < M / 2; ++i) {
    int gateNumber =random_gate( N);
    queues[gateNumber].attendees.push_back(i + 1);
  }

    for (int i = 0; i < N; ++i)
    {
        cout << "Gate " << (i + 1) << ": " << estimateWaitTime(queues[i].attendees.size(), p) << " minutes" << endl;
    }

  // Update estimated wait time for each queue after initial assignment
  for (int i = 0; i < N; ++i) {
    queues[i].estimatedWaitTime = estimateWaitTime(queues[i].attendees.size(), p);
  }
    
  // Simulate attendee entry and queue management
  for (int attendee = M / 2; attendee < M; ++attendee) {
    cout << "Attendee number " << attendee + 1 << " arriving." << endl;

    // Suggest the queue with the shortest estimated wait time
    int suggestedQueue = suggestShortestQueue(queues);
    cout << "Suggested queue for attendee " << attendee + 1 << ": " << suggestedQueue + 1 << endl;

    // Allow the attendee to choose a queue 
    int chosenQueue;
    cout << "Enter the chosen queue for attendee " << attendee + 1 << " (or same as suggested: " << suggestedQueue + 1 << "): ";
    cin >> chosenQueue;
    if (chosenQueue < 1 || chosenQueue > N) {
      chosenQueue = suggestedQueue; // Default to suggested queue if invalid input
      cout << "Invalid queue chosen. Defaulting to suggested queue " << chosenQueue + 1 << endl;
    }

    // Update queue information
    queues[chosenQueue - 1].attendees.push_back(attendee + 1);
    queues[chosenQueue - 1].estimatedWaitTime = estimateWaitTime(queues[chosenQueue - 1].attendees.size(), p);

    // Simulate attendee entering
    cout << " Attendee number " << attendee + 1 << " entering the stadium from queue " << chosenQueue << endl;

  }

  // Display final estimated wait times for each queue 
  for (int i = 0; i < N; ++i)
    {
        cout << "Gate " << (i + 1) << ": " << estimateWaitTime(queues[i].attendees.size(), p) << " minutes" << endl;
    }
  return 0;
}

