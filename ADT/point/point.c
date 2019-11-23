/*Nama: Panawar Hasibuan*/
/*NIM: 3517129*/
/* File: point.c */
/* Tanggal: 28 Agustus 2016 */
/*Deskripsi: Realisasi dari file poin.h*/
/*Topik: ADT Sederhana*/
/* *** Definisi ABSTRACT DATA TYPE POINT *** */


#include "point.h"
#include <stdio.h>
#include <math.h>

//typedef struct {
//	float X; /* absis   */
//	float Y; /* ordinat */
//} POINT;

/* *** Notasi Akses: Selektor POINT *** */
//#define Absis(P) (P).X
//#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	//kamus
	POINT P;
	//algoritma
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	//kamus
	float x,y;
	//algoritma
	scanf("%f %f",&x,&y);
	*P = MakePOINT(x,y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	//algoritma
	printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT p1, POINT p2)
  //Mengirimkan true jika P1 tidak sama dengan P2
  {
    //algoritma
    return !EQ(p1,p2);
  }

// *** Kelompok menentukan di mana P berada ***
 boolean IsOrigin (POINT p)
 //Menghasilkan true jika P adalah titik origin
 {
   //algoritma
    return (Absis(p)==0 && Ordinat(p)==0);
 }
 boolean IsOnSbX (POINT p)
 //Menghasilkan true jika P terletak Pada sumbu X
 {
    //algoritma
    return (Ordinat(p)==0);
 }
 boolean IsOnSbY (POINT p)
 //Menghasilkan true jika P terletak pada sumbu Y
 {
    //algoritma
    return (Absis(p)==0);
 }
 int Kuadran (POINT p)
 /*Menghasilkan kuadran dari P: 1, 2, 3, atau 4
    Prekondisi : P bukan Titik Origin,
                 dan P tidak terletak di salah satu sumbu  */
 {
    //algoritma
    if (Absis(p)>0 && Ordinat(p)>0) return 1;
    else if (Absis(p)<0 && Ordinat(p)>0) return 2;
    else if (Absis(p)<0 && Ordinat(p)<0) return 3;
    else if (Absis(p)>0 && Ordinat(p)<0) return 4;
 }

// *** KELOMPOK OPERASI LAIN TERHADAP TYPE ***
POINT NextX (POINT p)
//Mengirim salinan P dengan Absis ditambah satu
{
    //algoritma
    return MakePOINT(Absis(p) +=1,Ordinat(p));
}
POINT NextY (POINT p)
//Mengirim salinan P dengan Ordinat ditambah satu
{
    //algoritma
    return MakePOINT(Absis(p),Ordinat(p) +=1);
}
POINT PlusDelta (POINT p, float deltaX, float deltaY)
/*Mengirim salinan P Yang AbsisnYa adalah Absis(P) + deltaX dan OrdinatnYa adalah
    Ordinat(P) + deltaY */
{
    //algoritma
    return MakePOINT(Absis(p) += deltaX,Ordinat(p) += deltaY);
}
POINT MirrorOf (POINT p, boolean sbX)
/*Menghasilkan salinan P Yang dicerminkan terhadap salah satu sumbu
    Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
    Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    //algoritma
    float X = Absis(p);
    float Y = Ordinat(p);
    return (sbX) ? (MakePOINT(X,(Y!=0) ?-Y:0)) : (MakePOINT((X!=0)?-X:0,Y));
}
float Jarak0 (POINT p)
//Menghitung jarak P ke (0,0)
{
    //algoritma
    return sqrt(pow(p.X,2)+pow(p.Y,2));
}
float Panjang (POINT p1, POINT p2)
/*Menghitung panjang garis Yang dibentuk P1 dan P2
  menghitung panjang berdasarkan rumus Panjang= ((p1.X-p2.X)^2+(p1.Y-p2.Y)^2)^0.5*/
{
    //algoritma
    return sqrt( pow(p1.X-p2.X,2)+ pow(p1.Y-p2.Y,2));
}
void Geser (POINT *p, float deltaX,float deltaY)
/*I.S. P terdefinisi
  F.S. P digeser, AbsisnYa sebesar deltaX dan OrdinatnYa sebesar deltaY */
{
    //algoritma
    *p = PlusDelta(*p,deltaX,deltaY);
}
void GeserKeSbX (POINT *p)
/*I.S. P terdefinisi
  F.S. P berada pada sumbu X dengan Absis sama dengan Absis semula.
  Proses : P digeser ke sumbu X.
  Contoh : Jika koOrdinat semula (9,9), maka menjadi (9,0) */
{
    //algoritma
    *p = MakePOINT(Absis(*p),0);
}
void GeserKeSbY (POINT *p)
/*I.S. P terdefinisi
  F.S. P berada pada sumbu Y dengan Ordinat Yang sama dengan semula.
  Proses : P digeser ke sumbu Y.
  Contoh : Jika koOrdinat semula (9,9), maka menjadi (0,9) */
{
    //algoritma
    *p = MakePOINT(0,Ordinat(*p));
}
void Mirror (POINT *p,boolean sbX)
/*I.S. P terdefinisi
  F.S. P dicerminkan tergantung nilai SbX atau SbY
  Jika SbX true maka dicerminkan terhadap sumbu X
  Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    //algoritma
    *p = MirrorOf(*p,sbX);
}
void Putar(POINT *p, float sudut)
/*I.S. P terdefinisi
  F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0)  */
{
	//kamus
	float jarak;
    //algoritma
    sudut *= M_PI/180.0;
    jarak = Jarak0(*p);
    *p= MakePOINT(jarak*cos(sudut),jarak*sin(sudut));
}
