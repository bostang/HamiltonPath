/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul : 9 - Tugas Besar
*Kelompok : C4
*Hari dan Tanggal : Rabu, 20 April 2022
*Asisten (NIM) : Muhammad Morteza Mudrick (13219061)
*Nama File : func-proc.c
*Deskripsi : tempat mengimplementasikan fungsi dan prosedur di file .c terpisah agar main.c tidak terlalu keos
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func-proc.h"

void cetakSolusi(int solusi[],int n)
{
    // KAMUS LOKAL
    // ALGORITMA
    for (int i = 0; i < n; ++i)
    {
        printf("%d",solusi[i]);
        if (i != (n-1))
        {
            printf("-");
        }
    }
    printf("\n"); 
}

void cariSolusi(int** graph, int visited[],int hasil[],int node,int start, int counter, int hasil_sebelumnya[], int *no_solusi, int V)
{
    // referensi : https://kalkicode.com/print-hamiltonian-path-present-graph?msclkid=c0c150b3bf1411ec9c0983650e97158d
    // KAMUS LOKAL
    // ALGORITMA
    if(counter==V)
    {
  
        // jika belum dicetak, maka hamilton path akan dicetak
        int isSudahDicetak = 1;

        for (int i = 0;i<V;i++)
        {
            if (hasil[i] != hasil_sebelumnya[i])
            {
                isSudahDicetak = 0;
            }
        }

        if (!isSudahDicetak)
        {
            cetakSolusi(hasil,V);
            *no_solusi = (*no_solusi) + 1;
            simpanKeFile(hasil,V,*no_solusi);
        }
        
        // setelah dicetak, hasil_sebelumnya akan diupdate dengan hasil yang baru
        for (int i = 0;i<V;i++)
        {
            hasil_sebelumnya[i] = hasil[i];
        }

    }

    if(counter >= V ||  visited[node] != -1)
    {
        // ketika node sudah dikunjungi atau ukuran node lebih besar dari 
        // banyaknya node pada graph
        return ;
    }
    // menandai node sekarang sebagai telah dikunjungi
    visited[node] = 1;

    hasil[counter] = node;

    for (int i = 0; i < V; ++i)
    {
        if(graph[node][i]==1)
        {
            cariSolusi(graph,visited,hasil,i,start,counter+1,hasil_sebelumnya,no_solusi, V);
        }
    }
    
    visited[node] = -1;

}

void setDefault(int visited[], int V)
{
    // KAMUS LOKAL
    // ALGORITMA
    for (int i = 0; i < V; ++i)
    {
        visited[i] = -1;
    }
}

void hamiltonianPath(int** graph, int hasil_sebelumnya[], int V, int *nSolusi)
{

    // referensi : https://kalkicode.com/print-hamiltonian-path-present-graph?msclkid=c0c150b3bf1411ec9c0983650e97158d
    // KAMUS LOKAL
        // Variabel
            // visited : array [0..V-1] of integer { array yang menyatakan apakah vertex telah dikunjungi atau belum }
            // hasil : array[0..V] of integer { array untuk menyimpan path hamilton (sekuens vertex) } 
            // noSolusi : integer { jumlah hamilton path yang telah ditemukan }
    // ALGORITMA

    // indikator node yang sudah dikunjungi
    int visited[V];

    // array untuk menyimpan informasi path
    int hasil[V];
    int noSolusi = 0;

    printf("Hamiltonian Path:\n");
    for (int i = 0; i < V; ++i)
    {
        setDefault(visited,V);
        
        cariSolusi(graph,visited,hasil,i,i,0,hasil_sebelumnya,&noSolusi,V);  
    }
    printf("Banyak Hamilton Path: %d\n",noSolusi);
    *nSolusi = noSolusi; // mengubah nSolusi menjadi noSolusi
}

void simpanKeFile(int solusi[], int n, int noFile)
{      
    // KAMUS LOKAL
        // Variabel
            // fp : pointer to FILE
            // namaFile : string { nama file yang akan ditulis } 
    // ALGORITMA
    char namaFile[maxSize] = "";
    strcat(namaFile,"./output/"); // note : folder output sudah harus ada terlebih dahulu!
    strcat(namaFile,"solusi_");
    char buff[3];
    strcat(namaFile,itoa(noFile,buff,10));
    strcat(namaFile,".txt");

    FILE* fp;
    fp = fopen(namaFile,"w");
    
    for (int i = 0; i < n; ++i)
    {
        fprintf(fp,"%d",solusi[i]);
        if (i != (n-1))
        {
           fprintf(fp,"-");    
        }
    }
    strcpy(namaFile,""); // mengosongkan kembali string namaFile

    fclose(fp);
}

void hapusFile(int nFile)
{
    // KAMUS LOKAL
        // Variabel
            // namaFile : string
            // ret : integer { apakah sukses menghapus file atau tidak }
    // ALGORITMA
    for (int i = 1;i<=nFile;i++)
    {
        char namaFile[maxSize] = "";
        strcat(namaFile,"./output/"); // note : folder output sudah harus ada terlebih dahulu!
        strcat(namaFile,"solusi_");
        char buff[3];
        strcat(namaFile,itoa(i,buff,10));
        strcat(namaFile,".txt");

        int ret = remove(namaFile);

        if(ret == 0)
        {
        printf("File %s sukses dihapus\n",namaFile);
        } else {
        printf("Error: File %s gagal dihapus\n");
        }

        strcpy(namaFile,""); // mengosongkan kembali string namaFile
    }
}

void validasi_file(char filename[]){
    char *temp;

    temp = strtok(filename,".");
    temp = strtok(NULL,"\n"); //mengambil string setelah titik

    // Jika format file salah 
    if (temp == NULL || strcmp(temp,"txt")){
        printf("Error: format salah!\n");
        closing();
        exit(1); 
    }

    char temp2[15];

    // Mengubah nama file menjadi directory
    strcpy(temp2,filename);
    strcpy(filename,"");
    strcat(filename,"./input/");
    strcat(filename,temp2);
    strcat(filename,".txt");

    // Jika file tidak ada
    if (fopen(filename,"r")==NULL){
        printf("Error: file tidak ada!\n");
        closing();
        exit(1);
    }
}