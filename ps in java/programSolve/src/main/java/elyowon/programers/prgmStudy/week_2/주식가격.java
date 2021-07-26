package elyowon.programers.prgmStudy.week_2;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Stock {
    Integer price;

    public Stock(Integer price) {
        this.price = price;
    }

    public Integer getPrice() {
        return price;
    }
}

public class 주식가격 {
    public int[] solution(int[] prices) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < prices.length; i++) {
            int count = 0;
            for (int j = i + 1; j < prices.length; j++) {
                count++;
                if (prices[i] > prices[j]) break;
            }
            result.add(count);
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    public int[] solution2(int[] prices) {
        List<Stock> stocksByday = Arrays.stream(prices).mapToObj(Stock::new).collect(Collectors.toList());

        List<Integer> result = declinePrice(stocksByday);

        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    public List<Integer> declinePrice(List<Stock> stocksByday) {
        int size = stocksByday.size();
        return IntStream.range(0,size).map(i -> getDeclineCount(stocksByday,i)).boxed().collect(Collectors.toList());
    }

    private int getDeclineCount(List<Stock> stocksByday,int i) {
        int count = 0;
        int size = stocksByday.size();
        for (int j = i + 1; j < size; j++) {
            count++;
            if (isDeclineBefore(stocksByday.get(i).getPrice(),stocksByday.get(j).getPrice())) break;
        }
        return count;
    }

    private boolean isDeclineBefore(Integer price,Integer price2) {
        return price > price2;
    }
}