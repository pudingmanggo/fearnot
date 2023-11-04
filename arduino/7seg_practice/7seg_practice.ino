unsigned long before = 0;
//7세그먼트는 총 8개의 LED로 구성이 되어 있습니다.
int segmLed[] = {2, 3, 4, 5, 6, 7, 8, 9};
//7세그먼트 각 LED에 핀을 할당합니다.
//{2, 3, 4, 5, 6, 7, 8, 9} = {A, B, C, D, E, F, G, H}
int i, j;
int digitNum[10][8] = {
  // 캐소드 타입
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}  //9
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  for(i=0;i<8;i++){
    pinMode(segmLed[i], OUTPUT);
  }
}
unsigned long now = millis();
void loop() {
  for(i=0;i<10;i++){
    for(j=0;j<8;j++){
      digitalWrite(segmLed[j], digitNum[i][j]);
    }
    delay(100);
    while(now-before<=1000){
      now = millis();
    }
    before = now;
  }
  // for(i=7;i>=0;i--){
  //     digitalWrite(segmLed[i], LOW);
  //     delay(500);
  //   }
}
