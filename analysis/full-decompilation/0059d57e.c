
void FUN_0059d57e(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = (param_2 - param_1) / 0x18;
  if (0 < iVar2) {
    puVar3 = param_3;
    puVar4 = (undefined4 *)(param_2 + 0x14);
    puVar5 = param_3 + 5;
    param_3 = (undefined4 *)iVar2;
    do {
      puVar1 = (undefined4 *)(param_2 + -0x18);
      param_2 = param_2 + -0x18;
      puVar3 = puVar3 + -6;
      param_3 = (undefined4 *)((int)param_3 + -1);
      *puVar3 = *puVar1;
      puVar5[-10] = puVar4[-10];
      puVar5[-9] = puVar4[-9];
      puVar5[-8] = puVar4[-8];
      puVar5[-7] = puVar4[-7];
      puVar5[-6] = puVar4[-6];
      puVar4 = puVar4 + -6;
      puVar5 = puVar5 + -6;
    } while (param_3 != (undefined4 *)0x0);
  }
  return;
}

