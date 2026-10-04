
undefined4 __fastcall FUN_00579e40(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    FUN_00577447();
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    return 1;
  }
  if ((iVar1 != 1) && (iVar1 != 2)) {
    if (iVar1 == 3) {
      return 1;
    }
    if (iVar1 != 4) {
      return 1;
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x24) != 0) {
      *(undefined4 *)(param_1 + 8) = 5;
      iVar1 = **(int **)(param_1 + 4);
      uVar2 = (**(code **)(iVar1 + 0x74))(0,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x24),1,0);
      (**(code **)(iVar1 + 0x7c))(uVar2);
      return 1;
    }
  }
  FUN_00579ea3();
  return 1;
}

