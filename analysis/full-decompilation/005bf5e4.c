
char FUN_005bf5e4(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x60))();
  uVar2 = FUN_005bdd58(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = FUN_005bf892(uVar2,extraout_ECX + 4,*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
  FUN_00401729();
  if (cVar1 == '\0') {
    FUN_005bfa81();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar1;
}

