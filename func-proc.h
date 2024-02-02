/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul : 9 - Tugas Besar
*Kelompok : C4
*Hari dan Tanggal : Senin, 18 April 2022
*Asisten (NIM) : Muhammad Morteza Mudrick (13219061)
*Nama File : func-proc.h
*Deskripsi : header file untuk func-proc.c (func-proc.c adalah tempat mengimplementasikan fungsi/prosedur bentukan)
*/

// KAMUS
    // Konstanta
        // maxSize : integer := 63 { panjang maksimum string }
    // Fungsi/Prosedur
        // procedure hamiltonianCycle(int graph[V][V], int hasil_sebelumnya, *int nsolusi)
            // sebagai prosedur utama mencari hamilton cycle dari suatu graph
            // I.S. graph yang ingin dicari hamilton pathnya telah terdefinisi
            // F.S. semua kemungkinan hamilton path dari graph telah diperoleh dan dicetak ke layar
        // procedure cetakSolusi(int solusi[],int n)
            // mencetak hamilton path yang telah diperoleh dari posedur cariSolusi() ke layar
            // I.S. path hamilton telah ditemukan (sekuens vertexnya disimpan dalam bentuk array) 
            // F.S. path hamilton tercetak ke layar
        // procedure cariSolusi(int graph[V][V], int visited[],int hasil[],int node,int start, int counter)
            // prosedur rekursif yang mencari semua kemungkinan hamiltonian path dari suatu graf yang diberikan
            // I.S. graf yang ingin dicari hamiltonian pathnya telah terdefinisi sebagai sebuah matrix of integer
            // F.S. semua hamiltonian path akan dicari (sekaligus ditampilkan ke layar dan disimpan ke file)
        // procedure setDefault(int visited[])
            // menandai semua vertex belum dikunjungi
            // I.S. array visited telah terdefinisi
            // F.S. semua elemen array visited di-inisiasi dengan nilai -1
        // procedure simpanKeFile(int solusi[], int n, int noFile)
            // menyimpan solusi hamiltonian path ke dalam file
            // I.S. hamiltonian path telah dicari oleh prosedur cariSolusi 
            // F.S. hamiltonian path akan disimpan ke dalam file solusi_n.txt
                // dengan n menyatakan path ke-n yang ditemukan oleh prosedur cariSolusi()
        // procedure hapusFile(int nFile)
            // menghapus file solusi solusi_1.txt sampai solusi_nFile.txt
            // I.S. folder output terdefinisi
            // F.S. jika ada file solusi_n.txt untuk n dari 1 sampai n_File, maka akan dihapus, bila tidak, akan ditampilkan pesan error
        // procedure help()
            // menampilkan bantuan opsi aksi yang bisa dilakukan
            // I.S. -
            // F.S. opsi aksi yang bisa dilakukan ditampilkan ke layar
        // procedure validasi_file(char filename[])
            // memvalidasi nama dan format file eksternal
            // I.S. -
            // F.S. nama file ada dan format file benar (.txt)
// DEKLARASI KONSTANTA

#define maxSize 63 // untuk ukuran string

// DEKLARASI FUNGSI

void hamiltonianPath(int** graph, int hasil_sebelumnya[], int V, int *nSolusi);
void cetakSolusi(int solusi[],int n);
void cariSolusi(int** graph, int visited[],int hasil[],int node,int start, int counter, int hasil_sebelumnya[], int *no_solusi, int V);
void setDefault(int visited[], int V);
void simpanKeFile(int solusi[], int n, int noFile);
void hapusFile(int nFile);
void help();
void validasi_file(char filename[]);