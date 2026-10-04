
bool FUN_00625860(byte *param_1,int param_2)

{
  if (param_1[1] < param_1[2]) {
    return (int)((uint)param_1[2] + param_2) < (int)(uint)*param_1;
  }
  return (int)((uint)param_1[1] + param_2) < (int)(uint)*param_1;
}

