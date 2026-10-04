
void FUN_005d8aed(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = *(int *)(extraout_ECX + 0x2c) - *(int *)(extraout_ECX + 0x28);
  if (((iVar2 != 0) &&
      (cVar1 = *(char *)(iVar2 + -1 + *(int *)(extraout_ECX + 0x28)), cVar1 != '\\')) &&
     (cVar1 != '/')) {
    FUN_005b8755(0x5c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

