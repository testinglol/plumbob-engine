
void FUN_0059e120(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_005a0377();
  if (*(undefined4 **)(extraout_ECX + 0x40) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0x40))(1);
  }
  DAT_006f7670 = 0;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 0x28;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005a32ce();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005481b6();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 0x14;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005a2f1d();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005481b6();
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_005a2b6c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

