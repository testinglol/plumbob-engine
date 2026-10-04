
void FUN_00492d46(void)

{
  int *piVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) == 0) {
    FUN_004d2900(0);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
    piVar1 = DAT_006fe8bc;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(*piVar1 + 0x18))();
    FUN_005d9928(unaff_EBP + -0x14,unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -5;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x11;
    FUN_004d28b2(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10),
                 unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

