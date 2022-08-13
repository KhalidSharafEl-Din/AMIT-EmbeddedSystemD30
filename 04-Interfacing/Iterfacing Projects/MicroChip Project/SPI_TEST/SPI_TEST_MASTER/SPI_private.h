

#define SPDR *((volatile u8*)0x2F)   
#define SPSR *((volatile u8*)0x2E)  
#define SPCR *((volatile u8*)0x2D) 





#define SPI_u8MSB       15
#define SPI_u8LSB       17



#define SPI_u8FOSC_2    2 
#define SPI_u8FOSC_4    4
#define SPI_u8FOSC_8    8
#define SPI_u8FOSC_16   16
#define SPI_u8FOSC_32   32
#define SPI_u8FOSC_64   64
#define SPI_u8FOSC_128  128

#define SPI_u8MASTER       0
#define SPI_u8SLAVE        1
#define SPI_u8IDLE_LOW     3
#define SPI_u8IDLE_HIGH    5
#define SPI_u8LEADING      7
#define SPI_u8TAILLING     9
#define SPI_u8ENABLE       11
#define SPI_u8DISABLE      13
