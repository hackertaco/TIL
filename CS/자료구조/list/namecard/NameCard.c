#include "NameCard.h"
#include <stdio.h>
#include "ArrayList.h"

NameCard * MakeNameCard(char * name, char * phone)
{
    NameCard* nameCard = (NameCard*)malloc(sizeof(NameCard));
    strcpy(nameCard->name,name);
    strcpy(nameCard->phone,phone);
    return nameCard;
}
   
// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard * pcard)
{
    printf("Namecard info %s, %s", pcard->name, pcard->phone);
}
   
// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard * pcard, char * name)
{
    strcmp(pcard->name, name);
}
   
// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, char * phone)
{
    strcpy(pcard->phone, phone);
}