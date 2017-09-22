#define ledPin1 D0    // Define pin name
#define ledPin2 D4
#define ledPin3 D5
void setup() 
{
  pinMode(ledPin1, OUTPUT); // Set D0 pin as output
  pinMode(ledPin2, OUTPUT); // Set D4 pin as output
  pinMode(ledPin3, OUTPUT); // Set D5 pin as output
}

void loop() 
{
  digitalWrite(ledPin1, 0); // Set display pattern off-off-on 
  digitalWrite(ledPin2, 0);
  digitalWrite(ledPin3, 1);
  delay(1000);              // Delay 1 second
  digitalWrite(ledPin1, 0); // Set display pattern off-on-on
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);
  delay(1000);              // Delay 1 second
  digitalWrite(ledPin1, 1); // Set display pattern on-on-on
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);
  delay(1000);              // Delay 1 second
  digitalWrite(ledPin1, 0); // Turn off all
  digitalWrite(ledPin2, 0);
  digitalWrite(ledPin3, 0);
  delay(1000);              // Delay 1 second
}

