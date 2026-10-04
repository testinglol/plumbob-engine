
void __thiscall FUN_004b523c(char *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_004aeea6();
  if (iVar1 == 0) {
    *param_1 = (char)param_2;
LAB_004b5252:
    param_1[1] = (char)param_3;
  }
  else {
    if (iVar1 == 1) {
      param_1[2] = (char)param_2;
    }
    else {
      iVar1 = param_2 * param_2 + param_3 * param_3;
      if (iVar1 < (int)*param_1 * (int)*param_1 + (int)param_1[1] * (int)param_1[1]) {
        *param_1 = (char)param_2;
        goto LAB_004b5252;
      }
      if ((int)param_1[2] * (int)param_1[2] + (int)param_1[3] * (int)param_1[3] <= iVar1) {
        return;
      }
      param_1[2] = (char)param_2;
    }
    param_1[3] = (char)param_3;
  }
  return;
}

