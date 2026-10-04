
void FUN_004588f5(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  if (((DAT_006e50e0 != 0) && (DAT_006e50ac != 0)) && (DAT_006e50a8 != 0)) {
    FUN_0041ed89(DAT_006e50a8);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffff7;
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 8;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xffffffef;
    FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 8));
    puVar2 = *(undefined2 **)(unaff_EBP + 0xc);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffb;
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 4;
    *(undefined2 *)(unaff_EBP + -0x3c) = *puVar2;
    *(undefined2 *)(unaff_EBP + -0x3a) = puVar2[1];
    uVar1 = puVar2[3];
    *(undefined2 *)(unaff_EBP + -0x38) = puVar2[2];
    *(undefined2 *)(unaff_EBP + -0x36) = uVar1;
    FUN_00458cd7(unaff_EBP + -0x50);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

