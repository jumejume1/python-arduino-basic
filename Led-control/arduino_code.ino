int led1 = 6;
int led2 = 9;
int led3 = 11;

String value;
const char delim = ';';
int data[3]; 

char buffer[3];
int bufferIndex=0;

int dataIndex = 0;

int* leds;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);

  leds = data;
  
  delay(1000);
}

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
       
    data[dataIndex] = newData; 
    
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
  // put your main code here, to run repeatedly:
  readBuffer();
  parseBuffer(); 

  digitalWrite( led1 , leds[0]);
  digitalWrite( led2 , leds[1]);
  digitalWrite( led3 , leds[2]);
}
