#include <string.h>

#define RA 3
#define RB 5
#define RC 6
#define RD 9
#define RE 10
#define C1 19
#define C2 20
#define C3 21
#define C4 8
#define C5 7
#define C6 4
#define C7 11

char str[] = "HELLO WORLD";
int messageLength;

void stringLength(char *input, int *length) {
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == 'W' || input[i] == 'M') {
      length[0] += 5;
    }
    else if (input[i] == 'I' || input[i] == 'T') {
      length[0] += 3;
    }
    else {
      length[0] += 4;
    }
  }
  length[0] += strlen(input) + 4;

}

void setup() {

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);

  Serial.begin(9600);

  stringLength(&str[0], &messageLength);

}
static int frame[5][200];
static int transfer[6][8];
int t=0;



void wave() {
  digitalWrite(C1, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(C3, HIGH);
  digitalWrite(C4, HIGH);
  digitalWrite(C5, HIGH);
  digitalWrite(C6, HIGH);
  digitalWrite(C7, HIGH);
  analogWrite(RE, 100);
  analogWrite(RD, 50);
  analogWrite(RC, 25);
  analogWrite(RB, 10);
  analogWrite(RA, 255);
  delay(100);
  analogWrite(RE, 50);
  analogWrite(RD, 25);
  analogWrite(RC, 10);
  analogWrite(RB, 255);
  analogWrite(RA, 175);
  delay(100);
  analogWrite(RE, 25);
  analogWrite(RD, 10);
  analogWrite(RC, 255);
  analogWrite(RB, 175);
  analogWrite(RA, 100);
  delay(100);
  analogWrite(RE, 10);
  analogWrite(RD, 255);
  analogWrite(RC, 175);
  analogWrite(RB, 100);
  analogWrite(RA, 50);
  delay(100);
  analogWrite(RE, 255);
  analogWrite(RD, 175);
  analogWrite(RC, 100);
  analogWrite(RB, 50);
  analogWrite(RA, 25);
  delay(100);
  analogWrite(RE, 175);
  analogWrite(RD, 100);
  analogWrite(RC, 50);
  analogWrite(RB, 25);
  analogWrite(RA, 10);
  delay(100);
}

void execute(int *grid) {
  int rows[5] = {RE,RD,RC,RB,RA};
  int cols[7] = {C1,C2,C3,C4,C5,C6,C7};
  for(int t = 0; t<8; t++){
    for (int r = 0; r < 5; r++) {
      for (int c = 0; c < 7; c++) {
        if(grid[r*200+c]){
          digitalWrite(rows[r],HIGH);
          digitalWrite(cols[c],HIGH);
          delayMicroseconds(500);
          digitalWrite(rows[r],LOW);
          digitalWrite(cols[c],LOW);
        
        }
        else{
          delayMicroseconds(500);
        }
      }
    }
  }

}

int length(char arr[]) {
  return (sizeof(arr) / 2);
}

int charWidth(char s) {
  if (s == 'W' || s == 'M') {
    return 5;
  }
  else if (s == 'T' || s == 'I' || s == '1') {
    return 3;
  }
  else {
    return 4;
  }

}


void letter(char s, int* buffer) {
  /*
    int temp[5][7] =  {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  */
  int LetterA[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterB[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int LetterC[5][7] = {{0, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0}};
  int LetterD[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int LetterE[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
  int LetterF[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}};
  int LetterG[5][7] = {{0, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int LetterH[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterI[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int LetterJ[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int LetterK[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterL[5][7] = {{1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
  int LetterN[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterM[5][7] = {{1, 0, 0, 0, 1, 0, 0}, {1, 1, 0, 1, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 0, 0}};
  int LetterO[5][7] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int LetterP[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}};
  int LetterQ[5][7] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0}};
  int LetterR[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterS[5][7] = {{0, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int LetterT[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}};
  int LetterU[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int LetterV[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}};
  int LetterW[5][7] = {{1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0}};
  int LetterX[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}};
  int LetterY[5][7] = {{1, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}};
  int LetterZ[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
  int Letter0[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
  int Letter1[5][7] = {{0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int Letter2[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
  int Letter3[5][7] = {{1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int Letter4[5][7] = {{1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}};
  int Letter5[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}};
  int Letter6[5][7] = {{0, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int Letter7[5][7] = {{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}};
  int Letter8[5][7] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int Letter9[5][7] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0}};
  int LetterSpace[5][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  int r = 0;
  int c = 0;


  if (s == 'A') {
    for (r = 0; r < 5; r++) {
      for (c = 0; c < 7; c++) {
        buffer[r * 7 + c] = LetterA[r][c];

      }
    }
  }

  else if (s == 'B') {
    for (r = 0; r < 5; r++) {
      for (c = 0; c < 7; c++) {
        buffer[r * 7 + c] = LetterB[r][c];
      }
    }
  }

  else if (s == 'C') {
    for (r = 0; r < 5; r++) {
      for (c = 0; c < 7; c++) {
        buffer[r * 7 + c] = LetterC[r][c];
      }
    }
  }

  else if (s == 'D') {
    for (r = 0; r < 5; r++) {
      for (c = 0; c < 7; c++) {
        buffer[r * 7 + c] = LetterD[r][c];
      }
    }
  }

  else if (s == 'E') {
    for (r = 0; r < 5; r++) {
      for (c = 0; c < 7; c++) {
        buffer[r * 7 + c] = LetterE[r][c];
      }
    }
  }
  
    else if (s == 'F') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterF[r][c];
        }
      }
    }
    else if (s == 'G') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterG[r][c];
        }
      }

    }
    else if (s == 'H') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterH[r][c];
        }
      }

    }
    
    else if (s == 'I') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterI[r][c];
        }
      }

    }
    else if (s == 'J') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterJ[r][c];
        }
      }

    }
    else if (s == 'K') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterK[r][c];
        }
      }

    }
    if (s == 'L') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterL[r][c];
        }
      }

    }
    if (s == 'M') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterM[r][c];
        }
      }

    }
    if (s == 'N') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterN[r][c];
        }
      }

    }
    if (s == 'O') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterO[r][c];
        }
      }

    }
    if (s == 'P') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterP[r][c];
        }
      }

    }
    if (s == 'Q') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterQ[r][c];
        }
      }

    }
    if (s == 'R') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterR[r][c];
        }
      }

    }
    if (s == 'S') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterS[r][c];
        }
      }

    }
    if (s == 'T') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterT[r][c];
        }
      }

    }
    if (s == 'U') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterU[r][c];
        }
      }

    }
    if (s == 'V') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterV[r][c];
        }
      }

    }
    if (s == 'W') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterW[r][c];
        }
      }

    }
    if (s == 'X') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterX[r][c];
        }
      }

    }
    if (s == 'Y') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterY[r][c];
        }
      }

    }
    if (s == 'Z') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterZ[r][c];
        }
      }

    }
    if (s == '0') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter0[r][c];
        }
      }

    }
    if (s == '1') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter1[r][c];
        }
      }

    }
    if (s == '2') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter2[r][c];
        }
      }

    }
    if (s == '3') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter3[r][c];
        }
      }

    }
    if (s == '4') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter4[r][c];
        }
      }

    }
    if (s == '5') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter5[r][c];
        }
      }

    }
    if (s == '6') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter6[r][c];
        }
      }

    }
    if (s == '7') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter7[r][c];
        }
      }

    }
    if (s == '8') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter8[r][c];
        }
      }

    }
    if (s == '9') {
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = Letter9[r][c];
        }
      }
    }
    if (s == ' '){
      for (r = 0; r < 5; r++) {
        for (c = 0; c < 7; c++) {
          buffer[r * 7 + c] = LetterSpace[r][c];
        }
      }
    }
/*
  Serial.print("TRANSFER from Letter: ");
  Serial.println(s);
  Serial.println("~~~~~~~~~~~~~");
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 7; c++) {
      Serial.print(buffer[r * 7 + c]);
      Serial.print("-");
    }
    Serial.println();
  }
  Serial.println("~~~~~~~~~~~~~");
  Serial.println();
*/

}

void addChar(int* grid, int* buffer, int order, char check) {
  int offset = order * 5;
  
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 7; c++) {

      grid[r * 200 + c + offset] = buffer[r * 7 + c];
    }
  }
}

void addString(int* grid, int* buffer, char* content) {

  for (int i = 0; i < strlen(content); i++) {
    /*Serial.print(i);
      //Serial.print(" - ");
      Serial.print(content[i]);
      //Serial.print(" - ");
      Serial.println(strlen(content));
    */
    letter(content[i], &buffer[0]);
    addChar(&grid[0], &buffer[0], i, content[i]);
    
  }


  //letter(content[0], &buffer[0]);
  //addChar(&grid[0], &buffer[0], 0, 'A');

  //letter(content[1], &buffer[0]);
  //addChar(&grid[0], &buffer[0], 1, 'B');
  //
  //letter(content[2], &buffer[0]);
  //addChar(&grid[0], &buffer[0], 2, 'C');

  //letter(content[3], &buffer[0]);
  //addChar(&grid[0], &buffer[0], 3, 'C');



}

void scroll(int* grid, int speed, int endpoint){
  Serial.println(endpoint);
  int rEnds[5] = {grid[0], grid[200], grid[400], grid[600], grid[800]};
  
  for(int r = 0; r < 5; r++){
    for(int c = 0; c < endpoint+10; c++){
      if(r*200+c < 1000){
        grid[r*200+c] = grid[r*200+c+1];
      }
      
    }
  }
  for(int i=endpoint+10; i<1000; i+=200){  
    grid[i] = rEnds[(i-(endpoint-10))/200];
  }
}

void loop() {

  
  
  if(t<1){
    addString(&frame[0][0], &transfer[0][0], &str[0]);
    t++;
  }
  /*
  Serial.println();
  Serial.print("FRAME: ");
  Serial.println(str);
  Serial.print("LENGTH: ");
  Serial.println(messageLength);
  Serial.println("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
  for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 100; c++) {
      if (frame[r][c] != 0) {
        Serial.print(frame[r][c]);
        Serial.print(" ");
      }
      else {
        Serial.print("  ");
      }
    }
    Serial.println();
  } 
  Serial.println("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
  Serial.println();
  //delay(1000);*/
  execute(&frame[0][0]);
  scroll(&frame[0][0], 1, messageLength);


  //Serial.println(messageLength);
  


}
