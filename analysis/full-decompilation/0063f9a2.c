
uint FUN_0063f9a2(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00703ff0;
  while( true ) {
    if (DAT_00703ff0 + DAT_00703fec * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}

