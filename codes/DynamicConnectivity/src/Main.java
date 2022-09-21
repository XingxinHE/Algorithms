import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {

    /*
     * 3 different files
     */
    public static String[] paths = new String[]{"../res/tinyUF.txt", "../res/mediumUF.txt", "../res/largeUF.txt"};

    /*
     * Test function. Use QuickFind, QuickUnion, and WeightedUnion to process files and record their time.
     *
     * @param uf the base class object for polymorphism
     * @throws IOException if the files broken
     */
    public static void test(UnionFindBase uf) throws IOException {
        System.out.println("------" + uf.getClass() + " performance report------ ");
        for (String path : paths) {
            long startTime = System.nanoTime();
            Path filePath = Paths.get(path);
            Scanner scanner = new Scanner(filePath);
            int n = scanner.nextInt();
            uf.construct(n);        //👈since the object will be used few times. so use a method to
            // construct rather than constructor one time initialization
            while (scanner.hasNext()) {
                int p = scanner.nextInt();
                int q = scanner.nextInt();
                if (uf.connected(p, q)) continue;  //👈see if connected
                uf.union(p, q);                    //👈union
            }

            System.out.println("There are " + uf.amount + " components.");
            double elapsedTime = (System.nanoTime() - startTime) / 1000000.0;
            System.out.println("Processing \"" + filePath.getFileName() + "\" : " + elapsedTime + "ms");
        }
        System.out.println();
    }

    /*
     * The main method.
     */
    public static void main(String[] args) throws IOException {
        test(new QuickFind());
        test(new QuickUnion());
        test(new WeightedUnion());
    }
}
