
undefined4 FUN_005f884f(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = extraout_ECX[0xf];
  *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0xf;
  (**(code **)(iVar1 + 4))();
  piVar2 = (int *)extraout_ECX[0x19];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar2 != (int *)0x0) {
    cVar3 = (**(code **)(*piVar2 + 0x1c))();
    if (cVar3 != '\0') {
      (**(code **)(*(int *)extraout_ECX[0x19] + 0x18))();
    }
  }
  cVar3 = (**(code **)(*extraout_ECX + 0x24))();
  if (cVar3 != '\0') {
    (**(code **)(*extraout_ECX + 0x28))();
  }
  if ((int *)extraout_ECX[0x2f] != (int *)0x0) {
    piVar2 = *(int **)extraout_ECX[0x2f];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))();
      FUN_006321f0(*(undefined4 *)extraout_ECX[0x2f]);
    }
    FUN_006321f0(extraout_ECX[0x2f]);
    extraout_ECX[0x2f] = 0;
  }
  (**(code **)(*extraout_ECX + 0xf0))();
  iVar1 = extraout_ECX[0xf];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

