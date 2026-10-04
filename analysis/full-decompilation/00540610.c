
void __thiscall FUN_00540610(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xc + param_3 * 4);
  for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
    FUN_0053dd1c(param_2,param_4,0);
    piVar1 = *(int **)(param_1 + 0xc + param_3 * 4);
  }
  piVar1 = *(int **)(param_1 + 4 + param_3 * 4);
  for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
    FUN_0053c3dc(param_2,param_4,0);
    piVar1 = *(int **)(param_1 + 4 + param_3 * 4);
  }
  return;
}

