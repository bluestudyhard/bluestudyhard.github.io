package com.pokegame;
import java.util.Objects;
import java.util.Random;
public class Poke {
	String[] a = new String[53];
	String[] b = new String[53];
	String[] c = new String[14];
	String[] d = new String[14];
	String[] e = new String[53];
	String temp;
	public static void main(String[] args) {
        Poke user = new Poke();//ͨ��new�ؼ�����Ϲ����·���Pack2(),���ʵ������ȡ��ΪUser
        user.makePokeName();
        user.rondomPoke();
        user.realcombinepoke();
        user.sortPoke();
        user.printPokeName();

    }

    void makePokeName() {
        String[] cardType = {"fang", "hong", "mei", "hei"};
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                a[cnt] = cardType[i] + j + ".jpg" + "     ";
                cnt++;
            }
        }
        System.out.println("��ӡ����a");
        for (int i = 1; i <= a.length - 1; i++) {
            System.out.printf("%s", a[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
    }

    void printPokeName() {
    	System.out.println("��ӡ����c");
        for (int i = 1; i <= c.length - 1; i++) {
            System.out.printf("%s", c[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("��ӡ����d");

        for (int i = 1; i <= d.length - 1; i++) {
            System.out.printf("%s", d[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
        System.out.println("��ӡ����e");
        for (int i = 1; i <= e.length - 1; i++) {
            System.out.printf("%s", e[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
    }

    String[] rondomPoke() {
        System.arraycopy(a, 1, b, 1, 52);//������a���±�1  ���Ƶ�����b���±�1��ʼ��52����ֵ
        for (int i = 0; i < 100; i++) {
            Random r = new Random();
            // Ϊʲô����Ҫ+1�� ��Ϊrandom(52) ��[0,52]�����ֵ,�п��ܳ���0��Ȼ�����������Ļ��ͻỻ��null����Ϊ���ǵ������Ǵ�1��ʼ�ġ�����+1������������[1,52];
            int m = r.nextInt(52) + 1;
            int n = r.nextInt(52) + 1;
            //System.out.println(m+n);//������m,n Ϊ�±������
            temp = b[m];
            b[m] = b[n];
            b[n] = temp;
            //System.out.println(m+n);
        }
        System.out.println("\n");
    	System.out.println("��ӡ����b");
        for (int i = 1; i <= b.length - 1; i++) {
            System.out.printf("%s", b[i]);
            if (i % 13 == 0) {
                System.out.println(" ");
            }
        }
        System.out.println("\n");
		return b;
    }
    
    String[] realcombinepoke() {
        int a = 1;//��i �� j����ʾ�±꣬��������õ�˫ָ�뷨
        int j = 13;
        while (j <= 52) {
            //13 26 39 52
            System.arraycopy(b, a, c, 1, 13);
            sortPoke();
            System.arraycopy(d, 1, e, a, 13);// 1  14 27 40 52
            a = j + 1;//ΪʲôҪ+1������Ϊ������һ��Ҫ���и��Ƶ�Ԫ�أ��ǲ���ԭ�����������һ�������ԣ�1��Ȼ�ᵼ��e��������һ��Ϊnull��
            j += 13;
        }
		return e;
    }

    String[] sortPoke() {
        int k = 1;
        for (int i = 1; i <= a.length - 1; i++) {
            for (int j = 1; j <= c.length - 1; j++) {
                if (Objects.equals(a[i], c[j])) {
                    d[k++] = c[j];
                }
            }
        }
		return c;
    }
    
}
