# 1 "/home/suy/Desktop/STE/ControladorCerveja/app.ino"
# 2 "/home/suy/Desktop/STE/ControladorCerveja/app.ino" 2

# 4 "/home/suy/Desktop/STE/ControladorCerveja/app.ino" 2
# 5 "/home/suy/Desktop/STE/ControladorCerveja/app.ino" 2
# 6 "/home/suy/Desktop/STE/ControladorCerveja/app.ino" 2
# 7 "/home/suy/Desktop/STE/ControladorCerveja/app.ino" 2

Config conf;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup(){
    // pinos da temperatura 
    pinMode(A0, 0x0);
    pinMode(13, 0x1);

    // pinos da bomba
    pinMode(12, 0x1);
    pinMode(9, 0x0);

    // pinos do botoes
    pinMode(10, 0x0);
    pinMode(11, 0x0);
    pinMode(8, 0x0);

    pinMode(A1, 0x1);
    lcd.begin(16,2);

    // pega a receita
    conf = menu(lcd);

    // fica bloqueado ate encher o tanque de agua 
    // quando estiver cheio, ferve a agua e liga a bomba
    while(!check_water_min_lvl()) notify(lcd, "sem agua");

    lcd.println("Esquentando");
    pre_heat();
    lcd.clear();
    pump_on();
    lcd.println("Iniciando");
}

void loop(){
    // Notifica para adicionar os igredientes
    // controla a temperatura aumentando 1*C por min 
    // quando termina os três ingredientes sinaliza o fim da receita 

    notify(lcd, "ing 1");
    set_temp(conf.recipe.a, lcd);
    keep_temp(2, lcd);

    notify(lcd, "ing 2");
    set_temp(conf.recipe.b, lcd);
    keep_temp(2, lcd);

    notify(lcd, "ing 3");
    set_temp(conf.recipe.c, lcd);
    keep_temp(2, lcd);

    // notifica fim
    notify(lcd, "FIM");
    pump_off();
}
