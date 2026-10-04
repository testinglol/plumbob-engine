
int FUN_0042808b(void)

{
  int iVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  int unaff_EBP;
  int iVar10;
  
  FUN_00634c24();
  iVar8 = DAT_006e486c[7];
  *(int *)(unaff_EBP + -0x38) = extraout_ECX;
  *(int *)(unaff_EBP + -0x2c) = iVar8;
  iVar4 = FUN_00424850();
  if (iVar4 == 0) {
    do {
      piVar7 = *(int **)(extraout_ECX + 0x154);
      while( true ) {
        if (piVar7 == *(int **)(extraout_ECX + 0x158)) {
          if ((*(int *)(unaff_EBP + 0xc) < 1) || (*(int *)(unaff_EBP + 8) == 0)) goto LAB_00428146;
          piVar7 = *(int **)(extraout_ECX + 0x154);
          goto LAB_00428116;
        }
        iVar4 = FUN_004102e1();
        if ((iVar4 == 0) && (*(int *)(*piVar7 + 0x10c) != 0)) break;
        piVar7 = piVar7 + 1;
      }
      if (*(int *)(*piVar7 + 0x110) != 0) {
        *(int *)(*piVar7 + 0x110) = 0;
      }
      FUN_00425f45(*piVar7);
    } while( true );
  }
  goto LAB_004286b2;
LAB_00428116:
  if (piVar7 == *(int **)(extraout_ECX + 0x158)) goto LAB_0042812d;
  if (*(int *)(*piVar7 + 0x10c) == *(int *)(unaff_EBP + 0xc)) {
    iVar4 = *piVar7;
    goto LAB_0042812f;
  }
  piVar7 = piVar7 + 1;
  goto LAB_00428116;
LAB_0042854a:
  iVar8 = *(int *)(unaff_EBP + -0x10);
  piVar7 = *(int **)(iVar8 + 0x84);
  do {
    if (piVar7 == *(int **)(iVar8 + 0x88)) {
      if (*(char *)(unaff_EBP + -0x11) != '\0') {
        FUN_0046f824(unaff_EBP + -0x78,0,0x40);
        *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066651c;
        FUN_0046f847(s_import_lot_006c2744,0xffffffff);
        FUN_00444781(unaff_EBP + -0x84,0);
      }
      FUN_004c482f();
      FUN_0040766a(0xf6,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      goto LAB_004286af;
    }
    iVar8 = *piVar7;
    if (((byte)*(undefined4 *)(*(int *)(iVar8 + 0x11c) + 0xb4) & 0xc) == 4) {
      piVar5 = *(int **)(unaff_EBP + -0x20);
      if (piVar5 != *(int **)(unaff_EBP + -0x1c)) {
        do {
          if (*piVar5 == iVar8) break;
          piVar5 = piVar5 + 1;
        } while (piVar5 != *(int **)(unaff_EBP + -0x1c));
      }
      if ((piVar5 != *(int **)(unaff_EBP + -0x1c)) && (*(short *)(iVar8 + 0x5cc) != 0)) break;
      piVar5 = *(int **)(iVar10 + 0x154);
      if (piVar5 != *(int **)(iVar10 + 0x158)) {
        do {
          if (*(int *)(*piVar5 + 0x10c) == (int)*(short *)(iVar8 + 0x606)) {
            iVar8 = *piVar5;
            goto LAB_004285d4;
          }
          piVar5 = piVar5 + 1;
        } while (piVar5 != *(int **)(iVar10 + 0x158));
      }
      iVar8 = 0;
LAB_004285d4:
      if (((((((iVar8 != 0) && (iVar4 = *(int *)(iVar8 + 0x10c), iVar4 != 0)) && (iVar4 < 3000)) &&
            ((0xbc1 < iVar4 && (iVar4 != 2000)))) &&
           ((iVar4 != 4000 && ((iVar4 != 5000 && (iVar4 != 0x157c)))))) && (iVar4 != 6000)) &&
         (*(short *)(iVar8 + 0x110) == 0)) break;
    }
    iVar8 = *(int *)(unaff_EBP + -0x10);
    piVar7 = piVar7 + 1;
  } while( true );
  FUN_0044127f(CONCAT22((short)((uint)*piVar7 >> 0x10),*(undefined2 *)(*piVar7 + 0xf0)));
  goto LAB_0042854a;
LAB_0042812d:
  iVar4 = 0;
LAB_0042812f:
  if (iVar4 != 0) {
    iVar4 = FUN_00427368(iVar4,*(undefined4 *)(unaff_EBP + 8));
    if (iVar4 != 0) goto LAB_004286b2;
  }
LAB_00428146:
  FUN_004071be(*(undefined4 *)(extraout_ECX + 0x11c),*(undefined4 *)(extraout_ECX + 0x120));
  piVar7 = *(int **)(extraout_ECX + 0x158);
  iVar4 = *DAT_006e486c;
  *(int *)(unaff_EBP + -0x24) = iVar4;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar4 + 0x14);
  for (piVar5 = *(int **)(extraout_ECX + 0x154); piVar5 != piVar7; piVar5 = piVar5 + 1) {
    if (*(int *)(*piVar5 + 0x10c) == 0) {
      iVar9 = *piVar5;
      goto LAB_00428195;
    }
  }
  iVar9 = 0;
LAB_00428195:
  *(int *)(iVar4 + 0x10) = iVar9;
  FUN_0046f824(unaff_EBP + -0x188,0,0x104);
  *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
  FUN_00425691(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x194);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f71c(unaff_EBP + -0x194,0);
  cVar2 = FUN_0040682b();
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046b2e6();
    iVar4 = -0x44c;
  }
  else {
    uVar6 = FUN_00415ef5(unaff_EBP + -0x3d8,unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
    FUN_004286c3();
    sVar3 = FUN_004069f8(0x45585069);
    *(bool *)(unaff_EBP + -0x11) = 0 < sVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046b2e6();
    if (*(int *)(unaff_EBP + -0x28) == 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar4 = *(int *)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      for (piVar7 = *(int **)(iVar4 + 0x84); piVar7 != *(int **)(iVar4 + 0x88); piVar7 = piVar7 + 1)
      {
        if (*(short *)(*piVar7 + 0x5cc) == 0) {
          FUN_0042eadb(piVar7);
          iVar4 = *(int *)(unaff_EBP + -0x10);
        }
      }
      uVar6 = *(undefined4 *)(unaff_EBP + 8);
      *(undefined4 *)(extraout_ECX + 0x164) = uVar6;
      iVar4 = FUN_00425ddf(uVar6);
      if ((iVar4 == 0) || (*(int *)(unaff_EBP + 8) == 0)) {
        for (piVar7 = *(int **)(extraout_ECX + 0x154); piVar7 != *(int **)(extraout_ECX + 0x158);
            piVar7 = piVar7 + 1) {
          if (*(int *)(*piVar7 + 0x10c) == 0) {
            iVar4 = *piVar7;
            goto LAB_004282ec;
          }
        }
        iVar4 = 0;
      }
LAB_004282ec:
      iVar9 = *(int *)(unaff_EBP + 0xc);
      *(byte *)(unaff_EBP + -0x12) = (byte)(*(uint *)(iVar4 + 0x138) >> 2) & 1;
      *(int *)(*(int *)(unaff_EBP + -0x24) + 0x10) = iVar4;
      iVar10 = extraout_ECX;
      if (0 < iVar9) {
        iVar9 = *(int *)(iVar8 + 0x9c);
        *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar8 + 0xa0);
        *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(iVar8 + 0xa4);
        iVar8 = __ftol();
        iVar9 = iVar8 + *(int *)(unaff_EBP + -0x30) + iVar9;
        iVar8 = *(int *)(unaff_EBP + -0x2c);
        *(int *)(iVar4 + 0x118) = (*(int *)(iVar4 + 0x118) - iVar9) + *(int *)(iVar4 + 0x11c);
        *(int *)(iVar4 + 0x11c) = iVar9;
        iVar10 = *(int *)(unaff_EBP + -0x38);
      }
      FUN_0046dae0(9,*(undefined4 *)(iVar4 + 0x10c));
      FUN_0046dae0(10,*(undefined4 *)(unaff_EBP + 8));
      uVar6 = 0;
      if (*(int *)(iVar4 + 0x10c) != 0) {
        uVar6 = *(undefined4 *)(iVar4 + 0x118);
      }
      FUN_0046d9f8(uVar6);
      if (*(int *)(unaff_EBP + 8) == 0) {
        FUN_004427da();
      }
      else {
        iVar9 = *(int *)(iVar10 + 0x114);
        iVar1 = *(int *)(iVar10 + 0x110);
        *(undefined4 *)(unaff_EBP + 0xc) = 1;
        if (1 < (uint)(iVar9 - iVar1 >> 3)) {
          do {
            if (*(int *)(unaff_EBP + 0xc) != *(int *)(unaff_EBP + 8)) {
              FUN_0042eab4(unaff_EBP + 0xc);
            }
            iVar9 = *(int *)(iVar10 + 0x114);
            *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
          } while (*(uint *)(unaff_EBP + 0xc) < (uint)(iVar9 - *(int *)(iVar10 + 0x110) >> 3));
        }
        if (1 < (uint)(*(int *)(iVar10 + 0x120) - *(int *)(iVar10 + 0x11c) >> 2)) {
          FUN_0043004d(*(int *)(iVar10 + 0x11c),*(undefined4 *)(iVar10 + 0x120),FUN_00428003);
        }
      }
      FUN_0043fcd4(*(undefined4 *)(unaff_EBP + -0x34));
      do {
        piVar7 = *(int **)(*(int *)(unaff_EBP + -0x10) + 0x84);
        *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x88);
        while( true ) {
          if (piVar7 == *(int **)(unaff_EBP + 0xc)) {
            if (((DAT_006e4a58 == 0) && (*(short *)(iVar10 + 0x12a) < 3)) &&
               (*(short *)(iVar8 + 0x44) != 0)) {
              iVar8 = FUN_00440914(0xc3249a1d);
              if (iVar8 == 0) {
                iVar8 = FUN_0043acf5(0xc3249a1d);
                if (iVar8 != 0) {
                  FUN_00440b6d(iVar8);
                }
              }
            }
            if (((*(int *)(unaff_EBP + 8) != 0) && (*(int *)(iVar4 + 0x10c) != 0)) &&
               (*(char *)(unaff_EBP + -0x12) != '\0')) {
              *(uint *)(iVar4 + 0x138) = *(uint *)(iVar4 + 0x138) & 0xfffffffb;
              FUN_0046d98b(DAT_006e4a34,0);
              FUN_0046da96();
              FUN_0046d956();
              FUN_004165e9();
              FUN_0046f824(unaff_EBP + -0x78,0,0x40);
              *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066651c;
              FUN_0046f847(s_reset_lot_006c2750,0xffffffff);
              FUN_00444781(unaff_EBP + -0x84,0);
            }
            FUN_0042a2fe();
            goto LAB_0042854a;
          }
          iVar9 = *piVar7;
          if (((((byte)*(undefined4 *)(*(int *)(iVar9 + 0x11c) + 0xb4) & 0xc) == 4) &&
              (*(short *)(iVar9 + 0x606) == 0)) &&
             ((int)*(short *)(iVar9 + 0x612) != *(int *)(iVar10 + 0x164))) break;
          piVar7 = piVar7 + 1;
        }
        FUN_0044127f(CONCAT22((short)((uint)*piVar7 >> 0x10),*(undefined2 *)(*piVar7 + 0xf0)));
      } while( true );
    }
LAB_004286af:
    iVar4 = *(int *)(unaff_EBP + -0x28);
  }
LAB_004286b2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

