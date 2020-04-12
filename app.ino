#include "src/temp.h"
#include "src/pump.h"

// Receita *recipe;

void print_temp(float &t){
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("*C");
    Serial.println();
}

void setup(){
    // recipe->leveduras = 30;
    // recipe->lupulo = 30;
    // recipe->malte = 30;
    Serial.begin(9600);

}

void loop(){
	float t = read_temp(&analogRead);
    print_temp(t);
    delay(500);
}
