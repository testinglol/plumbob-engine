
undefined4 * FUN_00461d22(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int extraout_ECX;
  undefined1 uVar8;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  uVar1 = *(undefined4 *)(extraout_ECX + 0xc);
  puVar3 = operator_new(0x28);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004620e1(uVar1);
    puVar3[9] = 0;
    *puVar3 = &PTR_FUN_00667438;
    FUN_00461b8d();
  }
  if (puVar3 != (undefined4 *)0x0) {
    *(undefined1 *)(unaff_EBP + -0x12) = 0;
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    *(undefined1 *)(unaff_EBP + -0xf) = 0;
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    *(undefined1 *)(unaff_EBP + -0x22) = 0;
    *(undefined1 *)(unaff_EBP + -0x1f) = 0;
    uVar8 = (undefined1)uVar1;
    *(undefined1 *)(unaff_EBP + -0x14) = uVar8;
    *(undefined1 *)(unaff_EBP + -0x13) = uVar8;
    FUN_00461b74(unaff_EBP + -0x10);
    FUN_00461b74(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined1 *)(unaff_EBP + -0x26) = 0;
    FUN_004619d2(unaff_EBP + -0x34);
    puVar4 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar4;
    FUN_00461b74(puVar4 + 1);
    iVar9 = extraout_ECX;
    while( true ) {
      iVar5 = FUN_004619d2(unaff_EBP + -0x3c);
      cVar2 = FUN_0046198c(iVar5 + 4);
      if (cVar2 != '\0') break;
      pcVar6 = (char *)FUN_00461941(unaff_EBP + -0x14);
      pcVar7 = (char *)FUN_00461941(unaff_EBP + -0x10);
      *(undefined1 *)(*(int *)(puVar3[4] + *pcVar7 * 4) + (int)pcVar7[1]) =
           *(undefined1 *)(*(int *)(*(int *)(iVar9 + 0x10) + *pcVar6 * 4) + (int)pcVar6[1]);
      FUN_00461961();
      iVar9 = *(int *)(unaff_EBP + -0x1c);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}

