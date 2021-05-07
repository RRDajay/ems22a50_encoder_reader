#include "encoder_reader.h"
#include <stdlib.h>
#include <stdint.h>
//#include <Arduino.h>

void EncoderSetup(struct Encoder* encoder, int chipSelect, int clockPin, int dataPin)
{
    encoder->chipSelect = chipSelect;
    encoder->clockPin = clockPin;
    encoder->dataPin = dataPin;
    encoder->revolutions = 0;
    encoder->lastAngle = 0;
    encoder->reading = 0;

    // encoder->idx = 0;
    // encoder->avg_reading = 0;

    // for (int i = 0; i < READING_SIZE; i++)
    // {
    //     encoder->reading[i] = 0;
    // }

    //pinMode(chipSelect, OUTPUT);
    //pinMode(clockPin, OUTPUT);
    //pinMode(dataPin, INPUT);
}

int _pow(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;

    temp = _pow(x, y / 2);
    if ((y % 2) == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int Read(struct Encoder* encoder)
{
    int pos = 0;
    uint8_t byteArr[16];

    //digitalWrite(encoder->chipSelect, HIGH);
    //digitalWrite(encoder->chipSelect, LOW);

    for (int j = 0; j < 16; j++) {
        //digitalWrite(encoder->clockPin, LOW);
        //digitalWrite(encoder->clockPin, HIGH);
        //byteArr[j] = digitalRead(encoder->dataPin) == HIGH ? 1 : 0;
    }

    //digitalWrite(encoder->clockPin, LOW);
    //digitalWrite(encoder->clockPin, HIGH);

    for (int j = 0; j < 10; j++) {
        pos += byteArr[j] * _pow(2, 10 - (j + 1));
    }

     return pos;       
    
}

float ReadAngle(struct Encoder* encoder)
{
    float pos = Read(encoder);
    float angle = (pos * 360) / 1024;

    if (abs(encoder->lastAngle - angle) > 200)
    {
        if (angle > encoder->lastAngle)
        {
            encoder->revolutions--;
        }
        else
        {
            encoder->revolutions++;
        }
    }

    encoder->lastAngle = angle;

    return angle;

}

float ReadAbsoluteAngle(struct Encoder* encoder)
{
    float angle = ReadAngle(encoder) + encoder->revolutions * 360;

    encoder->reading = angle;

    // encoder->reading[encoder->idx] = angle;

    // encoder->idx++;

    // if(encoder->idx >= 5)
    // {
    //     AverageReading(encoder);
    //     encoder->idx = 0;
    // }
}

// float AverageReading(struct Encoder* encoder)
// {
//     encoder->avg_reading = 0;

//     for (int i = 0; i < READING_SIZE; i++)
//     {
//         encoder->avg_reading += encoder->reading[i];
//     }

//     encoder->avg_reading = encoder->avg_reading/ READING_SIZE;

// }