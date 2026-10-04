
undefined1 FUN_004e2fc2(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x278,0,0x104);
  *(undefined ***)(unaff_EBP + -0x284) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x388,0,0x104);
  *(undefined ***)(unaff_EBP + -0x394) = &PTR_FUN_006664e8;
  uVar3 = FUN_0041532c(0x55,0,unaff_EBP + -0x284);
  FUN_004eea6b(uVar3);
  uVar3 = FUN_0041532c(0x56,unaff_EBP + -0x394);
  uVar3 = FUN_0041532c(7,uVar3);
  FUN_004ee9ce(uVar3);
  FUN_00560763(unaff_EBP + -0x284);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(DAT_006e486c + 0x24);
  iVar4 = FUN_00425db3(*(undefined4 *)(unaff_EBP + 8));
  iVar5 = *(int *)(iVar4 + 0x10c);
  if ((((iVar5 == 2000) || (iVar5 == 4000)) || (iVar5 == 5000)) ||
     ((((iVar5 == 0x157c || (iVar5 == 6000)) || ((2999 < iVar5 && (iVar5 < 0xbc2)))) ||
      (*(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(DAT_006f2a08 + 0xb0), iVar4 == 0)))) {
    uVar1 = 0;
    goto LAB_004e324b;
  }
  iVar5 = *(int *)(iVar4 + 0x110);
  iVar4 = FUN_00428886();
  if (iVar5 == 0) {
    if (iVar4 != 0) {
      FUN_0042888d();
    }
    iVar5 = FUN_00425db3(*(undefined4 *)(unaff_EBP + 8));
    uVar1 = FUN_004ddfcd(unaff_EBP + -0x394,unaff_EBP + -0x284,iVar5);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
  }
  else {
    if (iVar5 == iVar4) {
LAB_004e313b:
      *(undefined1 *)(unaff_EBP + -0xd) = 1;
    }
    else {
      iVar5 = FUN_0042808b(iVar5,0xffffffff);
      if (iVar5 == 0) goto LAB_004e313b;
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
    }
    iVar5 = FUN_00425db3(*(undefined4 *)(unaff_EBP + 8));
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      cVar2 = FUN_004dcc78(unaff_EBP + -0x394,unaff_EBP + -0x284,iVar5,
                           *(undefined4 *)(unaff_EBP + -0x18));
      if (cVar2 != '\0') {
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
        goto LAB_004e317a;
      }
    }
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
LAB_004e317a:
  *(uint *)(iVar5 + 0x138) = *(uint *)(iVar5 + 0x138) | 0x18;
  FUN_0046f824(unaff_EBP + -0x498,0,0x104);
  *(undefined ***)(unaff_EBP + -0x4a4) = &PTR_FUN_006664e8;
  FUN_0046f8e4(*(undefined4 *)(unaff_EBP + -0x14));
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar5 = FUN_0046f71c(unaff_EBP + -0x4a4,1);
  if (iVar5 == 0) {
    FUN_004100cf(0,0xffffffff);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    cVar2 = FUN_00410398(unaff_EBP + -0x6e8,*(undefined4 *)(unaff_EBP + 8));
    if (cVar2 != '\0') {
      *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xffffffef;
      *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) | 0x10;
      iVar5 = DAT_006e486c;
      *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffff7;
      *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) | 8;
      FUN_00410729(unaff_EBP + -0x6e8,*(undefined4 *)(iVar5 + 0x44));
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00410173();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  uVar1 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_004e324b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

