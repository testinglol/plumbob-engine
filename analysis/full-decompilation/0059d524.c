
void FUN_0059d524(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = (param_2 - (int)param_1) / 0x18;
  if (0 < iVar2) {
    puVar5 = param_3 + 5;
    puVar4 = param_1 + 5;
    puVar3 = param_3;
    param_3 = (undefined4 *)iVar2;
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 6;
      *puVar3 = uVar1;
      puVar5[-4] = puVar4[-4];
      puVar5[-3] = puVar4[-3];
      puVar5[-2] = puVar4[-2];
      puVar5[-1] = puVar4[-1];
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 6;
      puVar3 = puVar3 + 6;
      puVar5 = puVar5 + 6;
      param_3 = (undefined4 *)((int)param_3 + -1);
    } while (param_3 != (undefined4 *)0x0);
  }
  return;
}

