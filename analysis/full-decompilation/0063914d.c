
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0063914d(int param_1)

{
  ushort uVar1;
  uint in_EAX;
  bool in_ZF;
  ushort in_FPUStatusWord;
  unkbyte10 in_ST0;
  float10 fVar2;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) == 0) && (param_1 == 0)) {
      in_FPUStatusWord = 1;
    }
    else {
      in_FPUStatusWord = FUN_00641a0c();
    }
    if (DAT_00703a9c == 0) {
      uVar1 = __startOneArgErrorHandling();
      return uVar1;
    }
  }
  else {
    fptan(in_ST0);
    fVar2 = (float10)1;
    if ((in_FPUStatusWord & 0x400) != 0) {
      do {
        fVar2 = fVar2 - ROUND(fVar2 / _DAT_0068954a) * _DAT_0068954a;
      } while ((in_FPUStatusWord & 0x400) != 0);
      fptan(fVar2);
    }
    if (DAT_00703a9c == 0) {
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  return in_FPUStatusWord;
}

