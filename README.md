           # Crearea modulelor kernel in linux.

## Ce este un modul kernel?
    Kernelul face legatura intre hardware si software. Kernelul este un program alcatuit din module si poate fi extins cu alte module. In urmatoarele randuri v-om scrie un modul kernel pe un sistem Fedora 24. Pentru acest lucru este nevoie de instalarea programului kernel-devel.

        sudo dnf install kernel-devel
``` C
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
```
Trebuie creata fila Makefile:
``` Make
obj-m += hello-1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

Rularea programului se executa in directorul curent cu comanda:

        make

