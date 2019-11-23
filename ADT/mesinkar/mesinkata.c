/*
  Nama      :Panawar Hasibuan
  NIM       :13517129
  Nama file :mesinkata.h
  Topik     :ADT
  Deskripsi :implementasi "ADT mesinkata.h"
  Tanggal   :26 September 2019
*/

#include "boolean.h"
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  //algoritma
  while (CC==BLANK)
    ADV();
  //CC!=BLANK
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  //algoritma
  START();
  IgnoreBlank();
  EndKata = false;
  ADVKATA();
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  //algoritma
  if (CC!=MARK) {
    SalinKata();
    IgnoreBlank();
  }
  else EndKata = true;
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  //kamus
  CKata.Length = 0;
  //algoritma;
  while(CC!=BLANK && CC != MARK) {
    if (CKata.Length<NMax) {
      CKata.TabKata[++CKata.Length] = CC;
    }
    ADV();
  } //CC == MARK || CC == BLANK
}
