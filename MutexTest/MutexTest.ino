/*
   Example of a FreeRTOS mutex
   https://www.freertos.org/Real-time-embedded-RTOS-mutexes.html
*/

// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>


// Include mutex support
#include <semphr.h>

/*
   Declaring a global variable of type SemaphoreHandle_t

*/
SemaphoreHandle_t mutex;

int globalCount = 0;

void setup() {

  Serial.begin(115200);

  /**
       Create a mutex.
       https://www.freertos.org/CreateMutex.html
  */
  mutex = xSemaphoreCreateMutex();
  if (mutex != NULL) {
    Serial.println("Mutex created");
  }

  /**
     Create tasks
  */
  xTaskCreate(TaskMutex, // Task function
              "Task1", // Task name for humans
              128, 
              30, // Task parameter
              1, // Task priority
              NULL);

  xTaskCreate(TaskMutex, "Task2", 128, 30, 1, NULL);

}

void loop() {}

void TaskMutex(void *pvParameters)
{
  TickType_t delayTime = *((TickType_t*)pvParameters); // Use task parameters to define delay

  for (;;)
  {
    /**
       Take mutex
       https://www.freertos.org/a00122.html
    */
    if (xSemaphoreTake(mutex, 10) == pdTRUE)
    {
      Serial.print("volledig");
      
      xSemaphoreGive(mutex);
    }

    vTaskDelay(delayTime / portTICK_PERIOD_MS);
  }
}
