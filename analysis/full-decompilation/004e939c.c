
undefined4 FUN_004e939c(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = (int *)FUN_004e8a7a();
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      param_1 = 0;
      FUN_005a55f6(*piVar1,param_2,&param_1,4);
      if (param_1 != 0) {
        FUN_005a5e48(param_1);
        return 1;
      }
    }
  }
  return 0;
}

