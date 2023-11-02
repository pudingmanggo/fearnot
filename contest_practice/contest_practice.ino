#include <LiquidCrystal_I2C.h>

const int bt1 = 2;
const int bt2 = 3;
const int bt3 = 4;
int bt1state[2];
int bt2state[2];
int bt3state[2];
int result[5]={0, 0, 0, 0, 0};
int num = -1;
int snum = -1;
int ans = -1;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void up(){
  num++;
  num%=5;
  lcd.setCursor(0, 0);
  lcd.print("Current num:");
  lcd.print(num+1);
  lcd.print("   ");
}
void sel(){
  snum = num;
  lcd.setCursor(0, 1);
  lcd.print("Snum:");
  lcd.print(snum+1);
  lcd.print(" Ans:");
  for(int i=0;i<3;i++){
    delay(900);
    lcd.print(".");
  }
  delay(2000);
  lcd.setCursor(11, 1);
  randomSeed(analogRead(0));
  ans = random(5);
  lcd.print(ans+1);
  lcd.print("  ");
  lcd.setCursor(0, 0);
  if(snum==ans){
    lcd.print("Congratulations!");
    result[snum]++;
  }else{
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("F");
    delay(500);
    lcd.print("a");
    delay(500);
    lcd.print("i");
    delay(500);
    lcd.print("l");
    delay(500);
    lcd.print("..          ");
  }
}
void check(){
  lcd.setCursor(0, 0);
  lcd.print("Res: ");
  for(int i=0;i<5;i++){
    lcd.print(result[i]);
    lcd.print(" ");
  }
}
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  bt1state[0] = digitalRead(bt1);
  bt2state[0] = digitalRead(bt2);
  bt3state[0] = digitalRead(bt3);
  if(bt1state[0]==HIGH&&bt1state[1]==LOW){
    up();
    delay(10);
    bt1state[1]=HIGH;
  }
  if(bt1state[0]==LOW&&bt1state[1]==HIGH){
    delay(10);
    bt1state[1]=LOW;
  }
  if(bt2state[0]==HIGH&&bt2state[1]==LOW){
    sel();
    delay(10);
    bt2state[1]=HIGH;
  }
  if(bt2state[0]==LOW&&bt2state[1]==HIGH){
    delay(10);
    bt2state[1]=LOW;
  }
  if(bt3state[0]==HIGH&&bt3state[1]==LOW){
    check();
    delay(10);
    bt3state[1]=HIGH;
  }
  if(bt3state[0]==LOW&&bt3state[1]==HIGH){
    delay(10);
    bt3state[1]=LOW;
  }
}
