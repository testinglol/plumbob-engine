
void __thiscall FUN_00424010(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = param_2;
  iVar2 = *(int *)(param_1 + 4) - param_3 >> 3;
  if (0 < iVar2) {
    iVar3 = param_3 - (int)param_2;
    puVar4 = param_2;
    param_2 = (undefined4 *)iVar2;
    do {
      *puVar4 = *(undefined4 *)(iVar3 + (int)puVar4);
      puVar4[1] = *(undefined4 *)(iVar3 + 4 + (int)puVar4);
      puVar4 = puVar4 + 2;
      param_2 = (undefined4 *)((int)param_2 + -1);
    } while (param_2 != (undefined4 *)0x0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)puVar1 >> 3) * -8;
  return;
}

