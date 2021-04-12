void setup()
{
    Serial.begin(9600);
    pinMode(A5, INPUT);
}

void loop()
{
    int keypadVal = analogRead(A5);
    if (keypadVal > 100)
    {
        Serial.print(getKey(keypadVal));
        Serial.print(" (");
        Serial.print(keypadVal);
        Serial.println(")");
    }
}

char getKey(int keypadVal)
{
    if (keypadVal < 204)
    {
        return 'D';
    }
    else if (keypadVal < 218)
    {
        return 'C';
    }
    else if (keypadVal < 229)
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