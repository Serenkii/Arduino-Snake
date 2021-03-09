enum SnakeDirection {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

#define SNAKE_MAX_LENGTH 32

class Snake {

  byte size;
  byte body[SNAKE_MAX_LENGTH][2];
  byte direction;
    
public:
  Snake(byte headPositionX, byte headPositionY, SnakeDirection facing) {
      setSize(1);
      setDirection(facing);
      body[0][0] = headPositionX;
      body[0][1] = headPositionY;
  }

  byte getBodyPartX(byte index) {
    return body[index][0];
  }
  byte getBodyPartY(byte index) {
    return body[index][1];
  }

  void setBodyPartX(byte index, byte x) {
    body[index][0] = x;
  }
  void setBodyPartY(byte index, byte y) {
    body[index][1] = y;
  }

  void turnRight() {
    Serial.print("turnRight() was called | direction was: ");
    Serial.println(direction);
    direction++;
    if (direction >= 4) {
      direction = 0; 
    }
    Serial.print("direction is now: ");
    Serial.println(direction);
  }
  void turnLeft() {
    Serial.print("turnLeft() was called | direction was: ");
    Serial.println(direction);
    direction--;
    if (direction < 0 || direction > 200) {   //it seems like byte direction cant be negative for some reason
      direction = 3; 
    }
    Serial.print("direction is now: ");
    Serial.println(direction);
  }
  
  void setDirection(SnakeDirection facing) {
    direction = facing;
    Serial.print("Snake is now facing ");
    Serial.println(facing);     //debug
  }
  SnakeDirection getDirection() {
    return direction;
  }

  void setSize(byte newSize) {
    if (newSize < 1) {
      newSize = 1;
    }
    if (newSize > 60) {
      newSize = 60;
    }
    size = newSize;
  }
  
  byte getSize() {
    return size;
  }
  
  byte getHeadPositionX() {
    return body[0][0];
  }
  
  byte getHeadPositionY() {
    return body[0][1];
  }


  bool move() {
    for (int i = size - 1; i > 0 ; i--) {
      body[i][0] = body[i - 1][0];
      body[i][1] = body[i - 1][1];
    }
    if (direction == UP) {
      Serial.println("move UP");
      body[0][1]++;
    }
    else if (direction == DOWN) {
      Serial.println("move DOWN");
      body[0][1]--;
    }
    else if (direction == LEFT) {
      Serial.println("move LEFT");
      body[0][0]--;
    }
    else if (direction == RIGHT) {
      Serial.println("move RIGHT");
      body[0][0]++;
    }
    else {
      Serial.println("problem with direction");
    }

    if (outOfBound()) {
      Serial.println("out of bound -- debug shutdown in 10000ms");
      delay(10000);
      exit(0);
      return false;
      
    }
    return true;
  }

  bool outOfBound() {
    if (body[0][0] < 0 || body[0][0] >= 8) {
      return true;
    }
    if (body[0][1] < 0 || body[0][1] >= 8) {
      return true;
    }
    return false;
  }
  
  
};
