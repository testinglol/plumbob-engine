
void __thiscall FUN_005cdf02(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (DAT_006d6184 != 0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)param_1[1]) {
      do {
        *piVar1 = *piVar1 + param_2;
        piVar1[1] = piVar1[1] + param_3;
        piVar1[2] = piVar1[2] + param_2;
        piVar1[3] = piVar1[3] + param_3;
        piVar1 = piVar1 + 4;
      } while (piVar1 != (int *)param_1[1]);
    }
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return;
}

