
undefined4 __fastcall FUN_004573f9(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    uVar1 = FUN_0043aeef(param_1);
    *(undefined4 *)(param_1 + 0x8c) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x8c);
}

