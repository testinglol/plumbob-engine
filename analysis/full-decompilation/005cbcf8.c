
void FUN_005cbcf8(uint *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = (ushort)(uVar1 >> 9) & 0x7c00 | (ushort)(uVar1 >> 6) & 0x3e0 |
               (ushort)(uVar1 >> 3) & 0x1f;
    param_2 = param_2 + 1;
  }
  return;
}

