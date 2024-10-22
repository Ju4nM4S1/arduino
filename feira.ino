#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int umidade = 0;
int umidade2 = 0;
int INA = 9;
int INB = 8;
float s = A2;
float t = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(INA , OUTPUT);
  pinMode(INB , OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  digitalWrite(A0, HIGH);
  lcd.init();                      
  lcd.backlight();

}

void loop()
{
  t = (analogRead(A2) * ((5.0/1023)) /0.01) -40 ;
  umidade = analogRead(A1);
  umidade = map(umidade, 1023, 315, 0, 100); //Transforma os valores analógicos em uma escala de 0 a 100

  if (umidade != umidade2){
    lcd.clear();
 }
 if (umidade >= 30){
  digitalWrite(7, HIGH);
 }

 if (umidade <= 90){
  digitalWrite(7, LOW);
 }

  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);


  lcd.setCursor(0,0);
  lcd.print("Umidade =");
  lcd.setCursor(10,0);
  lcd.print(umidade);
  lcd.setCursor(13,0);
  lcd.print("%");
  lcd.setCursor(2,1);
  lcd.print(t);
  umidade = umidade2;
  delay(1000); // Delay a little bit to improve simulation performance
}