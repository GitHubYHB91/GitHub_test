#include <stdio.h>
void SGFilter(signed short * ResultArray, signed short * InputArray, unsigned short point_len);

void main() {
	
	signed short a[23] = { 1,3,2,4,6,8,8,9,2,1,4,5,6,73,4,5,2,3,7,6,3,5,1 };
	signed short b[23] = { 1,3,2,4,6,8,8,9,2,1,4,5,6,73,4,5,2,3,7,6,3,5,1 };

	SGFilter(&(a[10]), &b[10], 9);
	short jk = 0x1234;
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n",jk >> (i << 2) & 0xf);

	}
}

void SGFilter(signed short * ResultArray, signed short * InputArray, unsigned short point_len)
{
	unsigned short cnt;
	signed short TempArray[5];
	float tempbuffer;

	//float para0[5] = {0.6f, 0.4f, 0.2f, 0.0f, -0.2f};
	float para1[5] = { 0.4f, 0.3f, 0.2f, 0.1f, 0.0f };
	float para2[5] = { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
	float para3[5] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f };
	float para4[5] = { -0.2f, 0.0f, 0.2f, 0.4f, 0.6f };



	tempbuffer = 0.0f;
	for (cnt = 0; cnt<5; cnt++)
		tempbuffer += ((float)InputArray[cnt - 4] * para4[cnt]);
	ResultArray[0] = (signed short)tempbuffer;


	TempArray[0] = ResultArray[0];
	TempArray[1] = InputArray[1];
	TempArray[2] = InputArray[2];
	TempArray[3] = InputArray[3];
	TempArray[4] = InputArray[4];

	tempbuffer = 0.0f;
	for (cnt = 0; cnt<5; cnt++)
		tempbuffer += ((float)TempArray[cnt] * para1[cnt]);
	ResultArray[1] = (signed short)tempbuffer;

	tempbuffer = 0.0f;
	for (cnt = 0; cnt<5; cnt++)
		tempbuffer += ((float)TempArray[cnt] * para2[cnt]);
	ResultArray[2] = (signed short)tempbuffer;

	for (cnt = 3; cnt<(point_len - 2); cnt++)
	{
		tempbuffer = 0.0f;
		for (unsigned short i = 0; i<5; i++)
			tempbuffer += ((float)InputArray[i + cnt - 2] * para2[i]);
		ResultArray[cnt] = (signed short)tempbuffer;
	}

	tempbuffer = 0.0f;
	for (cnt = 0; cnt<5; cnt++)
		tempbuffer += ((float)InputArray[point_len - 5 + cnt] * para3[cnt]);
	ResultArray[point_len - 2] = (signed short)tempbuffer;

	tempbuffer = 0.0f;
	for (cnt = 0; cnt<5; cnt++)
		tempbuffer += ((float)InputArray[point_len - 5 + cnt] * para4[cnt]);
	ResultArray[point_len - 1] = (signed short)tempbuffer;

}