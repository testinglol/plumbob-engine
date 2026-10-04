
undefined4 __fastcall FUN_004c24ab(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(char *)(param_1 + 0x150) != '\0') && (*(char *)(param_1 + 0x151) != '\0')) &&
     ((uint)(*(int *)(param_1 + 0x144) + *(int *)(param_1 + 0x18)) <= DAT_006e5490)) {
    uVar1 = 1;
  }
  return uVar1;
}

