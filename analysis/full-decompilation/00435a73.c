
uint __fastcall FUN_00435a73(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(short *)(param_1 + 0xb4) != 0) {
    uVar1 = (int)*(short *)(param_1 + 0xb4) << (*(byte *)(param_1 + 0x4c) & 0x1f);
    uVar1 = uVar1 & 0xff | uVar1 >> 8 & 0xff;
  }
  return uVar1;
}

