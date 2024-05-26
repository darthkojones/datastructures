public class DynamicArray {
    private int[] array;
    private int size;
    private int capacity;

    public DynamicArray() {
        capacity = 10; // Initial capacity
        array = new int[capacity]; // Create an array with the initial capacity
        size = 0; // Initial size
    }

    public int getSize() { // Getter for size
        return size;
    }

    public void add(int value) { // Add a value to the array
        if (size == capacity) { // If the array is full, resize it
            resize(capacity * 2); // Double the capacity
        }
        array[size++] = value; // Add the value to the array
    }

    public void addAt(int index, int value) { // Add a value at a specific index
        if (index < 0 || index >= capacity) { // If the index is out of bounds
            if (index >= capacity) { // If the index is greater than the capacity
                resize(index + 1); // Resize the array to the index + 1
            } else {
                throw new IndexOutOfBoundsException("Index out of bounds");
            }
        }
        if (index >= size) { // If the index is greater than the size
            size = index + 1; // Update the size
        }
        array[index] = value; // Add the value at the index
    }

    private void resize(int newCapacity) { // Resize the array
        int[] newArray = new int[newCapacity]; // Create a new array with the new capacity
        System.arraycopy(array, 0, newArray, 0, size); // Copy the elements from the old array to the new array
        array = newArray; // Update the array reference
        capacity = newCapacity; // Update the capacity
    }

    public void print() { // Print the elements of the array and its size
        for (int i = 0; i < size; i++) { // Loop through the elements of the array
            System.out.print(array[i] + " "); // Print the element
        }
        System.out.println(); // Print a new line
        System.out.println("Size: " + size); // Print the size
    }
}
