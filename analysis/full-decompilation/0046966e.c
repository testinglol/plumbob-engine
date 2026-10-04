
int FUN_0046966e(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_2;
  if (piVar1 != (int *)param_2[1]) {
    piVar2 = piVar1;
    do {
      if ((((param_1[1] < piVar2[3]) && (piVar2[1] < param_1[3])) && (*param_1 < piVar2[2])) &&
         (*piVar2 < param_1[2])) {
        return ((int)piVar2 - (int)piVar1) / 0x14;
      }
      piVar2 = piVar2 + 5;
    } while (piVar2 != (int *)param_2[1]);
  }
  return -1;
}

