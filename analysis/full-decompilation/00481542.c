
int FUN_00481542(int param_1,short *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = (int)(short)param_1 >> 0xd & 7;
  if (uVar1 == 0) {
    *param_2 = 0x1000;
  }
  else if (uVar1 == 1) {
    *param_2 = 0x2000;
  }
  else {
    if (uVar1 != 2) {
      return (uint)(uint3)(int3)(char)((uint)param_1 >> 8) << 8;
    }
    *param_2 = 0x100;
  }
  *param_2 = *param_2 + ((ushort)(param_1 >> 7) & 0x3f);
  *param_3 = (int)(short)param_1 & 0x7f;
  return 1;
}

