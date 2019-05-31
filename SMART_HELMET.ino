#include <math.h>
const int x_out = A1; /* connect x_out of module to A1 of UNO board */
const int y_out = A2; /* connect y_out of module to A2 of UNO board */
const int z_out = A3; /* connect z_out of module to A3 of UNO board */

#include <SoftwareSerial.h>   //bluetooth module
SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

void setup() {
  Serial.begin(9600); 

   // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");

  
}

void loop() {
  int x_adc_value, y_adc_value, z_adc_value; 
  double x_g_value, y_g_value, z_g_value;
 
  x_adc_value = analogRead(x_out); /* Digital value of voltage on x_out pin */ 
  y_adc_value = analogRead(y_out); /* Digital value of voltage on y_out pin */ 
  z_adc_value = analogRead(z_out); /* Digital value of voltage on z_out pin */ 
  
  
  x_g_value = ( ( ( (double)(x_adc_value * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in x-direction in g units */ 
  y_g_value = ( ( ( (double)(y_adc_value * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in y-direction in g units */ 
  z_g_value = ( ( ( (double)(z_adc_value * 5)/1024) - 1.80 ) / 0.330 ); /* Acceleration in z-direction in g units */ 

 
  Serial.print("x = ");
  Serial.print( x_g_value);
  Serial.print("\t\t");
  Serial.print("y = ");
  Serial.print(y_g_value);
  Serial.print("\t\t");
  Serial.print("z = ");
  Serial.print(z_g_value);
  Serial.print("\t\t");
  

  
  if((x_g_value>=3||x_g_value<=-3)||(y_g_value>=3||y_g_value<=-3)||(z_g_value>=3||z_g_value<=-3)){
    Serial.print("impact is detected");
  }
 
  Serial.print("\n");
   delay(1000);


   //bluetootModule
BT.available();
  // if text arrived in from BT serial...

  if((x_g_value>=3||x_g_value<=-3)||(y_g_value>=3||y_g_value<=-3)||(z_g_value>=3||z_g_value<=-3)){
    BT.println("impact is detected");
  }
    
   
      
}
