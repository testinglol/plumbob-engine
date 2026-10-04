
bool FUN_00625820(byte *param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = param_1[1];
  if (bVar1 < param_1[2]) {
    bVar1 = param_1[2];
  }
  return (int)((uint)bVar1 + param_2 * 2) < (int)(uint)*param_1;
}

