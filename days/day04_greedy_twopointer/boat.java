import java.util.*;

public class boat {
    public static int solution(int[] people, int limit) {
        int count = 0;
        Arrays.sort(people);
        int ridx = people.length - 1;
        int lidx = 0;

        while (lidx < ridx) {
            if (people[ridx] + people[lidx] <= limit) {
                lidx++;
            }
            ridx--;
            count++;
        }

        if (lidx == ridx) {
            count++;
        }

        return count;
    }

    public static void main(String[] args) {
        int[] people = {70, 50, 80, 50};
        int limit = 100;
        System.out.println(solution(people, limit)); // 3
    }



}
