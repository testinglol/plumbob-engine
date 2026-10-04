
undefined4 * FUN_00421b2e(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004227e6(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),
               *(undefined4 *)(unaff_EBP + 0x14));
  iVar1 = *(int *)(unaff_EBP + 0xc);
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x6b] = iVar1;
  *extraout_ECX = &PTR_FUN_00666b8c;
  *(undefined2 *)((int)extraout_ECX + 0x1b2) = 0;
  *(undefined2 *)(extraout_ECX + 0x6c) = 0;
  extraout_ECX[0x6e] = 0xfffffff0;
  extraout_ECX[0x6d] = 0xfffffff0;
  iVar1 = extraout_ECX[0x6b];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x6f] = 1;
  extraout_ECX[0x70] = 0xbf800000;
  if (iVar1 != 0) {
    FUN_0043270d(iVar1);
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      *(undefined2 *)(extraout_ECX + 0x72) = *(undefined2 *)(*(int *)(unaff_EBP + -0x1c) + 0xf0);
      *(undefined2 *)((int)extraout_ECX + 0x1ca) = *(undefined2 *)(unaff_EBP + -0x18);
      goto LAB_00421be2;
    }
  }
  *(undefined2 *)(extraout_ECX + 0x72) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x1ca) = 0;
LAB_00421be2:
  *(undefined2 *)(extraout_ECX + 0x71) = *(undefined2 *)(extraout_ECX + 0x72);
  *(undefined2 *)((int)extraout_ECX + 0x1c6) = *(undefined2 *)((int)extraout_ECX + 0x1ca);
  FUN_004223c0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

