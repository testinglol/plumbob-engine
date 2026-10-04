
void __thiscall FUN_0054074f(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(param_1 + 0xc + param_3 * 4);
  piVar3 = *(int **)(param_1 + 0xc + param_3 * 4);
  for (iVar4 = *piVar3; iVar4 != piVar3[1]; iVar4 = iVar4 + 4) {
    FUN_0053f04f(param_2);
    piVar3 = (int *)*puVar1;
  }
  puVar2 = (undefined4 *)(param_1 + 4 + param_3 * 4);
  piVar3 = *(int **)(param_1 + 4 + param_3 * 4);
  for (iVar4 = *piVar3; iVar4 != piVar3[1]; iVar4 = iVar4 + 4) {
    FUN_0053cc1c();
    piVar3 = (int *)*puVar2;
  }
  piVar3 = (int *)*puVar2;
  for (iVar4 = *piVar3; iVar4 != piVar3[1]; iVar4 = iVar4 + 4) {
    FUN_0053cdb5();
    piVar3 = (int *)*puVar2;
  }
  piVar3 = (int *)*puVar1;
  for (iVar4 = *piVar3; iVar4 != piVar3[1]; iVar4 = iVar4 + 4) {
    FUN_0053ef93();
    piVar3 = (int *)*puVar1;
  }
  return;
}

