
undefined4 FUN_005df69e(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
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
    cVar1 = (**(code **)(*extraout_ECX + 0x34))();
    cVar1 = (**(code **)(*piVar3 + 0xc))
                      (extraout_ECX[7],extraout_ECX[8],extraout_ECX[2],extraout_ECX[3],0,
                       cVar1 != '\0',2);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*(int *)extraout_ECX[0x12] + 0x24))(piVar3[0x12]);
      if (cVar1 != '\0') {
        extraout_ECX[0x17] = (int)piVar3;
        FUN_005e357a();
        cVar1 = (**(code **)(*(int *)extraout_ECX[0x17] + 0x20))(1);
        if (cVar1 != '\0') {
          (**(code **)(*(int *)extraout_ECX[0x17] + 0x38))(0xffff,0);
          (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(1);
        }
        uVar4 = 1;
        goto LAB_005df753;
      }
    }
    (**(code **)*piVar3)(1);
  }
  uVar4 = 0;
LAB_005df753:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

