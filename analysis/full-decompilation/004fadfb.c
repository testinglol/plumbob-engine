
undefined4 FUN_004fadfb(ushort *param_1)

{
  undefined4 uVar1;
  ushort in_FPUControlWord;
  
  uVar1 = 0;
  if ((((in_FPUControlWord & 0x300) != 0) || (((byte)in_FPUControlWord & 0x3f) != 0x3f)) ||
     ((in_FPUControlWord & 0xc00) != 0)) {
    uVar1 = 1;
  }
  if (param_1 != (ushort *)0x0) {
    *param_1 = in_FPUControlWord;
  }
  return uVar1;
}

