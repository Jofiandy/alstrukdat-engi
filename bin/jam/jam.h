/*
	File	: jam.h
	Tanggal	: 1 November 2018
	Definisi ADT Jam Tubes
*/

#ifndef ADTJAMTUBES_H
#define ADTJAMTUBES_H

#include <stdio.h>

/* Definisi Struct Waktu (D	H:M:S) */
typedef struct{
	int H;
	int M;
	int S;
	int Day;
	} Waktu;

/* Selektor Jam */
#define Hour(T) (T).H		
#define Min(T) (T).M
#define Sec(T) (T).S
#define Day(T) (T).Day

/* Asumsi game dimulai dari Day 0 dan Jam 0:0:0 */
/* Definisi waktu memulai game H:M:S -> 0:0:0 */
/* Definisi hari memulai game D -> 0 */

/* =============================================*/
/*			Membuat Waktu Mulai Game		 	*/
/* =============================================*/

Waktu CreateWaktu(int h, int m, int s, int d);
void CreateStart(Waktu *Time);
/*
	IS		: Time tidak terdefinisi
	FS		: Time terdefinisi sebagai waktu awal mulai game
	Proses	: Mendefinisikan setiap komponen Time dengan integer 0
*/


/* =============================================*/
/*				Update Waktu				 	*/
/* =============================================*/
void UpDate (Waktu *Time, int n);
/*
	IS		: Time sembarang dan terdefinisi
	FS		: Time diupdate
	Proses	: Menaikkan komponen S dari J sebanyak 1
			  Bila S > 59, maka S diset menjadi 0 dan komponen M bertabah 1
			  Bila M > 59, maka M diset menjadi 0 dan komponen H bertambah 1
			  Bila H > 23, maka H diset menjadi 0 dan D bertambah 1
*/


/* =============================================*/
/*				Menampilkan Waktu				 	*/
/* =============================================*/
void TulisWaktu(Waktu Time);
/*
	IS		: Time sembarang dan terdefinisi
	FS		: Nilai komponen jam dari Time tertulis dalam format H:M:S dan hari dari waktu dalam format D-D(nilai D)
	Proses	: Menuliskan satu per satu komponen jam ke layar dalam format H:M:S dan menampilkan komponen hari dalam D-D(nilai D)
*/

void TulisWaktuKesabaran(Waktu Time);

void TulisFileJam(Waktu Time, FILE *f);

#endif