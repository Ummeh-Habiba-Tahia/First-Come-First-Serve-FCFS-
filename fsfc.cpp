#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	// waiting time for the first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n; i++)
		wt[i] = bt[i-1] + wt[i-1];
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
				int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	// Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	// Display processes along with all details
	cout << "Processes " << " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << processes[i] << "\t\t" << bt[i] << "\t "
			<< wt[i] << "\t\t " << tat[i] << endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// Get the number of processes from the user
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;

	// Process IDs
	int processes[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the process ID for process " << i + 1 << ": ";
		cin >> processes[i];
	}

	// Burst time of all processes
	int burst_time[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the burst time for process " << processes[i] << ": ";
		cin >> burst_time[i];
	}

	findavgTime(processes, n, burst_time);
	return 0;
}
