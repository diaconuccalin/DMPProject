// DISPLAY

// Display pins
#define LCD_CLK 3
#define LCD_DIN 8
#define LCD_DC 9
#define LCD_CE 10
#define LCD_RST 11

// Matrix to square current state of the table (inverted top-bottom)
bool squares[20][10] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* data table:
    first row: EF 0F
    other row: EE 0E E0 00

   6 rows
   84 collumns

   screen row: 4m (1e 3b)x10 1e 3m
   each collumn in data, a row on screen (left -> right   bottom -> top)
*/
static byte data[] = {
  0xFF, 0xFF, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0B11101111, 0B11101111, 0B11101111, 0x0F, 0xFF,
  0xFF, 0xFF, 0x00, 0B11100000, 0B11100000, 0B11100000, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0xFF,
  0xFF, 0xFF, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0xFF,
  0xFF, 0xFF, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0xFF,
  0xFF, 0xFF, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0B11101110, 0B11101110, 0B11101110, 0x00, 0xFF,
  0xFF, 0xFF, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0B11101110, 0B11101110, 0B11101110, 0xE0, 0xFF
};

void lcdInitialise() {
  pinMode(LCD_CE, OUTPUT);
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_DC, OUTPUT);
  pinMode(LCD_DIN, OUTPUT);
  pinMode(LCD_CLK, OUTPUT);
  digitalWrite(LCD_RST, LOW);
  digitalWrite(LCD_RST, HIGH);
  lcdWrite(LOW, 0x21 );  // LCD Extended Commands.
  lcdWrite(LOW, 0xB9 );  // Set LCD Vop (Contrast).
  lcdWrite(LOW, 0x04 );  // Set Temp coefficent.
  lcdWrite(LOW, 0x14 );  // LCD bias mode 1:48.
  lcdWrite(LOW, 0x20 );  // LCD Basic Commands
  lcdWrite(LOW, 0x0C );  // LCD in normal mode.
}

void lcdLoop() {
  digitalWrite(8, HIGH);
  for (int i = 0; i < (84 * 48) / 8; i++)
    lcdWrite(HIGH, data[i]);
}

void lcdWrite(byte dc, byte data) {
  digitalWrite(LCD_DC, dc);
  digitalWrite(LCD_CE, LOW);
  shiftOut(LCD_DIN, LCD_CLK, MSBFIRST, data);
  digitalWrite(LCD_CE, HIGH);
}

// Translate the squares matrix for the data matrix
void squareToData() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (j % 2 == 0) {
        if (squares[i][j] == 1) {
          data[3 + 4 * i + 84 * (j / 2)] = 0B11100000 | data[3 + 4 * i + 84 * (j / 2)];
          data[4 + 4 * i + 84 * (j / 2)] = 0B11100000 | data[4 + 4 * i + 84 * (j / 2)];
          data[5 + 4 * i + 84 * (j / 2)] = 0B11100000 | data[5 + 4 * i + 84 * (j / 2)];
        } else {
          data[3 + 4 * i + 84 * (j / 2)] = 0B00011111 & data[3 + 4 * i + 84 * (j / 2)];
          data[4 + 4 * i + 84 * (j / 2)] = 0B00011111 & data[4 + 4 * i + 84 * (j / 2)];
          data[5 + 4 * i + 84 * (j / 2)] = 0B00011111 & data[5 + 4 * i + 84 * (j / 2)];
        }
      } else {
        if (squares[i][j] == 1) {
          data[3 + 4 * i + 84 * ((j + 1) / 2)] = 0B00001110 | data[3 + 4 * i + 84 * ((j + 1) / 2)];
          data[4 + 4 * i + 84 * ((j + 1) / 2)] = 0B00001110 | data[4 + 4 * i + 84 * ((j + 1) / 2)];
          data[5 + 4 * i + 84 * ((j + 1) / 2)] = 0B00001110 | data[5 + 4 * i + 84 * ((j + 1) / 2)];
        } else {
          data[3 + 4 * i + 84 * ((j + 1) / 2)] = 0B11110001 & data[3 + 4 * i + 84 * ((j + 1) / 2)];
          data[4 + 4 * i + 84 * ((j + 1) / 2)] = 0B11110001 & data[4 + 4 * i + 84 * ((j + 1) / 2)];
          data[5 + 4 * i + 84 * ((j + 1) / 2)] = 0B11110001 & data[5 + 4 * i + 84 * ((j + 1) / 2)];
        }
      }
    }
  }
}

// GAME
int block_blueprint[7][5][5] = {0};
int arranged_blocks[20][10];
short block_number;
int next = 0;
int coming_block[20][10];
int score = 0;
int delay_ = 700;
int delay_start = 700;
long int timePassed = 0;

void arrangedBlocksToSquare() {
  for (int i = 0; i < 20; i ++) {
    for (int j = 0; j < 10; j++) {
      if (arranged_blocks[i][j] > 0 || coming_block[i][j] > 0)
        squares[19 - i][j] = 1;
      else
        squares[19 - i][j] = 0;
    }
  }
}

bool check_space(int temporary_block[24][14]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 14; j++) {
      if (temporary_block[i][j] != 0) {
        //Serial.println("Entered 1");
        return false;
      }
    }
  }

  for (int i = 22; i < 24; i++) {
    for (int j = 0; j < 14; j++) {
      if (temporary_block[i][j] != 0) {
        //Serial.println("Entered 2");
        return false;
      }
    }
  }

  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 2; j++) {
      if (temporary_block[i][j] != 0) {
        //Serial.println("Entered 3");
        return false;
      }
    }
  }

  for (int i = 0; i < 22; i++) {
    for (int j = 12; j < 14; j++) {
      if (temporary_block[i][j] != 0) {
        //Serial.println("Entered 4");
        return false;
      }
    }
  }

  for (int i = 2; i < 20; i++) {
    for (int j = 2; j < 12; j++) {
      if (arranged_blocks[i - 2][j - 2] != 0 && temporary_block[i][j] != 0) {
        //Serial.println("Entered 5");
        return false;
      }
    }
  }

  return true;
}

void set_arrays_zero(int mat[20][10], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      mat[i][j] = 0;
  }
}

void newBlock() {
  delay(100);
  bool finish_game = is_the_game_over();

  if (finish_game == true)
    return;

  block_number = next;
  next = random(7);
  set_arrays_zero(coming_block, 20, 10);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++)
      coming_block[i][j + 2] = block_blueprint[block_number][i][j];
  }

  return;
}

void rotate() {
  if (block_number == 3) // 2x2 block
    return;

  int temp[5][5] = {0};
  bool flag = 0;
  short x, y = 0; // used to find i and j where coming_block[i][j]==3 (center)

  // find coordinates of the center of the coming block
  for (int i = 0; i < 20 && !flag; i++) {
    for (int j = 0; j < 10; j++) {
      if (coming_block[i][j] == 3) {
        x = i;
        y = j;
        flag = 1;
        break;
      }
    }
  }

  // to put the matrix in a 5X5 temp matrix
  for (int i = x - 2; i < x + 3; i++) {
    for (int j = y - 2; j < y + 3; j++)
      temp[i - x + 2][j - y + 2] = coming_block[i][j];
  }

  // actual rotation
  for (int i = 0; i <= 2; i++) {
    for (int j = i; j < 4 - i; j++) {
      int mat = temp[i][j];
      temp[i][j] = temp[j][4 - i];
      temp[j][4 - i] = temp[4 - i][4 - j];
      temp[4 - i][4 - j] = temp[4 - j][i];
      temp[4 - j][i] = mat;
    }
  }

  // new thing
  int temporary_block[24][14] = {0};
  for (int i = x - 2; i < x + 3; i++) {
    for (int j = y - 2; j < y + 3; j++)
      temporary_block[i + 2][j + 2] = temp[i - x + 2][j - y + 2];
  }

  bool check = check_space(temporary_block);

  if (check == true) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++)
        coming_block[i][j] = temporary_block[i + 2][j + 2];
    }
  }

  updating_arranged_blocks();
  arrangedBlocksToSquare();
}

void translate_right() {
  int temporary_block[24][14] = {0};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++)
      temporary_block[i + 2][j + 3] = coming_block[i][j];
  }

  bool check = check_space(temporary_block);

  if (check == true) {
    set_arrays_zero(coming_block, 20, 10);
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++)
        coming_block[i][j] = temporary_block[i + 2][j + 2];
    }
  }

  updating_arranged_blocks();
  arrangedBlocksToSquare();
}

void translate_down() {
  int temporary_block[24][14] = {0};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++)
      temporary_block[i + 3][j + 2] = coming_block[i][j];
  }

  bool check = check_space(temporary_block);

  if (check == true) {
    set_arrays_zero(coming_block, 20, 10);
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++)
        coming_block[i][j] = temporary_block[i + 2][j + 2];
    }
  } else {
    //Merging arranged blocks with coming blocks because the block can't go further down.
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++) {
        if (arranged_blocks[i][j] != 0 || coming_block[i][j] != 0)
          arranged_blocks[i][j] = 1;
      }
    }

    set_arrays_zero(coming_block, 20, 10);
    newBlock();
  }

  updating_arranged_blocks();
  arrangedBlocksToSquare();
  lcdLoop();
}

void translate_left() {
  int temporary_block[24][14] = {0};
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++)
      temporary_block[i + 2][j + 1] = coming_block[i][j];
  }

  bool check = check_space(temporary_block);

  if (check == true) {
    set_arrays_zero(coming_block, 20, 10);
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++)
        coming_block[i][j] = temporary_block[i + 2][j + 2];
    }
  }

  updating_arranged_blocks();
  arrangedBlocksToSquare();
}

void updating_arranged_blocks() {
  delay(100);
  int i, j, k;
  int number_of_lines_cleared = 0;

  for (i = 19; i >= 0; i--) {
    // check if filled row
    int count = 0;
    for (j = 0; j < 10; j++) {
      if (arranged_blocks[i][j] != 0)
        count++;
    }

    // clear row
    if (count == 10) {
      number_of_lines_cleared++;

      // move rows above
      for (k = i; k > 0; k--) {
        for (j = 0; j < 10; j++)
          arranged_blocks[k][j] = arranged_blocks[k - 1][j];
      }

      // empty first row
      for (j = 0; j < 10; j++)
        arranged_blocks[0][j] = 0;

      i++;
    }
  }

  score = score + number_of_lines_cleared;

  // bonus
  if (number_of_lines_cleared == 2)
    score = score + 1;
  else if (number_of_lines_cleared == 3)
    score = score + 2;
  else if (number_of_lines_cleared == 4)
    score = score + 3;
}

void update_delay() {
  if (score <= 5)
    delay_ = delay_start;
  else if (score > 5 && score <= 10)
    delay_ = (int) delay_start * 0.9;
  else if (score > 10 && score <= 15)
    delay_ = (int) delay_start * 0.9 * 0.9;
  else if (score > 15 && score <= 20)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9;
  else if (score > 20 && score <= 25)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9 * 0.9;
  else if (score > 25 && score <= 30)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9 * 0.9 * 0.9;
  else if (score > 30 && score <= 35)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9;
  else if (score > 35 && score <= 40)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9;
  else if (score > 40 && score <= 45)
    delay_ = (int) delay_start * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9 * 0.9;
}

bool is_the_game_over() {
  updating_arranged_blocks();
  for (int i = 0; i < 8; i++) {
    if (arranged_blocks[1][i]) {
      Serial.print("GAME OVER. SCORE: ");
      Serial.println(score);
      delay(3000);
      score = 0;
      set_arrays_zero(arranged_blocks, 20, 10);
      set_arrays_zero(coming_block, 20, 10);
    }
  }
  return false;
}

void game() {
  timePassed = millis();

  while (true) {
    if (millis() - timePassed > delay_) {
      translate_down();
      timePassed = millis();
      arrangedBlocksToSquare();
      squareToData();
      lcdLoop();
    }

    checkButtons();
  }
}

// BUTTONS
/*
   b0 - move left
   b1 - rotate
   b2 - move right
   b3 - play / drop
*/

// Button pins
#define b0 7
#define b1 6
#define b2 5
#define b3 4

void setupButtons() {
  pinMode(b0, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
}

// Move left
void button0() {
  //Serial.println("Left");
  translate_left();
  squareToData();
  lcdLoop();
}

// Rotate
void button1() {
  //Serial.println("Rotate");
  rotate();
  squareToData();
  lcdLoop();
}

// Move right
void button2() {
  //Serial.println("Right");
  translate_right();
  squareToData();
  lcdLoop();
}

// Drop
void button3() {
  //Serial.println("Down");
  translate_down();
  squareToData();
  lcdLoop();
}

void checkButtons() {
  if (digitalRead(b0))
    button0();
  if (digitalRead(b1))
    button1();
  if (digitalRead(b2))
    button2();
  if (digitalRead(b3))
    button3();
}

void setup() {
  Serial.begin(9600);
  // 3 = center of block (used at rotation)
  // Block blueprint 0
  //..2..
  //..2..
  //..3..
  //..2..
  //.....
  block_blueprint[0][0][2] = 2;
  block_blueprint[0][1][2] = 2;
  block_blueprint[0][2][2] = 3;
  block_blueprint[0][3][2] = 2;

  // Block blueprint 1
  //.....
  //..2..
  //..32.
  //..2..
  //.....
  block_blueprint[1][1][2] = 2;
  block_blueprint[1][2][2] = 3;
  block_blueprint[1][2][3] = 2;
  block_blueprint[1][3][2] = 2;

  // Block blueprint 2
  //.....
  //.2...
  //.23..
  //..2..
  //.....
  block_blueprint[2][1][1] = 2;
  block_blueprint[2][2][1] = 2;
  block_blueprint[2][2][2] = 3;
  block_blueprint[2][3][2] = 2;

  // Block blueprint 3
  //.....
  //.22..
  //.23..
  //.....
  //.....
  block_blueprint[3][1][1] = 2;
  block_blueprint[3][1][2] = 2;
  block_blueprint[3][2][1] = 2;
  block_blueprint[3][2][2] = 3;

  // Block blueprint 4
  //.....
  //..2..
  //.23..
  //.2...
  //.....
  block_blueprint[4][1][2] = 2;
  block_blueprint[4][2][1] = 2;
  block_blueprint[4][2][2] = 3;
  block_blueprint[4][3][1] = 2;

  // Block blueprint 5
  //.....
  //.22..
  //..3..
  //..2..
  //.....
  block_blueprint[5][1][1] = 2;
  block_blueprint[5][1][2] = 2;
  block_blueprint[5][2][2] = 3;
  block_blueprint[5][3][2] = 2;

  // Block blueprint 6
  //.....
  //..22.
  //..3..
  //..2..
  //.....
  block_blueprint[6][1][2] = 2;
  block_blueprint[6][1][3] = 2;
  block_blueprint[6][2][2] = 3;
  block_blueprint[6][3][2] = 2;

  // Generate random seed for generating blocks
  int seed = (analogRead(0) + 1) * (analogRead(1) + 1) * (analogRead(2) + 1) * (analogRead(3) + 1);
  randomSeed(seed);
  random(10, 9610806);
  seed = seed * random(3336, 15679912) + analogRead(random(4)) ;
  randomSeed(seed);
  random(10, 98046);

  setupButtons();
  lcdInitialise();

  next = random(7);
  newBlock();
}

void loop() {
  game();
}
