// Python with arduino Servo control 

#include <Servo.h>

String value;
const char delim = ';';
int data[3]; //Holds most recent angles for servo

char buffer[3];
int bufferIndex;

int dataIndex = 0;

Servo servo;
int servoPos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1); 

  servo.attach (A2); // Declare Servo Object (A2 = "Resume" pin)
   
  bufferIndex = 0;   
  servo.write(180);
  delay(2000);
  servo.write(0);
  delay(2000);
  
} // Setup End

void readBuffer()
{
  if (Serial.available())
  {
    char c = Serial.read();
    buffer[bufferIndex] = c;
    bufferIndex++;

  }
}

void parseBuffer()
{
  
  
  if (buffer[bufferIndex-1] == ';')
  {
    
    buffer[bufferIndex-1] = '\0';

    int newData = atoi(buffer);
       
    servo.write( newData);   
    
    dataIndex++;
    dataIndex %= sizeof(data)/sizeof(*data);
        
    bufferIndex = 0;

    for (int j = 0; j < sizeof(buffer)/sizeof(*buffer); j++)
    {
      buffer[j] = 1;
    }
    
  }
}

void loop() {
   
  // put your main code here, to run repeatedly:
  readBuffer();
  parseBuffer(); 

}
