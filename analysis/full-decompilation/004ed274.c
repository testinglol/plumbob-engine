
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004ed274(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(extraout_ECX + 9,0,0x104);
  extraout_ECX[6] = &PTR_FUN_006664e8;
  FUN_0046f824(extraout_ECX + 0x4d,0,0x104);
  extraout_ECX[0x4a] = &PTR_FUN_006664e8;
  FUN_0046f824(extraout_ECX + 0x91,0,0x104);
  extraout_ECX[0x8e] = &PTR_FUN_006664e8;
  if (DAT_006f26b4 == _DAT_006f26b0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x18c) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar2 = FUN_0041532c(9,unaff_EBP + -0x18c,0);
    cVar1 = FUN_004fff98(0x9a,uVar2);
    if (cVar1 == '\0') {
      pcVar3 = s_No_Description_006c9f20;
    }
    else {
      pcVar3 = (char *)FUN_004705f2(4,0xffffffff);
    }
    FUN_005d4bbf(pcVar3);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00470467();
  }
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0xffffffff;
  FUN_005d499c(&DAT_006f26b0);
  FUN_0046f824(unaff_EBP + -0x114,0,0x104);
  *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
  FUN_0046f847(s_NoFilename_jpg_006c9f10,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x120);
  FUN_0046f824(unaff_EBP + -0x114,0,0x104);
  *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
  FUN_0046f847(s_NoFilename_jpg_006c9f10,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x120);
  FUN_0046f824(unaff_EBP + -0x114,0,0x104);
  *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
  FUN_0046f847(s_NoFilename_txt_006c9f00,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x120);
  extraout_ECX[0xd2] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

