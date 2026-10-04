
undefined4 * FUN_00544cc2(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  extraout_ECX[0x35] = 0xffffffff;
  *extraout_ECX = &PTR_FUN_0066f920;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  iVar1 = DAT_006f4f84;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (iVar1 == DAT_006f4f80) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar3 = FUN_0041532c(9,unaff_EBP + -0x7c,0);
    cVar2 = FUN_004fff98(0x80,uVar3);
    if (cVar2 == '\0') {
      pcVar4 = s_Personality_for__s_006cd644;
    }
    else {
      pcVar4 = (char *)FUN_004705f2(0xd,0xffffffff);
    }
    FUN_005d4bbf(pcVar4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00470467();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

