
void __thiscall FUN_005bd82a(int param_1,undefined2 *param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  
  puVar1 = param_2;
  iVar2 = *(int *)(param_1 + 4) - param_3 >> 1;
  if (0 < iVar2) {
    iVar3 = param_3 - (int)param_2;
    puVar4 = param_2;
    param_2 = (undefined2 *)iVar2;
    do {
      *puVar4 = *(undefined2 *)(iVar3 + (int)puVar4);
      puVar4 = puVar4 + 1;
      param_2 = (undefined2 *)((int)param_2 + -1);
    } while (param_2 != (undefined2 *)0x0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)puVar1 >> 1) * -2;
  return;
}

