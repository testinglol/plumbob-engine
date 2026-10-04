
undefined4 __thiscall FUN_0049bfe2(undefined4 *param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  void *pvVar2;
  
  param_1[1] = param_2;
  iVar1 = FUN_0049bf89(param_2);
  param_1[2] = iVar1;
  param_1[3] = iVar1 * 0x40;
  param_1[4] = 0xe8;
  if (param_3 == '\0') {
    pvVar2 = _malloc(iVar1 * 0x3a00);
    *param_1 = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 1;
    }
  }
  return 0;
}

