/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul : 9 - Tugas Besar
*Kelompok : C4
*Hari dan Tanggal : Selasa, 19 April 2022
*Asisten (NIM) : Muhammad Morteza Mudrick (13219061)
*Nama File : interface.h
*Deskripsi : header file untuk keperluan interface/ program interaktif dengan user
*/

// DEKLARASI KONSTANTA

char bumper_1[127] = " _    _          __  __ _____ _     _              _             \n";
char bumper_2[127] = "| |  | |   /\\   |  \\/  |_   _| |   | |            (_)            \n";
char bumper_3[127] = "| |__| |  /  \\  | \\  / | | | | |   | |_ ___  _ __  _  __ _ _ __  \n";
char bumper_4[127] = "|  __  | / /\\ \\ | |\\/| | | | | |   | __/ _ \\| '_ \\| |/ _` | '_ \\ \n";
char bumper_5[127] = "| |  | |/ ____ \\| |  | |_| |_| |___| || (_) | | | | | (_| | | | |\n";
char bumper_6[127] = "|_|  |_/_/    \\_\\_|  |_|_____|______\\__\\___/|_| |_|_|\\__,_|_| |_|\n";

char pengarang_1[31] = "Gilbert Ng (13220032)";
char pengarang_2[31] = "Yusuf Hafizh Sofwan (13220040)";
char pengarang_3[31] = "Jota Baret Tata (13220048)";
char pengarang_4[31] = "Bostang Palaguna (13220055)";
char pengarang_5[31] = "Michael Tiroi (13220062)";

char bumper_7[127] = " _________  ___  ___  ________  ________   ___  __             ___    ___ ________  ___  ___  ___   \n";
char bumper_8[127] = "|\\___   ___\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\  \\|\\  \\          |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\|\\  \\ \n";
char bumper_9[127] = "\\|___ \\  \\_\\ \\  \\\\  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\/  /|_        \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\  \\ \\  \\ \n";
char bumper_10[127] = "     \\ \\  \\ \\ \\   __  \\ \\   __  \\ \\  \\ \\  \\ \\   ___  \\        \\ \\    / / \\ \\  \\\\  \\ \\  \\\\  \\ \\  \\  \n";
char bumper_11[127] = "      \\ \\  \\ \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\        \\/  /  /   \\ \\  \\\\  \\ \\  \\\\  \\ \\__\\   \n";
char bumper_12[127] = "       \\ \\__\\ \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\     __/  / /      \\ \\_______\\ \\_______\\|__|    \n";
char bumper_13[127] = "        \\|__|  \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|__| \\|__|    |\\___/ /        \\|_______|\\|_______|   ___  \n";
char bumper_14[127] = "                                                             \\|___|/                               |\\__\\ \n";
char bumper_15[127] = "                                                                                                   \\|__| \n\n";

// DEKLARASI FUNGSI/PROSEDUR
void cetakBumperOp()
{
    printf("\nSelamat datang di program:\n\n");
    printf("%s",bumper_1);
    printf("%s",bumper_2);
    printf("%s",bumper_3);
    printf("%s",bumper_4);
    printf("%s",bumper_5);
    printf("%s",bumper_6);  
    printf("\n");
}

void cetakPengarang()
{
    printf("%s\n",pengarang_1);    
    printf("%s\n",pengarang_2);
    printf("%s\n",pengarang_3);
    printf("%s\n",pengarang_4);
    printf("%s\n",pengarang_5);
    printf("\n");
}

void help()
{
    // KAMUS LOKAL
    // ALGORITMA
    printf("--- Opsi Aksi ---\n");
    printf("H : mencari hamiltonian path dari graph\n");
    printf("d : menghapus output file\n");
    printf("q : keluar dari program\n");
    printf("h : bantuan\n");
    printf("\n");
}

void opening()
{
    cetakBumperOp();
    printf("oleh:\n");
    cetakPengarang();

    help();
}

void cetakBumperCls(){
    printf("%s",bumper_7);
    printf("%s",bumper_8);
    printf("%s",bumper_9);
    printf("%s",bumper_10);
    printf("%s",bumper_11);
    printf("%s",bumper_12);
    printf("%s",bumper_13);
    printf("%s",bumper_14); 
    printf("%s",bumper_15);
}     

void closing(){
    printf("Program selesai.\n");
    cetakBumperCls();
}
