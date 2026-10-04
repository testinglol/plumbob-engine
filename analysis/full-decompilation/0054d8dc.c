
void FUN_0054d8dc(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  char *pcVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x88) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x1c0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1cc) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x2d0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2dc) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2dc);
  uVar6 = *(undefined4 *)(unaff_EBP + -0x2d8);
  uVar4 = FUN_0041532c(10,unaff_EBP + -0x1cc);
  FUN_004ee9ce(uVar6,uVar4);
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar5 = FUN_0046f71c(unaff_EBP + -0x1cc,1);
  if (iVar5 == 0) {
    cVar3 = FUN_004067fa();
    if (cVar3 == '\0') {
      pcVar8 = s_Lot_Positions_are_not_writeable__006cdb50;
    }
    else {
      FUN_0047034e(unaff_EBP + -0x520,2,0x53545223,0,0xffffffff);
      FUN_0046ffa4(0,1);
      iVar5 = *(int *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x14) = 10;
      piVar7 = (int *)(iVar5 + 0x14c);
      do {
        iVar5 = *piVar7;
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
        iVar2 = *(int *)(iVar5 + 0x1d8);
        uVar6 = *(undefined4 *)(iVar5 + 0x20c);
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar5 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
        iVar5 = FUN_0046fbe5(0xffffffff);
        if (0 < iVar5) {
          do {
            uVar6 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
            FUN_006358b0(unaff_EBP + -0xbc,uVar6);
            iVar5 = FUN_00635f62(unaff_EBP + -0xbc);
            if (iVar5 == iVar2) {
              FUN_00635858(unaff_EBP + -0xbc,s__d___d___d_006cdb44,iVar2,
                           *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
              FUN_004704a5(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0xbc,0xffffffff);
              break;
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            iVar5 = FUN_0046fbe5(0xffffffff);
          } while (*(int *)(unaff_EBP + -0x10) <= iVar5);
        }
        piVar7 = piVar7 + 1;
        piVar1 = (int *)(unaff_EBP + -0x14);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      FUN_0046fd72();
      FUN_0046b7ee();
      pcVar8 = s_Lot_Positions_have_been_saved_006cdb24;
    }
    FUN_004f6994(pcVar8,s_Lot_Positions_006cdbb8,0,0);
  }
  else {
    uVar6 = FUN_0041532c(10,unaff_EBP + -0x1cc);
    uVar6 = FUN_0041532c(0,uVar6);
    FUN_004ee9ce(uVar6);
    FUN_0046f71c(unaff_EBP + -0x1cc,1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046b2e6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

