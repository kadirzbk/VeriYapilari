////////////// 7. DERS


#include <stdio.h>
#include <stdlib.h>

struct bag 
{
    int veri;
    struct bag *next;
};

struct bag *start = NULL;
struct bag *temp = NULL;

void basaEkle(int veri) 
{
    struct bag *eleman;
    eleman = (struct bag *) malloc(sizeof(struct bag));
    eleman->veri = veri;
    eleman->next = start;
    start = eleman;
}

void sonaEkle(int veri) 
{
    struct bag *eleman;
    eleman = (struct bag *) malloc(sizeof(struct bag));
    eleman->veri = veri;
    eleman->next = NULL;

    if (start == NULL) 
    {
        start = eleman;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = eleman;
    }
}

void arayaEkle(int n, int veri) 
{
    struct bag *eleman;
    eleman = (struct bag *) malloc(sizeof(struct bag));
    eleman->veri = veri;

    temp = start;

    
    if (temp == NULL) 
    {
        printf("Liste bo?, araya eleman eklenemez.\n");
        return;
    }

   
    while (temp != NULL && temp->veri != n) 
    {
        temp = temp->next;
    }

    
    if (temp == NULL) 
    {
        printf("Eleman listede bulunamad?.\n");
        free(eleman); 
        return;
    }

   
    eleman->next = temp->next;
    temp->next = eleman;
}

void bastanSil()
{
	if(start!=NULL)
	{
	
	temp=start->next;
	free(start ) ;
	start= temp;
    } 
    else 
    free(start) ;

}

void sondanSil()
{
	if(start->next!= NULL )
	{
		temp= start;
		while (temp->next->next!=NULL )
		{
			temp= temp->next;
		}
		free(temp->next ) ;
		temp->next= NULL;
		
	}
	else
	bastanSil();
	
}

void yazdir() 
{
	system("cls") ;
	if(start!= NULL  )
	{
    temp = start;
    while (temp->next!= NULL) 
    
	
	{
        printf("%d ", temp->veri );
        temp = temp->next;
    } 
	printf("%d ", temp->veri );
   
    }
    else
    printf("Eleman yok ! !") ;
}

int main() 
{
    int sayi, adet = 0, secim, n;

    while (adet != 6) 
    {
        printf("\nBasa eleman eklemek icin 1\n");
        printf("Sona eleman eklemek icin 2\n");
        printf("Araya eleman eklemek icin 3\n");
        printf("Bastan eleman silmek icin 4\n");
        printf("Sondan eleman silmek icin 5\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) 
        {
            case 1:
                printf("\nBasa eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;

            case 2:
                printf("\nSona eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;

            case 3:
                printf("Hangi sayidan once araya eklemek istersiniz: ");
                scanf("%d", &n);
                printf("\nAraya eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                arayaEkle(n, sayi);
                yazdir();
                break;
                
            case 4:
                bastanSil();
                yazdir();
                break;

            case 5:
                sondanSil();
                yazdir();
                break;
                
                
            default:
                printf("Gecersiz secim!\n");
                break;
        }
        adet++;
    }

    return 0;
}
