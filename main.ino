#include <IRremote.hpp> // version 2.8, flemme de me faire chier avec la version 3.x, elle a pas l'air si compliquée mais la doc présente la ver 2.x
#define irpin 1
#define sensorTrig 2
#define sensorEcho 3 // on définit les pins des capteurs IR & Ultrasonique

IRrecv irrecv(irpin); // constructeur de l'irremote
decode_results results; // ils ont fait une structure pour ça jsp pourquoi mais bon on va pas se plaindre, ça me simplifie la tâche 

void setup() {
  pinMode(sensorTrig, OUTPUT);
  pinMode(sensorEcho, INPUT); 
  irrecv.enableIRIn(); 
}

void loop() {
  
  digitalWrite(sensorTrig, LOW); // reset du trig
  digitalWrite(sensorTrig, HIGH); 
  delay(15);
  digitalWrite(sensorTrig, LOW);
  
  long duration = pulseIn(sensorEcho, HIGH); // return l'echo (en ms), comme les pulses commencent à 10ms j'ai mis le delay au mm tps environ, ils appellent ça de l'advance I/O quand même, c'est honteux arduino smr.  
  int distance = duration * 0.034 / 2; // vous avez besoin d'un commentaire même ? J'vous jure que je les mets juste pour les profs hein, vous êtes pas idiots, si ? Distance en cm
  
  if(distance <= 10) {
    
    // stopper les moteurs / faire reculer automatiquement, comme tu veux, je jure que je vais ùettre une autodestruction sur ce robot de merde
  }
  
  switch(results.value) {
    
    case haut:
     // faire aller le moteur en avant
    break;
    case bas:
     // faire aller à l'envers, tah Michael Jackson et son moonwalk du futur là
    break;
    case gauche:
     // faire aller à gauche mgl on s'ennuie hein ? J'me fais grave chier perso, on m'a interdit le projet full prog parce que j'suis trop forte quand même, vous imaginez ça ? Non c'est grv je jure, en mode je dois avoir une mauvaise note ?
    break;
    case droite: 
     // faire aller à droite
    break;
    case brashaut:
     // servomoteur
    break;
    case brasbas:
     // servomoteur encore
    break;
    case pincefermer:
     // servomoteur, on est fatigué de répéter là quand même hein c'est long à force vous savez, moi de base j'attends que le code de Lucas mais il prend 3 ans le relou.
    break;
    case pinceouverte:
     // ORH VOUS AVEZ COMPRIS C EST PAS COMPLIQUE SI ?!
    break;
  }
  irrecv.resume(); // réception du prochain signal
}