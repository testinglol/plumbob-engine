
undefined4 __fastcall FUN_00413154(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    FUN_005b8e25(iVar1);
    FUN_005b95c0(iVar1);
    *(undefined4 *)(param_1 + 4) = 0;
    return 0;
  }
  return 0xffffffcf;
}

