
void FUN_005a026f(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = FUN_005a2263(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005a242b(unaff_EBP + -0x14,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0059eecd();
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x30) == '\0') {
      FUN_005a385a();
    }
    if (*(int *)(iVar1 + 0x34) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x78) = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

