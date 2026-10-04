
int FUN_005ca52e(byte *param_1,byte *param_2)

{
  return ((uint)param_1[2] - (uint)param_2[2]) * ((uint)param_1[2] - (uint)param_2[2]) +
         ((uint)*param_1 - (uint)*param_2) * ((uint)*param_1 - (uint)*param_2) * 2 +
         ((uint)param_1[1] - (uint)param_2[1]) * ((uint)param_1[1] - (uint)param_2[1]) * 4;
}

