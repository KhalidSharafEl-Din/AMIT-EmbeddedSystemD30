#include<stdlib.h>
#include<stdio.h>
#include"simpleDB.h"


int main(int argc, char const *argv[])
{ 
    SDB* head = NULL;
    SDB_IsFull(head);

    uint8 grades[3]= {99,100,95};
    uint8 courses[3]= {101,102,103};

    uint8 grades1[3]= {33,33,44};
    uint8 courses1[3]= {22,11,22};
    

    SDB_AddEntry(&head, 1, 10,courses, grades);
    SDB_AddEntry(&head, 20, 20,courses, grades);
    SDB_AddEntry(&head, 3, 30,courses1, grades1);
    SDB_AddEntry(&head, 4, 40,courses, grades);
    SDB_AddEntry(&head, 5, 50,courses, grades);
    SDB_AddEntry(&head, 6, 50,courses, grades);
    SDB_AddEntry(&head, 7, 70,courses, grades);
    SDB_AddEntry(&head, 81, 80,courses, grades);
    SDB_AddEntry(&head, 9, 90,courses, grades);
    SDB_AddEntry(&head, 10, 100,courses, grades);
    SDB_AddEntry(&head, 11, 110,courses, grades);


    SDB_DeleteEntry(&head, 3);
   

    printf("The length of the data base is : %d\n", SDB_GetUsedSize(head));
    SDB_PrintDataBase(head);
    
    SDB_IsFull(head);

    if(SDB_isIdExist(head, 3)){
        printf("This student does exist\n");
    }else{
        printf("This student dose NOT exist\n");
    }

    uint8 arr[3]={0};
    uint8 arr_2[3]={0};
    uint8 year=0;
    SDB_ReadEntry(head, 5, &year, arr, arr_2 );
 
    printf("%d, %d, %d, %d, %d, %d, %d\n",year,
         arr[0],arr[1],arr[2],
         arr_2[0],arr_2[1],arr_2[2]);

    
    uint8 count =0;
    uint8 ids[10]={0};
    SDB_GetIdList(head, &count, ids);
    
    for(int i = 0; i < count; i++){
        printf("%d, ", ids[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}



