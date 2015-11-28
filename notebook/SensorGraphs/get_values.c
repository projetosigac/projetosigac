#include <stdio.h>
#include "sgl.h"

void get_values(SGLfloat (*temperature), SGLfloat (*heart_beat), SGLuint8 (*bpm)[255UL]) {
	FILE *f = fopen("values.data", "r");
	if (f) {
		float t, hb, b;
		if (fscanf(f, "%f %f %f", &t, &hb, &b) == 3 && !ferror(f)) {
			*temperature = t;
			*heart_beat = hb;
			sprintf((char*)bpm, "%.1f", b);
		}
		fclose(f);
	}
}