
int * FUN_00619ba0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)FUN_005a9320(param_1 * 0x14 + 0x48);
  if (piVar1 != (int *)0x0) {
    piVar2 = piVar1 + 0x12;
    piVar1[2] = (int)piVar2;
    *piVar1 = param_1;
    piVar1[1] = 0;
    piVar1[3] = 0;
    FUN_00619c00(piVar1 + 4,0x14,100);
    if (0 < param_1) {
      do {
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar2 = piVar2 + 5;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return piVar1;
}

