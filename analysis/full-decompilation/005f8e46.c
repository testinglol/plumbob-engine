
undefined4 __fastcall FUN_005f8e46(int param_1)

{
  int iVar1;
  
  (**(code **)(*(int *)(param_1 + 0x1c) + 8))();
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00634ecc(*(int *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_00634ecc(*(int *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    thunk_FUN_0062bc70();
    FUN_00634ecc(iVar1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  *(undefined1 *)(param_1 + 0x1068) = 0;
  return 1;
}

