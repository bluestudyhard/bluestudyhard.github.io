package com.finalwork;


public class Text2 {
    public static void main(String[] args) {
        student s1 = new student("����", "1.75", "63kg", "2114100314", "�������", 1002, 120);
        student s2 = new student("�л���", "1.76", "64kg", "2114100306", "�������", 1002, 120);
        student s3 = new student("sha��", "1.77", "65kg", "2114100328", "�������", 1004, 120);
        student s4 = new student("�л���", "1.78", "66kg", "2114100328", "�������", 1005, 120);
        student s5 = new student("ɵ��", "1.79", "67kg", "2114100306", "�������", 1003, 120);
        student all[] = new student[]{s1, s2, s3, s4, s5};
        for (int i = 0; i < 5; i++) {
            all[i].dislpay();
        }
    }
}

class people {
    String name, height, weight;

    people(String s1, String s2, String s3) {
        name = s1;
        height = s2;
        weight = s3;
    }

}

class student extends people {
    private
    String name, number, subject;
    double totalscore, avgscore, Mscore, Escore;

    student(String s1, String s2, String s3, String number, String project, double M, double E) {
        super(s1, s2, s3);
        this.number = number;
        this.subject = project;
        this.Mscore = M;
        this.Escore = E;
        this.name = s1;
    }

    double getAvgscore() {
        avgscore = Mscore + Escore / 2;
        return avgscore;
    }

    double getTotalscore() {
        totalscore = Escore + Mscore;
        return totalscore;
    }

    void dislpay() {
        String ss = "ѧ��Ϊ��" + number + "����Ϊ��" + name + "���Ϊ��" + height + "����Ϊ��" + weight + "רҵΪ:" + subject + "��ѧ�ɼ���Ӣ��ɼ��ֱ�Ϊ: " + Mscore + ", " + Escore + "�ܳɼ�Ϊ" + getTotalscore() + "ƽ���ɼ�Ϊ" + getAvgscore();
        System.out.println(ss);
    }
}