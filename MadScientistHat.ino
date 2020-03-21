/*
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
    
    H DECIMAL
 */

//12 for flicker
//5 for solid
#define MUTIPLEX_SPEED 5
//5 seems to be good
#define COUNT_TIME_RANDOMIZE 5

const int pinA = 9;
const int pinB = A0;
const int pinC = 5;
const int pinD = 3;
const int pinE = 2;
const int pinF = 10;
const int pinG = 6;
const int pinH = 4;
const int D1 = 8;
const int D2 = 11;
const int D3 = 12;
const int D4 = 7;

//ABCDEFG
const int numbers[10][7]= {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
};

byte savedMultiplexNumber[4]{0,0,0,0};

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(pinH, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  

  randomSeed(analogRead(A5));
}



void displayNumber(byte disp, byte num){
    digitalWrite(D1, (disp == 0) ? LOW : HIGH);
    digitalWrite(D2, (disp == 1) ? LOW : HIGH);
    digitalWrite(D3, (disp == 2) ? LOW : HIGH);
    digitalWrite(D4, (disp == 3) ? LOW : HIGH);

    digitalWrite(pinA, numbers[num][0] ? HIGH : LOW);
    digitalWrite(pinB, numbers[num][1] ? HIGH : LOW);
    digitalWrite(pinC, numbers[num][2] ? HIGH : LOW);
    digitalWrite(pinD, numbers[num][3] ? HIGH : LOW);
    digitalWrite(pinE, numbers[num][4] ? HIGH : LOW);
    digitalWrite(pinF, numbers[num][5] ? HIGH : LOW);
    digitalWrite(pinG, numbers[num][6] ? HIGH : LOW);
    //digitalWrite(pinH, numbers[num][7] ? HIGH : LOW);
}

int count = 0;

void loop() {
  updateDisplays(); 

  if(count > COUNT_TIME_RANDOMIZE){
    count = 0;
    randomiseDisplays();
  }

  count++;
}

void randomiseDisplays(){
  byte display = random(4);
  byte number = random(10);
  savedMultiplexNumber[display] = number;
}


void updateDisplays(){
    for(byte i = 0; i < 4; i++){
      displayNumber(i, savedMultiplexNumber[i]);
      delay(MUTIPLEX_SPEED);
    }
}


//unused but an idea
/*
void glitchDisplay(){
    digitalWrite(D1, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(D2, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(D3, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(D4, (random(2) == 0) ? LOW : HIGH);

    digitalWrite(pinA, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinB, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinC, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinD, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinE, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinF, (random(2) == 0) ? LOW : HIGH);
    digitalWrite(pinG, (random(2) == 0) ? LOW : HIGH);
}
*/