*//SEMÀFOR//

// pins que utilitzarem

int vermell = 2;       // LED vermell
int groc = 3;     // LED groc
int verd = 4;      //LED verd
int p_vermell = 5;    // LED vermell per a peatons
int p_groc = 6;     // LED groc
int p_verd = 7;   // LED verd per a peatons
int bot1=12;       // botó 1
int bot2=13;      // botó 2



void setup() {
  // S'inicialitzen els pins com sortida o entrada
  pinMode(vermell, OUTPUT);
  pinMode(groc, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(p_vermell, OUTPUT);
  pinMode(p_groc, OUTPUT);
  pinMode(p_verd, OUTPUT);
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT); 
}

void loop() {

  int i, j;   // Variables que fer servir als cicles
  
  if ((digitalRead(bot1)) || (digitalRead(bot2))) {   // Si es detecta la presència de un peató en algun dels costats
      // S'avisa de la presència de peatons amb un canvi de color del semàfor
    digitalWrite(verd, LOW);       // Es canvien els semàfors de verd
    digitalWrite(groc, HIGH);     // a groc,
    delay(20000);               // que es manté durante 20 segundos.
      // Es permet el pas dels peatons
    digitalWrite(groc, LOW);    // Es canvien els semàfors de groc
    digitalWrite(vermell, HIGH);       // a verd.
    digitalWrite(p_vermell, LOW);
    digitalWrite(p_groc, HIGH);
    digitalWrite(p_groc, LOW);
    digitalWrite(p_verd, HIGH);
    
           // Es torna a permetre la circulació de vehicles
  digitalWrite(vermell, LOW);     // S'apaga la llum vermella
  digitalWrite(verd, HIGH);     // i s'encèn la llum verda
  digitalWrite(p_vermell, HIGH);
  digitalWrite(p_verd, LOW);
  delay(180000);               // S'espera al menys 3 minuts per a tornar a habilitar el pas de peatons
  }
        // Es permet la circulació de vehicles
  digitalWrite(vermell, LOW);     // S'apaga la llum vermella
  digitalWrite(verd, HIGH);     // i s'encèn la llum verda per vehicles
  digitalWrite(p_vermell, HIGH);   // Al revés per a peatons
  digitalWrite(p_verd, LOW);
}
