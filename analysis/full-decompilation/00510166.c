
undefined4 * FUN_00510166(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f824(extraout_ECX + 9,0,8);
  extraout_ECX[6] = &PTR_FUN_00666644;
  FUN_00635e55(extraout_ECX + 0xb,0x28,2,&LAB_005102b3,FUN_005103a2);
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_0066be28;
  extraout_ECX[0x1f] = 0;
  FUN_00510747(uVar3);
  FUN_00510775(*(undefined4 *)(unaff_EBP + 0xc));
  iVar2 = *(int *)(unaff_EBP + 0x14);
  extraout_ECX[5] = *(undefined4 *)(unaff_EBP + 0x10);
  if (iVar2 == 0) {
    if (*(int *)(unaff_EBP + 0x24) != 0) {
      uVar3 = FUN_005102c9(2,*(undefined4 *)(unaff_EBP + 0x24),0,0,0,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00510339(uVar3);
      cVar1 = *(char *)(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto joined_r0x0051022a;
    }
  }
  else {
    uVar3 = FUN_005102c9(1,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),0,0,0
                        );
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00510339(uVar3);
    cVar1 = *(char *)(unaff_EBP + -0x14);
    *(undefined1 *)(unaff_EBP + -4) = 0;
joined_r0x0051022a:
    if (cVar1 != '\0') {
      FUN_005e3581();
    }
  }
  if (*(int *)(unaff_EBP + 0x1c) == 0) {
    if (*(int *)(unaff_EBP + 0x24) == 0) goto LAB_00510299;
    uVar3 = FUN_005102c9(2,*(undefined4 *)(unaff_EBP + 0x28),0,0,0,0);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_00510339(uVar3);
    cVar1 = *(char *)(unaff_EBP + -0x14);
    *(undefined1 *)(unaff_EBP + -4) = 0;
  }
  else {
    uVar3 = FUN_005102c9(1,*(undefined4 *)(unaff_EBP + 0x1c),*(undefined4 *)(unaff_EBP + 0x20),0,0,0
                        );
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00510339(uVar3);
    cVar1 = *(char *)(unaff_EBP + -0x14);
    *(undefined1 *)(unaff_EBP + -4) = 0;
  }
  if (cVar1 != '\0') {
    FUN_005e3581();
  }
LAB_00510299:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x20) = 1;
  return extraout_ECX;
}

