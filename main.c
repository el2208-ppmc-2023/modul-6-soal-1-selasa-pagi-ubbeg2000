/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int dec;
	struct node* next;
    struct node* prev;
}node;

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

int lexi(node** head){
    node* temp =*head;
    node* suff = NULL;

    //mencari lokasi pertama ketika urutan bilangan yang menurun sanpai akhir 
    while(temp != NULL){
        if(temp->next != NULL && temp->prev != NULL){
            if(temp->dec >= temp->next->dec && temp->dec > temp->prev->dec){
                suff = temp;
            }
        }
        else if (temp->prev != NULL){
            if(temp->dec > temp->prev->dec){
                suff = temp;
            }
        }
        temp = temp->next;
    }

    //jika urutan bilangan yang diinputkan urutannya selalu menurun maka tidak ada permutasi terdekat yang lebih besar
    //yang lebih tinggi lagi nilainya => program menampilkan urutan yang sama dengan yang diinputkan
    if(suff == NULL){
        return 0;
    }

    //dari lokasi pertama urutan bilangan menurun, 
    //cari lokasi dimana terdapat bilangan terkecil dari urutan bilangan menurun
    //yang nilainya lebih besar dari bilangan tepat sebelum lokasi pertama bilangan menurun ditemukan
    node* min_suff = NULL;
    if(suff->next !=NULL){
        int temp_min = suff->dec;
        min_suff = suff;
        temp = suff->next;
        while(temp != NULL){
            if(temp->dec <= temp_min && temp->dec > suff->prev->dec ){
                min_suff = temp;
                temp_min = temp->dec;
            }
            temp = temp->next;
        }
    }
    else{
        min_suff = suff;
    }
    //swap nilai antara bilangan terkecil dari urutan bilangan menurun
    //yang nilainya lebih besar dari bilangan tepat sebelum lokasi pertama bilangan menurun ditemukan dengan bilangan tepat sebelum lokasi pertama bilangan menurun
    int num_dum = min_suff->dec;
    min_suff->dec = suff->prev->dec;
    suff->prev->dec = num_dum;

    //reverse urutan sisa bilangan menurun jadi menaik 
    node* current = suff->next;
    node* prev_suff = suff->prev;
    temp = NULL;
    suff->next = NULL;
    suff->prev = current;
    while(current !=NULL){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        if(temp == NULL){
            current->prev = prev_suff;
            prev_suff->next = current;
        }
        current = temp;
    }
    return 1;
}

int main(){
    node *head = NULL;
    int n_list = 0;

    printf("Masukkan jumlah elemen list: ");
    scanf("%d", &n_list);

    create_list(n_list, &head);
    print_list(&head);
    printf("=> ");
    lexi(&head);
    print_list(&head);
    printf("\n");
    return 0;
}
