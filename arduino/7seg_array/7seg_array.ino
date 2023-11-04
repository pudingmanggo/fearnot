unsigned long before = 0;
unsigned long before1 = 0;
const unsigned int led[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int bt1 = 10;
int bt1state[2];
int cnt = 0;
const unsigned int num[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 1, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 1, 1, 0}
};

void display_init(){
  for(int x=0;x<8;x++){
    pinMode(led[x], OUTPUT);
  }
  pinMode(bt1, INPUT);
}

void display_clear(){
  for(int x=0;x<8;x++){
    digitalWrite(led[x], LOW);
  }
}

void display_number(int n){
  if(0<=n&&n<=9){
    for(int x=0;x<8;x++){
      digitalWrite(led[x], num[n][x]==1?HIGH:LOW);
    }
  }
}
void setup() {
  Serial.begin(115200);
  display_init();
}
int number = 0;
void loop() {
  unsigned long now = millis();
  bt1state[0] = digitalRead(bt1);

  if(Serial.available()){
    char userInput = Serial.read();
    if('0'<=userInput && userInput <= '9'){
      int num = userInput - '0';

      display_clear();
      display_number(num);
    }
  }
  //int num = millis()%1000/100;
  
  //display_clear();
  // if(number!=millis()%1000/100){
  //   number = millis()%1000/100;
  //   display_clear();
  //   display_number(number);
  //   Serial.println(number);
  //   delay(100);
  // }
    number = millis()%1000/100;
    //display_clear();
    display_number(number);
  if(bt1state[0]==HIGH&&bt1state[1]==LOW&&now-before>=100){
    cnt++;
    display_number(5);
    Serial.println(cnt);
    before = now;
    bt1state[1]=HIGH;
  }
  if(bt1state[0]==LOW&&bt1state[1]==HIGH&&now-before>=100){
    bt1state[1]=LOW;
    before=now;
  }

}
