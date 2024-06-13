import java.util.Scanner;

class Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnAroundTime;

    Process(int id, int burstTime) {
        this.id = id;
        this.burstTime = burstTime;
        this.waitingTime = 0;
        this.turnAroundTime = 0;
    }
}

public class FCFS {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = scanner.nextInt();

        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter burst time for process " + (i + 1) + ": ");
            int burstTime = scanner.nextInt();
            processes[i] = new Process(i + 1, burstTime);
        }

        calculateWaitingTime(processes);
        calculateTurnAroundTime(processes);
        printProcesses(processes);
        printAverageTimes(processes);

        scanner.close();
    }

    private static void calculateWaitingTime(Process[] processes) {
        processes[0].waitingTime = 0;

        for (int i = 1; i < processes.length; i++) {
            processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        }
    }

    private static void calculateTurnAroundTime(Process[] processes) {
        for (Process process : processes) {
            process.turnAroundTime = process.waitingTime + process.burstTime;
        }
    }

    private static void printProcesses(Process[] processes) {
        System.out.println("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

        for (Process process : processes) {
            System.out.println(process.id + "\t\t" + process.burstTime + "\t\t" + process.waitingTime + "\t\t" + process.turnAroundTime);
        }
    }

    private static void printAverageTimes(Process[] processes) {
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        for (Process process : processes) {
            totalWaitingTime += process.waitingTime;
            totalTurnAroundTime += process.turnAroundTime;
        }

        double avgWaitingTime = (double) totalWaitingTime / processes.length;
        double avgTurnAroundTime = (double) totalTurnAroundTime / processes.length;

        System.out.println("\nAverage Waiting Time: " + avgWaitingTime);
        System.out.println("Average Turnaround Time: " + avgTurnAroundTime);
    }
}
