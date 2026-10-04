
void __thiscall FUN_005cee52(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  local_8 = param_1;
  if (*(int *)(param_1 + 0x1c8) == 0) {
    piVar1 = (int *)FUN_005d0135();
    iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_1 + 0x1cc,0);
    *(int *)(param_1 + 0x5c) = iVar2;
    if (iVar2 != 0) {
      return;
    }
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0x1cc) + 0xc))(*(int **)(param_1 + 0x1cc),param_2);
  *(int *)(param_1 + 0x5c) = iVar2;
  if (iVar2 == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x1cc) + 0x14))
                      (*(int **)(param_1 + 0x1cc),*(undefined4 *)(*(int *)(param_1 + 0x60) + 0x38),
                       &local_8);
    *(int *)(param_1 + 0x5c) = iVar2;
    if (iVar2 == 0) {
      uVar3 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(*(int **)(param_1 + 0xd8),local_8);
      *(undefined4 *)(param_1 + 0x5c) = uVar3;
    }
  }
  return;
}

