#define Button_Pin 12
#define LED_Pin 14

 int flashMode[3][2]={{100,100},
                      {1500,250},
                      {500,1000}};
int modeIndex=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Button_Pin,INPUT);
  pinMode(LED_Pin,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_Pin,HIGH);
delay(flashMode[modeIndex][0]);
digitalWrite(LED_Pin,LOW);
delay(flashMode[modeIndex][1]);
bool btnPressed=false;
  if(digitalRead(Button_Pin)==HIGH&&btnPressed==false){
    modeIndex+=1;
    if(modeIndex>=3)modeIndex=0;
  }
  else if(digitalRead(Button_Pin)==LOW&&btnPressed==true){
    btnPressed=false;
  }
}
