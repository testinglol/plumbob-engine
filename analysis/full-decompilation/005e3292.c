
int * FUN_005e3292(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(100);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005dfb13();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar3 + 0xc))
                      (extraout_ECX[7],extraout_ECX[8],extraout_ECX[2],extraout_ECX[3],0,
                       extraout_ECX[0x10],extraout_ECX[0x11]);
    if (cVar1 == '\0') {
      (**(code **)*piVar3)(1);
    }
    else {
      *(int *)(unaff_EBP + -0x18) = extraout_ECX[9];
      *(int *)(unaff_EBP + -0x14) = extraout_ECX[10];
      (**(code **)(*piVar3 + 0x74))(unaff_EBP + -0x18);
      (**(code **)(*extraout_ECX + 0x70))();
      cVar1 = (**(code **)(*piVar3 + 0x20))(0x10);
      if (cVar1 != '\0') {
        (**(code **)(*piVar3 + 0x9c))(extraout_ECX,extraout_ECX + 5,extraout_ECX + 5,0);
        (**(code **)(*piVar3 + 0x24))(0x10);
        (**(code **)(*extraout_ECX + 0x74))(unaff_EBP + -0x18);
        goto LAB_005e3364;
      }
      (**(code **)*piVar3)(1);
      (**(code **)(*extraout_ECX + 0x74))(unaff_EBP + -0x18);
    }
  }
  piVar3 = (int *)0x0;
LAB_005e3364:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

