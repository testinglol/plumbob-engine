
void FUN_0061d9b0(byte *param_1,undefined4 param_2,int param_3)

{
  byte local_4;
  
  if (0 < param_3) {
    do {
      param_1[1] = param_1[1] ^ (byte)((uint)param_2 >> 8);
      local_4 = (byte)param_2;
      param_1[3] = param_1[3] ^ (byte)((uint)param_2 >> 0x18);
      param_1[2] = param_1[2] ^ param_2._2_1_;
      *param_1 = *param_1 ^ local_4;
      param_1 = param_1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

