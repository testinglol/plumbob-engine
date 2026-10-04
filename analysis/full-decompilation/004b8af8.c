
void __thiscall FUN_004b8af8(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  
  puVar3 = (undefined2 *)(DAT_006f0bcc + DAT_006f0bbc * param_3 + param_2 * 2);
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar4 = *(undefined2 *)(param_1 + 6);
  }
  else {
    uVar4 = *(undefined2 *)(param_1 + 8);
  }
  if (param_5 == 0) {
    if (param_4 < 1) {
      return;
    }
    puVar1 = (undefined2 *)(param_1 + 6);
    *puVar3 = *(undefined2 *)(param_1 + 6);
    puVar3[1] = *puVar1;
    puVar3[2] = *puVar1;
    puVar3[3] = *puVar1;
    puVar3 = (undefined2 *)((int)puVar3 + DAT_006f0bbc);
    param_4 = param_4 + -1;
    param_5 = 1;
  }
  if (0 < param_4) {
    do {
      if ((param_5 & 3) == 2) {
        uVar2 = *(undefined2 *)(param_1 + 4);
        puVar3[2] = uVar4;
        *puVar3 = uVar2;
      }
      puVar3 = (undefined2 *)((int)puVar3 + DAT_006f0bbc);
      param_5 = param_5 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

