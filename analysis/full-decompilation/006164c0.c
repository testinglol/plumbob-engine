
void FUN_006164c0(byte *param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    if (0 < param_3) {
      do {
        uVar1 = (uint)param_1[3];
        param_1[3] = param_1[3];
        param_1[2] = (byte)((param_1[2] * uVar1 + 0x80) / 0xff);
        param_1[1] = (byte)((param_1[1] * uVar1 + 0x80) / 0xff);
        param_3 = param_3 + -1;
        *param_1 = (byte)((*param_1 * uVar1 + 0x80) / 0xff);
        param_1 = param_1 + 4;
      } while (param_3 != 0);
    }
  }
  else if (0 < param_3) {
    do {
      uVar1 = (uint)param_1[3];
      param_1[3] = param_1[3];
      if (uVar1 != 0) {
        param_1[2] = (byte)(((uint)param_1[2] * 0xff + 0x80) / uVar1);
        param_1[1] = (byte)(((uint)param_1[1] * 0xff + 0x80) / uVar1);
        *param_1 = (byte)(((uint)*param_1 * 0xff + 0x80) / uVar1);
      }
      param_1 = param_1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return;
  }
  return;
}

