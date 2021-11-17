#include <Keypad.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

const byte FILAS = 4;
const byte COLUMNAS = 4;

char keys[FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char clave[5] = {'1','2','3','4','5'};
char claveUsuario[5];



byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS);

int cerradura = 13;


int cont = 0;
int iden = 0;
int con2 = 5;

char Tecla;

void setup() {
Serial.begin(9600);
lcd.init(); // inicializar pantalla
lcd.backlight(); //luz de fondo
lcd.clear();
pinMode(cerradura,OUTPUT);
digitalWrite(cerradura,HIGH);    
}

void loop() {
lcd.setCursor(0,0);
lcd.print("INGRESE LA CLAVE");
 
Tecla = teclado.getKey();


if(Tecla){
  claveUsuario[cont] = Tecla;
  cont++;
  
  
  lcd.setCursor(con2,1);
  lcd.print("*");
  con2++;
  
  

if(cont == 5){
  
  for(int i = 0; i<=4;i++){
    
    if(claveUsuario[i] != clave[i]){
      iden = 1;
    }
    }
    
   if(iden ==1){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("CLAVE");
    lcd.setCursor(3,1);
    lcd.print("INCORRECTA"); 
    delay(3000);
    cont = 0;
    iden = 0;
    con2 =5;
     lcd.clear();
  }
  else{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("CLAVE");
    lcd.setCursor(4,1);
    lcd.print("CORRECTA"); 
    digitalWrite(cerradura,LOW);
    delay(2000);
    digitalWrite(cerradura,HIGH);
    
    con2 =5;
    cont= 0;
      lcd.clear();
  }

    
  }

 
  
}



}
