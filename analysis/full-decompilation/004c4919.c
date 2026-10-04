
undefined4 __fastcall FUN_004c4919(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x24);
  if (((sVar1 < 0x1c) || (0x1d < sVar1)) && ((sVar1 < 0x2e || (0x30 < sVar1)))) {
    return 0;
  }
  return 1;
}

