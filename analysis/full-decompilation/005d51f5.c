
undefined8 __fastcall
FUN_005d51f5(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = rdtsc();
  *param_1 = (int)uVar1;
  param_1[1] = (int)((ulonglong)uVar1 >> 0x20);
  param_1[2] = param_3;
  param_1[3] = param_4;
  return CONCAT44(param_2,param_1);
}

