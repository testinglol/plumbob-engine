
void FUN_0055c517(void)

{
  int *piVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  char *pcVar7;
  size_t sVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar6 = *(char *)(extraout_ECX + 0x1d4);
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ((cVar6 == '\0') && (*(char *)(extraout_ECX + 0x121) != '\0')) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x18);
    pcVar7 = (char *)FUN_0041532c(0x58);
    sVar8 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar8);
    sVar8 = _strlen(s___FAM_006c28a4);
    FUN_00412d8a(s___FAM_006c28a4,s___FAM_006c28a4 + sVar8);
    bVar3 = FUN_005d8a11(unaff_EBP + -0x18);
    FUN_004f2baf(unaff_EBP + -0x18);
    pcVar7 = (char *)FUN_0041532c(0x58);
    sVar8 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar8);
    sVar8 = _strlen(s___rdt_006cdfe4);
    FUN_00412d8a(s___rdt_006cdfe4,s___rdt_006cdfe4 + sVar8);
    bVar4 = FUN_005d8a11(unaff_EBP + -0x18);
    FUN_004f2baf(unaff_EBP + -0x18);
    pcVar7 = (char *)FUN_0041532c(0x58);
    sVar8 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar8);
    sVar8 = _strlen(s___cmt_006cdfec);
    FUN_00412d8a(s___cmt_006cdfec,s___cmt_006cdfec + sVar8);
    bVar5 = FUN_005d8a11(unaff_EBP + -0x18);
    bVar5 = bVar3 | bVar4 | bVar5;
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x1c) + 0x170);
    if (*(byte *)(piVar1 + 0x5a) != bVar5) {
      *(byte *)(piVar1 + 0x5a) = bVar5;
      (**(code **)(*piVar1 + 0x168))();
    }
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004f2baf(unaff_EBP + -0x28);
    pcVar7 = (char *)FUN_0041532c(0x58);
    sVar8 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar8);
    sVar8 = _strlen(s_Tutorial_FAM_006cac44);
    FUN_00412d8a(s_Tutorial_FAM_006cac44,s_Tutorial_FAM_006cac44 + sVar8);
    cVar6 = FUN_005ed4a5(unaff_EBP + -0x28);
    if (cVar6 != '\0') {
      bVar2 = false;
      uVar9 = FUN_004096c2();
      FUN_0046f824(unaff_EBP + -0x2d0,0,0x104);
      *(undefined ***)(unaff_EBP + -0x2dc) = &PTR_FUN_006664e8;
      FUN_0046f847(uVar9,0xffffffff);
      FUN_004e2e34();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      cVar6 = FUN_004e2b6b(unaff_EBP + -0x2dc,unaff_EBP + -0x1cc,0);
      if (cVar6 != '\0') {
        uVar9 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + -0x74));
        FUN_0042ba55(*(undefined4 *)(unaff_EBP + -0x74),1);
        cVar6 = FUN_004e2d6b(unaff_EBP + -0x1cc,unaff_EBP + -0x2c);
        if (cVar6 == '\0') {
          FUN_0042ba55(*(undefined4 *)(unaff_EBP + -0x74),uVar9);
          FUN_004f6994(s_Couldn_t_import_the_family_006cdd88,s_Error_006cbdc4,0,0);
        }
        else {
          if ((*(char *)(unaff_EBP + -0xbc) != '\0') && (*(int *)(unaff_EBP + -0x74) != 0)) {
            bVar2 = true;
          }
          FUN_004fc1e5();
          if (bVar2) {
            FUN_004f5aa0(1);
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004e2e81();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined1 *)(*(int *)(unaff_EBP + -0x1c) + 0x1d4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

