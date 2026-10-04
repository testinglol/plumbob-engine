
void FUN_00596429(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c35b0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005963ab(unaff_EBP + -0x50);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *puVar1 = *(undefined4 *)(unaff_EBP + -0x20);
  puVar1[1] = uVar2;
  puVar1[2] = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

