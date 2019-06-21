#include "__cf_PWM_emulator.h"
#include <math.h>
#include "PWM_emulator_acc.h"
#include "PWM_emulator_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T adtpljogbc ;
ZCEventType zcEvent ; real_T tmp ; i3hrwc4e31 * _rtB ; h520mytdpf * _rtP ;
ego3mxhxp0 * _rtZCE ; b4i2pmity5 * _rtDW ; _rtDW = ( ( b4i2pmity5 * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( ego3mxhxp0 * ) _ssGetPrevZCSigState ( S
) ) ; _rtP = ( ( h520mytdpf * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( i3hrwc4e31
* ) _ssGetModelBlockIO ( S ) ) ; adtpljogbc = ( _rtDW -> jg1n0jnxw3 < _rtP ->
P_6 ) && ( _rtDW -> jg1n0jnxw3 >= 0 ) ? _rtP -> P_4 : 0.0 ; if ( _rtDW ->
jg1n0jnxw3 >= _rtP -> P_5 - 1.0 ) { _rtDW -> jg1n0jnxw3 = 0 ; } else { _rtDW
-> jg1n0jnxw3 ++ ; } zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & _rtZCE ->
f2qzzghgti , ( adtpljogbc ) ) ; if ( zcEvent != NO_ZCEVENT ) {
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW -> mqpt0ci2wv
= 4 ; } if ( ( _rtB -> kynmsw1ve2 > 0 ) && ( _rtZCE -> cktpssidzl !=
POS_ZCSIG ) ) { ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ;
_rtDW -> jbelzecr5w = 4 ; } _rtZCE -> cktpssidzl = ( uint8_T ) ( _rtB ->
kynmsw1ve2 > 0 ) ; if ( _rtDW -> cwl5vklh5b != 0 ) { _rtDW -> ax3iekfdon =
muDoubleScalarSin ( _rtP -> P_10 * ssGetTaskTime ( S , 0 ) ) ; _rtDW ->
p3qkz4glcv = muDoubleScalarCos ( _rtP -> P_10 * ssGetTaskTime ( S , 0 ) ) ;
_rtDW -> cwl5vklh5b = 0 ; } if ( ( _rtB -> ceqr3ops04 > 0 ) && ( _rtZCE ->
bbysozp5li != POS_ZCSIG ) ) { adtpljogbc = ( ( ( _rtDW -> ax3iekfdon * _rtP
-> P_14 + _rtDW -> p3qkz4glcv * _rtP -> P_13 ) * _rtP -> P_12 + ( _rtDW ->
p3qkz4glcv * _rtP -> P_14 - _rtDW -> ax3iekfdon * _rtP -> P_13 ) * _rtP ->
P_11 ) * _rtP -> P_8 + _rtP -> P_9 ) / ( real_T ) _rtB -> gc5kopzp1y ; if (
adtpljogbc > _rtP -> P_1 ) { adtpljogbc = _rtP -> P_1 ; } else { if (
adtpljogbc < _rtP -> P_2 ) { adtpljogbc = _rtP -> P_2 ; } } tmp =
muDoubleScalarFloor ( adtpljogbc * ( real_T ) _rtB -> ofrkro13vk ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 65536.0 ) ; } _rtB -> ize5bzjovr = (
uint16_T ) ( tmp < 0.0 ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T )
- tmp : ( int32_T ) ( uint16_T ) tmp ) ; _rtB -> nyzocdhntc = _rtP -> P_3 *
adtpljogbc ; _rtDW -> n55d1xsvo4 = 4 ; } _rtZCE -> bbysozp5li = ( uint8_T ) (
_rtB -> ceqr3ops04 > 0 ) ; if ( _rtB -> oorv0ozrog <= _rtB -> ize5bzjovr ) {
_rtB -> gs5isiaetb = _rtB -> alsd0seegg ; } else { _rtB -> gs5isiaetb = _rtB
-> h3huy1vpsk ; } ssCallAccelRunBlock ( S , 5 , 12 , SS_CALL_MDL_OUTPUTS ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID1 ( SimStruct * S ,
int_T tid ) { i3hrwc4e31 * _rtB ; h520mytdpf * _rtP ; _rtP = ( ( h520mytdpf *
) ssGetModelRtp ( S ) ) ; _rtB = ( ( i3hrwc4e31 * ) _ssGetModelBlockIO ( S )
) ; _rtB -> alsd0seegg = _rtP -> P_18 ; _rtB -> hx22wj2igj = _rtP -> P_19 ;
_rtB -> ffthze2ats = _rtP -> P_20 ; _rtB -> gc5kopzp1y = _rtP -> P_16 ; _rtB
-> ofrkro13vk = _rtP -> P_17 ; _rtB -> h3huy1vpsk = _rtP -> P_21 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T HoldSine ;
h520mytdpf * _rtP ; b4i2pmity5 * _rtDW ; _rtDW = ( ( b4i2pmity5 * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( h520mytdpf * ) ssGetModelRtp ( S ) ) ;
HoldSine = _rtDW -> ax3iekfdon ; _rtDW -> ax3iekfdon = _rtDW -> ax3iekfdon *
_rtP -> P_12 + _rtDW -> p3qkz4glcv * _rtP -> P_11 ; _rtDW -> p3qkz4glcv =
_rtDW -> p3qkz4glcv * _rtP -> P_12 - HoldSine * _rtP -> P_11 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID1 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 4282600360U ) ; ssSetChecksumVal ( S , 1 , 641714551U ) ;
ssSetChecksumVal ( S , 2 , 1268680580U ) ; ssSetChecksumVal ( S , 3 ,
2126258264U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
b4i2pmity5 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( i3hrwc4e31 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
h520mytdpf ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & pz2jr5oad4 ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID1 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
