
void FUN_005621bb(void)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x188) == '\0') {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x28);
    pcVar3 = (char *)FUN_0041532c(0x58);
    sVar4 = _strlen(pcVar3);
    FUN_00412d8a(pcVar3,pcVar3 + sVar4);
    sVar4 = _strlen(s___FAM_006c28a4);
    FUN_00412d8a(s___FAM_006c28a4,s___FAM_006c28a4 + sVar4);
    cVar2 = FUN_005d8a11(unaff_EBP + -0x28);
    piVar1 = *(int **)(extraout_ECX + 0x138);
    if ((char)piVar1[0x5a] != cVar2) {
      *(char *)(piVar1 + 0x5a) = cVar2;
      (**(code **)(*piVar1 + 0x168))();
    }
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004f2baf(unaff_EBP + -0x1c);
    pcVar3 = (char *)FUN_0041532c(0x58);
    sVar4 = _strlen(pcVar3);
    FUN_00412d8a(pcVar3,pcVar3 + sVar4);
    sVar4 = _strlen(s_Tutorial_FAM_006cac44);
    FUN_00412d8a(s_Tutorial_FAM_006cac44,s_Tutorial_FAM_006cac44 + sVar4);
    cVar2 = FUN_005ed4a5(unaff_EBP + -0x1c);
    if (cVar2 != '\0') {
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      uVar5 = FUN_004096c2();
      FUN_0046f824(unaff_EBP + -0x130,0,0x104);
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_006664e8;
      FUN_0046f847(uVar5,0xffffffff);
      FUN_004e2e34();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      cVar2 = FUN_004e2b6b(unaff_EBP + -0x13c,unaff_EBP + -0x2dc,0);
      if (cVar2 != '\0') {
        cVar2 = FUN_004e2d6b(unaff_EBP + -0x2dc,unaff_EBP + -0x2c);
        if (cVar2 == '\0') {
          FUN_004f6994(s_Couldn_t_import_the_family_006cdd88,s_Error_006cbdc4,0,0);
        }
        else {
          if ((*(char *)(unaff_EBP + -0x1cc) != '\0') && (*(int *)(unaff_EBP + -0x184) != 0)) {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          FUN_004fc1e5();
          if (*(char *)(unaff_EBP + -0xd) != '\0') {
            FUN_004f5aa0(1);
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004e2e81();
    }
    *(undefined1 *)(extraout_ECX + 0x188) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

