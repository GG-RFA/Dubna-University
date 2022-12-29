package com.company;

class Авторы {
    int	Кодавтора;
    String	ФИОавтора;
    static String title;

    static void setTitle (String s) { title =  s; }

    Авторы (String s) {
        String r[] =  s.split(", ");
        Кодавтора = Integer.parseInt(r[0]);
        ФИОавтора = r[1];
    }

    @Override
    public String toString() {
        String r[] = title.split(", ");
        return "|"+r[0]+"|"+r[1]+"|";
    }

    public static void show (Авторы s[]) {
        System.out.println (s[0]);
        for (Авторы p: s){
            System.out.format("|%02d|%-25s|\n", p.Кодавтора,   p.ФИОавтора);
        }
    }
}

class Книги {
    String ISBN;
    int	Кодавтора;
    String	Названиекниги;
    String	Цена;
    static String title;

    static void setTitle (String s) { title = s; }

    Книги (String s) {
        String r[] =  s.split(", ");
        ISBN = r[0];
        Кодавтора = Integer.parseInt(r[1]);
        Названиекниги = r[2];
        Цена = r[3];
    }

    @Override
    public String toString() {
        String r[] = title.split(", ");
        return  "|" + r[0] + "|" + r[1] + "|" + r[2] + "|" + r[3] + "|";
    }

    public static void show (Книги s[]) {
        System.out.println (s[0]);
        for (Книги k: s) {
            System.out.format ("|%3s|%02d|%-16s|%-5s| \n", k.ISBN, k.Кодавтора, k.Названиекниги, k.Цена);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String[] АвторыКниг={
                "Код автора, ФИО автора",
                "01, Иванов Сергей Степанович",
                "02, Сидорова Ольга Юрьевна",
                "03, Петров Иван Петрович"
        };

        String[] КнигиДляПокупки={
                "ISBN, Код автора, Название книги, Цена",
                "978-5-388-00003, 01, Самоучитель JAVA, 300руб.",
                "978-5-699-58103, 02, JAVA за 21 день, 600руб.",
                "758-3-004-87105, 03, Сопромат, 350руб.",
                "758-3-057-37854, 01, Механика, 780руб.",
                "675-3-423-00375, 03, Физика, 450руб."
        };

// Создаем массива объектов класса "Авторы"
        Авторы.setTitle(АвторыКниг[0]);
        Авторы WS[] =  new Авторы[АвторыКниг.length-1];
        for (int i = 0; i < WS.length;  i++)
            WS[i] = new Авторы (АвторыКниг[i+1]);

// Выводим массива объектов класса "Авторы"
        Авторы.show(WS);

// Создаем массива объектов класса "Книги"
        Книги.setTitle (КнигиДляПокупки[0]);
        Книги KL[] = new Книги[КнигиДляПокупки.length-1];
        for (int i=0;  i<KL.length; i++)
            KL[i] = new Книги(КнигиДляПокупки[i+1]);

// Выводим массива объектов класса "Книги"
        Книги.show(KL);
    }
}

