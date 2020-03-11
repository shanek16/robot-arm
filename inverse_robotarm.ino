#include <Servo.h>
#define _CRT_SECURE_NO_WARNINGS

Servo servo1, servo2, servo3, servo4, servo5, servo6;  // create servo object to control a servo

float l2=120, l4=121.5;
float pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0; // variable to store the servo position
float px=-100,py=-100,pz=100,r1=1,r4=0,r7=0;
double Au0=0,Au1=0,Au2=0,Bu0=0,Bu1=0,Bu2=0;
int count=0;

float calculate1()
{
      Au0=(sq(px*cos(pos1)+py*sin(pos1))+sq(pz)-sq(l4)-sq(l2))/(2*l4*l2);
      Bu0=sqrt(1-sq(Au0));
      pos3=atan2(Bu0,Au0)*180/PI;
      Serial.print("pos3: ");
      Serial.println(pos3);
    
      Au1=((cos(pos3)*l4+l2)*(cos(pos1)*px+py*sin(pos1))+pz*sin(pos3)*l4)/(sq(px*cos(pos1)+py*sin(pos1))+sq(pz));
      Bu1=sqrt(1-sq(Au1));
      Serial.print(Bu1);Serial.print(" ");Serial.print(Au1);Serial.print(" ");Serial.println(Bu1/Au1);
      pos2=atan2(Bu1,Au1)*180/PI;
      Serial.print("pos2: ");
      Serial.println(pos2);
    
      Au2=(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*cos(pos1)*r1-(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*sin(pos1)*r4+(cos(pos2)*cos(pos3)-sin(pos2)*sin(pos3))*r7;
      Bu2=-cos(pos1)*r4+r1*sin(pos1);
      pos4=atan2(Bu2,Au2)*180/PI;
      Serial.print("pos4: ");
      Serial.println(pos4);
      Serial.println("");
}

float calculate2()
{
      Serial.println("case2:");
      Au0=(sq(px*cos(pos1)+py*sin(pos1))+sq(pz)-sq(l4)-sq(l2))/(2*l4*l2);
      Bu0=-sqrt(1-sq(Au0));
      pos3=atan2(Bu0,Au0)*180/PI;
      Serial.print("pos3: ");
      Serial.println(pos3);
    
      Au1=((cos(pos3)*l4+l2)*(cos(pos1)*px+py*sin(pos1))+pz*sin(pos3)*l4)/(sq(px*cos(pos1)+py*sin(pos1))+sq(pz));
      Bu1=sqrt(1-sq(Au1));
      pos2=atan2(Bu1,Au1)*180/PI;
      Serial.print("pos2: ");
      Serial.println(pos2);
    
      Au2=(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*cos(pos1)*r1-(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*sin(pos1)*r4+(cos(pos2)*cos(pos3)-sin(pos2)*sin(pos3))*r7;
      Bu2=-cos(pos1)*r4+r1*sin(pos1);
      pos4=atan2(Bu2,Au2)*180/PI;
      Serial.print("pos4: ");
      Serial.println(pos4);
      Serial.println("");
}

float calculate3()
{
      Serial.println("case3:");
      Au0=(sq(px*cos(pos1)+py*sin(pos1))+sq(pz)-sq(l4)-sq(l2))/(2*l4*l2);
      Bu0=sqrt(1-sq(Au0));
      pos3=atan2(Bu0,Au0)*180/PI;
      Serial.print("pos3: ");
      Serial.println(pos3);
    
      Au1=((cos(pos3)*l4+l2)*(cos(pos1)*px+py*sin(pos1))+pz*sin(pos3)*l4)/(sq(px*cos(pos1)+py*sin(pos1))+sq(pz));
      Bu1=-sqrt(1-sq(Au1));
      pos2=atan2(Bu1,Au1)*180/PI;
      Serial.print("pos2: ");
      Serial.println(pos2);
    
      Au2=(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*cos(pos1)*r1-(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*sin(pos1)*r4+(cos(pos2)*cos(pos3)-sin(pos2)*sin(pos3))*r7;
      Bu2=-cos(pos1)*r4+r1*sin(pos1);
      pos4=atan2(Bu2,Au2)*180/PI;
      Serial.print("pos4: ");
      Serial.println(pos4);
      Serial.println("");
}

float calculate4()
{
      Serial.println("case4:");
      Au0=(sq(px*cos(pos1)+py*sin(pos1))+sq(pz)-sq(l4)-sq(l2))/(2*l4*l2);
      Bu0=-sqrt(1-sq(Au0));
      pos3=atan2(Bu0,Au0)*180/PI;
      Serial.print("pos3: ");
      Serial.println(pos3);
    
      Au1=((cos(pos3)*l4+l2)*(cos(pos1)*px+py*sin(pos1))+pz*sin(pos3)*l4)/(sq(px*cos(pos1)+py*sin(pos1))+sq(pz));
      Bu1=-sqrt(1-sq(Au1));
      pos2=atan2(Bu1,Au1)*180/PI;
      Serial.print("pos2: ");
      Serial.println(pos2);
    
      Au2=(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*cos(pos1)*r1-(cos(pos2)*sin(pos3)+cos(pos3)*sin(pos2))*sin(pos1)*r4+(cos(pos2)*cos(pos3)-sin(pos2)*sin(pos3))*r7;
      Bu2=-cos(pos1)*r4+r1*sin(pos1);
      pos4=atan2(Bu2,Au2)*180/PI;
      Serial.print("pos4: ");
      Serial.println(pos4);
      Serial.println("");
}

void setup() 
{
  Serial.begin(9600);
  servo1.attach(2);  // attaches the servo on pin 9 to the servo object
  servo2.attach(3); 
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  Serial.println("initializing...");
  servo1.write(0); 
  servo2.write(90); 
  servo3.write(0); 
  servo4.write(0);
  servo5.write(0);
}

void loop() 
{ 
  if(count==0)
  {  
  Serial.println("Enter px py pz r1 r4 r7:");
  count++;
  }
  
  if(Serial.available())
  {
    px=Serial.parseFloat();
    py=Serial.parseFloat();
    pz=Serial.parseFloat();
    r1=Serial.parseFloat();
    r4=Serial.parseFloat();
    r7=Serial.parseFloat();

    Serial.println("Entered values:");
    Serial.print(px);Serial.print(" ");Serial.print(py );Serial.print(" ");Serial.println(pz);
    Serial.print(r1 );Serial.print(" ");Serial.print(r4 );Serial.print(" ");Serial.println(r7);

      if(pow(px,2)+pow(py,2)+pow(pz,2)>pow((l2+l4),2))//longer than robot arm
      {
        Serial.println("not reachable point");
        Serial.println("Re-enter:");
      }
      else
      {
      pos1=atan2(py,px)*180/PI;
      Serial.print("pos1: ");
      Serial.println(pos1);

      calculate1();

      if(pos1<0||pos2<0||pos3<0||pos4<0||1-sq(Au1)<0||1-sq(Au0))
      {
        Serial.println("out of angle range, finding another solution...");
        calculate2();
        if(pos1<0||pos2<0||pos3<0||pos4<0||1-sq(Au1)<0||1-sq(Au0))
        {
          calculate3();
          if(pos1<0||pos2<0||pos3<0||pos4<0||1-sq(Au1)<0||1-sq(Au0))
          {
            calculate4;
            if(pos1<0||pos2<0||pos3<0||pos4<0||1-sq(Au1)<0||1-sq(Au0))
            {
              Serial.println("no solution");
            }
 
          }
        }
      }
      
      servo1.write(pos1);            
      delay(500);
    
      servo2.write(pos2/2);            
      delay(500);
      servo2.write(pos2);            
      delay(500);
    
      servo3.write(pos3);            
      delay(500);
    
      servo4.write(pos4);            
      delay(500);

       if(Serial.available()&&count==1)
    {
      Serial.println("enter pos5 pos6:");
      pos5=Serial.parseFloat();
      Serial.print("pos5: ");
      Serial.println(pos5);
      servo5.write(pos5); 
      
      pos6=Serial.parseFloat();
      Serial.print("pos6: ");
      Serial.println(pos6);
      servo6.write(pos6); 
      count=0;
     }
    /*
      servo5.write(pos5);            
      delay(15);
    
      Serial.print("6: ");
      scanf("%d", &pos6);
      
      servo6.write(pos6);            
      delay(15);
      */
      }
   }
}
