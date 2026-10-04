
void __fastcall FUN_004a496a(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

