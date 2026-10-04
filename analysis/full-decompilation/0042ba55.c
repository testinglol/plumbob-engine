
undefined1 FUN_0042ba55(void)

{
  int iVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar8;
  size_t _Count;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  for (piVar3 = *(int **)(extraout_ECX + 0x174); piVar3 != *(int **)(extraout_ECX + 0x178);
      piVar3 = piVar3 + 2) {
    if (*piVar3 == *(int *)(unaff_EBP + 8)) {
      if (piVar3[1] == iVar1) goto LAB_0042ba92;
      break;
    }
  }
  if (piVar3 == *(int **)(extraout_ECX + 0x178)) {
LAB_0042ba92:
    uVar2 = 0;
  }
  else {
    piVar3[1] = iVar1;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046f824(unaff_EBP + -0x250,0,0x104);
    iVar5 = DAT_006e486c;
    *(undefined ***)(unaff_EBP + -0x25c) = &PTR_FUN_006664e8;
    FUN_00412122(*(undefined4 *)(iVar5 + 0x24),unaff_EBP + -0x25c);
    uVar8 = 0xffffffff;
    uVar4 = FUN_0041532c(0xb,0xffffffff);
    FUN_0046f847(uVar4,uVar8);
    FUN_0046f5cd();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar5 = FUN_0046f71c(unaff_EBP + -0x25c,1);
    if ((iVar5 == 0) && (iVar5 = FUN_004703f1(unaff_EBP + -0x4a0,1), iVar5 == 0)) {
      *(undefined4 *)(unaff_EBP + 0xc) = 1;
      iVar5 = FUN_0046fbe5(0xffffffff);
      if (0 < iVar5) {
        do {
          _Count = 99;
          pcVar6 = (char *)FUN_004705f2(*(undefined4 *)(unaff_EBP + 0xc),0);
          _strncpy((char *)(unaff_EBP + -0x14c),pcVar6,_Count);
          puVar7 = (undefined1 *)FUN_00636450(unaff_EBP + -0x14c,0x2c);
          if (puVar7 != (undefined1 *)0x0) {
            *puVar7 = 0;
            iVar5 = FUN_00635f62(unaff_EBP + -0x14c);
            if (iVar5 == *(int *)(unaff_EBP + 8)) {
              FUN_0046f824(unaff_EBP + -0xdc,0,100);
              *(undefined ***)(unaff_EBP + -0xe8) = &PTR_FUN_00666d14;
              FUN_0046fa40(*(undefined4 *)(unaff_EBP + 8));
              FUN_0046f847(&DAT_006c25a8,0xffffffff);
              if ((iVar1 == 1) || (iVar1 != 2)) {
                pcVar6 = s_residential_006c2594;
              }
              else {
                pcVar6 = s_community_006c2588;
              }
              FUN_0046f847(pcVar6,0xffffffff);
              FUN_004704a5(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + -0xe4),0);
              break;
            }
          }
          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
          iVar5 = FUN_0046fbe5(0xffffffff);
        } while (*(int *)(unaff_EBP + 0xc) <= iVar5);
      }
      FUN_0046fd04(unaff_EBP + -0x4a0,1);
      FUN_00406746();
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
    }
    else {
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046b2e6();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    uVar2 = *(undefined1 *)(unaff_EBP + 0xb);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

