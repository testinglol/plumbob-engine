
undefined4 FUN_0042c91c(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_ec [8];
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined *puStack_dc;
  int iStack_d8;
  char *pcStack_d4;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  if ((0x11 < *(int *)(unaff_EBP + 8)) || (*(int *)(unaff_EBP + 8) < 0)) {
    uVar4 = 0;
    goto LAB_0042cae9;
  }
  pcStack_d4 = (char *)0x3e8;
  iStack_d8 = 0x42c959;
  uVar3 = FUN_005bc722();
  pcStack_d4 = &DAT_006de560;
  *(uint *)(unaff_EBP + 8) = (uint)(*(int *)(unaff_EBP + 8) < 7);
  *(uint *)(unaff_EBP + -0x10) = uVar3 % 3;
  iStack_d8 = 0x42c97c;
  FUN_0040bfed();
  pcStack_d4 = (char *)0x42c984;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pcStack_d4 = (char *)0x42c992;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xd0) = &PTR_FUN_0066643c;
  iVar1 = *(int *)(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar1 == 0) {
    pcStack_d4 = &DAT_006c1010;
    iStack_d8 = 0x42c9de;
    FUN_0040bfed();
    pcStack_d4 = (char *)(unaff_EBP + -0x54);
LAB_0042c9e1:
    iStack_d8 = 0x42c9ea;
    FUN_0046f8e4();
  }
  else {
    if (iVar1 == 1) {
      pcStack_d4 = &DAT_006c100c;
      iStack_d8 = 0x42c9cc;
      FUN_0040bfed();
      pcStack_d4 = (char *)(unaff_EBP + -0x44);
      goto LAB_0042c9e1;
    }
    if (iVar1 == 2) {
      pcStack_d4 = &DAT_006c1008;
      iStack_d8 = 0x42c9ba;
      FUN_0040bfed();
      pcStack_d4 = (char *)(unaff_EBP + -100);
      goto LAB_0042c9e1;
    }
  }
  if (*(int *)(unaff_EBP + 8) == 0) {
    pcStack_d4 = s_Nomad_006c28bc;
    iStack_d8 = 0x42ca29;
    FUN_005d4bbf();
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    uStack_e0 = 0xa7;
LAB_0042ca3e:
    iStack_d8 = unaff_EBP + -0xd0;
    pcStack_d4 = (char *)0x0;
    puStack_dc = &DAT_006c265c;
    uStack_e4 = 0x42ca43;
    FUN_004fff98();
  }
  else if (*(int *)(unaff_EBP + 8) == 1) {
    pcStack_d4 = &DAT_006c28c4;
    iStack_d8 = 0x42ca01;
    FUN_005d4bbf();
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    uStack_e0 = 0xa8;
    goto LAB_0042ca3e;
  }
  *(undefined4 *)(unaff_EBP + 8) = 0;
  do {
    pcStack_d4 = (char *)0x3e8;
    iStack_d8 = 0x42ca51;
    uVar4 = FUN_005bc722();
    pcStack_d4 = (char *)0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
    iStack_d8 = 0x42ca61;
    uVar3 = FUN_0046fbe5();
    pcStack_d4 = (char *)0xffffffff;
    iStack_d8 = *(uint *)(unaff_EBP + -0x24) % uVar3 + 1;
    puStack_dc = (undefined *)0x42ca79;
    pcStack_d4 = (char *)FUN_004705f2();
    iStack_d8 = 0x42ca82;
    FUN_005d4bbf();
    iStack_d8 = unaff_EBP + -0x20;
    pcStack_d4 = (char *)0x157c;
    puStack_dc = (undefined *)0x42ca93;
    cVar2 = FUN_0042da84();
    if (cVar2 == '\x01') break;
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
  } while (*(int *)(unaff_EBP + 8) < 0x12);
  pcStack_d4 = (char *)0x0;
  iStack_d8 = 0;
  puStack_dc = (undefined *)0x0;
  *(undefined1 **)(unaff_EBP + 8) = auStack_ec;
  FUN_0042c904(unaff_EBP + -0x34);
  uVar4 = FUN_0042ccd8(*(undefined4 *)(unaff_EBP + 0xc),0,*(undefined4 *)(unaff_EBP + -0x10),
                       unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  pcStack_d4 = (char *)0x42cad7;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pcStack_d4 = (char *)0x42cae3;
  FUN_005b8770();
LAB_0042cae9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

