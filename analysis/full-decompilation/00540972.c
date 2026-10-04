
void __thiscall FUN_00540972(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    iVar2 = 0;
    param_2 = 2;
  }
  else {
    iVar2 = param_2 + -1;
  }
  if (iVar2 < param_2) {
    param_2 = param_2 - iVar2;
    puVar3 = (undefined4 *)(param_1 + 0x10 + iVar2 * 4);
    do {
      piVar1 = (int *)*puVar3;
      for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 4) {
        FUN_0053f59e();
        piVar1 = (int *)*puVar3;
      }
      puVar3 = puVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  FUN_004a6a08();
  return;
}

