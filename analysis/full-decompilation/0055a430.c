
undefined1 FUN_0055a430(void)

{
  char cVar1;
  char *_Str;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004f2baf(unaff_EBP + -0x5c);
  _Str = (char *)FUN_0041532c(0x58);
  sVar2 = _strlen(_Str);
  FUN_00412d8a(_Str,_Str + sVar2);
  FUN_005d8277(unaff_EBP + -0x5c,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar3 = FUN_005d4956(s___rdt_006cdfe4);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d8ab4(uVar3,1);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  FUN_0054dee4();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  cVar1 = FUN_00559739(unaff_EBP + -0x16c,unaff_EBP + -0x8c,unaff_EBP + -0x50);
  while (cVar1 != '\0') {
    uVar3 = FUN_004096c2();
    FUN_0046f824(unaff_EBP + -0x48c,0,0x104);
    *(undefined ***)(unaff_EBP + -0x498) = &PTR_FUN_006664e8;
    FUN_0046f847(uVar3,0xffffffff);
    FUN_00418fea();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x244) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 9;
    iVar4 = FUN_004190d3(unaff_EBP + -0x498,0);
    if (iVar4 == 0) {
      iVar4 = FUN_00470383(unaff_EBP + -0xfc,2000,1);
      if (iVar4 == 0) {
        uVar3 = FUN_004705f2(1,0xffffffff);
        FUN_005d4bbf(uVar3);
        uVar3 = FUN_004705f2(2,0xffffffff);
        FUN_005d4bbf(uVar3);
        uVar3 = FUN_004705f2(3,0xffffffff);
        FUN_005d4bbf(uVar3);
      }
      FUN_004195ba();
    }
    uVar3 = FUN_004096c2();
    uVar3 = FUN_00635f62(uVar3);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    pvVar5 = operator_new(0x148);
    *(void **)(unaff_EBP + -0x1c) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (pvVar5 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00523434();
    }
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005d499c(unaff_EBP + -0x44);
    FUN_00523be3(unaff_EBP + -0x28);
    FUN_005d499c(unaff_EBP + -0x68);
    FUN_00523be3(unaff_EBP + -0x28);
    uVar3 = FUN_004705f2(7,0xffffffff);
    FUN_005d4bbf(uVar3);
    FUN_0052386b(unaff_EBP + -0x28,1);
    FUN_00523afc(1,0xd);
    uVar3 = FUN_004705f2(8,0xffffffff);
    FUN_005d4bbf(uVar3);
    FUN_0052386b(unaff_EBP + -0x28,0);
    FUN_00523afc(0,0x1b);
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x388) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar3 = FUN_0041532c(9,unaff_EBP + -0x388,0);
    cVar1 = FUN_004fff98(0x90,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_004705f2(5,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      FUN_0052386b(unaff_EBP + -0x74,2);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_00470467();
    (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
              (unaff_EBP + -0x34,unaff_EBP + -0x30,unaff_EBP + -0x38);
    uVar3 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),
                         *(undefined4 *)(unaff_EBP + -0x38));
    *(undefined4 *)(iVar4 + 100) = uVar3;
    FUN_00418fea();
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_004190d3(unaff_EBP + -0x498,0);
    FUN_005a55f6(unaff_EBP + -0xd0,0x200,unaff_EBP + -0x2c,4);
    FUN_004195ba();
    if (*(int **)(unaff_EBP + -0x2c) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x2c) + 0x68))(DAT_006f2a64);
      FUN_00523b25(*(undefined4 *)(unaff_EBP + -0x2c),0);
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x31c) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    uVar3 = FUN_0041532c(9,unaff_EBP + -0x31c,0);
    cVar1 = FUN_004fff98(0xac,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar3);
    }
    FUN_00523771(unaff_EBP + -0x28);
    (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x18));
    piVar6 = (int *)FUN_005e7f2f(unaff_EBP + -0x18);
    FUN_00523724(2,*piVar6 + 0xc);
    uVar3 = FUN_004f6c41(iVar4,1,0);
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
    FUN_005da4c7(iVar4);
    (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x19c))(0);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_00470467();
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_0041905d();
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005b8770();
    if (*(int *)(unaff_EBP + -0x1c) == 1) {
      *(undefined1 *)(unaff_EBP + -0xd) = 1;
      FUN_00418fea();
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_0046f824(unaff_EBP + -0x59c,0,0x104);
      *(undefined ***)(unaff_EBP + -0x5a8) = &PTR_FUN_006664e8;
      FUN_00425691(*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x5a8);
      FUN_0041c785(unaff_EBP + -0x5a8);
      uVar3 = *(undefined4 *)(unaff_EBP + -0x5a4);
      uVar7 = *(undefined4 *)(unaff_EBP + -0x494);
      FUN_005b8e25(uVar7,uVar3);
      FUN_005b9976(uVar7,uVar3);
      FUN_0041c785(unaff_EBP + -0x498);
      FUN_0046f824(unaff_EBP + -0x6ac,0,0x104);
      *(undefined ***)(unaff_EBP + -0x6b8) = &PTR_FUN_006664e8;
      FUN_00425531(unaff_EBP + -0x6b8);
      FUN_0046f847(s_Houses_NeighborhoodDesc_iff_006c268c,0xffffffff);
      FUN_0046f5cd();
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      iVar4 = FUN_0046f71c(unaff_EBP + -0x6b8,1);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x1d8) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      if (iVar4 == 0) {
        iVar4 = FUN_00470383(unaff_EBP + -0x8fc,*(int *)(unaff_EBP + -0x18) + 2000,1);
        if (iVar4 == 0) {
          uVar7 = 0xffffffff;
          uVar3 = FUN_004096c2(0xffffffff);
          FUN_004704a5(1,uVar3,uVar7);
          uVar7 = 0xffffffff;
          uVar3 = FUN_004096c2(0xffffffff);
          FUN_004704a5(2,uVar3,uVar7);
          FUN_0046fd72();
        }
        FUN_0046b7ee();
      }
      FUN_0042ba55(*(undefined4 *)(unaff_EBP + -0x18),1);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_0046b2e6();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_0041905d();
    }
    else if (*(int *)(unaff_EBP + -0x1c) == 2) {
      FUN_005d4956(s_Confirm_File_Delete_006cda9c);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_005d4956(s_Are_you_sure_you_want_to_delete_t_006cda70);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x2b0) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      uVar3 = FUN_0041532c(9,unaff_EBP + -0x2b0,0);
      cVar1 = FUN_004fff98(0x9a,uVar3);
      if (cVar1 != '\0') {
        uVar3 = FUN_004705f2(0x12,0xffffffff);
        FUN_005d4bbf(uVar3);
        uVar3 = FUN_004705f2(0x13,0xffffffff);
        FUN_005d4bbf(uVar3);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_00470467();
      iVar4 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                        (unaff_EBP + -0x98,unaff_EBP + -0xa4,2,0);
      if (iVar4 == 4) {
        uVar3 = *(undefined4 *)(unaff_EBP + -0x494);
        FUN_005b8e25(uVar3);
        FUN_005b9796(uVar3);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b8770();
    }
    FUN_005d82fa();
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_00470467();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0041905d();
    cVar1 = FUN_00559739(unaff_EBP + -0x16c,unaff_EBP + -0x8c,unaff_EBP + -0x50);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042ecc0();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042a889();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

