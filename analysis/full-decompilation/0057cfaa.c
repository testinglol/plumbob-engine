
undefined4 FUN_0057cfaa(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 0x28) = 1;
  FUN_00580a92(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  while( true ) {
    if (*(int *)(unaff_EBP + -0x1c) == *(int *)(unaff_EBP + -0x24)) {
      FUN_0057d65a();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 1;
    }
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x1c) + 8);
    if (piVar1 != (int *)0x0) break;
    FUN_00576e56();
  }
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar2 + 0x58))();
  uVar3 = FUN_0057cfff();
  return uVar3;
}

