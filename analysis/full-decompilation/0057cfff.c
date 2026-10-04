
undefined4 FUN_0057cfff(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  do {
    FUN_00576e56();
    if (*(int *)(unaff_EBP + -0x1c) == *(int *)(unaff_EBP + -0x24)) {
      FUN_0057d65a();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x1c) + 8);
  } while (piVar1 == (int *)0x0);
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar2 + 0x58))();
  uVar3 = FUN_0057cfff();
  return uVar3;
}

