// 210206026 DAVUT BOZTAÞ
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int OgrenciNo;
    int Not;
    struct node* next;
};
struct node* YeniDugum(int OgrenciNo,int Not)
{
  struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
  eklenecek->next=NULL;
  eklenecek->Not=Not;
  eklenecek->OgrenciNo=OgrenciNo;
  return eklenecek;
}
struct node* start;
void SiraliEkle(int OgrenciNo,int Not)
{
    struct node* eklenecek=YeniDugum(OgrenciNo,Not);
    if(start==NULL)
    {
        start=eklenecek;
    }
    else if(start->next==NULL)
    {
        if(start->OgrenciNo>=eklenecek->OgrenciNo)
        {
            eklenecek->next=start;
            start=eklenecek;
        }
        else
        {
            start->next=eklenecek;
        }
    }
    else
    {
        struct node* temp=start;
        struct node* onceki;
        while(temp!=NULL && temp->OgrenciNo<=eklenecek->OgrenciNo)
        {
            onceki=temp;
            temp=temp->next;
        }
        if(temp==start)
        {
            eklenecek->next=start;
            start=eklenecek;
        }
        else if(onceki->next==NULL)
        {
            onceki->next=eklenecek;
        }
        else
        {
            eklenecek->next=temp;
            onceki->next=eklenecek;
        }
    }
}
void Traverselist()
{
    struct node* temp=start;
    while(temp!=NULL)
    {
        printf("%d %d ",temp->OgrenciNo,temp->Not);
        printf("\n");
        temp=temp->next;
    }

}
int main(){
    FILE*dosya2;
    int OgrenciNo;
    int Not;
    dosya2=fopen("ogrenci.txt","r");
    if(dosya2!=NULL)
    {
        while(!feof(dosya2))
        {
            fscanf(dosya2,"%d %d",&OgrenciNo,&Not);
            SiraliEkle(OgrenciNo,Not);

        }
    }
    else
    {
        printf("Dosya bulunamadi");
    }



    Traverselist();

    fclose(dosya2);




    return 0;
}
