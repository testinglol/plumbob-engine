
int FUN_004288ff(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  undefined2 extraout_var;
  int unaff_EBP;
  int iVar8;
  int *piVar9;
  undefined2 *puVar10;
  undefined *puVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x758,0,0x100);
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined ***)(unaff_EBP + -0x764) = &PTR_FUN_00666524;
  FUN_00410947(unaff_EBP + -0x764);
  FUN_00405584(*(undefined4 *)(unaff_EBP + 8));
  if (*(short *)(unaff_EBP + -0x324) == 0) {
    iVar3 = -1;
  }
  else {
    cVar2 = *(char *)((*(ushort *)(unaff_EBP + -0x324) - 1) + *(int *)(unaff_EBP + -0x328));
    if ((cVar2 != '\\') && (cVar2 != '/')) {
      FUN_0046fa24(0x2f);
    }
    FUN_0046f917(unaff_EBP + -0x764,0xffffffff);
    FUN_00405584(unaff_EBP + -0x32c);
    FUN_0046f847(&DAT_006c2808,0xffffffff);
    if (*(int *)(iVar1 + 0x110) != 0) {
      FUN_0046f824(unaff_EBP + -0x64c,0,0x104);
      uVar7 = *(undefined4 *)(iVar1 + 0x110);
      *(undefined ***)(unaff_EBP + -0x658) = &PTR_FUN_006664e8;
      FUN_00425691(uVar7,unaff_EBP + -0x658);
      BVar4 = CopyFileA(*(LPCSTR *)(unaff_EBP + -0x654),*(LPCSTR *)(unaff_EBP + -0x438),0);
      if (BVar4 == 0) {
        iVar3 = -0x32;
        goto LAB_00428f3e;
      }
    }
    FUN_00418fea();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar3 = FUN_00465a37(unaff_EBP + -0x43c,1);
    if (iVar3 == 0) {
      FUN_00410729(unaff_EBP + -0x4c,*(undefined4 *)(DAT_006e486c + 0x44));
      iVar8 = 0;
      FUN_0046f824(unaff_EBP + -0x53c,0,0x100);
      *(undefined ***)(unaff_EBP + -0x548) = &PTR_FUN_00666524;
      FUN_004102d4(unaff_EBP + -0x548);
      FUN_004706f0();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0047132c(1,*(undefined4 *)(unaff_EBP + -0x544),0);
      FUN_0047034e(unaff_EBP + -0x4c,1000,0x43545353,0,0xffffffff);
      FUN_00470b98();
      *(undefined1 *)(unaff_EBP + -0x74) = *(undefined1 *)(DAT_006e486c + 100);
      *(undefined4 *)(unaff_EBP + -0x70) = 0;
      *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      *(undefined4 *)(unaff_EBP + -0x68) = 0;
      *(undefined4 *)(unaff_EBP + -100) = 0;
      *(short *)(unaff_EBP + -0x72) = (short)*(undefined4 *)(iVar1 + 0x10c);
      iVar3 = FUN_004102e1();
      if (0 < iVar3) {
        puVar10 = (undefined2 *)(unaff_EBP + -0x70);
        do {
          puVar5 = (undefined4 *)FUN_004102ab(iVar8);
          puVar6 = (undefined2 *)FUN_00425769(*puVar5);
          iVar8 = iVar8 + 1;
          *puVar10 = *puVar6;
          puVar10 = puVar10 + 1;
          iVar3 = FUN_004102e1();
        } while (iVar8 < iVar3);
      }
      iVar3 = FUN_0042fe97(unaff_EBP + -0x74,unaff_EBP + -0x4c,0x45585069,0,0x3f);
      if (iVar3 == 0) {
        iVar3 = *(int *)(unaff_EBP + -0x10);
        piVar9 = *(int **)(iVar3 + 0x148);
        if (piVar9 != *(int **)(iVar3 + 0x14c)) {
          do {
            iVar8 = *piVar9;
            if ((iVar8 != 0) && ((int)*(short *)(iVar8 + 0xee) == *(int *)(iVar1 + 0x10c))) {
              puVar5 = *(undefined4 **)(iVar8 + 8);
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0xe0) = &PTR_FUN_0066643c;
              uVar7 = *puVar5;
              *(undefined1 *)(unaff_EBP + -4) = 2;
              iVar3 = FUN_00470383(uVar7,200,0);
              *(int *)(unaff_EBP + 0xc) = iVar3;
              if (iVar3 == 0) {
                FUN_0047034e(unaff_EBP + -0x4c,
                             CONCAT22((short)((uint)*piVar9 >> 0x10),*(undefined2 *)*piVar9),
                             0x75436872,0,0xffffffff);
                iVar3 = FUN_0046fd72();
                *(int *)(unaff_EBP + 0xc) = iVar3;
                if (iVar3 == 0) {
                  FUN_00457ea7();
                  iVar3 = FUN_004063b5(unaff_EBP + -0x4c,
                                       CONCAT22(extraout_var,*(undefined2 *)*piVar9));
                  *(int *)(unaff_EBP + 0xc) = iVar3;
                  if (iVar3 == 0) {
                    FUN_004706f0();
                    uVar7 = *puVar5;
                    *(undefined1 *)(unaff_EBP + -4) = 3;
                    FUN_0047034e(uVar7,2000,0x43545353,0,0xffffffff);
                    FUN_00470d9f(1,0);
                    FUN_0047034e(unaff_EBP + -0x4c,
                                 CONCAT22((short)((uint)*piVar9 >> 0x10),*(undefined2 *)*piVar9) +
                                 2000,0x43545353,0,0xffffffff);
                    FUN_00470b98();
                    iVar3 = (**(code **)(*(int *)*puVar5 + 0x38))(0x424d505f,0x7d4,0);
                    *(int *)(unaff_EBP + 0xc) = iVar3;
                    if (iVar3 != 0) {
                      (**(code **)(*(int *)*puVar5 + 100))(iVar3);
                      FUN_0046f824(unaff_EBP + -0x198,0,0x40);
                      *(undefined ***)(unaff_EBP + -0x1a4) = &PTR_FUN_0066651c;
                      FUN_0046f847(&DAT_006de560,0xffffffff);
                      FUN_00419f36(*(undefined4 *)(unaff_EBP + 0xc),0x424d505f,
                                   CONCAT22((short)((uint)*piVar9 >> 0x10),*(undefined2 *)*piVar9),
                                   unaff_EBP + -0x1a4,1);
                      FUN_00419f53(*(undefined4 *)(unaff_EBP + 0xc));
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 2;
                    FUN_004712d0();
                    *(undefined1 *)(unaff_EBP + -4) = 1;
                    FUN_00470467();
                    iVar3 = *(int *)(unaff_EBP + -0x10);
                    goto LAB_00428d25;
                  }
                }
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_00470467();
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_004712d0();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              FUN_0041905d();
              iVar3 = *(int *)(unaff_EBP + 0xc);
              goto LAB_00428f3e;
            }
LAB_00428d25:
            piVar9 = piVar9 + 1;
          } while (piVar9 != *(int **)(iVar3 + 0x14c));
        }
        iVar8 = DAT_006e486c;
        *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x14;
        *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666cf4;
        uVar7 = *(undefined4 *)(iVar8 + 0x44);
        *(int *)(unaff_EBP + -0x14) = iVar3 + 0x148;
        *(undefined4 *)(unaff_EBP + -0x10) = 0x4e425253;
        *(undefined4 *)(unaff_EBP + -0x18) = 0x4e425253;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar3 = FUN_00464eab(unaff_EBP + -0x20,uVar7,unaff_EBP + -0x4c,1);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00465055();
        if (iVar3 == 0) {
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          *(undefined4 *)(unaff_EBP + 0xc) = 0;
          iVar3 = FUN_004102e1();
          if (0 < iVar3) {
            puVar10 = (undefined2 *)(unaff_EBP + -0x70);
            do {
              uVar7 = FUN_0042a8e3(*puVar10);
              *(undefined4 *)(unaff_EBP + 8) = uVar7;
              FUN_0042ec2b(unaff_EBP + 8);
              *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
              puVar10 = puVar10 + 1;
              iVar3 = FUN_004102e1();
            } while (*(int *)(unaff_EBP + 0xc) < iVar3);
          }
          iVar3 = DAT_006e486c;
          *(int *)(unaff_EBP + -0x54) = unaff_EBP + -0x60;
          *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_00666ce4;
          uVar7 = *(undefined4 *)(iVar3 + 0x44);
          *(int *)(unaff_EBP + -0x60) = unaff_EBP + -0x20;
          *(undefined4 *)(unaff_EBP + -0x5c) = 0x46494e56;
          *(undefined4 *)(unaff_EBP + -0x50) = 0x46494e56;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_00464eab(unaff_EBP + -0x58,uVar7,unaff_EBP + -0x4c,2);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_00465055();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0048c4c9();
          FUN_004195ba();
          FUN_00405584(unaff_EBP + -0x32c);
          FUN_0046f847(&DAT_006c2800,0xffffffff);
          FUN_0041c785(unaff_EBP + -0x984);
          FUN_00405584(unaff_EBP + -0x32c);
          FUN_0046f847(&DAT_006c27f8,0xffffffff);
          FUN_0041c785(unaff_EBP + -0xa94);
          FUN_00405584(unaff_EBP + -0x32c);
          if ((*(int *)(iVar1 + 0x110) < 0x5a) || (0x5c < *(int *)(iVar1 + 0x110))) {
            puVar11 = &DAT_006c2800;
          }
          else {
            puVar11 = &DAT_006c27f8;
          }
          FUN_0046f847(puVar11,0xffffffff);
          uVar7 = *(undefined4 *)(unaff_EBP + -0x870);
          uVar12 = *(undefined4 *)(unaff_EBP + -0x438);
          FUN_005b8e25(uVar12,uVar7);
          cVar2 = FUN_005b9849(uVar12,uVar7);
          if (cVar2 == '\0') {
            iVar3 = -0x32;
          }
          else {
            iVar3 = 0;
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004712d0();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0041905d();
  }
LAB_00428f3e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

