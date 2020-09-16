#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "stm32f4xx_hal.h"
#include "MacroAndConst.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
//�û������Լ�����Ҫ����
#ifdef STM32F411xE
#define STM32_FLASH_SIZE 512 	 		//��ѡSTM32��FLASH������С(��λΪK)
#endif
#ifdef STM32F401xC
#define STM32_FLASH_SIZE 128 	 		//��ѡSTM32��FLASH������С(��λΪK)
#endif
#define STM32_FLASH_WREN 1        		//ʹ��FLASHд��(0����ʹ��;1��ʹ��)

#define STM_SECTOR_SIZE	131072U		// ������С:128K

#define FLASH_WAITETIME  50000          //FLASH�ȴ���ʱʱ��

#define FIRST_128K_SECTOR_NUM		3

#ifdef STM32F411xE
// F411XE ��7������   FLASH������512K 
//FLASH ��������ʼ��ַ				
#define ADDR_FLASH_SECTOR_0     ((u32)0x08000000) 	//����0��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_1     ((u32)0x08004000) 	//����1��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_2     ((u32)0x08008000) 	//����2��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_3     ((u32)0x0800C000) 	//����3��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_4     ((u32)0x08010000) 	//����4��ʼ��ַ, 64 Kbytes  
#define ADDR_FLASH_SECTOR_5     ((u32)0x08020000) 	//����5��ʼ��ַ, 128 Kbytes  
#define ADDR_FLASH_SECTOR_6     ((u32)0x08040000) 	//����6��ʼ��ַ, 128 Kbytes  
#define ADDR_FLASH_SECTOR_7     ((u32)0x08060000) 	//����7��ʼ��ַ, 128 Kbytes  

#endif	//#ifdef STM32F411xE

#ifdef STM32F401xC
// F401CCU6��൶����5 FLASH������256K
#define ADDR_FLASH_SECTOR_0     ((u32)0x08000000) 	//����0��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_1     ((u32)0x08004000) 	//����1��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_2     ((u32)0x08008000) 	//����2��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_3     ((u32)0x0800C000) 	//����3��ʼ��ַ, 16 Kbytes  
#define ADDR_FLASH_SECTOR_4     ((u32)0x08010000) 	//����4��ʼ��ַ, 64 Kbytes  
#define ADDR_FLASH_SECTOR_5     ((u32)0x08020000) 	//����5��ʼ��ַ, 128 Kbytes  
#endif	//#ifdef STM32F401xC


//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH����ʼ��ַ

u32 STMFLASH_ReadWord(u32 faddr);
u16 STMFLASH_ReadHalfWord(u32 faddr);		   //�������� 
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//ָ����ַ��ʼ��ȡָ����������
void STMFLASH_Read(u32 ReadAddr,u32 *pBuffer,u32 NumToRead);
void STMFLASH_HalfRead(u32 ReadAddr,u16 *pBuffer,u32 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

#if STM32_FLASH_WREN	//���ʹ����д   
HAL_StatusTypeDef STMFLASH_HalfWrite(u32 WriteAddr,u16 *pBuffer,u32 NumToWrite)	;	//��ָ����ַ��ʼд��ָ�����ȵ�����
HAL_StatusTypeDef STMFLASH_Write(u32 WriteAddr,u32 *pBuffer,u32 NumToWrite);
void Test_Write(u32 WriteAddr,u16 WriteData);      //����д��
  
#endif	//#if STM32_FLASH_WREN	

#endif

















