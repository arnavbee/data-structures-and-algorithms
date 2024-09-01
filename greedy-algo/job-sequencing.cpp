struct Job {
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is completed before or on deadline
};

// Comparator function to sort jobs by descending profit
bool comparitor(Job max, Job min) {
    return max.profit > min.profit;
}

// Function to perform job scheduling
pair<int, int> JobScheduling(Job jobs[], int n) {
    // Sort jobs in descending order of profit
    sort(jobs, jobs + n, comparitor);

    int profit = 0;        // Total profit gained
    int maxTime = 0;       // Maximum deadline among all jobs
    int jobCount = 0;      // Number of jobs that can be done

    // Find the maximum deadline to determine the size of the timeslots array
    for (int i = 0; i < n; i++) {
        maxTime = max(maxTime, jobs[i].dead);
    }

    // Create a timeslots vector initialized to false (no job scheduled)
    vector<int> timeslots(maxTime + 1, false);

    // Iterate through each job in the sorted list
    for (int i = 0; i < n; i++) {
        Job currJob = jobs[i]; // Current job being considered

        // Check available timeslots from the job's deadline downwards
        for (int t = currJob.dead; t > 0; t--) {
            // If the timeslot is free, schedule the job
            if (!timeslots[t]) {
                timeslots[t] = true; // Mark timeslot as occupied
                profit += currJob.profit; // Add job's profit to total profit
                jobCount++; // Increment the count of scheduled jobs
                break; // Exit loop since job is scheduled
            }
        }
    }

    // Return the total number of jobs scheduled and the total profit
    return {jobCount, profit};
}
