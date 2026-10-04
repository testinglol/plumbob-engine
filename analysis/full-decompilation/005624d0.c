
undefined4 FUN_005624d0(void)

{
  int iVar1;
  char cVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_00429c21();
  iVar1 = *(int *)(extraout_ECX + 0xd4);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar1 == 1) {
    cVar2 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x160),unaff_EBP + -0x2c);
    if (cVar2 != '\0') {
      FUN_005b86bd(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      goto LAB_0056252c;
    }
  }
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
LAB_0056252c:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

