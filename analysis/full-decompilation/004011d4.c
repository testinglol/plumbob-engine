
void FUN_004011d4(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  uVar2 = 0;
  while( true ) {
    iVar1 = FUN_004015a1(uVar2);
    if (iVar1 == 0) break;
    iVar1 = FUN_004015a1(*(undefined4 *)(extraout_ECX + 0xc));
    if (iVar1 != 0) {
      FUN_0040123a(1);
    }
    if (*(int *)(extraout_ECX + 0xc) <= *(int *)(extraout_ECX + 8)) {
      *(int *)(extraout_ECX + 0xc) = *(int *)(extraout_ECX + 0xc) + 1;
    }
    uVar2 = *(undefined4 *)(extraout_ECX + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401634();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

