/*
 * hello-1.c Cel mai simplu modul kernel.
 */
#include <linux/module.h>   /* Necesar in toate modulele */
#include <linux/kernel.h>   /* Necesar pt. KERN_INFO */

int init_module(void){

    printk(KERN_INFO "Hello world 1.\n");
    /*
     * Returnarea altei valori decat 0 inseamna ca modulul nu 
     *  poate fi incarcat.
     */
    return 0;
}

void cleanup_module(void){
    
    printk(KERN_INFO "Goodby world 1.\n");
}
