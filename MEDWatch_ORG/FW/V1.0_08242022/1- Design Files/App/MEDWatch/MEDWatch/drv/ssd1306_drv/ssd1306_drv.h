

#ifndef SSD1306_DRV_H
#define SSD1306_DRV_H


#define SSD1306_I2C_ADDR    0X78

/*
    1. Fundamental Command Table
*/
#define SET_CONTRAST_CTRL   0X81    //  Double byte command to select 1 out of 256 contrast steps. Contrast increases as the value increases.(RESET = 7Fh )
#define ENT_DIS_ON_RESUME   0XA4    //  A4h, X0=0b: Resume to RAM content display (RESET) Output follows RAM content
#define ENT_DIS_ON          0XA5    //  A5h, X0=1b: Entire display ON Output ignores RAM content
#define SET_NORMAL_DIS      0XA6    //  A6h, X[0]=0b: Normal display (RESET) 0 in RAM: OFF in display panel 1 in RAM: ON in display panel
#define SET_INVERSE_DIS     0XA7    //  A7h, X[0]=1b: Inverse display 0 in RAM: ON in display panel 1 in RAM: OFF in display panel
#define SET_DIS_OFF         0XAE    //  AEh, X[0]=0b:Display OFF (sleep mode)(RESET)
#define SET_DIS_ON          0XAF    //  AFh X[0]=1b:Display ON in normal mode
/*
    2. Scrolling Command Table
*/

/*
     3. Addressing Setting Command Table
*/

/*
    4. Hardware Configuration (Panel resolution & layout related) Command Table
*/

/*
    5. Timing & Driving Scheme Setting Command Table
*/
#define DEACTIVE_SCROLL     0X2E    //  Stop scrolling that is configured by command 26h/27h/29h/2Ah. "After sending 2Eh command to deactivate the scrolling action, the ram data needs to be rewritten. "
#define ACTIVATE_SCROLL     0X2F    //  Start scrolling that is configured by the scrolling setup commands :26h/27h/29h/2Ah with the following valid sequences:
#define SET_MEM_ADDR_HOR    0X20    //  A[1:0] = 00b, Horizontal Addressing Mode
#define SET_MEM_ADDR_VERT   0X21    //  A[1:0] = 01b, Vertical Addressing Mode
#define SET_MEM_ADDR_PAGE   0X22    //  A[1:0] = 10b, Page Addressing Mode (RESET)
#define NOP                 0XE3    //  Command for no operation


#endif // SSD1306_DRV_H
