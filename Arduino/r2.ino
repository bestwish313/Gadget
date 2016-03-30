// DEFINE PIN ADDRESS
#define LED_TWO 2
#define LED_THREE 3
#define LED_FOUR 4
#define LED_FIVE 5
#define LED_SIX 6
#define LED_SEVEN 7
#define LED_EIGHT 8
#define LED_NINE 9
#define LED_TEN 10
#define LED_ELEVEN 11
#define LED_THIRTEEN 13


void setup()
{  
  // PIN MODE MAPPING
  pinMode(LED_TWO,OUTPUT);
  pinMode(LED_THREE,OUTPUT);
  pinMode(LED_FOUR,OUTPUT);
  pinMode(LED_FIVE,OUTPUT);
  pinMode(LED_SIX,OUTPUT);
  pinMode(LED_SEVEN,OUTPUT);
  pinMode(LED_EIGHT,OUTPUT);
  pinMode(LED_NINE,OUTPUT);  
  pinMode(LED_TEN, OUTPUT);
  pinMode(LED_ELEVEN, OUTPUT);
    
  // SKOH ADDED /////
  Serial.begin(9600);
  ///////////////////
}

void loop()
{
  if (Serial.available()) {
    char led_specifier = Serial.read();
    write_leds(led_specifier);
  }   
}

void write_leds(char led_index) 
{
  if (led_index == '2') {
    digitalWrite(LED_TWO, HIGH);      
  }  
  else if (led_index == 'A') {
    digitalWrite(LED_TWO, LOW);      
  }  
  else if (led_index == '3') {
    digitalWrite(LED_THREE, HIGH);      
  } 
  else if (led_index == 'B') {
    digitalWrite(LED_THREE, LOW);      
  }
  else if (led_index == '4') {
    digitalWrite(LED_FOUR, HIGH);      
  } 
  else if (led_index == 'C') {
    digitalWrite(LED_FOUR, LOW);      
  }
  else if (led_index == '5') {
    digitalWrite(LED_FIVE, HIGH);      
  } 
  else if (led_index == 'D') {
    digitalWrite(LED_FIVE, LOW);      
  }
  else if (led_index == '6') {
    digitalWrite(LED_SIX, HIGH);      
  } 
  else if (led_index == 'E') {
    digitalWrite(LED_SIX, LOW);      
  }
  else if (led_index == '7') {
    digitalWrite(LED_SEVEN, HIGH);      
  }
 else if (led_index == 'F') {
    digitalWrite(LED_SEVEN, LOW);      
  } 
  else if (led_index == '8') {
    digitalWrite(LED_EIGHT, HIGH);      
  } 
  else if (led_index == 'G') {
    digitalWrite(LED_EIGHT, LOW);      
  } 
  else if (led_index == '9') {    
    digitalWrite(LED_NINE, HIGH);   
  } 
  else if (led_index == 'H') {    
    digitalWrite(LED_NINE, LOW);   
  }
  else if (led_index == 'a') {
    
    digitalWrite(LED_TEN, HIGH);   
  }
  else if (led_index == 'I') {
    
    digitalWrite(LED_TEN, LOW);   
  }
  else if (led_index == 'b') {
    
    digitalWrite(LED_ELEVEN, HIGH);   
  }
  else if (led_index == 'J') {
    
    digitalWrite(LED_ELEVEN, LOW);   
  }
  else if (led_index == 'c') {
    
    for (int i = 1; i < 14; i++) {
    digitalWrite(i, LOW);  
    }    
  } 
  
  else
    return;
}
