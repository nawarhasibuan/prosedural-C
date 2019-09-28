
/* Nama / NIM	: Panawar Hasibuan / 13517129				*/
/* Nama File	: matriks.c 										*/
/* Topik		: ADT MATRIKS 										*/
/* Tanggal		: 19 September 2019									*/
/* Deskripsi	: IMPLEMENTASI ADT MATRIKS							*/

/* File Include */
#include "boolean.h"
#include <stdio.h>
#include "matriks.h"

/*	DEFINISI PROTOTIPE PRIMITIF */
/*	Konstruktor pembentuk MATRIKS */
void MakeMATRIKS (int NB, int NK, MATRIKS *M) {
/*	Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” 
	memori 
	I.S. 	: NB dan NK adalah valid untuk memori matriks yang dibuat 
	F.S. 	: Matriks M sesuai dengan definisi di atas terbentuk */
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}

/*	Selektor "DUNIA MATRIKS" */
boolean IsIdxValid (int i, int j) {
/*	Mengirimkan true jika i, j adalah indeks yang valid */
	return ((i<=BrsMax)&&(i>=BrsMin)&&(j<=KolMax)&&(j>=KolMin));
}

/*	Untuk sebuah matriks M yang terdefinisi: */
indeks GetFirstIdxBrs (MATRIKS M) {
/*	Mengirimkan indeks baris terkecil M */
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M) {
	/*	Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M) {
/* 	Mengirimkan indeks baris terbesar M */
	return (M).NBrsEff;	
}
indeks GetLastIdxKol (MATRIKS M) {
	/*	Mengirimkan indeks kolom terbesar M */
	return (M).NKolEff;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return ((i>=GetFirstIdxBrs(M))&&(i<=GetLastIdxBrs(M))&&(j>=GetFirstIdxKol(M))&&(j<=GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i) {
/* 	Mengirimkan elemen M(i,i) */
	return M.Mem[i][i];
}

/*	Assignment  MATRIKS */
void CopyMATRIKS (MATRIKS MIn, MATRIKS *MHsl) {
/*	Melakukan assignment MHsl ← Min */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++) {
		for (j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++) {
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}

/*	KELOMPOK BACA/TULIS */
void BacaMATRIKS (MATRIKS *M, int NB, int NK) {
/*	I.S. 	: IsIdxValid(NB,NK)
	F.S. 	: M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK
			  Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya
			  dari pembacaan dengan traversal per baris */
	/*	Kamus */
	indeks i,j;
	ElType X;
	/*	Algoritma */
	MakeMATRIKS(NB,NK,M);
	for (i=1;i<=NB;i++) {
		for (j=1;j<=NK;j++) {
			scanf("%d",&X);
			Elmt(*M,i,j) = X;
		}
		printf("\n");
	}
}
void TulisMATRIKS (MATRIKS M) {
/*	I.S. 	: M terdefinisi
	F.S. 	: Sama dengan I.S, dan nilai M(i,j) ditulis ke layar
			  Menulis nilai setiap indeks dan elemen M ke layar dengan 
			  traversal per baris */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=GetFirstIdxBrs(M);i<GetLastIdxBrs(M);i++) {
		printf("[");
		for (j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++) {
			printf("%d ",Elmt(M,i,j));
		}
		printf("%d",Elmt(M,i,j));
		printf("]");
		printf("\n");
	}
	printf("[");
	for (j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++) {
		printf("%d ",Elmt(M,i,j));
	}
	printf("%d",Elmt(M,i,j));
	printf("]");
}

/*	KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : M1  berukuran sama dengan M2
	Mengirim hasil penjumlahan matriks: M1 + M2 */
	/*	Kamus */
	MATRIKS M;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M);
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++) {
			Elmt(M,i,j) = (Elmt(M1,i,j)+Elmt(M2,i,j));
		}
	}
	return M;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : M berukuran sama dengan M
	Mengirim hasil pengurangan matriks: salinan M1 – M2 */
	/*	Kamus */
	MATRIKS M;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M);
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++) {
			Elmt(M,i,j) = (Elmt(M1,i,j)-Elmt(M2,i,j));
		}
	}
	return M;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
/*	Prekondisi : Ukuran baris efektif M1 = ukuran kolom efektif M2
	Mengirim hasil perkalian matriks: salinan M1 * M2 */
	/*	Kamus */
	MATRIKS M;
	ElType X;
	indeks i,j,k;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M);
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++) {
		for (j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++) {
			X=0;
			for (k=GetFirstIdxKol(M1);k<=GetLastIdxKol(M1);k++) {
				X+=Elmt(M1,i,k)*Elmt(M2,k,j);
			}
			Elmt(M,i,j) = X;
		}
	}
	return M;
}
MATRIKS KaliKons (MATRIKS M, int X) {
/*	Mengirim hasil perkalian setiap elemen M dengan X */
	/*	Kamus */
	MATRIKS MK;
	indeks i,j;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MK);
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++) {
			Elmt(MK,i,j) = (X*Elmt(M,i,j));
		}
	}
	return MK;
}
void  PKaliKons(MATRIKS *M, int K) {
/*	Mengalikan setiap elemen M dengan K */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++) {
			Elmt(*M,i,j) = (K*Elmt(*M,i,j));
		}
	}
}

/*	KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS */
boolean EQ (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan 
	untuk setiap i,j yang merupakan indeks baris dan kolom
	M1(i,j) = M2(i,j) */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (NBElmt(M1)!=NBElmt(M2)) {
		cek=false;
	} else {
		i=GetFirstIdxBrs(M1);
		while ((i<=GetLastIdxBrs(M1))&&(cek)) {
			j=GetFirstIdxKol(M1);
			while ((j<=GetLastIdxKol(M1))&&(cek)) {
				if (Elmt(M1,i,j)!=Elmt(M2,i,j)) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean NEQ (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika not EQ(M1,M2) */
	return (!EQ(M1,M2));	
}
boolean EQSize (MATRIKS M1, MATRIKS M2) {
/*	Mengirimkan true jika ukuran efektif matriks M1 sama dengan 
	ukuran efektif M2 yaitu NBrsEff(M1) = NBrsEff (M2) dan 
	NKolEff (M1) = NKolEff (M2) */
	return ((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2)));
}

/*	Operasi lain */
int NBElmt (MATRIKS M) {
/*	Mengirimkan banyaknya elemen M */
	return GetLastIdxKol(M)*GetLastIdxBrs(M);
}

/*	KELOMPOK TEST TERHADAP MATRIKS */
boolean IsBujurSangkar (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks dengan ukuran baris dan kolom
	sama */
	return GetLastIdxKol(M)==GetLastIdxBrs(M);	
}
boolean IsSimetri (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
	dan untuk setiap elemen M, M(i,j)=M(j,i) */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (!IsBujurSangkar(M)) {
		cek=false;
	} else {
		i=GetFirstIdxBrs(M);
		while ((i<=GetLastIdxBrs(M))&&(cek)) {
			j=GetFirstIdxKol(M);
			while ((j<=GetLastIdxKol(M))&&(cek)) {
				if (Elmt(M,i,j)!=Elmt(M,j,i)) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean IsSatuan (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) 
	dan setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal
	bernilai 0 */
	/*	Kamus */
	boolean cek=true;
	indeks i,j;
	/*	Algoritma */
	if (!IsBujurSangkar(M)) {
		cek=false;
	} else {
		i=GetFirstIdxBrs(M);
		while ((i<=GetLastIdxBrs(M))&&(cek)) {
			j=GetFirstIdxKol(M);
			while ((j<=GetLastIdxKol(M))&&(cek)) {
				if ((i==j)&&(GetElmtDiagonal(M,i)!=1)) {
					cek=false;
				} else if (Elmt(M,i,j)!=0) {
					cek=false;
				}
				j++;
			}
			i++;
		}
	}
	return cek;
}
boolean IsSparse (MATRIKS M) {
/*	Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan
	definisi: hanya maksimal 5% dari memori matriks yang efektif bukan
	bernilai 0 */
	/*	Kamus */
	float percent=0,jumlah=0;
	indeks i,j;
	/*	Algoritma */
	for (i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++) {
		for (j=GetFirstIdxKol(M);j<=NKolEff(M);j++) {
			if (M.Mem[i][j]!=0) {
				jumlah++;
			}
		}
	}
	percent=jumlah/(NBrsEff(M)*NKolEff(M));
	return percent<=0.05;
}
MATRIKS Inverse1 (MATRIKS M) {
/*	Menghasilkan salinan M dg setiap elemen "di-invers", yaitu dinegasikan */
	/*	Kamus */
	indeks i,j;
	MATRIKS MI;
	/*	Algoritma */
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MI);
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++) {
			Elmt(MI,i,j) = -Elmt(M,i,j);
		}
	}
	return MI;
}
float Determinan (MATRIKS M) {
/*	Prekondisi: IsBujurSangkar(M)
	Menghitung nilai determinan M */
	/*	Kamus */
	MATRIKS MOBE;
	float pengurang,determinan=1;
	indeks i,j,k;
	/*	Algoritma */
	/*	Menggunakan Operasi Baris Elementer */
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MOBE);
	CopyMATRIKS(M,&MOBE);
	for (i=GetFirstIdxKol(M);i<=GetLastIdxKol(M);i++) {
		Elmt(MOBE,GetFirstIdxBrs(M),i) = Elmt(M,GetFirstIdxBrs(M),i);
	}
	for (i=GetFirstIdxBrs(M)+1;i<=GetLastIdxBrs(M);i++) {
		for (j=GetFirstIdxKol(M);j<i;j++) {
			pengurang=(-Elmt(MOBE,i,j))/GetElmtDiagonal(MOBE,j);
			for (k=j;k<=GetLastIdxKol(M);k++) {
				Elmt(MOBE,i,k) = Elmt(MOBE,i,k)+Elmt(MOBE,j,k)*pengurang;
			}	
		}
	}
	for (i=GetFirstIdxBrs(MOBE);i<=GetLastIdxBrs(MOBE);i++) {
		determinan=determinan*GetElmtDiagonal(MOBE,i);
	}
	return determinan;
}
void PInverse1(MATRIKS *M) {
/*	I.S.	: M terdefinisi
	F.S.	: M di-invers, yaitu setiap elemennya dinegasikan */
	/*	Kamus */
	indeks i,j;
	/*	Algoritma */
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++) {
			Elmt(*M,i,j) = -Elmt(*M,i,j);
		}
	}
}
void Transpose (MATRIKS *M) {
/*	I.S.	: M terdefinisi dan IsBujurSangkar(M)
	F.S.	: M "di-transpose", yaitu setiap elemen M(i,j) ditukar 
			  nilainya dengan elemen M(j,i) */
	/*	Kamus */
	MATRIKS M1;
	indeks i,j;
	ElType temp;
	/*	Algoritma */
	MakeMATRIKS(NKolEff(*M),NBrsEff(*M),&M1);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++) {
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++) {
			Elmt(M1,j,i) = Elmt(*M,i,j);
		}
	}
	CopyMATRIKS(M1,M);
}
/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	//kamus
	int sum = 0;
	//algoritma
	for(int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		sum += Elmt(M,i,j);
	}
	return sum/(float) NKolEff(M);
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	//kamus
	int sum = 0;
	//algoritma
	for(int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		sum += Elmt(M,i,j);
	}
	return sum/(float) NBrsEff(M);
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	*max = Elmt(M,i,GetFirstIdxKol(M));
	*min = Elmt(M,i,GetFirstIdxKol(M));
	for(int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		if (Elmt(M,i,j) > *max) {
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min) {
			*min = Elmt(M,i,j);
		}
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	*max = Elmt(M,GetFirstIdxBrs(M),j);
	*min = Elmt(M,GetFirstIdxBrs(M),j);
	for(int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M,i,j) > *max) {
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min) {
			*min = Elmt(M,i,j);
		}
	}
}


int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	//kamus
	int count = 0;
	//algoritma
	for(int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		if (Elmt(M,i,j) == X) {
			count++;
		}
	}
	return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	//kamus
	int count = 0;
	//algoritma
	for(int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M,i,j) == X) {
			count++;
		}
	}
	return count;
}