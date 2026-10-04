
undefined1 * FUN_004746d5(undefined1 *param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  param_2 = param_2 - (int)param_1;
  if (0 < param_2) {
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = param_3 + 1;
      param_2 = param_2 + -1;
      *param_3 = uVar2;
      param_3 = puVar1;
    } while (param_2 != 0);
  }
  return param_3;
}

