
undefined4 FUN_0057d0ce(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  FUN_00575b11(unaff_EBP + -0x18,unaff_EBP + 8);
  iVar1 = *(int *)(unaff_EBP + -0x18);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 8);
    iVar1 = FUN_005816d2(unaff_EBP + -0x20);
    piVar2 = *(int **)(unaff_EBP + 0xc);
    *(int **)(iVar1 + 4) = piVar2;
  }
  else {
    piVar2 = *(int **)(iVar1 + 8);
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(iVar1 + 0xc))();
      (**(code **)*piVar2)(1);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8) = 0;
      iVar1 = *(int *)(unaff_EBP + -0x18);
    }
    piVar2 = *(int **)(unaff_EBP + 0xc);
    *(int **)(iVar1 + 8) = piVar2;
  }
  (**(code **)(*piVar2 + 0x10))(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

