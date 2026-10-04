
void FUN_0042bce6(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  LPCSTR pCVar8;
  DWORD DVar9;
  uint dwFileAttributes;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar10;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005b870f(s__family_006c28b4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b870f(&DAT_006c28ac);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046f824(unaff_EBP + -0x218,0,0x104);
  *(undefined ***)(unaff_EBP + -0x224) = &PTR_FUN_006664e8;
  FUN_00412122(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x224);
  uVar10 = 0xffffffff;
  uVar4 = FUN_0041532c(0x59,0xffffffff);
  FUN_0046f847(uVar4,uVar10);
  FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x220));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d8277(unaff_EBP + -0x48,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  uVar4 = FUN_005d4956(s___FAM_006c28a4);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d8ab4(uVar4,1);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x114) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar4 = FUN_0041532c(9,unaff_EBP + -0x114,0);
  FUN_004fff98(0x10e,uVar4);
  pvVar5 = operator_new(0x13c);
  *(void **)(unaff_EBP + -0x10) = pvVar5;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (pvVar5 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_00525cfd();
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (piVar6 != (int *)0x0) {
    uVar4 = FUN_004705f2(1,0xffffffff);
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_00525fb7(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    uVar4 = FUN_004705f2(2,0xffffffff);
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005260e7(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_005a5631(0x13ce,unaff_EBP + -0x10,4);
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      FUN_005260b1(*(undefined4 *)(unaff_EBP + -0x10),1);
    }
    piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar7 = (int *)(**(code **)(*piVar7 + 8))();
    (**(code **)(*piVar6 + 0x138))();
    FUN_005ddfdc(1);
    (**(code **)(*piVar7 + 0x94))();
    (**(code **)(*piVar7 + 0x20))(piVar6);
    (**(code **)(*piVar7 + 0x168))();
    (**(code **)(*piVar6 + 0x94))();
    (**(code **)(*piVar6 + 0x168))();
    (**(code **)(*piVar6 + 0x44))();
    FUN_00526e66(7);
    (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
    (**(code **)(*DAT_006fe8bc + 0x3c))();
  }
  FUN_0042eeac(unaff_EBP + -0x15,unaff_EBP + -0x16);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  cVar3 = FUN_0042bc75(unaff_EBP + -0xa8,unaff_EBP + -0x3c,unaff_EBP + -0x30);
  while (cVar3 != '\0') {
    (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
    Sleep(0x1e);
    uVar4 = FUN_004096c2();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
    FUN_0046f824(unaff_EBP + -0x328,0,0x104);
    *(undefined ***)(unaff_EBP + -0x334) = &PTR_FUN_006664e8;
    FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
    pCVar8 = (LPCSTR)FUN_004096c2();
    DVar9 = GetFileAttributesA(pCVar8);
    dwFileAttributes = DVar9 & 0xfffffffe;
    pCVar8 = (LPCSTR)FUN_004096c2();
    SetFileAttributesA(pCVar8,dwFileAttributes);
    FUN_004e2e34();
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    cVar3 = FUN_004e2b6b(unaff_EBP + -0x334,unaff_EBP + -0x4d4,0);
    if (cVar3 != '\0') {
      piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
      piVar7 = (int *)(**(code **)(*piVar7 + 0x58))(0);
      iVar2 = DAT_006e486c;
      iVar1 = *piVar7;
      *(int **)(unaff_EBP + -0x10) = piVar7;
      (**(code **)(iVar1 + 0x78))((int)*(char *)(iVar2 + 100));
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x78))((int)*(char *)(unaff_EBP + -0x344));
      FUN_004e2d6b(unaff_EBP + -0x4d4,unaff_EBP + -0x4c);
    }
    FUN_005d82fa();
    if (piVar6 != (int *)0x0) {
      FUN_00526e73();
      (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
      (**(code **)(*DAT_006fe8bc + 0x18))();
      FUN_005da67b();
      Sleep(0x1e);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_004e2e81();
    cVar3 = FUN_0042bc75(unaff_EBP + -0xa8,unaff_EBP + -0x3c,unaff_EBP + -0x30);
  }
  if (piVar6 != (int *)0x0) {
    FUN_005da4c7(piVar6);
  }
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0042ecc0();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042a889();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

