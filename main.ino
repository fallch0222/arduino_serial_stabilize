#include <Servo.h>

char data;

Servo servo1;


void setup() {
  servo1.attach(8);
  Serial.begin(9600);
}
int target;
 int stack;
bool IsBug = false;
void loop() {
 data = Serial.read();
 
 if(data == '1'&&target != '1'){
  stack = 0;
  target = '1';
  
 }
 if(data == '2'&& target != '2'){
  stack = 0;
  target = '2';
  
 }

 if(stack < 10000){
  stack = stack + 1;
 
  return;
  }

  
  
 
 
  if(data == '1' && IsBug == true) // 티처블 머신에서 사진 판별이 1번이라면 {  }안에 내용을 실행
  {
     servo1.write(90);
      IsBug = false;   // 서보모터를 10도로 움직이기
  }
  else if(data == '2' && IsBug == false) // 티처블 머신에서 사진 판별이 2번이라면 {  }안에 내용을 실행
  {
      servo1.write(0);
      IsBug = true;   // 서보모터를 90의 위치로 움직이기
  }
 

}
