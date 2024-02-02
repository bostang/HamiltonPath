/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul : 9 - Tugas Besar
*Kelompok : C4
*Hari dan Tanggal : Senin, 18 April 2022
*Asisten (NIM) : Muhammad Morteza Mudrick (13219061)
*Nama File : main.c
*Deskripsi : main program/driver code dari program yang menghitung banyaknya hamilton path dari suatu graph
*/

// KAMUS
    // Variabel
        // aksi : character
        // isProgramFinished : boolean
        // V : integer { banyaknya vertex pada graph }
        // filename : string { nama file input yang berisi representasi adjacency matrix dari graph}
        // temp  : string (pointer to chracter)
          // string untuk mengambil token dari filename
        // temp2 : string (array of character)
          // string  untuk memodifikasi filename (setelah pemeriksaan apakah tidak kosong dan sesuai format), string filename akan dikembalikan
        // n_solusi : integer { jumlah solusi dari operasi mencari hamiltonian path terakhir }
// ALGORITMA UTAMA

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "func-proc.h"
#include "interface.h"
#define MAX_LEN 255

int main()
{
  bool isProgramFinished = false;
  char aksi;
  int n_solusi = 0;

  // pesan selamat datang (ala-ala TuBes)    
  opening();

  while (!isProgramFinished){ 
    printf("Masukkan aksi:\n>>> ");
    aksi = getchar();
    if (aksi == 'H'){
      // Menerima input file
      // File diasumsikan diletakkan di dalam folder 'input'
      char filename[MAX_LEN];
      printf("Masukkan Graphs: ");
      scanf("%s", &filename);

      validasi_file(filename);

      // Jika sudah divalidasi, buka file
      FILE* stream = fopen(filename, "r");

      // Cek file sampai akhir
      fseek(stream, 0, SEEK_END);
      // Jika file kosong
      if (ftell(stream)==0){
          printf("Error: file kosong!\n");
          exit(1);
      }

      fseek(stream, 0, SEEK_SET); // Kembali ke awal

      char line[MAX_LEN];
      char* token;

      // dynamic matrix of integer dengan C
      // Mengambil jumlah vertex dari file
      int V;

      // Baca jumlah vertex
      fgets(line, MAX_LEN, stream);
      token = strtok(line, "\n");
      V = atoi(token);

      // Alokasi memori untuk graph (matriks of integer berukuran dinamis)
      int** graph = (int**)malloc(V * sizeof(int*));
      for (int index=0;index<V;++index){
          graph[index] = (int*)malloc(V * sizeof(int));
      }

      // Menyimpan data dari file ke dalam graph
      for (int i=0;i<V;i++)
      {
          fgets(line, MAX_LEN, stream);
          token = strtok(line, ",");
          graph[i][0]=atoi(token);
          for (int j=1; j<(V-1); j++){
              token = strtok(NULL, ",");
              graph[i][j]=atoi(token);
          }
          token = strtok(NULL, "\n");
          graph[i][V-1]=atoi(token);
      }
      fclose(stream);

      // inisiasi array hasil_sebelumnya
      int hasil_sebelumnya[V];
      for (int i =0;i<V;i++){
        hasil_sebelumnya[i] = -1;
      }

      hamiltonianPath(graph, hasil_sebelumnya, V, &n_solusi);
    }

    else if (aksi == 'd'){
      char n_solusi_hapus[4];
      printf("Berapa file solusi yang ingin dihapus?\n>>> ");
      scanf("%s",n_solusi_hapus);

      if (!strcmp(n_solusi_hapus,"a"))
        hapusFile(n_solusi);

      else
        hapusFile(atoi(n_solusi_hapus)); // asumsikan input n_solusi_hapus berupa angka
    }

    else if (aksi == 'q'){
      closing();
      isProgramFinished = true;
    } 

    else if (aksi == 'h')
      help();

    else
      printf("aksi tidak valid!\n");

    fflush(stdin); /* penting untuk membersihkan buffer. kalau tidak dibersihkan,
                      akan membuat masalah di iterasi berikutnya */
  }
  return 0;
}