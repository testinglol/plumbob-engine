
uint FUN_0063626d(uint param_1,uint param_2)

{
  uint uVar1;
  bool in_ZF;
  short in_FPUControlWord;
  
  if (in_ZF) {
    if (((param_2 & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_00641a0c();
      goto LAB_006362eb;
    }
    param_1 = param_2 & 0x80000000;
    param_2 = 0;
joined_r0x006362dc:
    if (param_1 == 0) {
LAB_0063628e:
      if (DAT_00703a9c != 0) {
        return param_2;
      }
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      param_2 = FUN_006419f5();
    }
    if ((param_2 & 0x80000000) == 0) goto LAB_0063628e;
    if (((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) goto joined_r0x006362dc;
  }
  uVar1 = 1;
LAB_006362eb:
  if (DAT_00703a9c != 0) {
    return uVar1;
  }
  uVar1 = __startOneArgErrorHandling();
  return uVar1;
}

