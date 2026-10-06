int ledPin[]= {8, 9, 10};
int buttonPin[]= {11, 12, 13};
int ledCorreto= 2;
int ledErrado= 3;
bool equal = true;
int i= 0;
int som= 4;
int life=3;
int time= 1000;
int x, y;
int resposta[5];
int values[5];
void setup()
{
  while(i<3){
  pinMode(ledPin[i], OUTPUT);
  pinMode(buttonPin[i], INPUT);
    i++;
  }
  pinMode(ledCorreto, OUTPUT); 
  pinMode(ledErrado, OUTPUT); 
  pinMode(som, OUTPUT);
}

void loop()
{
  for(x= 0; x<5; x++){
    int a= random(3);
    	digitalWrite(ledPin[a], HIGH);
    		delay(time);
    	digitalWrite(ledPin[a], LOW);
    		delay(time);
   		values[x]= a;
  }
  

 	while(y<5){
    		if(digitalRead(buttonPin[0])== HIGH){
    			resposta[y]= 0;
              	y++;
              while(digitalRead(buttonPin[0])== HIGH){}
        	}
    		else if(digitalRead(buttonPin[1])== HIGH){
    			resposta[y]= 1;
              	y++;	
              while(digitalRead(buttonPin[1])== HIGH){}
        	}
    		else if(digitalRead(buttonPin[2])== HIGH){
    			resposta[y]= 2;
              	y++;
              while(digitalRead(buttonPin[2])== HIGH){}
        	}
  	}
  
  if(y=5){
    for(i=0; i<5; i++){
    	if(values[i] != resposta[i]){
          equal = false;
    	} 
    }
    	if(equal){
          if(time>400){
            time=time-200;
          } else { time=400;}
        			tone(som, 739, 850);
    					delay(75);
        			tone(som, 783, 850);
    					delay(100);
        	digitalWrite(ledCorreto, HIGH);
    			delay(500);
    		digitalWrite(ledCorreto, LOW);
    			delay(1000);
          	x=0; y=0;
        } else {
        			tone(som, 246, 850);
    					delay(75);
        			tone(som, 233, 850);
    					delay(100);
        	digitalWrite(ledErrado, HIGH);
    			delay(500);
    		digitalWrite(ledErrado, LOW);
    			delay(1000);
          	x=0; y=0; life=life-1;
          if(life==0){
        			tone(som, 246, 850);
    					delay(75);
        			tone(som, 233, 850);
    					delay(75);
        			tone(som, 220, 850);
    					delay(500);
          }
          
        }
  }
 
}