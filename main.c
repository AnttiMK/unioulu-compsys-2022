/* C Standard library */
#include <stdio.h>

/* XDCtools files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CCC26XX.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/UART.h>

/* Board Header files */
#include "Board.h"
#include "wireless/comm_lib.h"
#include "sensors/opt3001.h"
#include "sensors/mpu9250.h"
#include <functions/buttons/buttons.h>
#include <functions/buzzer/buzzer.h>
#include <functions/movementSensor/movementSensor.h>
#include <functions/messaging/uart.h>
#include <functions/night/night.h>

/* Task */
#define STACKSIZE 2048
Char sensorTaskStack[STACKSIZE];
Char uartTaskStack[STACKSIZE];

// JTKJ: Teht�v� 3. Tilakoneen esittely
// JTKJ: Exercise 3. Definition of the state machine
enum state { WAITING = 1, DATA_READY };
enum state programState = WAITING;

// JTKJ: Teht�v� 3. Valoisuuden globaali muuttuja
// JTKJ: Exercise 3. Global variable for ambient light

Int main(void) {
    // Task variables

    // Initialize board
    Board_initGeneral();
    Init6LoWPAN();

    //i2c k�ytt��n otto
    Board_initI2C();
    // JTKJ: Teht�v� 4. Ota UART k�ytt��n ohjelmassa
    // JTKJ: Exercise 4. Initialize UART
    //Board_initUART();

    UART_registerTask();
    Movement_registerTask();

    //Y�-taskin rekist�r�inti

    night_registerTask();

    // Rekister�id��n painonapit ja niiden taskit
    Buttons_registerTasks();

    // Rekister�id��n summeri
    //Buzzer_register();


    /* Sanity check */
    System_printf("Hello world!\n");
    System_printf("tickperiod is %d\n", Clock_tickPeriod);
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
