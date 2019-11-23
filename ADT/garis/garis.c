/*Nama: Panawar Hasibuan*/
/*NIM: 13517129*/
/*Topik: ADT Sederhana*/
/*Deskripsi: */
/* File: garis.c */
/* Tanggal: 29 Agustus 2019 */
/* Definisi ADT GARIS, menggunakan ADT point */
//#ifndef GARIS_H
//#define GARIS_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
#include "garis.h"
#include <stdio.h>

/* *** Definisi TYPE GARIS *** */
//typedef struct {
  //POINT PAw;  /* Titik Awal  */
  //POINT PAkh; /* Titik Akhir */
//} GARIS;

/* *** Selektor GARIS *** */
//#define PAwal(L) (L).PAw
//#define PAkhir(L) (L).PAkh
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
    //algoritma
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
    //kamus
    POINT P1,P2;
    boolean valid;
    //algoritma
    valid = false;
    //pengulangan pembaccan garis sampai pembaccan valid
    while (!valid) {
        BacaPOINT(&P1);
        BacaPOINT(&P2);
        if(NEQ(P1,P2)) {
            valid = true;
        } else {
            printf("Garis tidak valid\n");
        }
    }
    MakeGARIS(P1,P2,L);
}
void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : berikan rumusnya */
{
    /*RUMUS*/
    /*GARIS L degeser sejauh (-1)*Absis(PAwal(L)) arah sumbu X dan (-1)*Ordinat(PAwal(L)) arah sumbu Y*/
    /*PanjangGaris == Jarak0(PAkhir(L)) dari garis yang sudah digeser*/
    //kamus
    float jarak;
    POINT p;
    //algoritma
    p = PAwal(L);
    GeserGARIS(&L,(-1)*Absis(p),(-1)*Ordinat(p));
    jarak = Jarak0(PAkhir(L));
    return jarak;
}
float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    //kamus
    float m;
    //algoritma
    m = (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
    return m;
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
    //algoritma
    Geser(&PAwal(*L),deltaX,deltaY);
    Geser(&PAkhir(*L),deltaX,deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
    return (Gradien(L1)*Gradien(L2) == -1);
}
boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    return (Gradien(L1) == Gradien(L2));
}

//#endif