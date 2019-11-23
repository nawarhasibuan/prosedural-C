/* File: jam.c
   Deskripsi:
   Isi: realisasi/ kode program dari semua prototype yang
        didefinisikan pada jam.h .*/

#include <stdio.h>
#include "jam.h"

/******************************************************************
  DEFINISI PRIMITIF
  ***************************************************************** */

  // Validasi tipe data
    boolean IsJAMValid (int h, int m, int s)
    /* Mengirim true  jika H,M,S dapat membentuk J yang valid
      dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    {
      //algoritma
      return (( (h>=0)&&(h<=23) )&&( (m>=0)&&(m<=59) )&&( (s>=0)&&(s<=59) ));
    }

  // Konstruktor: Membentuk sebuah JAM dari komponen-komponennya
    JAM MakeJAM (int hh, int mm, int ss)
    /* Membentuk sebuah JAM dari komponen-komponennya yang valid
      Prekondisi : HH, MM, SS valid untuk membentuk JAM */
    {
      //kamus
      JAM j;
      //algoritma
      Hour(j) = hh;
      Minute(j) = mm;
      Second(j) = ss;
      return j;
    }

/******************************************************************
  KELOMPOK BACA/TULIS
  ***************************************************************** */

  void BacaJAM (JAM *j)
  /*I.S. : J tidak terdefinisi
    F.S. : J terdefinisi dan merupakan jam yang valid
    Proses : mengulangi membaca komponen H,M,S sehingga membentuk J
    yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
  {
    //kamus
    int h,m,s;
    //algoritma
    do {
      scanf("%d %d %d",&h,&m,&s);
      if (!IsJAMValid(h,m,s))
      {
        printf("Jam tidak valid\n");
      }
    } while(!IsJAMValid(h,m,s));
    *j = MakeJAM(h,m,s);
  }

  void TulisJAM (JAM j)
  /*I.S. : J sembarang
    F.S. :   Nilai J ditulis dg format HH:MM:SS
    Proses : menulis nilai setiap komponen J ke layar */
  {
    //algoritma
    printf("%02d:%02d:%02d",Hour(j),Minute(j),Second(j));
  }

/******************************************************************
  KELOMPOK KONVERSI TERHADAP TYPE
  ***************************************************************** */
  long JAMToDetik (JAM j)
  /*Diberikan sebuah JAM, mengkonversi menjadi jumlah Detik dari pukul 0:0:0
    Rumus : detik = 3600*HH + 60*MM + SS
    nilai maksimum = 3600*23+59*60+59 = 86399
    Hati-hati dengan representasi integer pada bahasa implementasi
    kebanyakan sistem mengimplementasi integer,
    bernilai maksimum kurang dari nilai maksimum hasil konversi */
  {
    return (3600*Hour(j) + 60*Minute(j) + Second(j));
  }

  JAM DetikToJAM (long n)
  /*Mengirim  konversi detik ke JAM
    Pada beberapa bahasa, representasi integer tidak cukup untuk
    menampung N
    Catatan: Jika N ≥ 86400, maka harus dikonversi dulu menjadi jumlah detik yang
    mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan
    rumus: N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
  {
    //kamus
    JAM j;
    long detik = n%86400;
    //algotima
    return MakeJAM((int)detik/3600,((int)detik%3600)/60,(int)detik%60);
  }

/******************************************************************
  KELOMPOK OPERASI TERHADAP TYPE
  ***************************************************************** */

  //Kelompok Operator Relational
    boolean JEQ (JAM j1, JAM j2)
    //Mengirimkan true jika J1=J2, false jika tidak
    {
      //algoritma
      return (JAMToDetik(j1)==JAMToDetik(j2));
    }
    boolean JNEQ (JAM j1, JAM j2)
    //Mengirimkan true jika J1 tidak sama dengan J2
    {
      //algoritma
      return (!JEQ(j1,j2));
    }
    boolean JLT (JAM j1, JAM j2)
    //Mengirimkan true jika J1<J2 , false jika tidak
    {
      //algotima
      return (JAMToDetik(j1)<JAMToDetik(j2));
    }
    boolean JGT (JAM j1, JAM j2)
    //Mengirimkan true jika J1>J2, false jika tidak
    {
      //algotima
      return (JAMToDetik(j1)>JAMToDetik(j2));
    }

  //Operator aritmatika JAM
    JAM NextDetik (JAM j)
    //Mengirim 1 detik setelah J dalam bentuk JAM
    {
      //algoritma
      return  DetikToJAM(JAMToDetik(j)+1);
    }
    JAM NextNDetik (JAM j, int n)
    //Mengirim N detik setelah J dalam bentuk JAM
    {
      //algoritma
      for (int i = 0; i < n; i++) {
        j = NextDetik(j);
      }
      return j;
    }
    JAM PrevDetik (JAM j)
    //Mengirim 1 detik sebelum J dalam bentuk JAM
    {
      //algoritma
      long temp = JAMToDetik(j);
      if (temp>0) return DetikToJAM(temp-1);
      else return DetikToJAM(86399);
    }
    JAM PrevNDetik (JAM j, int n)
    //Mengirim N detik sebelum J dalam bentuk JAM
    {
      //algoritma
      for (int i = 0; i < n; i++) {
        j = PrevDetik(j);
      }
      return  j;
    }

  //Kelompok Operator Aritmetika
    long Durasi (JAM Jaw, JAM Jakh)
    //Mengirim Jakh-Jaw dlm Detik, dengan kalkulasi
    //Jika Jaw > Jakh, maka Jakh adalah 1 hari setelah Jaw
    {
      //kamus
      //algoritma
      if (JGT(Jaw,Jakh)) return JAMToDetik(Jakh)-JAMToDetik(Jaw)+86400;
      else return JAMToDetik(Jakh)-JAMToDetik(Jaw);
    }
