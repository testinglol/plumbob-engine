
undefined4 FUN_005a020f(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = FUN_005a1f21(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005a242b(unaff_EBP + -0x14,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0059ee43();
  iVar1 = *(int *)(unaff_EBP + -0x14);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x30) == '\0') {
      FUN_005a3698();
    }
    uVar2 = *(undefined4 *)(iVar1 + 0x34);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

