public class main2
{
    public static void main(String args[])
    {
        Address a = new Address(7, "Bangalore", "Karnataka", "India");
        Student s = new Student("1RV18CS002", "Aarush", a);
        College c = new College("RVCE", a);
        Employee e = new Employee("18CS", "Aarush", a);

        System.out.println(a);
        System.out.println("---------------------");
        System.out.println(s);
        System.out.println("---------------------");
        System.out.println(c);
        System.out.println("---------------------");
        System.out.println(e);
    }
}

class Address
{
    private int streetNum;
    private String city;
    private String state;
    private String country;

    public Address(int snum, String city, String state, String country)
    {
        this.streetNum = snum;
        this.city = city;
        this.state = state;
        this.country = country;
    }
    public String toString() {
        String cs = String.format("%s, %s\n%s, %s",
                this.streetNum,
                this.city,
                this.state,
                this.country);
        return cs;
    }
}

class Student
{
    private String usn;
    private String name;
    private Address addr;
    public Student(String u, String n, Address a)
    {
        this.usn = u;
        this.name = n;
        this.addr = a;
    }
    public String toString() {
        String cs = String.format("USN: %s\nName: %s\nAddress:%s",
                this.usn,
                this.name,
                this.addr.toString()
        );
        return cs;
    }
}

class College
{
    private String name;
    private Address addr;

    public College(String n, Address a)
    {
        this.name = n;
        this.addr = a;
    }
    public String toString() {
        String cs = String.format("Name: %s\nAddress: %s",
                this.name,
                this.addr.toString());
        return cs;
    }
}

class Employee
{
    private String empId;
    private String name;
    private Address addr;

    public Employee(String e, String n, Address a)
    {
        this.empId = e;
        this.name = n;
        this.addr = a;
    }
    public String toString() {
        String cs = String.format("Employee Id: %s\nName: %s\nAddress:%s",
                this.empId,
                this.name,
                this.addr.toString()
        );
        return cs;
    }
}
