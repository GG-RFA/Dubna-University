import java.util.Random;
import java.util.concurrent.Semaphore;

class App
{
    public static void main(String[] args) {
        System.out.println("Парковка");
        Parking parking = new Parking(10);
        parking.Info();
        Semaphore sem = new Semaphore(parking.amountOfParkingSpace);
        for (int i = 0; i < 25; i++) {
            Car temp = new Car(sem, i, parking);
            temp.start();
        }

        try { Thread.sleep(100); }
        catch (Exception e) {}
        parking.isOpen = false;
        parking.Info();
    }
}

class Parking
{
    public int amountOfParkingSpace;
    public int freeParkingSpace;
    public boolean isOpen;

    public Parking(int amountOfParkingSpace) 
    {
        this.amountOfParkingSpace = amountOfParkingSpace;
        this.freeParkingSpace = amountOfParkingSpace;
        isOpen = true;
    }

    public void Info()
    {
        System.out.println("Парковочных мест: " + amountOfParkingSpace);
        System.out.println("Свободных парковочных мест: " + freeParkingSpace);
    }
}

class Car extends Thread
{
    Semaphore sem;
    int carId;
    boolean onParking;
    Parking parking;

    public Car(Semaphore sem, int carId, Parking parking)
    {
        this.sem = sem;
        this.carId = carId;
        this.parking = parking;
        onParking = false;
    }

    public void run()
    {
        try 
        {
            sem.acquire();
            GetPlace();
            LeavePlace();
            sem.release();
        } 
        catch (Exception e) { }
    }

    public void GetPlace()
    {
        if (!parking.isOpen) return;
        System.out.println("Машина под номером: " + carId + " заняла место на парковке");
        onParking = true;
        parking.freeParkingSpace--;
    }

    public void LeavePlace()
    {
        if (!onParking) return;
        int rnd = new Random().nextInt(2000);
        try { sleep(rnd); }
        catch (Exception ex) { }
        System.out.println("Машина под номером: " + carId + " простояла на парковке " + rnd + " секунд");
        System.out.println("Машина под номером: " + carId + " покинула парковку!");
        onParking = false;
        parking.freeParkingSpace++;
    }
}