/*Nama: Panawar Hasibuan*/
/*NIM: 135171298/
/*Topik: ADT Sederhana*/
/*Deskripsi: implementasi vector.h, dibuat dengan memanfaatkan ADT point*/
/* File: vector.c */
/* Tanggal: 29 Agustus 2019 */
#include "point.h"
#include "vector.h"
#include <stdio.h>

//#ifndef VECTOR_H
//#define VECTOR_H

/* *** Definisi ABSTRACT DATA TYPE VECTOR *** */
//#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
//#define AbsisComponent(V) Absis(V)
//#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
	//kamus
	VECTOR v;
	//algoritma
	v = MakePOINT(x,y);
	return v;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
	printf("<%.2f,%.2f>",AbsisComponent(v),OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
	return Jarak0(v);
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
	//kamus
	VECTOR v;
	//algoritma
	v = MakeVector(AbsisComponent(a)+AbsisComponent(b),OrdinatComponent(a)+OrdinatComponent(b));
	return v;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
	//kamus
	VECTOR v;
	//algoritma
	v = MakeVector(AbsisComponent(a)-AbsisComponent(b),OrdinatComponent(a)-OrdinatComponent(b));
	return v;
}
float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
	//kamus
	float value;
	//algoritma
	value = AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b);
	return value;
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
	//kamus
	VECTOR vt;
	//algoritma
	vt = MakeVector(s*AbsisComponent(v),s*OrdinatComponent(v));
	return vt;
}

//#endif