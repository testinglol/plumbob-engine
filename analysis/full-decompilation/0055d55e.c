
void FUN_0055d55e(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int iVar5;
  int unaff_EBP;
  char *pcVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x88) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x1c0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1cc) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x2d0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2dc) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2dc);
  uVar4 = *(undefined4 *)(unaff_EBP + -0x2d8);
  uVar2 = FUN_0041532c(10,unaff_EBP + -0x1cc);
  FUN_004ee9ce(uVar4,uVar2);
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar3 = FUN_0046f71c(unaff_EBP + -0x1cc,1);
  if (iVar3 == 0) {
    cVar1 = FUN_004067fa();
    if (cVar1 == '\0') {
      pcVar6 = s_Lot_Positions_are_not_writeable__006cdb50;
    }
    else {
      FUN_0047034e(unaff_EBP + -0x520,4,0x53545223,0,0xffffffff);
      FUN_0046ffa4(0,1);
      iVar3 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x148);
      iVar5 = *(int *)(iVar3 + 8);
      *(int *)(unaff_EBP + -0x14) = iVar5;
      while (iVar5 != iVar3) {
        iVar3 = *(int *)(iVar5 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar3 + 0x20c);
        iVar5 = *(int *)(iVar3 + 0x1d8);
        uVar4 = *(undefined4 *)(iVar3 + 0x208);
        if (*(int *)(iVar3 + 0x194) == 0) {
          *(undefined4 *)(unaff_EBP + -0x10) = 1;
          iVar3 = FUN_0046fbe5(0xffffffff);
          if (0 < iVar3) {
            do {
              uVar2 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
              FUN_006358b0(unaff_EBP + -0xbc,uVar2);
              iVar3 = FUN_00635f62(unaff_EBP + -0xbc);
              if (iVar3 == iVar5) {
                FUN_00635858(unaff_EBP + -0xbc,s__d___d___d_006cdb44,iVar5,uVar4,
                             *(undefined4 *)(unaff_EBP + -0x1c));
                FUN_004704a5(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0xbc,0xffffffff);
                break;
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              iVar3 = FUN_0046fbe5(0xffffffff);
            } while (*(int *)(unaff_EBP + -0x10) <= iVar3);
          }
        }
        FUN_0041674f();
        iVar3 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x148);
        iVar5 = *(int *)(unaff_EBP + -0x14);
      }
      FUN_0046fd72();
      FUN_0046b7ee();
      pcVar6 = s_Lot_Positions_have_been_saved_006cdb24;
    }
    FUN_004f6994(pcVar6,s_Lot_Positions_006cdbb8,0,0);
  }
  else {
    uVar4 = FUN_0041532c(10,unaff_EBP + -0x1cc);
    uVar4 = FUN_0041532c(0,uVar4);
    FUN_004ee9ce(uVar4);
    FUN_0046f71c(unaff_EBP + -0x1cc,1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046b2e6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

