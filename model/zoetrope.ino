

//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)

int dir = 4;  // connect pin 12 to dir
int stp = 5;  //connect pin 13 to step
int rst = 7;  // connect pin 12 to dir
int led = 6;  // connect pin 12 to dir
int a = 0;     //  gen counter
int l=0;
int dl = 10;

void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);     
  pinMode(rst, OUTPUT);   
  pinMode(led, OUTPUT); 
  digitalWrite(rst, HIGH);
  digitalWrite(led, LOW);
}


void loop() 
{
  
    a++;
    l++;
    digitalWrite(stp, HIGH);
    if (l>=20){
       digitalWrite(led, HIGH); 
       l=0;  
     }    
    delay(1);        
    digitalWrite(stp, LOW);
    digitalWrite(led, LOW);   

    
      
    delay(dl);              

    if (dl>3 && a>20) {
      if (dl>20) dl=dl-2;
      dl--;
      a = 0;
    }
  }
