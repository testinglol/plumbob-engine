
undefined4 FUN_0046eaca(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  void *pvVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = extraout_ECX;
  FUN_0046fb9b(unaff_EBP + -0x138,0x104);
  uVar3 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
  *(undefined ***)(unaff_EBP + -0x144) = &PTR_LAB_00666cdc;
  FUN_0046fb9b(unaff_EBP + -0x248,0x104);
  *(undefined ***)(unaff_EBP + -0x254) = &PTR_LAB_00666cdc;
  FUN_0046f847(uVar3,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x254);
  iVar2 = FUN_00635845(*(undefined4 *)(unaff_EBP + -0x140),&DAT_006c16d8);
  *(int *)(unaff_EBP + 8) = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_0046fb9b(unaff_EBP + -0x654,0x400);
    *(undefined ***)(unaff_EBP + -0x660) = &PTR_LAB_00667744;
    while (iVar2 = FUN_00636bfa(*(undefined4 *)(unaff_EBP + 8),&DAT_006c4c3c,unaff_EBP + -0x10),
          0 < iVar2) {
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      piVar1 = *(int **)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046ef44(unaff_EBP + -0x34);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      iVar2 = *piVar1;
      *(int *)(unaff_EBP + -0x18) = iVar2 + -0xc + ((piVar1[1] - iVar2) / 0xc) * 0xc;
      if (*(char *)(unaff_EBP + -0x10) != '\n') {
        *(undefined2 *)(unaff_EBP + -0x658) = 0;
        **(undefined1 **)(unaff_EBP + -0x65c) = 0;
        FUN_0046fa24(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_00636bfa(*(undefined4 *)(unaff_EBP + 8),s_______006c4c34,
                     *(int *)(unaff_EBP + -0x65c) + 1);
        FUN_00636bfa(*(undefined4 *)(unaff_EBP + 8),&DAT_006c4c3c,unaff_EBP + -0x10);
        FUN_0046fa24(9);
        sVar4 = _strlen(*(char **)(unaff_EBP + -0x65c));
        iVar6 = 0;
        iVar2 = -1;
        *(size_t *)(unaff_EBP + -0x28) = sVar4;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (0 < (int)sVar4) {
          do {
            if (*(char *)(*(int *)(unaff_EBP + -0x65c) + iVar6) == '\t') {
              iVar7 = (iVar6 - iVar2) - 1;
              if (iVar7 == 0) {
                *(undefined4 *)(unaff_EBP + -0x24) = 0;
                iVar2 = unaff_EBP + -0x24;
              }
              else {
                FUN_0046f824(unaff_EBP + -0xa60,0,0x400);
                *(undefined ***)(unaff_EBP + -0xa6c) = &PTR_FUN_0066773c;
                FUN_0046f847(*(int *)(unaff_EBP + -0x65c) + 1 + iVar2,iVar7);
                pvVar5 = operator_new(iVar6 - iVar2);
                *(void **)(unaff_EBP + -0x1c) = pvVar5;
                FUN_006358b0(pvVar5,*(undefined4 *)(unaff_EBP + -0xa68));
                iVar2 = unaff_EBP + -0x1c;
              }
              FUN_0046ef6c(iVar2);
              iVar2 = *(int *)(unaff_EBP + -0x14);
            }
            iVar6 = *(int *)(unaff_EBP + -0x14) + 1;
            *(int *)(unaff_EBP + -0x14) = iVar6;
          } while (iVar6 < *(int *)(unaff_EBP + -0x28));
        }
      }
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + 8));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

