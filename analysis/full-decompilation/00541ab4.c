
void FUN_00541ab4(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (int *)0x0) {
      if (*param_1 != 0) {
        piVar1 = (int *)(*param_1 + 0x58);
        *piVar1 = *piVar1 + 1;
      }
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}

