
void FUN_00541a8c(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (int *)0x0) {
      if (*param_1 != 0) {
        piVar1 = (int *)(*param_1 + 0x20);
        *piVar1 = *piVar1 + 1;
      }
      *param_3 = *param_1;
    }
    param_3 = param_3 + 1;
  }
  return;
}

