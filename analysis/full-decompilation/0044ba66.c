
undefined1 FUN_0044ba66(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  char cVar5;
  short sVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  char *pcVar8;
  undefined4 uVar9;
  int extraout_ECX;
  uint uVar10;
  int iVar11;
  int unaff_EBP;
  int iVar12;
  undefined1 uVar13;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  iVar11 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (iVar11 == 1) {
    uVar13 = *(char *)(extraout_ECX + 0x20) != '\0';
    goto LAB_0044bcaf;
  }
  puVar3 = *(undefined2 **)(unaff_EBP + 0xc);
  if ((*(byte *)(puVar3 + 1) & 1) == 0) {
    uVar7 = FUN_004754d8();
    sVar6 = FUN_004021ff(uVar7);
    if (sVar6 == 2) {
      uVar7 = FUN_00401f6f();
      goto LAB_0044baa5;
    }
    *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(iVar2 + 0xc);
    uVar7 = FUN_004021d9(3);
    uVar7 = (*(code *)**(undefined4 **)(unaff_EBP + 8))(uVar7);
    iVar11 = *(int *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + 8) = uVar7;
  }
  else {
    uVar7 = FUN_00401f73();
LAB_0044baa5:
    *(undefined4 *)(unaff_EBP + 8) = uVar7;
    iVar11 = extraout_ECX;
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xcc) = &PTR_FUN_0066643c;
  uVar1 = *puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(*(undefined4 *)(unaff_EBP + 8),CONCAT22(extraout_var,uVar1),0);
  pcVar8 = (char *)FUN_004705f2(*(undefined1 *)(puVar3 + 2),0xffffffff);
  *(char **)(unaff_EBP + -0x14) = pcVar8;
  if ((pcVar8 == (char *)0x0) || (*pcVar8 == '\0')) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    uVar13 = 0;
    goto LAB_0044bcaf;
  }
  cVar5 = *(char *)((int)puVar3 + 5);
  if (cVar5 == '\0') {
    uVar10 = (uint)*(short *)(iVar2 + 4);
    iVar4 = *(int *)(iVar11 + 0xdc);
    iVar12 = 0;
    *(int *)(unaff_EBP + 0xc) = iVar11;
    if ((0 < (int)uVar10) && (uVar10 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U))
    {
      iVar12 = *(int *)(*(int *)(iVar4 + 0x18) + -4 + uVar10 * 4);
    }
LAB_0044bbdd:
    *(undefined1 *)(unaff_EBP + 0xb) = 1;
  }
  else {
    if (cVar5 == '\x01') {
      uVar10 = (uint)*(short *)(iVar2 + 4);
      iVar11 = *(int *)(iVar11 + 0xdc);
      iVar12 = 0;
      if ((0 < (int)uVar10) &&
         (uVar10 < (*(int *)(iVar11 + 0x1c) - *(int *)(iVar11 + 0x18) >> 2) + 1U)) {
        iVar12 = *(int *)(*(int *)(iVar11 + 0x18) + -4 + uVar10 * 4);
      }
      *(int *)(unaff_EBP + 0xc) = iVar12;
      goto LAB_0044bbdd;
    }
    if (cVar5 != '\x02') {
      *(undefined4 *)(unaff_EBP + 8) = 0x2c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
    }
    uVar10 = (uint)*(short *)(iVar2 + 4);
    iVar4 = *(int *)(iVar11 + 0xdc);
    iVar12 = 0;
    *(int *)(unaff_EBP + 0xc) = iVar11;
    if ((0 < (int)uVar10) && (uVar10 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U))
    {
      iVar12 = *(int *)(*(int *)(iVar4 + 0x18) + -4 + uVar10 * 4);
    }
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
  }
  if ((*(int *)(unaff_EBP + 0xc) == 0) || (iVar12 == 0)) {
    *(undefined4 *)(unaff_EBP + 8) = 0x15;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  uVar7 = *(undefined4 *)(*(int *)(iVar12 + 0x11c) + 0xc);
  FUN_0046f824(unaff_EBP + -0x54,0,0x40);
  *(undefined ***)(unaff_EBP + -0x60) = &PTR_FUN_0066651c;
  FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
  uVar9 = FUN_00402246(unaff_EBP + -0x60);
  if ((short)uVar9 == 0) {
LAB_0044bc32:
    uVar13 = 0;
  }
  else if (*(char *)(unaff_EBP + 0xb) == '\0') {
    if ((*(int **)(unaff_EBP + 0xc) != *(int **)(unaff_EBP + -0x10)) ||
       (cVar5 = (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x34))(iVar12,0,uVar9,0), cVar5 == '\0'))
    goto LAB_0044bc32;
    *(undefined4 *)(iVar2 + 8) = 1;
    uVar13 = 3;
  }
  else {
    cVar5 = FUN_00474b22(uVar7,CONCAT22((short)((uint)iVar12 >> 0x10),*(undefined2 *)(iVar12 + 0xf0)
                                       ),uVar9,0);
    if (cVar5 == '\0') goto LAB_0044bc32;
    uVar13 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_0044bcaf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar13;
}

