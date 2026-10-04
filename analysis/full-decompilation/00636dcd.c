
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00636dcd(int param_1)

{
  uint in_EAX;
  bool in_ZF;
  unkbyte10 in_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      fVar1 = (float10)FUN_00641a0c();
      if (DAT_00703a9c != 0) {
        return fVar1;
      }
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
    fVar1 = _DAT_006dd37a;
    if ((in_EAX & 0x80000000) != 0) {
      fVar1 = -_DAT_006dd37a;
    }
  }
  else {
    fVar1 = (float10)fpatan(in_ST0,(float10)1);
  }
  if (DAT_00703a9c != 0) {
    return fVar1;
  }
  fVar1 = (float10)__math_exit();
  return fVar1;
}

