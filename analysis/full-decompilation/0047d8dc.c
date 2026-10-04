
undefined1 * FUN_0047d8dc(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = (param_2 - param_1) / 3;
  if (iVar1 < 1) {
    return param_3;
  }
  do {
    puVar2 = param_3 + -3;
    iVar1 = iVar1 + -1;
    *puVar2 = *(undefined1 *)(param_2 + -3);
    param_3[-2] = *(undefined1 *)(param_2 + -2);
    param_3[-1] = *(undefined1 *)(param_2 + -1);
    param_3 = puVar2;
    param_2 = param_2 + -3;
  } while (iVar1 != 0);
  return puVar2;
}

