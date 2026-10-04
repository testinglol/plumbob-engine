
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004201ab(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  HMENU pHVar4;
  int iVar5;
  void *pvVar6;
  byte *pbVar7;
  undefined4 uVar8;
  short *psVar9;
  undefined2 extraout_var;
  int extraout_ECX;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 uVar10;
  undefined2 extraout_var_02;
  int unaff_EBP;
  undefined4 uVar11;
  
  FUN_00634c24();
  FUN_00466617(extraout_ECX);
  if (*(short *)(unaff_EBP + 0x10) == 0) {
    *(undefined2 *)(extraout_ECX + 0xc) = DAT_006c21a8;
    _DAT_006c21a8 = _DAT_006c21a8 + 1;
  }
  else {
    *(short *)(extraout_ECX + 0xc) = *(short *)(unaff_EBP + 0x10);
  }
  uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
  piVar2 = *(int **)(unaff_EBP + 8);
  *(uint *)(extraout_ECX + 0x14) = *(uint *)(extraout_ECX + 0x14) & 0xfffffffe;
  *(undefined2 *)(extraout_ECX + 0xe) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = uVar8;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(int **)(extraout_ECX + 0x124) = piVar2;
  *(undefined2 *)(extraout_ECX + 0x20) = 0;
  **(undefined1 **)(extraout_ECX + 0x1c) = 0;
  if (*(int *)(extraout_ECX + 0x10) == 0x4d454e55) {
    pHVar4 = CreatePopupMenu();
    iVar5 = *(int *)(unaff_EBP + 0x14);
    *(HMENU *)(extraout_ECX + 4) = pHVar4;
    uVar10 = extraout_var_00;
    if (iVar5 != 0) {
      FUN_0046f847(*(undefined4 *)(unaff_EBP + 0x14),0xffffffff);
      uVar10 = extraout_var_01;
    }
    if ((*(short *)(unaff_EBP + 0x10) == 0) || (piVar2 == (int *)0x0)) goto LAB_0042070e;
    iVar5 = (**(code **)(*piVar2 + 0x38))
                      (0x4d454e55,CONCAT22(uVar10,*(undefined2 *)(extraout_ECX + 0xc)),FUN_00420be9)
    ;
    *(int *)(unaff_EBP + -0x14) = iVar5;
    if (iVar5 == 0) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_0066643c;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_0047034e(piVar2,*(undefined2 *)(extraout_ECX + 0xc),0x4d535452,1,0xffffffff);
      FUN_0046ffa4(0,1);
      iVar5 = FUN_0046fbe5(0xffffffff);
      if (iVar5 != 0) {
        FUN_0046f824(unaff_EBP + -0x58,0,0x40);
        *(undefined ***)(unaff_EBP + -100) = &PTR_FUN_0066651c;
        FUN_0046fc01(unaff_EBP + -100);
        FUN_0046f8e4(unaff_EBP + -100);
        *(undefined4 *)(unaff_EBP + 0x10) = 1;
        iVar5 = FUN_0046fbe5(0xffffffff);
        if (0 < iVar5) {
          do {
            uVar11 = 0;
            uVar8 = FUN_004705f2(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
            FUN_004207e3(uVar8,uVar11);
            *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
            iVar5 = FUN_0046fbe5(0xffffffff);
          } while (*(int *)(unaff_EBP + 0x10) <= iVar5);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00420709:
      FUN_00470467();
      goto LAB_0042070e;
    }
    iVar5 = FUN_00420048(iVar5);
    *(int *)(unaff_EBP + 0x10) = iVar5 + 0xe;
    FUN_0046f824(unaff_EBP + -0x23c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x248) = &PTR_FUN_00666524;
    FUN_004644bd(*(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0x248);
    if (*(int *)(unaff_EBP + 0x14) == 0) {
      FUN_0046f8e4(unaff_EBP + -0x248);
    }
    pbVar7 = *(byte **)(unaff_EBP + 0x10) + **(byte **)(unaff_EBP + 0x10) + 1;
    while( true ) {
      *(byte **)(unaff_EBP + 0x10) = pbVar7;
      FUN_004644bd(pbVar7,unaff_EBP + -0x248);
      if (**(byte **)(unaff_EBP + 0x10) == 0) break;
      iVar5 = **(byte **)(unaff_EBP + 0x10) + 1 + *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + 0x14) = iVar5;
      cVar1 = *(char *)(iVar5 + 1);
      *(char *)(unaff_EBP + -0x10) = cVar1;
      if (cVar1 == '\x1b') {
        iVar5 = FUN_0042079e(0x4d454e55,(int)*(char *)(iVar5 + 2));
        if (iVar5 == 0) {
          pvVar6 = operator_new(0x128);
          *(void **)(unaff_EBP + 0x10) = pvVar6;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar6 == (void *)0x0) {
            iVar5 = 0;
          }
          else {
            *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x244);
            *(short *)(unaff_EBP + -0x18) = (short)*(char *)(*(int *)(unaff_EBP + 0x14) + 2);
            FUN_0046f824((int)pvVar6 + 0x24,0,0x100);
            uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
            puVar3 = *(undefined4 **)(unaff_EBP + 0x10);
            uVar11 = *(undefined4 *)(unaff_EBP + -0x18);
            *(undefined ***)(*(int *)(unaff_EBP + 0x10) + 0x18) = &PTR_FUN_00666524;
            *puVar3 = &PTR_FUN_006669f4;
            FUN_004201ab(*(undefined4 *)(unaff_EBP + 8),0x4d454e55,uVar11,uVar8);
            iVar5 = *(int *)(unaff_EBP + 0x10);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
        FUN_00420b1a(iVar5);
      }
      else {
        FUN_004207e3(*(undefined4 *)(unaff_EBP + -0x244),*(undefined4 *)(unaff_EBP + -0x10));
      }
      pbVar7 = (byte *)(*(int *)(unaff_EBP + 0x14) + 4);
    }
    uVar8 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  else {
    if (*(int *)(extraout_ECX + 0x10) != 0x4d424152) goto LAB_0042070e;
    pHVar4 = CreateMenu();
    *(HMENU *)(extraout_ECX + 4) = pHVar4;
    if ((piVar2 == (int *)0x0) || (*(short *)(unaff_EBP + 0x10) == 0)) goto LAB_0042070e;
    iVar5 = (**(code **)(*piVar2 + 0x38))
                      (0x4d424152,CONCAT22(extraout_var_02,*(undefined2 *)(extraout_ECX + 0xc)),
                       &LAB_00420c01);
    *(int *)(unaff_EBP + -0x10) = iVar5;
    if (iVar5 == 0) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xd0) = &PTR_FUN_0066643c;
      uVar10 = *(undefined2 *)(extraout_ECX + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      FUN_0047034e(piVar2,CONCAT22(extraout_var,uVar10),0x4d425354,1,0xffffffff);
      FUN_0046ffa4(0,1);
      iVar5 = FUN_0046fbe5(0xffffffff);
      if (iVar5 != 0) {
        FUN_0046f824(unaff_EBP + -0x58,0,0x40);
        *(undefined ***)(unaff_EBP + -100) = &PTR_FUN_0066651c;
        FUN_0046fc01(unaff_EBP + -100);
        FUN_0046f8e4(unaff_EBP + -100);
        FUN_0046f824(unaff_EBP + -0x348,0,0x100);
        *(undefined ***)(unaff_EBP + -0x354) = &PTR_FUN_00666524;
        *(undefined4 *)(unaff_EBP + 0x10) = 1;
        iVar5 = FUN_0046fbe5(0xffffffff);
        if (0 < iVar5) {
          do {
            uVar8 = FUN_004705f2(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
            FUN_0046f8cb(uVar8);
            iVar5 = FUN_00635f62(*(undefined4 *)(unaff_EBP + -0x350));
            *(int *)(unaff_EBP + 0xc) = iVar5;
            if (iVar5 != 0) {
              iVar5 = FUN_0042079e(0x4d454e55,iVar5);
              if (iVar5 == 0) {
                pvVar6 = operator_new(0x128);
                *(void **)(unaff_EBP + 0x14) = pvVar6;
                *(undefined1 *)(unaff_EBP + -4) = 4;
                if (pvVar6 == (void *)0x0) {
                  iVar5 = 0;
                }
                else {
                  FUN_0046f824((int)pvVar6 + 0x24,0,0x100);
                  puVar3 = *(undefined4 **)(unaff_EBP + 0x14);
                  uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
                  *(undefined ***)(*(int *)(unaff_EBP + 0x14) + 0x18) = &PTR_FUN_00666524;
                  *puVar3 = &PTR_FUN_006669f4;
                  FUN_004201ab(*(undefined4 *)(unaff_EBP + 8),0x4d454e55,uVar8,0);
                  iVar5 = *(int *)(unaff_EBP + 0x14);
                }
                *(undefined1 *)(unaff_EBP + -4) = 3;
              }
              FUN_00420b1a(iVar5);
            }
            *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
            iVar5 = FUN_0046fbe5(0xffffffff);
          } while (*(int *)(unaff_EBP + 0x10) <= iVar5);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_00420709;
    }
    psVar9 = (short *)FUN_00420048(iVar5);
    if (0 < *psVar9) {
      *(int *)(unaff_EBP + 0xc) = (int)*psVar9;
      *(short **)(unaff_EBP + 0x14) = psVar9 + 1;
      do {
        pvVar6 = operator_new(0x128);
        *(void **)(unaff_EBP + 0x10) = pvVar6;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        if (pvVar6 == (void *)0x0) {
          uVar8 = 0;
        }
        else {
          *(undefined2 *)(unaff_EBP + -0x14) = **(undefined2 **)(unaff_EBP + 0x14);
          FUN_0046f824((int)pvVar6 + 0x24,0,0x100);
          puVar3 = *(undefined4 **)(unaff_EBP + 0x10);
          uVar8 = *(undefined4 *)(unaff_EBP + -0x14);
          *(undefined ***)(*(int *)(unaff_EBP + 0x10) + 0x18) = &PTR_FUN_00666524;
          *puVar3 = &PTR_FUN_006669f4;
          FUN_004201ab(*(undefined4 *)(unaff_EBP + 8),0x4d454e55,uVar8,0);
          uVar8 = *(undefined4 *)(unaff_EBP + 0x10);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00420b1a(uVar8);
        *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 2;
        piVar2 = (int *)(unaff_EBP + 0xc);
        *piVar2 = *piVar2 + -1;
      } while (*piVar2 != 0);
    }
    uVar8 = *(undefined4 *)(unaff_EBP + -0x10);
  }
  FUN_00465a06(uVar8);
LAB_0042070e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

