//
// Created by wangyang on 17/3/8.
//

#include "NRFSendApp.h"

char seg[10]={0xC0,0xCF,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};         //0~~9∂Œ¬Î
char TxBuf[32]=
        {
                0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4,0x01,0x02,0x03,0x4
        };
char sta,tf;
//*********************************************NRF24L01*************************************
#define TX_ADR_WIDTH    5   	// 5 uints TX address width
#define RX_ADR_WIDTH    5   	// 5 uints RX address width
#define TX_PLOAD_WIDTH  4  	// 20 uints TX payload
#define RX_PLOAD_WIDTH  4  	// 20 uints TX payload
char  TX_ADDRESS[TX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//±æµÿµÿ÷∑
char  RX_ADDRESS[RX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//Ω” ’µÿ÷∑
//***************************************NRF24L01ºƒ¥Ê∆˜÷∏¡Ó*******************************************************
#define READ_REG        0x00  	// ∂¡ºƒ¥Ê∆˜÷∏¡Ó
#define WRITE_REG       0x20 	// –¥ºƒ¥Ê∆˜÷∏¡Ó
#define RD_RX_PLOAD     0x61  	// ∂¡»°Ω” ’ ˝æ›÷∏¡Ó
#define WR_TX_PLOAD     0xA0  	// –¥¥˝∑¢ ˝æ›÷∏¡Ó
#define FLUSH_TX        0xE1 	// ≥Âœ¥∑¢ÀÕ FIFO÷∏¡Ó
#define FLUSH_RX        0xE2  	// ≥Âœ¥Ω” ’ FIFO÷∏¡Ó
#define REUSE_TX_PL     0xE3  	// ∂®“Â÷ÿ∏¥◊∞‘ÿ ˝æ›÷∏¡Ó
#define NOP1             0xFF  	// ±£¡Ù
//*************************************SPI(nRF24L01)ºƒ¥Ê∆˜µÿ÷∑****************************************************
#define CONFIG          0x00  // ≈‰÷√ ’∑¢◊¥Ã¨£¨CRC–£—Èƒ£ Ω“‘º∞ ’∑¢◊¥Ã¨œÏ”¶∑Ω Ω
#define EN_AA           0x01  // ◊‘∂Ø”¶¥π¶ƒ‹…Ë÷√
#define EN_RXADDR       0x02  // ø…”√–≈µ¿…Ë÷√
#define SETUP_AW        0x03  //  ’∑¢µÿ÷∑øÌ∂»…Ë÷√
#define SETUP_RETR      0x04  // ◊‘∂Ø÷ÿ∑¢π¶ƒ‹…Ë÷√
#define RF_CH           0x05  // π§◊˜∆µ¬ …Ë÷√
#define RF_SETUP        0x06  // ∑¢…‰ÀŸ¬ °¢π¶∫ƒπ¶ƒ‹…Ë÷√
#define STATUS          0x07  // ◊¥Ã¨ºƒ¥Ê∆˜
#define OBSERVE_TX      0x08  // ∑¢ÀÕº‡≤‚π¶ƒ‹
#define CD              0x09  // µÿ÷∑ºÏ≤‚
#define RX_ADDR_P0      0x0A  // ∆µµ¿0Ω” ’ ˝æ›µÿ÷∑
#define RX_ADDR_P1      0x0B  // ∆µµ¿1Ω” ’ ˝æ›µÿ÷∑
#define RX_ADDR_P2      0x0C  // ∆µµ¿2Ω” ’ ˝æ›µÿ÷∑
#define RX_ADDR_P3      0x0D  // ∆µµ¿3Ω” ’ ˝æ›µÿ÷∑
#define RX_ADDR_P4      0x0E  // ∆µµ¿4Ω” ’ ˝æ›µÿ÷∑
#define RX_ADDR_P5      0x0F  // ∆µµ¿5Ω” ’ ˝æ›µÿ÷∑
#define TX_ADDR         0x10  // ∑¢ÀÕµÿ÷∑ºƒ¥Ê∆˜
#define RX_PW_P0        0x11  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define RX_PW_P1        0x12  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define RX_PW_P2        0x13  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define RX_PW_P3        0x14  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define RX_PW_P4        0x15  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define RX_PW_P5        0x16  // Ω” ’∆µµ¿0Ω” ’ ˝æ›≥§∂»
#define FIFO_STATUS     0x17  // FIFO’ª»Î’ª≥ˆ◊¥Ã¨ºƒ¥Ê∆˜…Ë÷√

#define SSD1306_LCDHEIGHT 32
#define SSD1306_LCDWIDTH 128

#define CE      13
#define SCK     12
#define MISO    11
#define IRQ     10
#define MOSI    9
#define CSN     8


uint8_t SPI_RW(uint8_t data, bool send = true) {
    uint8_t recvData = 0x00;
    // Send Data
    for(unsigned char bit = 0x80; bit; bit >>= 1) {
        // One bit will be transmitted when SCK change from low to high
        digitalWrite(SCK, LOW);
        if (data & bit) {
            digitalWrite(MOSI, HIGH);
        } else {
            digitalWrite(MOSI, LOW);
        }

        recvData <<= 1;
        digitalWrite(SCK, HIGH);
        if (digitalRead(MISO)) {
            recvData++;
        }
        digitalWrite(SCK, LOW);
    }
    return recvData;
}

uint8_t SPI_Read(uint8_t reg, bool send = true) {
    uint8_t reg_val = 0x00;
    digitalWrite(CSN, LOW);
    SPI_RW(reg, send);
    reg_val = SPI_RW(0, send);
    digitalWrite(CSN, HIGH);

    return reg_val;
}

uint8_t SPI_RW_Reg(uint8_t reg, uint8_t value, bool send = true)
{
    char status;

    digitalWrite(CSN, LOW);                  // CSN low, init SPI transaction
    status = SPI_RW(reg, send);      // select register
    SPI_RW(value, send);             // ..and write value to it..
    digitalWrite(CSN, HIGH);                   // CSN high again

    return(status);            // return nRF24L01 status uchar
}

char SPI_Read_Buf(char reg, char *pBuf, char uchars, bool send = true)
{
    int status,uchar_ctr;

    digitalWrite(CSN, LOW);                  		// Set CSN low, init SPI tranaction
    status = SPI_RW(reg, send);       		// Select register to write to and read status uchar

    for(uchar_ctr=0;uchar_ctr<uchars;uchar_ctr++)
        pBuf[uchar_ctr] = SPI_RW(0, send);    //

    digitalWrite(CSN, HIGH);

    return(status);                    // return nRF24L01 status uchar
}

char SPI_Write_Buf(char reg, char *pBuf, char uchars, bool send = true)
{
    char status,uchar_ctr;

    digitalWrite(CSN, LOW);            //SPI πƒ‹
    status = SPI_RW(reg, send);
    for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
        SPI_RW(*pBuf++, send);
    digitalWrite(CSN, HIGH);           //πÿ±’SPI
    return(status);    		  //
}

void SetRX_Mode(bool send = true)
{
    digitalWrite(CE, LOW);;
    //SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f, send);   		// IRQ ’∑¢ÕÍ≥…÷–∂œœÏ”¶£¨16ŒªCRC	£¨÷˜Ω” ’
    digitalWrite(CE, HIGH);;
    _delay_ms(1000);
}

char nRF24L01_RxPacket(char* rx_buf, bool send = true)
{
    char revale=0;
    sta=SPI_Read(STATUS, send);	// ∂¡»°◊¥Ã¨ºƒ¥Ê∆‰¿¥≈–∂œ ˝æ›Ω” ’◊¥øˆ
    if(sta&0x40)				// ≈–∂œ «∑ÒΩ” ’µΩ ˝æ›
    {
        digitalWrite(CE, LOW); 			//SPI πƒ‹
        SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH, send);// read receive payload from RX_FIFO buffer
        revale =1;			//∂¡»° ˝æ›ÕÍ≥…±Í÷æ
    }
    SPI_RW_Reg(WRITE_REG+STATUS,sta, send);   //Ω” ’µΩ ˝æ›∫ÛRX_DR,TX_DS,MAX_PT∂º÷√∏ﬂŒ™1£¨Õ®π˝–¥1¿¥«Â≥˛÷–∂œ±Í÷æ
    return revale;
}

void nRF24L01_TxPacket(char * tx_buf, bool send = true)
{
    digitalWrite(CE, LOW);			//StandBy Iƒ£ Ω
//    SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH, send);    // –¥±æµÿµÿ÷∑
//    SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH, send); // ◊∞‘ÿΩ” ’∂Àµÿ÷∑
    SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH, send); 			 // ◊∞‘ÿ ˝æ›
//	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ ’∑¢ÕÍ≥…÷–∂œœÏ”¶£¨16ŒªCRC£¨÷˜∑¢ÀÕ
    digitalWrite(CE, HIGH);		 //÷√∏ﬂCE£¨º§∑¢ ˝æ›∑¢ÀÕ
    _delay_us(10);
}

void init_NRF24L01_Send(bool send = true)
{
    _delay_us(100);
    digitalWrite(CE, LOW);    // chip enable
    digitalWrite(CSN, HIGH);   // Spi disable
    digitalWrite(SCK, LOW);   // Spi clock line init high
    SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH, send);    // –¥±æµÿµÿ÷∑
    SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH, send); // –¥Ω” ’∂Àµÿ÷∑
    SPI_RW_Reg(WRITE_REG + SETUP_AW, 0x03);//5byteµÄµØÖ·
    SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0xff);//½ûÖ¹ÖØ·¢
    SPI_RW_Reg(WRITE_REG + EN_AA, 0x00, send);      //  ∆µµ¿0◊‘∂Ø	ACK”¶¥‘ –Ì
    SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01, send);  //  ‘ –ÌΩ” ’µÿ÷∑÷ª”–∆µµ¿0£¨»Áπ˚–Ë“™∂‡∆µµ¿ø…“‘≤ŒøºPage21
    SPI_RW_Reg(WRITE_REG + RF_CH, 20, send);        //   …Ë÷√–≈µ¿π§◊˜Œ™2.4GHZ£¨ ’∑¢±ÿ–Î“ª÷¬
    SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH, send); //…Ë÷√Ω” ’ ˝æ›≥§∂»£¨±æ¥Œ…Ë÷√Œ™32◊÷Ω⁄
    SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x0f, send);   		//…Ë÷√∑¢…‰ÀŸ¬ Œ™1MHZ£¨∑¢…‰π¶¬ Œ™◊Ó¥Û÷µ0dB
    SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e, send);   		 // IRQ ’∑¢ÕÍ≥…÷–∂œœÏ”¶£¨16ŒªCRC£¨÷˜∑¢ÀÕ
}

void NRFSendApp::sendBytes(uint8_t *data, uint8_t count) {
    static uint8_t packageNo = 0x00;
    TxBuf[0] = *data;
    TxBuf[1] = *data;
    for (int i = 0; i < count; ++i) {
        TxBuf[2 + i] = *(data + i);
    }
    TxBuf[3] = 0xaa;
    for (int i = 0; i < 8; ++i) {
        nRF24L01_TxPacket(TxBuf, true);
    }
    packageNo++;
}

void NRFSendApp::setup() {
    Serial.begin(9600);
    Serial.println("System On");

    pinMode(CE, OUTPUT);
    pinMode(CSN, OUTPUT);
    pinMode(SCK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(MISO, INPUT);
    pinMode(IRQ, INPUT);

    Serial.println("NRF init send...");
    init_NRF24L01_Send(true);

    SPI_RW_Reg(WRITE_REG + STATUS, 0x10, false);
    nRF24L01_TxPacket(TxBuf, true);
}

void NRFSendApp::loop() {
    static uint8_t data = 0x01;
    sendBytes(&data, 1);
    _delay_ms(500);
    data <<= 1;
    if (data == 0) {
        data = 0x01;
    }
}