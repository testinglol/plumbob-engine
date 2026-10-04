
int * __thiscall FUN_005a5856(int *param_1,int *param_2)

{
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  *(char *)(param_1 + 6) = (char)param_2[6];
  if (*param_2 != 0) {
    FUN_005e357a();
  }
  *param_1 = *param_2;
  return param_1;
}

