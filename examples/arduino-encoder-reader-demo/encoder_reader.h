/*
 * encoder_reader.h
 *
 *  Created on: Apr 23, 2021
 *      Author: ryanr
 */

#ifndef INC_ENCODER_READER_H_
#define INC_ENCODER_READER_H_

//#define READING_SIZE 5

typedef struct Encoder {
	int chipSelect;
	int clockPin;
	int dataPin;
	int revolutions;

	float lastAngle;

	volatile float reading;

} Encoder_t;

void EncoderSetup(struct Encoder* encoder, int chipSelect, int clockPin, int dataPin);

float ReadAngle(struct Encoder* encoder);
float ReadAbsoluteAngle(struct Encoder* encoder);

int Read(struct Encoder* encoder);
int _pow(int x, unsigned y);

#endif /* INC_ENCODER_READER_H_ */
