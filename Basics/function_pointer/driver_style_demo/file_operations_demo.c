/*
 * file_operations_demo.c
 *
 * it Demonstrates:
 * 1. Function Pointer Declaration
 * 2. Structure of Function Pointers
 * 3. Linux Device Driver Style Design
 * 4. Runtime Function Invocation
 *
 * Similar to Linux Kernel's:
 * struct file_operations
 */

#include <stdio.h>

/*
 * Called when device is opened.
 */
int device_open(void){
    printf("Driver: Device Opened\n");

    return 0;
}

/*
 * Called when user reads data.
 */
int device_read(void){
    printf("Driver: Reading Data from Device\n");

    return 0;
}

/*
 * Called when user writes data.
 */
int device_write(void){
    printf("Driver: Writing Data to Device\n");

    return 0;
}

/*
 * Called when device is closed.
 */
int device_close(void){
    printf("Driver: Device Closed\n");

    return 0;
}

/* 
 * Each member is a function pointer.
 */
typedef struct
{
    int (*open)(void);   /* Pointer to open function  */
    int (*read)(void);   /* Pointer to read function  */
    int (*write)(void);  /* Pointer to write function */
    int (*close)(void);  /* Pointer to close function */
} FileOperations;


/* 
 * Helper Function
 * Simulates kernel accessing the driver.
 */

void simulate_kernel(FileOperations *fops) {
    printf("\nKernel Invoking Driver Operations\n\n");
    if(fops->open != NULL){
        fops->open();
    }

    if(fops->read != NULL){
        fops->read();
    }

    if(fops->write != NULL){
        fops->write();
    }

    if(fops->close != NULL){
        fops->close();
    }
}

int main(){
    /*
     * Register driver operations.
     *
     * Similar to:
     * static const struct file_operations my_fops =
     * {
     *     .open = my_open,
     *     .read = my_read,
     *     .write = my_write,
     *     .release = my_close
     * };
     */

    FileOperations driver =
    {
        .open  = device_open,
        .read  = device_read,
        .write = device_write,
        .close = device_close
    };

    /*
     * Display stored addresses.
     */
    printf("Function Addresses\n");
    printf("-----------------------------\n");

    printf("open  = %p\n", (void *)driver.open);
    printf("read  = %p\n", (void *)driver.read);
    printf("write = %p\n", (void *)driver.write);
    printf("close = %p\n", (void *)driver.close);

    /*
     * Simulate kernel calling driver.
     */
    simulate_kernel(&driver);

    return 0;
}