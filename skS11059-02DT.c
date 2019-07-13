/*******************************************************************************
*  skADXL345I2C - ＡＤＸＬ３４５関数ライブラリ(I2Cバージョン)                  *
*             このライブラリは、ADXL345を使った3軸加速度センサモジュール用です *
*             現在このライブラリは各軸の値を読み込む機能のみ対応です。         *
*                                                                              *
*    acceler_Init - ADXL345の初期化を行う処理                                  *
*    acceler_Read - ADXL345の各軸の値を読み込む処理                            *
*                                                                              *
*    メモ：__delay_us() を使用しているので "skADXL345I2C.h" に                 *
*         "#define _XTAL_FREQ 8000000"が記述されています、                     *
*         8MHz以外のCPUクロックにする人は書き換えましょう。                    *
* ============================================================================ *
*  VERSION DATE        BY                    CHANGE/COMMENT                    *
* ---------------------------------------------------------------------------- *
*  1.00    2014-01-29  きむ茶工房(きむしげ)  Create                            *
*  1.01    2014-03-29  きむ茶工房(きむしげ)  ファイル名とacceler_Initの変更    *
*  1.10    2015-10-10  きむ茶工房(きむしげ)  MPLAB X・XC8 V1.32用に書換え      *
* ============================================================================ *
*  PIC 12F1822 16F1827 (このライブラリ自体は他のＰＩＣでもＯＫと思います)      *
*  MPLAB IDE(V8.84)  MPLAB X(v2.15)                                            *
*  MPLAB(R) XC8 C Compiler Version 1.00/1.32                                   *
*******************************************************************************/
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "skI2Clib.h"
#include "skS11059-02DT.h"
#include "skI2CLCDlib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

    uint8_t a[4]={};
    uint8_t b[4]={};
    uint16_t c[4]={};


// ADXL345のレジスターからデータを読み込む処理
// adress : 読み込むアドレスを指定
//int register_read(char address)
//{
//     int ans ;
//
//     ans = I2C_Start(S11059_ADRES,RW_0);    // スタートコンディションを発行する
//     if (ans == 0) {
//          I2C_Send(address) ;                // レジスタアドレスの送信
//          I2C_rStart(S11059_ADRES,RW_1) ;   // リピート・スタートコンディションを発行する
//          ans = I2C_Receive(NOACK);          // データ内容を受信する
//     } else ans = -1 ;
//     I2C_Stop() ;                            // ストップコンディションを発行する
//     return ans ;
//}
// ADXL345のレジスターにデータを書き込む処理
// adress : 書き込むアドレスを指定
// val    : 書き込むデータを指定

//int register_write(char address, char val)
//{
//     int ans ;
//      
//     ans = I2C_Start(S11059_ADRES,RW_0);    // スタートコンディションを発行する
//     if(ans == 0){
//          I2C_Send(address) ;                // レジスタアドレスの送信
//          I2C_Send(val) ;                    // データ内容の送信
//           
//     } else ans = -1 ;
//     return ans ;
//}

//int register_rewrite(char address, char val)
//{
//     int ans ;
//
//     ans = I2C_rStart(S11059_ADRES,RW_0);    // スタートコンディションを発行する
//     if (ans == 0) {
//          I2C_Send(address) ;                // レジスタアドレスの送信
//          I2C_Send(val) ;                    // データ内容の送信
//     } else ans = -1 ;
//     return ans ;
//}

//int register_write_read(char address)
//{
//     int ans ;
//      
//     ans = I2C_Start(S11059_ADRES,RW_0);    // スタートコンディションを発行する
//     if(ans == 0){
//          I2C_Send(address) ;                // レジスタアドレスの送信
////          I2C_Send(val) ;                    // データ内容の送信
//           
//     } else ans = -1 ;
//     I2C_rStart(S11059_ADRES,RW_1);    // スタートコンディションを発行する
//     return ans ;
//}

/*******************************************************************************
*  ans = acceler_Init()                                                        *
*    ADXL345の初期化を行う処理                                                 *
*    ans = -1ならADXL345が応答していない                                       *
*******************************************************************************/
//int ColorSensor_Init(void)
//{
//    int ans ;
//    
//    register_write(CONTROL,0x89) ;     // ADCリセット、スリープ解除
//    register_rewrite(CONTROL,0x09) ;     // ADCリセット解除、バスリリース
//    
//    I2C_Stop();                            // ストップコンディションを発行する
//    __delay_ms(1000);
//    
//    register_write_read(0x03);
//    
//    
//
//}
/*******************************************************************************
*  void Color_Read(void)                                                        *
*    各色の値を読み込む処理。先に1回、初期設定ありのColor();を実行すること                                   *
*                                                                              *
*******************************************************************************/
void Color_Read(void)
{
    char buf[16];
    int i;
    int  ans ;
    
    __delay_ms(100);
    ans =I2C_Start(0x2A,RW_0);
    if (ans == 0) {
        I2C_Send(0x03);
    }
    ans =I2C_rStart(0x2A,RW_1);
    i=0;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(NOACK);
    c[i]=(a[i]<<8)|b[i];
    
    I2C_Stop();
    
    LCD_Clear() ;
    __delay_ms(20);
    
    i=0;
    sprintf(buf,"R:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(10);
    i++;
    
    sprintf(buf,"G:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(10);
    i++;
    
    LCD_SetCursor(0,1);
    __delay_ms(10);
    
    sprintf(buf,"B:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(10);
    i++;
    
    sprintf(buf,"I:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(10);

}
/*******************************************************************************
*  void Color(void)                                                        *
*    ST11059の初期設定と各色の値を読み込む処理                                     *
 *   固定時間モード、Highゲイン、22.4ms/ch                                   *
*******************************************************************************/
void Color(void){

    char buf[16];
    int i;
    int  ans ;

    ans =I2C_Start(0x2A,RW_0);
    if (ans == 0) {
        I2C_Send(0x00);
        I2C_Send(0x8A);
    }
    __delay_ms(10);
    
    ans =I2C_rStart(0x2A,RW_0);
    if (ans == 0) {
        I2C_Send(0x00);
        I2C_Send(0x0A);
        }
    I2C_Stop();
    

    __delay_ms(120);
    ans =I2C_Start(0x2A,RW_0);
    if (ans == 0) {
        I2C_Send(0x03);
    }
    ans =I2C_rStart(0x2A,RW_1);
    i=0;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(ACK);
    c[i]=(a[i]<<8)|b[i];
    i++;
    a[i]=I2C_Receive(ACK);
    b[i]=I2C_Receive(NOACK);
    c[i]=(a[i]<<8)|b[i];
    
    I2C_Stop();
    
    LCD_Clear() ;
    __delay_ms(20);
    
    i=0;
    sprintf(buf,"R:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(20);
    i++;
    
    sprintf(buf,"G:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(20);
    i++;
    
    LCD_SetCursor(0,1);
    __delay_ms(20);
    
    sprintf(buf,"B:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(20);
    i++;
    
    sprintf(buf,"I:0x%04x",c[i]);
    LCD_Puts(buf);
    __delay_ms(20);
    
}