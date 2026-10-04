
int __fastcall FUN_005d4650(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 0x54) == 0) && (*(int *)(param_1 + 0x58) == 0)) &&
     (iVar2 = FUN_005d4615(), iVar2 != 0)) {
    return iVar2;
  }
  if (*(int *)(param_1 + 0x8c) == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
  }
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x64f4fffe;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1 + 4);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x58) + 0x14))
                        (*(int **)(param_1 + 0x58),*(undefined4 *)(*(int *)(param_1 + 0x60) + 0x38),
                         param_1 + 0x5c);
      return iVar2;
    }
  }
  return iVar2;
}

