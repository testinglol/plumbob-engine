
int FUN_005cffec(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x90);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005d0bd9(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar3 == (int *)0x0) {
LAB_005d0028:
    iVar4 = -0x64f4ffff;
  }
  else {
    iVar4 = FUN_005d0973();
    if (iVar4 != 0) goto LAB_005d00a0;
    (**(code **)(*piVar3 + 8))();
    (**(code **)(*piVar3 + 8))();
    if (*(int *)(extraout_ECX + 0x2c) - *(int *)(extraout_ECX + 0x28) >> 2 == 0x3fffffff) {
      cVar1 = FUN_005d00b1();
      if (cVar1 == '\0') {
        (**(code **)(*piVar3 + 4))();
        (**(code **)(*piVar3 + 4))();
        **(undefined4 **)(unaff_EBP + 8) = 0;
        goto LAB_005d0028;
      }
    }
    *(int **)(unaff_EBP + -0x10) = piVar3;
    FUN_00468a79(unaff_EBP + -0x10);
    cVar1 = *(char *)(unaff_EBP + 0xc);
    **(undefined4 **)(unaff_EBP + 8) = piVar3;
    if (cVar1 == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005d00fa(piVar3);
    }
  }
LAB_005d00a0:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

