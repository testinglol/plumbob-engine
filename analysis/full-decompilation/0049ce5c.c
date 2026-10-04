
void __fastcall FUN_0049ce5c(int param_1)

{
  int iVar1;
  
  FUN_004a496a();
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  if (iVar1 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  if (iVar1 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar1);
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}

