
void FUN_005cbc09(uint *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = (ushort)(uVar1 >> 0x10) & 0xf000 | (ushort)(uVar1 >> 0xc) & 0xf00 |
               (ushort)(uVar1 >> 8) & 0xf0 | (ushort)(uVar1 >> 4) & 0xf;
    param_2 = param_2 + 1;
  }
  return;
}

