
void __thiscall FUN_005406d1(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_3 == 0) {
    iVar2 = 0;
    param_3 = 2;
  }
  else {
    iVar2 = param_3 + -1;
  }
  if (iVar2 < param_3) {
    param_3 = param_3 - iVar2;
    puVar3 = (undefined4 *)(param_1 + 8 + iVar2 * 4);
    do {
      piVar1 = (int *)puVar3[2];
      for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
        FUN_0053d91f(param_2);
        piVar1 = (int *)puVar3[2];
      }
      piVar1 = (int *)*puVar3;
      for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
        FUN_0053cc1c();
        piVar1 = (int *)*puVar3;
      }
      piVar1 = (int *)*puVar3;
      for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
        FUN_0053cdb5();
        piVar1 = (int *)*puVar3;
      }
      puVar3 = puVar3 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

