
bool FUN_005a3e90(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  bVar3 = false;
  FUN_005a42e3(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = FUN_005a4387(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  if (cVar1 != '\0') {
    uVar2 = FUN_00401742(0x14);
    *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
    *(undefined4 *)uVar2 = uVar2;
    *(int *)(*(int *)(unaff_EBP + 0xc) + 4) = *(int *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    cVar1 = FUN_005a4449(unaff_EBP + 0xc);
    bVar3 = cVar1 != '\0';
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042ed0e();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a433d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

