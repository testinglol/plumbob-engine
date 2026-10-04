
void FUN_0057cf17(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar2;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  (**(code **)(*(int *)(extraout_ECX + 0x128) + 4))();
  FUN_0057584f(extraout_ECX + 0x2c);
  iVar1 = *(int *)(extraout_ECX + 0x128);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 8))();
  piVar2 = *(int **)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  while( true ) {
    *(int **)(unaff_EBP + -0x14) = piVar2;
    if (piVar2 == *(int **)(unaff_EBP + -0x1c)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if (*piVar2 != 0) break;
    piVar2 = piVar2 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0057fa52();
  FUN_0057cf7d();
  return;
}

