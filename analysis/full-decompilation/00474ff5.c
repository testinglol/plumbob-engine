
undefined4 FUN_00474ff5(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  do {
    uVar1 = FUN_004750a6();
    iVar2 = FUN_00474cae(uVar1);
    if (iVar2 == 1) {
      uVar1 = 1;
      goto LAB_00475046;
    }
  } while (iVar2 != 2);
  uVar1 = 0;
LAB_00475046:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

