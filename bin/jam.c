/*
	File	: jam.c
	Tanggal	: 1 November 2018
	Body ADT Jam Tubes
*/

#include <stdio.h>
#include "jam.h"

/* Asumsi game dimulai dari Day 0 dan Jam 0:0:0 */
/* Definisi waktu memulai game H:M:S -> 0:0:0 */
/* Definisi hari memulai game D -> 0 */

/* =============================================*/
/*			Membuat Waktu Mulai Game		 	*/
/* =============================================*/

Waktu CreateWaktu(int h, int m, int s, int d){
	Waktu T;
	T.H = h;
	T.M = m;
	T.S = s;
	T.Day = d;
	return T;
}

void CreateStart(Waktu *Time)
/*
	IS		: Time tidak terdefinisi
	FS		: Time terdefinisi sebagai waktu awal mulai game
	Proses	: Mendefinisikan setiap komponen Time dengan integer 0
*/
{
	Hour(*Time) = 0;
	Min(*Time) = 0;
	Sec(*Time) = 0;
	Day(*Time) = 0;
}

/* =============================================*/
/*				Update Waktu				 	*/
/* =============================================*/
void UpDate (Waktu *Time,int n)
/*
	IS		: Time sembarang dan terdefinisi, n terdefinisi
	FS		: Time diupdate
	Proses	: Menaikkan komponen S dari J sebanyak n
			  Bila S > 59, maka S diset menjadi S mod 60 dan komponen M bertabah 1
			  Bila M > 59, maka M diset menjadi M mod 60 dan komponen H bertambah 1
			  Bila H > 23, maka H diset menjadi H mod 24 dan D bertambah 1
*/
{
	Sec(*Time)+=n;
	if(Sec(*Time) > 59)
	{
		Min(*Time) += (Sec(*Time)/60);
		Sec(*Time) %= 60;
		if(Min(*Time) > 59)
		{
			Hour(*Time) += (Min(*Time)/60);
			Min(*Time) %= 60;
			if(Hour(*Time) > 23)
			{
				Day(*Time) += (Hour(*Time)/23);
				Hour(*Time) %= 24;	
			}	
		}	
	}
}

/* =============================================*/
/*				Menampilkan Waktu				 	*/
/* =============================================*/
void TulisWaktu(Waktu Time)
/*
	IS		: Time sembarang dan terdefinisi
	FS		: Nilai komponen jam dari Time tertulis dalam format H:M:S dan hari dari waktu dalam format D-D(nilai D)
	Proses	: Menuliskan satu per satu komponen jam ke layar dalam format H:M:S dan menampilkan komponen hari dalam D-D(nilai D)
*/
{
	printf("Day-%d   Current time: %d:%d:%d\n",Day(Time),Hour(Time),Min(Time),Sec(Time));
}

void TulisWaktuKesabaran(Waktu Time)
{
	printf("Day-%d   Time: %d:%d:%d\n",Day(Time),Hour(Time),Min(Time),Sec(Time));
}

void TulisFileJam(Waktu Time, FILE *f){
	fprintf(f, "%d %d %d %d", Day(Time), Hour(Time),Min(Time), Sec(Time));
	fprintf(f,"\n");
}