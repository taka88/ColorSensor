/*******************************************************************************
*  skI2CLCDlib.h - Ｉ２Ｃ接続ＬＣＤ関数ライブラリ用インクルードファイル        *
*             ST7032iのコントローラ(8文字x2行／16文字x2行)タイプならＯＫです。 *
*                                                                              *
* ============================================================================ *
*  VERSION  DATE        BY                    CHANGE/COMMENT                   *
* ---------------------------------------------------------------------------- *
*  1.00     2013-07-25  きむ茶工房(きむしげ)  Create                           *
*  2.00     2015-03-01  きむ茶工房(きむしげ)  ST7032iコントローラLCDに対応     *
*******************************************************************************/
#ifndef _SKI2CLCDLIB_H_
#define _SKI2CLCDLIB_H_

#ifndef _XTAL_FREQ
 // Unless already defined assume 8MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 16000000  // 使用するPIC等により動作周波数値を設定する
#endif
#define ST7032_ADRES 0x3E     // I2C接続小型LCDモジュールのアドレス
//adress指定は7bitで指定。末尾のRWは関数内でビットシフト挿入

/******************************************************************************/
/*  定数の定義                                                                */
/******************************************************************************/
#define LCD_VDD3V                  1   // LCDの電源は3.3Vで使用する(昇圧回路ON)
#define LCD_VDD5V                  0   // LCDの電源は5.0Vで使用する(昇圧回路OFF)
#define LCD_USE_ICON               1   // アイコンを使う(アイコン付LCDのみ)
#define LCD_NOT_ICON               0   // アイコンは使わない

/******************************************************************************/
/*  LCDのアイコン用のアドレス定義(ST7032i液晶コントローラ)                    */
/******************************************************************************/
#define LCD_ICON_ANTENNA           0x4010    // アンテナ
#define LCD_ICON_PHONE             0x4210    // 電話
#define LCD_ICON_COMMUNICATION     0x4410    // 通信
#define LCD_ICON_INCOMING          0x4610    // 着信
#define LCD_ICON_UP                0x4710    // △
#define LCD_ICON_DOWN              0x4708    // ▽
#define LCD_ICON_LOCK              0x4910    // 錠
#define LCD_ICON_KINSHI            0x4B10    // 禁止(着信音OFF？)
#define LCD_ICON_BATTERY_LOW       0x4D10    // 電池が少ない充電しようよ
#define LCD_ICON_BATTERY_HALF      0x4D08    // 電池がまだまだ使えるよぉ
#define LCD_ICON_BATTERY_FULL      0x4D04    // 電池がまんぱい
#define LCD_ICON_BATTERY_EMPTY     0x4D02    // 電池が空っぽもうだめ
#define LCD_ICON_HANAMARU          0x4F10    // 大変よく出来ました(あ、ツールかも？)

/******************************************************************************/
/*  関数のプロトタイプ宣言                                                    */
/******************************************************************************/
void LCD_Clear(void) ;
void LCD_SetCursor(int col, int row) ;
void LCD_Putc(char c) ;
void LCD_Puts(const char * s) ;
void LCD_CreateChar(int p,char *dt) ;
void LCD_Init_ST7032i(int icon, int contrast, int bon, int colsu);
void LCD_Contrast(int contrast) ;
void LCD_IconClear(void) ;
void LCD_IconOnOff(int flag, unsigned int dt) ;
int  LCD_PageSet(int no) ;
void LCD_PageClear(void) ;
void LCD_PageSetCursor(int col, int row) ;
int  LCD_PageNowNo(void) ;
void LCD_Command(unsigned char c);


#endif
