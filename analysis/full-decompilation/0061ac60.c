
void FUN_0061ac60(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x18) == param_1 + 0x20) {
    iVar2 = FUN_00619c40(param_1,*(undefined4 *)(param_1 + 4));
    if (iVar2 == 0) {
      return;
    }
  }
  iVar2 = *(int *)*piVar1;
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  return;
}

