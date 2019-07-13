// skADXL345I2C.h
// ＡＤＸＬ３４５関数ライブラリ用インクルードファイル(I2Cバージョン)
#ifndef _SKADXL345I2C_H_
#define _SKADXL345I2C_H_

#ifndef _XTAL_FREQ
 // Unless already defined assume 8MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 16000000       // 使用するPIC等により動作周波数値を設定する
#endif

// Ｉ２Ｃのアドレス
#define S11059_ADRES 0x2A        // ADXL345のアドレス(ALT ADDRESSピンがHIGHの時)

// レジスタのアドレス
#define CONTROL         0x00        // コントロール
#define MANUAL_TIME_Hi       0x01        // マニュアルタイミングレジスタ
#define MANUAL_TIME_Lo       0x02        // マニュアルタイミングレジスタ
#define DATA_RED_Hi     0x03        // センサのデータ用レジスタ（上位）
#define DATA_RED_Lo     0x04        // センサのデータ用レジスタ（下位）
#define DATA_GREEN_Hi   0x05        // センサのデータ用レジスタ（上位）
#define DATA_GREEN_Lo   0x06        // センサのデータ用レジスタ（下位）
#define DATA_BLUE_Hi    0x07        // センサのデータ用レジスタ（上位）
#define DATA_BLUE_Lo    0x08        // センサのデータ用レジスタ（下位）
#define DATA_IR_Hi      0x09        // センサのデータ用レジスタ（上位）
#define DATA_IR_Lo      0x0A        // センサのデータ用レジスタ（下位）


#define DEVID_VALUE   0xE5        // 固定のデバイスIDコードの内容

int register_read(char address);
int register_write(char address, char val);
int ColorSensor_Init(void) ;
void Color_Read(void) ;
void Color(void) ;

#endif
