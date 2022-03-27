/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : -
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
  
//Struct Node Linked List
struct Node {
	int data;
	struct Node* next;
} Node;
  
//Fungsi untuk menggabungkannya dua buah linked list dengan data terurut
//menjadi sebuah linked list besar dengan data terurut
struct Node* gabungkan_urutkan(struct Node* a, struct Node* b)
{
	struct Node temp;
	struct Node* tail = &temp;
  
	//tail->next tempat menambahkan node baru di tujuan
	temp.next = NULL;
	while (1)
	{
		//Jika list a sudah kosong, lanjutkan ke list b
		if (a == NULL)
		{
			tail->next = b;
			break;
		}
		
		//Jika list b sudah kosong, lanjutkan ke list a
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		
		//Pilih data dari list mana yang akan ditambahkan
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);
  
		tail = tail->next;
	}
	return(temp.next);
}
  
//Fungsi untuk mengambil node dari bagian depan sumber dan 
//memindahkannya ke bagian depan tujuan
void MoveNode(struct Node** tujuan, struct Node** sumber)
{
	struct Node* newNode = *sumber;
	assert(newNode != NULL);
  
	//Memindahkan pointer pada sumber
	*sumber = newNode->next;
	newNode->next = *tujuan;
	*tujuan = newNode;
}
  
//Fungsi untuk memasukkan urutan integer ke dalam linked list
void push(struct Node** newHead, int new_data)
{
	struct Node* new_node;

	// membuat node untuk data baru
	new_node =(struct Node*) malloc(sizeof(struct Node));
		
	// memasukkan data ke dalam list
	new_node->data = new_data;

	// mengganti head
	new_node->next = (*newHead); 
	(*newHead) = new_node;
}
  
// fungsi untuk membalikkan isi linked list
void reverse(struct Node** head){
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return;
}


int main()
{
	//Deklarasi variabel-variabel
	struct Node* pertama = NULL;
	struct Node* kedua = NULL;
	struct Node* ketiga = NULL;	
	struct Node* temp = NULL;
	struct Node* hasil = NULL;
	int i, n, m, o;
	
	//input linked list pertama
	printf("Masukkan jumlah elemen linked list pertama: ");
	scanf("%d", &n);
	int elemen_pertama[n];
	
	printf("Masukkan elemen-elemen linked list pertama: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &elemen_pertama[i]);
		push(&pertama, elemen_pertama[i]);
	}
	
	//input linked list kedua
	printf("Masukkan jumlah elemen linked list kedua: ");
	scanf("%d", &m);
	int elemen_kedua[m];
	
	printf("Masukkan elemen-elemen linked list kedua: ");
	for (i = 0; i < m; i++) {
		scanf("%d", &elemen_kedua[i]);
		push(&kedua, elemen_kedua[i]);
	}
	
	//input linked list ketiga
	printf("Masukkan jumlah elemen linked list ketiga: ");
	scanf("%d", &o);
	int elemen_ketiga[o];
	
	printf("Masukkan elemen-elemen linked list ketiga: ");
	for (i = 0; i < o; i++) {
		scanf("%d", &elemen_ketiga[i]);
		push(&ketiga, elemen_ketiga[i]);
	}
	
	//Ketika urutan integer dimasukkan ke linked list, urutannya menjadi 
	//terbalik, maka perlu dibalikkan lagi agar seperti semula
	reverse(&pertama);
	reverse(&kedua);
	reverse(&ketiga);
	
	//Gabungkan dan urutkan ketiga linked list
	temp = gabungkan_urutkan(pertama, kedua);
	hasil = gabungkan_urutkan(temp, ketiga);

	//Cetak output berupa urutan integer 
	printf("\nHasil urutan gabungan ketiga linked list: ");
	while (hasil != NULL)
	{
		printf("%d ", hasil->data);
		hasil = hasil->next;
	}

	return 0;
}
