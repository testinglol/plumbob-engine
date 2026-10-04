
void FUN_004b56ae(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_2 - param_1 >> 2;
  if (0 < iVar2) {
    puVar1 = (undefined1 *)(param_1 + 2);
    param_1 = (int)param_3 - param_1;
    do {
      if (param_3 != puVar1 + -2) {
        *param_3 = puVar1[-2];
        param_3[1] = puVar1[-1];
        puVar1[param_1] = *puVar1;
        param_3[3] = puVar1[1];
      }
      param_3 = param_3 + 4;
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

