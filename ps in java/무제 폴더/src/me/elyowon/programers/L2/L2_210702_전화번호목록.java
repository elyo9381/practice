package me.elyowon.programers.L2;


import java.util.*;
import java.util.stream.Collectors;

/**
 *
 */
public class L2_210702_전화번호목록 {



    public boolean solution(String[] phone_book) {
        HashSet<String> hashSet = (HashSet<String>) Arrays.stream(phone_book).collect(Collectors.toSet());

        for (String key : hashSet)
            for (int j = 1; j <= key.length() - 1; j++) {

                if (hashSet.contains(key.substring(0, j))) return false;
            }
        return true;
    }

}
