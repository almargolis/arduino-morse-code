/* arduino-morse-code
This is a simple arduino demo program that blinks morse code
on the LED that is provided on pin D13 of most arduino boards.

This uses the Morse Code specification found on Wikipedia:
https://en.wikipedia.org/wiki/Morse_code

The function sendletter() only handles the letters "S" and "O" but
the case statement could easily be filled out for the full alphabet.

Copyright 2021 Albert Margolis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

const int dit_ms = 200;
const int dah_ms = dit_ms * 3;
const int interditdah_ms = dit_ms;
const int interletter_ms = dit_ms * 3;
const int interword_ms = dit_ms * 7;
const int interword_delay = interword_ms - interletter_ms;
const int led = 13;  

void lastditdah(int ditdah) {
  digitalWrite(led, HIGH);
  delay(ditdah);
  digitalWrite(led, LOW);
  delay(interletter_ms);
}

void innerditdah(int ditdah) {
  digitalWrite(led, HIGH);
  delay(ditdah);
  digitalWrite(led, LOW);
  delay(interditdah_ms);
}

void interword() {
  delay(interword_delay);  
}

void sendletter(char c) {
  switch(c) {
    case 'o':
      innerditdah(dah_ms);  
      innerditdah(dah_ms);  
      lastditdah(dah_ms);
      break;  
    case 's':
      innerditdah(dit_ms);  
      innerditdah(dit_ms);  
      lastditdah(dit_ms);
      break;  
  }
}

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  sendletter('s');
  sendletter('o');
  sendletter('s');
}
