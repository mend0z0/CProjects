;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
;
;				Project Name:
;		  @Brief Description:
;				 File Status:	DRAFT
;						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
;	File Name:	xxxx.c
;	Version:	xx
;	Revision:	xx
;	Date:		10/01/2022
;   Company:    Mend0z0
;	Client:     ----------
;	License:	Private License (Contact for more info.)
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Project Description ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	@Detailed Description:
;
;
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; File Description ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	@Detailed Description:
;
;
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  Processor Info ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Processor:					x-Bits
;	Clock Frequency:	00.000	xHz
;	RAM/SRAM Size:		00.00	MBytes
;	Flash Size:			00.00	MBytes
;	Cache Size:			00.00	MBytes
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  Case Style  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Variables = camelCase			
;	Const Variables = SCREAMIN_SNAKE_CASE
;	Labels = PascalCase				
;	Macros = _lower_case
;	Struct = lower_case					Struct.members = camelCase
;	Enum = lower_case					Enum Members = SNAKE_CASE
;	Pointer Variables = p_camelCase
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Contact Info ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Author:	Siavash Taher Parvar
;	Email:  s.taherparvar@gmail.com
;	Github: github.com/mend0z0
;						CONFIDENTIAL DOCUMENT, DO NOT DISTRIBUTE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;			  MACROS		     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;				©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
;
;		 @Brief Description:
;			Function Status: 	DRAFT
;					(DRAFT , PRILIMINARY, CHECKED, RELEASED)
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Author:		Siavash Taher Parvar					Checked By:
;	Date:		mm/dd/yyyy
;	Version:	xx
;	Revision:	xx
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	Macro Name:
;	Macro Parameters:
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	@Detailed Description: (Do numbering and tag the number to each part of code)
;	(1)
;	(2)
;	(3)
;	.
;	.
;	.
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Revision History (Description, author, date: mm/dd/yyyy)
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	License: Private License (Contact for more info.)
;	Email: s.taherparvar@gmail.com
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;			  LABELS		     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;				©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
;
;		 @Brief Description:
;			Function Status: 	DRAFT
;					(DRAFT , PRILIMINARY, CHECKED, RELEASED)
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Author:		Siavash Taher Parvar					Checked By:
;	Date:		mm/dd/yyyy
;	Version:	xx
;	Revision:	xx
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	Label Name:
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	@Detailed Description: (Do numbering and tag the number to each part of code)
;	(1)
;	(2)
;	(3)
;	.
;	.
;	.
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Revision History (Description, author, date: mm/dd/yyyy)
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	License: Private License (Contact for more info.)
;	Email: s.taherparvar@gmail.com
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;		  DATA SECTION		     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
section .data		;r/w data	This data is initialized, but can be modified.
POWER_UP				EQU		0X01	;	Power up device and mode selection.
GET_REV					EQU		0X10	;	Returns revision information on the device.
POWER_DOWN				EQU		0X11	;	Power down device.
SET_PROPERTY			EQU		0X12	;	Sets the value of a property.
GET_PROPERTY			EQU		0X13	;	Retrieves a property’s value.
GET_INT_STATUS			EQU		0X14	;	Reads interrupt status bits.
PATCH_ARGS				EQU		0X15	;	Reserved command used for patch file downloads.
PATCH_DATA				EQU		0X16	;	Reserved command used for patch file downloads.
FM_TUNE_FREQ			EQU		0X20	;	Selects the FM tuning frequency.
FM_SEEK_START			EQU		0X21	;	Begins searching for a valid frequency.
FM_TUNE_STATUS			EQU		0X22	;	Queries the status of previous FM_TUNE_FREQ or FM_SEEK_START command.
FM_RSQ_STATUS			EQU		0X23	;	Queries the status of the Received Signal Quality (RSQ) of the current channel.
FM_RDS_STATUS			EQU		0X24	;	Returns RDS information for current channel and reads an entry from RDS FIFO.
FM_AGC_STATUS			EQU		0X27	;	Queries the current AGC settings
FM_AGC_OVERRIDE			EQU		0X28	;	Override AGC setting by disabling and forcing it to a fixed value
GPIO_CTL				EQU		0X80	;	Configures GPO1, 2, and 3 as output or Hi-Z.
GPIO_SET				EQU		0X81	;	Sets GPO1, 2, and 3 output level (low or high).

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;       MAIN BODY PROGRAM         ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
start:
    inc r16
    rjmp start
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;				©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
;
;		 @Brief Description:
;			Function Status: 	DRAFT
;					(DRAFT , PRILIMINARY, CHECKED, RELEASED)
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Author:		Siavash Taher Parvar					Checked By:
;	Date:		mm/dd/yyyy
;	Version:	xx
;	Revision:	xx
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	Main Routin:
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	@Detailed Description: (Do numbering and tag the number to each part of code)
;	(1)
;	(2)
;	(3)
;	.
;	.
;	.
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	Revision History (Description, author, date: mm/dd/yyyy)
;
;	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	License: Private License (Contact for more info.)
;	Email: s.taherparvar@gmail.com
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
section		.text		;r/o code	This is the program's executable machine code (it's binary data, not plain text!).


	

;;;;;;;;;;;;;;;;;;;;;;;;;;;   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     END OF THE FILE      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
