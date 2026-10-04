
void FUN_00618e70(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (0 < param_2) {
    puVar1 = (undefined1 *)(param_1 + 2);
    puVar2 = (undefined1 *)(param_3 + 2);
    do {
      puVar2[1] = puVar1[-2];
      *puVar2 = puVar1[-1];
      puVar2[-1] = *puVar1;
      puVar2[-2] = puVar1[1];
      puVar1 = puVar1 + 0xc;
      puVar2 = puVar2 + 4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

