
undefined4 __fastcall FUN_00457759(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xac) == -1) {
    FUN_00457da4();
    uVar1 = FUN_004561a0(0);
    uVar1 = FUN_00402741(uVar1);
    *(undefined4 *)(param_1 + 0xac) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0xac);
}

