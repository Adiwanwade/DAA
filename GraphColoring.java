import java.util.*;

public class GraphColoring {

    private int[][] a;
    private int[] Colors;
    private int numE;
    private int numC;

    public GraphColoring(int[][] a, int numC) {
        this.a = a;
        this.numE = a.length;
        this.numC = numC;
        this.Colors = new int[numE];
    }

    public boolean VColor(int exam, int color) {
        for (int i = 0; i < numE; i++) {
            if (a[exam][i] == 1 && Colors[i] == color) {
                return false;
            }
        }
        return true;
    }

    public boolean schedule(int exam) {
        if (exam == numE) {
            return true; 
        }

        for (int color = 1; color <= numC; color++) {
            if (VColor(exam, color)) {
                Colors[exam] = color;

                if (schedule(exam + 1)) {
                    return true;
                }

                Colors[exam] = 0; 
            }
        }

        return false;
    }

    public boolean scheduleExams() {
        return schedule(0);
    }

    public void print() {
        for (int i = 0; i < numE; i++) {
            System.out.println("Exam " + (i + 1) + " is scheduled at time slot " + Colors[i]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of exams: ");
        int numE = scanner.nextInt();
        int[][] a = new int[numE][numE];

        System.out.println("Enter the adjacency matrix (1 for conflict, 0 for no conflict):");
        for (int i = 0; i < numE; i++) {
            for (int j = 0; j < numE; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        System.out.print("Enter the number of time slots (colors): ");
        int numC = scanner.nextInt();

        GraphColoring scheduler = new GraphColoring(a, numC);
        if (scheduler.scheduleExams()) {
            System.out.println("Exams scheduled successfully:");
            scheduler.print();
        } else {
            System.out.println("Failed to schedule exams.");
        }

        scanner.close();
    }
}
