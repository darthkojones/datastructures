public class Main {
    public static void main(String[] args) {
        // 1. Create a dynamic array
        DynamicArray arr = new DynamicArray();

        // 2. Print out all the elements of the array and its size
        System.out.println("Initial array:");
        arr.print();

        // 3. Add elements with values 100 and 200 to the array
        arr.add(100);
        arr.add(200);

        // 4. Print out all the elements of the array and its size
        System.out.println("After adding 100 and 200:");
        arr.print();

        // 5. Add element 500 at location 5
        arr.addAt(5, 500);

        // 6. Print out all the elements of the array and its size
        System.out.println("After adding 500 at location 5:");
        arr.print();

        // 7. Add element 2100 at location 21
        arr.addAt(21, 2100);

        // 8. Print out all the elements of the array and its size
        System.out.println("After adding 2100 at location 21:");
        arr.print();
    }
}
