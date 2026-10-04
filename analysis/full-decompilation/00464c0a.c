
void __fastcall FUN_00464c0a(int *param_1)

{
  int *piVar1;
  
  if (*(char *)((int)param_1 + 0x13) != '\0') {
    param_1[8] = 0;
  }
  if (param_1[3] != 2) {
    if (param_1[3] == 1) {
      if (param_1[9] != 0) {
        piVar1 = (int *)(param_1[9] + *param_1);
        *piVar1 = param_1[2];
        if ((short)param_1[4] != 0) {
          FUN_004730c5(piVar1);
        }
      }
      param_1[9] = param_1[2];
      *(undefined4 *)(param_1[2] + *param_1) = 0;
    }
    else {
      param_1[9] = *(int *)(param_1[2] + *param_1);
      if ((short)param_1[4] != 0) {
        FUN_004730c5(param_1 + 9);
      }
    }
  }
  param_1[2] = param_1[2] + 4;
  return;
}

