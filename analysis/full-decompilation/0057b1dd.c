
void FUN_0057b1dd(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00671754;
  puVar1 = (undefined4 *)extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    iVar2 = puVar3[2];
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 != 0) {
      FUN_005b8770();
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0057bddc();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006029b3();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *extraout_ECX = &PTR_FUN_006698c8;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

