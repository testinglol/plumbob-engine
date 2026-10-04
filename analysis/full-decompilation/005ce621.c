
int __fastcall FUN_005ce621(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined1 uStack_8;
  
  *(undefined1 *)(param_1 + 100) = 1;
  piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
  iVar3 = (**(code **)(*piVar1 + 0x24))();
  if (iVar3 == 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
    iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2,*(undefined4 *)(param_1 + 0xd8));
    if (iVar3 == 0) {
      uStack_8 = (char)piVar1;
      if (uStack_8 != '\0') {
        FUN_005ce7c8();
      }
      iVar3 = 0;
    }
  }
  else if (iVar3 == -0x7789fe3e) {
    FUN_005d0125();
    piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
    iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1);
  }
  return iVar3;
}

