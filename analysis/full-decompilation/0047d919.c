
undefined1 * FUN_0047d919(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = (int)param_2 - param_1 >> 2;
  if (iVar1 < 1) {
    return param_3;
  }
  do {
    puVar3 = param_2 + -4;
    puVar2 = param_3 + -4;
    if (puVar2 != puVar3) {
      *puVar2 = *puVar3;
      param_3[-3] = param_2[-3];
      param_3[-2] = param_2[-2];
      param_3[-1] = param_2[-1];
    }
    iVar1 = iVar1 + -1;
    param_3 = puVar2;
    param_2 = puVar3;
  } while (iVar1 != 0);
  return puVar2;
}

