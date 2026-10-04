
undefined1 * FUN_005403de(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = ((int)param_2 - param_1) / 6;
  if (iVar1 < 1) {
    return param_3;
  }
  do {
    puVar2 = param_3 + -6;
    iVar1 = iVar1 + -1;
    param_3[-5] = param_2[-5];
    *(undefined2 *)(param_3 + -4) = *(undefined2 *)(param_2 + -4);
    *(undefined2 *)(param_3 + -2) = *(undefined2 *)(param_2 + -2);
    *puVar2 = param_2[-6];
    param_3 = puVar2;
    param_2 = param_2 + -6;
  } while (iVar1 != 0);
  return puVar2;
}

