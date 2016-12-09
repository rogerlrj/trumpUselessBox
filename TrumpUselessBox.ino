#include <Servo.h>                        //包含舵机库

Servo handServo;                          //定义舵机名称
Servo boxServo;

int switchStatus=0, action=1, vot, randNumber=0;                   //定义基本整形变量用于存储开关状态 电池电压 开关次数和种类
const int ledPin = 13;                    //定义LED引脚
const int frontSwitchPin = 2;
const int handServoPin = 5;
const int boxServoPin = 6;


void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);                  //定义LED引脚为输出
  digitalWrite(ledPin,HIGH);
  
  handServo.attach(handServoPin);              //定义舵机信号引脚
  boxServo.attach(boxServoPin);
  handServo.write(180);                        //舵机复位
  boxServo.write(70);

  //randomSeed(analogRead(0));
}


void loop()
{
  switchStatus = digitalRead(frontSwitchPin); //读取开关状态
  //action = random(1,16);
  
  if (switchStatus == LOW){                   //若开关被按下
    
    if (action == 1)
    {
      Serial.println("Action 1");           //第一种 慢慢抬头看 慢慢关开关
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(1000);
      handServo.write(26);
      delay(200);
      for (int i = 26; i <=180; i++)
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 110; i >= 70; i--)
      {
        boxServo.write(i);
        delay(20);
      }
      action++;
    }
    
    
    else if (action == 2)
    {
      Serial.println("Action 2");         //第二种 迅速关开关 事后探头看
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(550);
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(550);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 3)
    {
      Serial.println("Action 3");         //第三种 抬头看一下 然后迅速关开关
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      boxServo.write(70);
      delay(2000);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(500);
      boxServo.write(70);
      action++;
    }
   
    else if (action == 4)
    {
      Serial.println("Action 4");         //第四种 慢慢抬头看 手碰开关 然后迅速关开关
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(2000);
      handServo.write(26);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 5)
    {
      Serial.println("Action 5");       //第五种 抬头看然后挥手抗议
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      handServo.write(65);
      delay(550);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(65);
      delay(2000);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 6)             
    {
      Serial.println("Action 6");      
      //第六种 抬头看然后摔盒子 然后关开关 然后探头看
      for (int i = 70; i <110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 12; i++)
      {
        for (int j = 70; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(30);
      }
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(80);
      action++;
    }
    
    else if (action == 7)
    {
      Serial.println("Action 7");      //第七种 关上开关然后摔盒子
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(400);
      handServo.write(26);
      delay(1000);
      for (int i = 0; i < 6; i++)
      {
        for (int j = 70; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      delay(500);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 8)
    {
      Serial.println("Action 8");      //第八种 关上开关然后举手抗议
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 7; i++)
      {
        handServo.write(75);
        delay(100);
        handServo.write(40);
        delay(100);
      }
      delay(500);
      handServo.write(180);
      delay(1000);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 9)
    {
      Serial.println("Action 9");      //第九种 露半个头非常生气 慢慢慢慢地关上开关 然后探半个头看
      for (int i = 70; i <= 105; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      boxServo.write(110);
      for (int i = 180; i >=35; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(500);
      handServo.write(26);
      delay(200);
      for (int i = 26; i <=180; i++)
      {
        handServo.write(i);
        delay(40);
      }
      boxServo.write(70);
      delay(2000);
      boxServo.write(100);
      delay(3000);
      boxServo.write(70);
      action++;
    }
  
    
    else if (action == 10)
    {
      Serial.println("Action 10");      //第十种 慢慢探半个头看 然后摔盒子 然后迅速关开关
      for (int i = 70; i <= 105; i++)
      {
        boxServo.write(i);
        delay(100);
      }
      delay(1000);
      for (int i = 0; i < 10; i++)
      {
        for (int j = 70; j <= 100; j++){
          boxServo.write(j);
          delay(6);
      }
        delay(100);
      }
      boxServo.write(110);
      delay(100);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 11)
    {
      Serial.println("Action 11");      //第十一种 迅速探头关开关 然后慢速举手抗议 然后再探头按住开挂
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(2000);
      for (int i = 0; i < 3; i++)
      {
        handServo.write(65);
        delay(200);
        handServo.write(40);
        delay(200);
      }
      delay(1500);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(3000);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 12)
    {
      Serial.println("Action 12");      //第十二种 慢慢地露出头 非常生气 慢慢慢慢地关上开关 然后迅速缩回去
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(50);
      }
      delay(1000);
      for (int i = 180; i >= 26; i--)
      {
        handServo.write(i);
        delay(50);
      }
      delay(2000);
      handServo.write(26);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 13)
    {
      Serial.println("Action 13");      //第十三种 迅速探头 挥手假装要关开关 然后重复几次 关上开关然后缩回去
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(2000);
      for (int i = 180; i >= 60; i--)
      {
        handServo.write(i);
        delay(40);
      }
      for (int i = 0; i < 3; i++)
      {
        handServo.write(60);
        delay(200);
        handServo.write(40);
        delay(800);
      }
      handServo.write(26);
      delay(2000);
      handServo.write(180);
      delay(500);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 14)
    {
      Serial.println("Action 14");     //第十四种 很生气 露出半个头盯着你 然后迅速关掉开关 然后继续盯着你
      for (int i = 70; i <= 105; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(4000);
      boxServo.write(110);
      handServo.write(26);
      delay(650);
      handServo.write(180);
      delay(500);
      boxServo.write(100);
      delay(4000);
      boxServo.write(70);
      action++;
    }
    
    else if (action == 15)
    {
      Serial.println("Action 15");    //第十五种 很生气 露出半个头然后整个头然后又露剩半个头重复 然后慢慢关掉开关
      for (int i = 70; i <= 105; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 0; i < 3; i++)
      {      
        for (int j = 70; j <= 105; j++){
          boxServo.write(j);
          delay(50);
        }
        for (int j = 105; j >= 70; j--)
        {
          boxServo.write(j);
          delay(50);
        }
      }
      for (int j = 70; j <= 110; j++){
        boxServo.write(j);
        delay(50);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(1000);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action = 1;
    }
    
  }
  
}

