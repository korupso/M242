// Set keypad pin
int keypadPin = A5;

// Set water pump pins
int pumpPinA = 2;
int pumpPinB = 3;
int pumpPinC = 4;
int pumpPinD = 5;

// Initialize state of pumps
boolean running = false;

void setup()
{
    // Start console output
    Serial.begin(9600);

    // Set keypad pin as input
    pinMode(A5, INPUT);

    // Set water pump pins as output
    pinMode(pumpPinA, OUTPUT);
    pinMode(pumpPinB, OUTPUT);
    pinMode(pumpPinC, OUTPUT);
    pinMode(pumpPinD, OUTPUT);

    // Set water pump pins to HIGH
    digitalWrite(pumpPinA, HIGH);
    digitalWrite(pumpPinB, HIGH);
    digitalWrite(pumpPinC, HIGH);
    digitalWrite(pumpPinD, HIGH);
}

void loop()
{
    if (!running)
    {
        // Read keypad input
        int keypadVal = analogRead(A5);
        if (keypadVal > 100)
        {
            char key = getKey(keypadVal);
            switch (key)
            {
            case 'A':
                testPump(pumpPinA);
                break;
            case 'B':
                testPump(pumpPinB);
                break;
            case 'C':
                testPump(pumpPinC);
                break;
            case 'D':
                testPump(pumpPinD);
            }

            char str[8];
            sprintf(str, "%c (%d)", key, keypadVal);
            Serial.println(str);
        }
    }
}

void testPump(int pin)
{
    running = true;
    digitalWrite(pin, LOW);
    delay(1000);
    digitalWrite(pin, HIGH);
    running = false;
}

char getKey(int keypadVal)
{
    if (keypadVal < 204)
    {
        return 'D';
    }
    else if (keypadVal < 213)
    {
        return 'C';
    }
    else if (keypadVal < 227)
    {
        return 'B';
    }
    else if (keypadVal < 258)
    {
        return 'A';
    }
    else if (keypadVal < 299)
    {
        return '#';
    }
    else if (keypadVal < 329)
    {
        return '9';
    }
    else if (keypadVal < 355)
    {
        return '6';
    }
    else if (keypadVal < 377)
    {
        return '3';
    }
    else if (keypadVal < 422)
    {
        return '0';
    }
    else if (keypadVal < 486)
    {
        return '8';
    }
    else if (keypadVal < 535)
    {
        return '5';
    }
    else if (keypadVal < 563)
    {
        return '*';
    }
    else if (keypadVal < 637)
    {
        return '2';
    }
    else if (keypadVal < 778)
    {
        return '7';
    }
    else if (keypadVal < 939)
    {
        return '4';
    }
    else
    {
        return '1';
    }
}