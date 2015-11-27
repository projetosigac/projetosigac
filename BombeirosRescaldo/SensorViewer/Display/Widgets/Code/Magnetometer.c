/*+ FILE DESCRIPTION -------------------------------------------------------
 DESCRIPTION       : Magnetometer (works only on tablets) 
 VERSION           : $Revision: 16884 $
 MODIFICATION DATE : $Date: 2015-04-27 16:46:17 +0200 (lun., 27 avr. 2015) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies.
---------------------------------------------------------------------------- +*/

#include "sgl_types.h"
#include "sgl.h"
#include "imported_sensors.h"

#ifndef accelerometer_event
sdy_magnetometer_event_t magnetometer_event = {0,0.0,0.0,0.0};
#endif

void magnetometer(SGLfloat (*x), SGLfloat (*y), SGLfloat (*z)){
	if (x != SGL_NULL) {
		*x = magnetometer_event.x;
	}
	if (y != SGL_NULL) {
		*y = magnetometer_event.y;
	}
	if (z != SGL_NULL) {
		*z = magnetometer_event.z;
	}
}
