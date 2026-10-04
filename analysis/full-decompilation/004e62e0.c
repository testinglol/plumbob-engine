
undefined4 __fastcall FUN_004e62e0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    uVar1 = FUN_0057aed0();
    *(undefined4 *)(param_1 + 0x18) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x18);
}

