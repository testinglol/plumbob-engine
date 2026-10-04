
int FUN_005cfd9c(void)

{
  undefined4 *puVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  piVar5 = (int *)0x0;
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *puVar1 = 0;
  pvVar3 = operator_new(0x90);
  *(void **)(unaff_EBP + 8) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 != (void *)0x0) {
    piVar5 = (int *)FUN_005d0b68(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar5 == (int *)0x0) {
LAB_005cfddd:
    iVar4 = -0x64f4ffff;
  }
  else {
    iVar4 = FUN_005d0973();
    if (iVar4 != 0) goto LAB_005cfe51;
    (**(code **)(*piVar5 + 8))();
    (**(code **)(*piVar5 + 8))();
    if (*(int *)(extraout_ECX + 0x2c) - *(int *)(extraout_ECX + 0x28) >> 2 == 0x3fffffff) {
      cVar2 = FUN_005d00b1();
      if (cVar2 == '\0') {
        (**(code **)(*piVar5 + 4))();
        (**(code **)(*piVar5 + 4))();
        *puVar1 = 0;
        goto LAB_005cfddd;
      }
    }
    *(int **)(unaff_EBP + 8) = piVar5;
    FUN_00468a79(unaff_EBP + 8);
    cVar2 = *(char *)(unaff_EBP + 0xc);
    *puVar1 = piVar5;
    if (cVar2 == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005d00fa(piVar5);
    }
  }
LAB_005cfe51:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

