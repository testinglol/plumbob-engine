
void FUN_005103e6(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00510339(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    cVar1 = *(char *)(unaff_EBP + -0x10);
  }
  else {
    uVar2 = FUN_005102c9(1,*(undefined4 *)(unaff_EBP + 0xc),0,0,0,0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00510339(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    cVar1 = *(char *)(unaff_EBP + -0x38);
  }
  if (cVar1 != '\0') {
    FUN_005e3581();
  }
  if (*(int *)(extraout_ECX + 0x7c) != 0) {
    FUN_0050fcbb();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

