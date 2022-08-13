#ifndef SIMPLEDB_H
#define SIMPLEDB_H

#include<stdbool.h>
#define MAXSIZE 10

typedef  signed char        int8;
typedef  unsigned char      uint8;
typedef  signed short       int16;
typedef  unsigned short     uint16;
typedef  signed long        int32;
typedef  unsigned long      uint32;
typedef  signed long long   int64;
typedef  unsigned long long uint64;

typedef struct SDB SDB;

struct SDB{
    uint8 studentID;
    uint8 studentYear;
    uint8 course_ID[3];
    uint8 course_Grade[3];

    SDB* next;

};

bool    SDB_IsFull(SDB* head);                                                                  // Done
uint8   SDB_GetUsedSize(SDB* head);                                                             // Done
bool    SDB_AddEntry(SDB** head, uint8 id, uint8 year, uint8* subjects, uint8* grades);         // Done
void    SDB_DeleteEntry(SDB** head, uint8 id);                                                  // Done
bool    SDB_ReadEntry(SDB* head, uint8 id, uint8* year, uint8* subjects, uint8* grades);        // Done
void    SDB_GetIdList(SDB* head, uint8* count, uint8* list);                                    // Done
bool    SDB_isIdExist(SDB* head, uint8 id);                                                     // Done


void    SDB_PrintDataBase(SDB* head);                                                           // Done



#endif // SIMPLEDB_H