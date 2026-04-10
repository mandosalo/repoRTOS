/* CICLO QUE: Prende leds GPIOS:2,3,4 |@r 2023 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    // FILE *led0, *led1, *led2, *led3;
    FILE *io, *iodir2, *ioval2, *iodir3, *ioval3, *iodir4, *ioval4;
    int n = 0;

    io = fopen("/sys/class/gpio/export", "w");

    // ----Configura GPIO2--------------------------
    fseek(io,0,SEEK_SET);
    fprintf(io,"%d",2); // abre el gpio2
    fflush(io);

    iodir2 = fopen("/sys/class/gpio/gpio2/direction", "w");
    fseek(iodir2,0,SEEK_SET);
    fprintf(iodir2,"out");
    fflush(iodir2);

    ioval2 = fopen("/sys/class/gpio/gpio2/value", "w");
    fseek(ioval2,0,SEEK_SET);

    // ---Configura GPIO3---------------------------
    fseek(io,0,SEEK_SET);
    fprintf(io,"%d",3); // abre el gpio3
    fflush(io);

    iodir3 = fopen("/sys/class/gpio/gpio3/direction", "w");
    fseek(iodir3,0,SEEK_SET);
    fprintf(iodir3,"out");
    fflush(iodir3);

    ioval3 = fopen("/sys/class/gpio/gpio3/value", "w");
    fseek(ioval3,0,SEEK_SET);

    // ---Configura GPIO4 – Bloque similar a GPIO2 y 3

    while(n < 4){
        fprintf(ioval2,"%d",1);
        fflush(ioval2);
        sleep(1);

        fprintf(ioval3,"%d",1);
        fflush(ioval3);
        sleep(1);

        fprintf(ioval4,"%d",1);
        fflush(ioval4);
        sleep(1);

        fprintf(ioval2,"%d",0);
        fflush(ioval2);
        sleep(1);

        fprintf(ioval3,"%d",0);
        fflush(ioval3);
        sleep(1);

        fprintf(ioval4,"%d",0);
        fflush(ioval4);
        sleep(1);

        n++;
    } // while

    fclose(io);
    fclose(iodir2);
    fclose(ioval2);
    fclose(iodir3);
    fclose(ioval3);
    fclose(iodir4);
    fclose(ioval4);

    return 0;
} // main