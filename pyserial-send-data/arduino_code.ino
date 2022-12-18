int led1 = 6;
int led2 = 9;
int led3 = 11;

int btn1 = 3;
int btn2 = 4;

bool b1Pressed = false;
bool b2Pressed = false;

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

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);

  leds = data;
  
  delay(1000);

  Serial.write("Ready");
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
  int b1 = digitalRead(btn1);
  int b2 = digitalRead(btn2);
  readBuffer();
  parseBuffer(); 

  digitalWrite( led1 , leds[0]);
  digitalWrite( led2 , leds[1]);
  digitalWrite( led3 , leds[2]);


  if( b1 == HIGH && !b1Pressed){
     b1Pressed = true;
     leds[0] = !leds[0];
     writeSerial();
     
  }
  if( b2 == HIGH && !b2Pressed){
    b2Pressed = true;
    leds[1] = !leds[1];
    writeSerial();
  }

  if( b1 == LOW && b1Pressed) b1Pressed = false;
  if( b2 == LOW && b2Pressed) b2Pressed = false;
}

void writeSerial()
{
    String stringData =  String(leds[0])+ ";"+String(leds[1]);
    for (int i = 0; i < stringData.length(); i++)
  {
    Serial.write(stringData[i]);   // Push each char 1 by 1 on each loop pass
  }
}
