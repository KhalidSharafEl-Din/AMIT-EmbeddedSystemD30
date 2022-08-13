#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"simpleDB.h"

bool    SDB_IsFull(SDB* head){

    if( SDB_GetUsedSize(head) == 10){
        printf("This Database is Full.\n"); return true;
    }else{
        printf("This database is not full yet.\n"); false;
    }
    return false;
}


uint8   SDB_GetUsedSize(SDB* head){

    SDB* temp=head;
    if(head == NULL) return 0;
    uint8 count =1;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }

    return count;

}


bool    SDB_AddEntry(SDB** head, uint8 id, uint8 year, uint8* subjects, uint8* grades){

    // Checking the if the data base is full or not 
    if(SDB_GetUsedSize(*head) == 10) {
        printf("The database is full\n"); return false;
    }
    // Check the input range for the grades  
    for (int i =3; i<3; i++){
        if(grades[i] > 100 || grades[i] <0){
            printf("Out of range grade\n"); return false;
        }
    }

    // Allocate Memory     
    SDB* newNode = (SDB*) malloc(sizeof(SDB));
    // Check if the we got the memeory
    if(newNode == NULL){
       printf("Couldn't Allocate Memeory\n"); return true;
    }

    newNode->studentID = id;
    newNode->studentYear = year;
    newNode->course_ID[0] = subjects[0];
    newNode->course_ID[1] = subjects[1];
    newNode->course_ID[2] = subjects[2];

    newNode->course_Grade[0] = grades[0];
    newNode->course_Grade[1] = grades[1];
    newNode->course_Grade[2] = grades[2];
    
    newNode->next= *head;
    *head = newNode;
    
    return true;
    

}


void    SDB_DeleteEntry(SDB** head, uint8 id){

    SDB *temp = (*head);
    SDB *prev;

    if(temp != NULL && temp->studentID==id){
            // We Found the student and it's the first item
            printf("We found that bitch :D 1 \n");
            // Change the head to point to the next item and free the memory.
            *head=temp->next;
            free(temp);
            return ;
        }
    // move throuh the database till you find the correct id 
    while (temp != NULL && temp->studentID !=id){
        prev = temp;
        temp = temp->next;
    }

    //if ater going through the data base temp is null, the id does not exist.
    if(temp == NULL) return;

    //skip this one and free it 
    prev->next = temp->next;
    free(temp);
}


bool    SDB_ReadEntry(SDB* head, uint8 id, uint8* year, uint8* subjects, uint8* grades){

    SDB *temp = head;
    while (temp->next != NULL){
        if(temp->studentID == id){
            *year = temp->studentYear;
            for(int i=0; i < 3; i++){
                subjects[i]=temp->course_ID[i];
                grades[i]=temp->course_Grade[i];
            }
            return true;
        }
        temp = temp->next;
    }

    return false;

}


void    SDB_GetIdList(SDB* head, uint8* count, uint8* list){

    // Get the used size of the database and return it in the variable count
    *count = SDB_GetUsedSize(head);
    
    // Loop through the data base and return the students ids in the variable list
    SDB *temp = head;
    for(int i =0; i < *count; i++){
        list[i]=temp->studentID;
        temp=temp->next;
    }

}


bool    SDB_isIdExist(SDB* head, uint8 id){

    SDB *temp = head;
    while (temp->next != NULL){
        if(temp->studentID == id) return true;
        temp = temp->next;
    }

    return false;

}

void SDB_PrintDataBase(SDB* head){
    SDB* current = head;
    int counter =0;
    printf("\n");
    while(current != NULL){
        printf("Enter %d ==> ", counter);
        printf("Student ID: %d\t\tYear : %d\t\tCourses: [%d, %d, %d]\t\tGrades : [%d, %d, %d]\n",current->studentID,current->studentYear,
        current->course_ID[0],current->course_ID[1],current->course_ID[2],
        current->course_Grade[0],current->course_Grade[1],current->course_Grade[2]);
        current=current->next;
        counter++;
    }
    printf("\n");
}

