
void __fastcall FUN_005cce4d(undefined4 *param_1)

{
  int *piVar1;
  
  if (DAT_006d6184 != 0) {
    for (piVar1 = (int *)*param_1; piVar1 != (int *)param_1[1]; piVar1 = piVar1 + 4) {
      FUN_004a7901();
      if ((piVar1[2] <= *piVar1) || (piVar1[3] <= piVar1[1])) {
        FUN_005db3b0(piVar1);
        piVar1 = piVar1 + -4;
      }
    }
    FUN_005cce97();
  }
  return;
}

