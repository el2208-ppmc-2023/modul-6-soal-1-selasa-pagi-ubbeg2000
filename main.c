/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include<stdio.h>
#include<stdlib.h>


// Anda dibebaskan untuk memakai template code atau tidak
// Namun tetap harus memakai struktur data linked list dalam memecahkannya
// Jenis linked list yang digunakan dibebaskan

typedef struct node{
	int dec;
	node* next;
    node* prev;
} node;

void create_list(int n, node** head){
    node* dum = (node*)malloc(sizeof(node));
	node* dum2 = NULL;
	*head = dum; //simpan lokasi dum sebagai head
    printf("Masukkan elemen list ke-1: ");
    scanf("%d", &(dum->dec));
    dum->prev = NULL;
    for(int i=1; i<n; i++){
        dum2 = (node*)malloc(sizeof(node));
		dum->next = dum2;
        dum2->prev = dum;
		dum = dum2;
        printf("Masukkan elemen list ke-%d: ", i+1);
        scanf("%d", &(dum->dec));
    }
    dum->next = NULL;
}

void print_list(node** head){
    node* dum = *head;
    while(dum!=NULL){
        printf("%d ", dum->dec);
        dum = dum->next;
    }
}

int main(){
    node *head = NULL;
    int n_list = 0;

    printf("Masukkan jumlah elemen list: ");
    // scanf("%d", &n_list);

    // create_list(n_list, &head);

    // print_list(&head);
    // printf("=> ");
    // print_list(&head);

    printf("\n");
	
    return 0;
}
