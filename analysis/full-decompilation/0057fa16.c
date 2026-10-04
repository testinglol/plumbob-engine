
undefined4 __fastcall FUN_0057fa16(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x1d0) == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x48);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xbc) + 0x88))(0x15);
  (**(code **)(**(int **)(param_1 + 0x1d0) + 0x44))(iVar1 + -0xe10 + iVar2);
  return 1;
}

