
uint FUN_0063ccfd(int param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  bool in_ZF;
  unkbyte10 in_ST0;
  
  if (!in_ZF) {
    if ((param_2 & 0x7ff00000) == 0) {
      if (((param_2 & 0xfffff) == 0) && (param_1 == 0)) {
        uVar1 = 2;
        goto LAB_0063cd8d;
      }
    }
    else if ((param_2 & 0x80000000) != 0) goto LAB_0063cd5c;
    log2(in_ST0);
LAB_0063cd2a:
    if (DAT_00703a9c != 0) {
      return param_2;
    }
    uVar1 = __math_exit();
    return uVar1;
  }
  if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
    uVar1 = FUN_00641a0c();
    goto LAB_0063cd8d;
  }
  param_2 = 0;
  if ((in_EAX & 0x80000000) == 0) goto LAB_0063cd2a;
LAB_0063cd5c:
  uVar1 = 1;
LAB_0063cd8d:
  if (DAT_00703a9c != 0) {
    return uVar1;
  }
  uVar1 = __startOneArgErrorHandling();
  return uVar1;
}

