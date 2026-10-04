
undefined4 __fastcall FUN_004d4090(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x174) == 0) && (*(int *)(DAT_006e486c + 4) != 0)) {
    uVar1 = FUN_004d44d4();
    *(undefined4 *)(param_1 + 0x174) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x174);
}

