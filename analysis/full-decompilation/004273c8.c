
int FUN_004273c8(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int extraout_ECX;
  int unaff_EBP;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 auStack_474 [7];
  undefined4 uStack_458;
  int iStack_454;
  char *pcStack_450;
  int iStack_44c;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(extraout_ECX + 0x164) == 0) {
    iStack_44c = *(undefined4 *)(unaff_EBP + 8);
    pcStack_450 = (char *)0x4273f2;
    iVar3 = FUN_00425ddf();
    iVar6 = *(int *)(*DAT_006e486c + 0x1c);
    if ((iVar3 != 0) || (*(int *)(unaff_EBP + 0xc) != 0)) {
      iVar8 = -1;
      if (iVar3 != 0) {
        iVar8 = *(int *)(iVar3 + 0x10c);
        *(undefined4 *)(iVar3 + 0x110) = 0;
      }
      iStack_44c = DAT_006e486c[0x11];
      pcStack_450 = (char *)0x427431;
      FUN_00425316();
      iStack_44c = 0xffffffff;
      pcStack_450 = *(char **)(unaff_EBP + 8);
      iStack_454 = 0x42743d;
      iVar3 = FUN_0042808b();
      for (piVar7 = *(int **)(extraout_ECX + 0x154); piVar7 != *(int **)(extraout_ECX + 0x158);
          piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x10c) == iVar8) {
          iVar8 = *piVar7;
          *(int *)(unaff_EBP + -0x28) = iVar8;
          goto LAB_0042746a;
        }
      }
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      iVar8 = *(int *)(unaff_EBP + -0x28);
LAB_0042746a:
      if (iVar3 != 0) {
        if (iVar8 != 0) {
          *(undefined4 *)(iVar8 + 0x110) = *(undefined4 *)(unaff_EBP + 8);
        }
        goto LAB_004278d9;
      }
      if (iVar8 != 0) {
        *(uint *)(iVar8 + 0x138) = *(uint *)(iVar8 + 0x138) & 0xfffffff7;
      }
      iVar3 = *(int *)(*DAT_006e486c + 0x14);
      *(int *)(unaff_EBP + -0x14) = iVar3;
      if (iVar8 != 0) {
        iStack_44c = *(undefined4 *)(iVar8 + 0x118);
        pcStack_450 = (char *)0x4274b1;
        FUN_0046d9f8();
      }
      iStack_44c = 0x40;
      iStack_454 = unaff_EBP + -0x70;
      pcStack_450 = (char *)0x0;
      uStack_458 = 0x4274c1;
      FUN_0046f824();
      iStack_44c = 0xffffffff;
      pcStack_450 = s_evict_lot_006c26d0;
      *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066651c;
      iStack_454 = 0x4274d7;
      FUN_0046f847();
      pcStack_450 = (char *)(unaff_EBP + -0x7c);
      iStack_44c = 0;
      iStack_454 = 0x4274e4;
      FUN_00444781();
      iVar3 = *(int *)(iVar3 + 0x30);
      while (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar3 + 0xe0);
        pcStack_450 = (char *)0x427501;
        iStack_44c = iVar3;
        FUN_0043270d();
        if (*(int *)(unaff_EBP + -0x3c) == 0) {
          iStack_44c = 0x42750e;
          cVar2 = FUN_0043557a();
          if (cVar2 == '\0') {
            if (*(int *)(unaff_EBP + 0xc) != 0) {
              iStack_44c = 0x42751f;
              cVar2 = FUN_00432644();
              if (((cVar2 == '\0') &&
                  (*(short *)(*(int *)(*(int *)(iVar3 + 0x11c) + 0x60) + 0x54) == 0)) ||
                 (((*(byte *)(iVar3 + 0xa0) & 0x10) == 0 &&
                  ((*(byte *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x30 + *(char *)(iVar3 + 0xfe) * 4)
                                               + 0xc) + *(char *)(iVar3 + 0xfc) * 4) +
                             (int)*(char *)(iVar3 + 0xfd)) & 0x20) == 0)))) goto LAB_00427560;
            }
          }
          else {
LAB_00427560:
            iStack_44c = CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0xf0));
            iVar3 = *(int *)(unaff_EBP + -0x14);
            pcStack_450 = (char *)0x427572;
            FUN_0044127f();
            *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar3 + 0x30);
          }
        }
        iVar3 = *(int *)(unaff_EBP + -0x10);
      }
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        puVar9 = (undefined4 *)(unaff_EBP + -0x5c);
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 1;
        do {
          iVar3 = *(int *)(iVar6 + 0x10);
          *(undefined4 *)(unaff_EBP + -0x18) = 1;
          if (1 < iVar3 + -1) {
            do {
              iStack_44c = 1;
              *(undefined4 *)(unaff_EBP + -0x14) = 1;
              if (1 < iVar3 + -1) {
                iVar8 = (int)*(char *)(unaff_EBP + -0x1c);
                iVar3 = (int)*(char *)(unaff_EBP + -0x18);
                *(int *)(unaff_EBP + -0x20) = iVar8;
                *(int *)(unaff_EBP + -0x2c) = iVar3;
                do {
                  *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + -0x18);
                  *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x14);
                  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x1c);
                  iVar1 = *(int *)(iVar6 + 0x30 + iVar8 * 4);
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  iVar4 = *(char *)(unaff_EBP + -0x14) * 4;
                  if ((*(byte *)(*(int *)(*(int *)(iVar1 + 0xc) + iVar4) + iVar3) & 0x20) == 0) {
                    iVar8 = *(int *)(iVar6 + 0x20 + iVar8 * 4);
                    *(undefined4 **)(unaff_EBP + -0x30) = auStack_474;
                    *(undefined2 *)(*(int *)(*(int *)(iVar8 + 0xc) + iVar4) + iVar3 * 2) = 0;
                    puVar9 = (undefined4 *)(unaff_EBP + -0x5c);
                    puVar10 = auStack_474;
                    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
                      *puVar10 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar10 = puVar10 + 1;
                    }
                    FUN_00479954(unaff_EBP + -0x10);
                    iVar3 = *(int *)(unaff_EBP + -0x2c);
                    iVar8 = *(int *)(unaff_EBP + -0x20);
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  iVar1 = *(int *)(iVar6 + 0x10);
                  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                } while (*(int *)(unaff_EBP + -0x14) < iVar1 + -1);
              }
              iVar3 = *(int *)(iVar6 + 0x10);
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
            } while (*(int *)(unaff_EBP + -0x18) < iVar3 + -1);
          }
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        } while (*(int *)(unaff_EBP + -0x1c) < 3);
        iStack_44c = 0x427659;
        FUN_004790b4();
        iStack_44c = 0x427660;
        FUN_00461b8d();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        iVar8 = *(int *)(unaff_EBP + -0x28);
      }
      if (iVar8 != 0) {
        iStack_44c = 0x427678;
        uVar5 = FUN_0046d9e5();
        *(undefined4 *)(iVar8 + 0x118) = uVar5;
      }
      iStack_44c = 0;
      pcStack_450 = (char *)0x42768d;
      FUN_0046d9f8();
      iStack_44c = 0;
      pcStack_450 = (char *)0x1a;
      iStack_454 = 0x42769f;
      FUN_0046dae0();
      iStack_44c = 0x4276ac;
      FUN_0046da96();
      iStack_44c = 0x4276b8;
      FUN_004165e9();
      if (iVar8 != 0) {
        iStack_44c = 0x4276c3;
        uVar5 = FUN_00410304();
        *(undefined4 *)(iVar8 + 0x118) = uVar5;
        *(undefined4 *)(iVar8 + 0x11c) = 0;
      }
      iStack_44c = 0;
      pcStack_450 = (char *)0x91;
      iStack_454 = 0x4276da;
      FUN_0040766a();
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        do {
          piVar7 = *(int **)(*(int *)(unaff_EBP + -0x24) + 0x148);
          while( true ) {
            if (piVar7 == *(int **)(*(int *)(unaff_EBP + -0x24) + 0x14c)) goto LAB_0042771d;
            if ((*piVar7 != 0) && ((int)*(short *)(*piVar7 + 0xfa) == *(int *)(unaff_EBP + 8)))
            break;
            piVar7 = piVar7 + 1;
          }
          iStack_44c = *piVar7;
          pcStack_450 = (char *)0x427714;
          iVar6 = FUN_00427017();
        } while (iVar6 == 0);
      }
LAB_0042771d:
      iStack_44c = 1;
      pcStack_450 = (char *)0x427724;
      FUN_004a695b();
      iStack_44c = 0x42772c;
      iVar6 = FUN_004286d1();
      *(int *)(unaff_EBP + -0x20) = iVar6;
      if ((iVar6 == 0) || (iVar8 == 0)) {
        iVar6 = *(int *)(unaff_EBP + 8);
      }
      else {
        iVar6 = *(int *)(unaff_EBP + 8);
        *(int *)(iVar8 + 0x110) = iVar6;
      }
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        iStack_44c = 0x104;
        iStack_454 = unaff_EBP + -0x1f8;
        pcStack_450 = (char *)0x0;
        uStack_458 = 0x427766;
        FUN_0046f824();
        piVar7 = DAT_006e486c;
        *(undefined ***)(unaff_EBP + -0x204) = &PTR_FUN_006664e8;
        iStack_44c = unaff_EBP + -0x204;
        pcStack_450 = (char *)piVar7[9];
        iStack_454 = 0x427785;
        FUN_00412122();
        if ((iVar6 < 0x15) || (0x1e < iVar6)) {
          if ((0x27 < iVar6) && (iVar6 < 0x31)) {
            pcStack_450 = s_Houses_VIDesc_iff_006c26a8;
            goto LAB_0042780a;
          }
          if (iVar6 == 0) {
LAB_004277dd:
            pcStack_450 = s_Houses_NeighborhoodDesc_iff_006c268c;
            goto LAB_0042780a;
          }
          for (piVar7 = *(int **)(DAT_006e486c[9] + 0x174);
              piVar7 != *(int **)(DAT_006e486c[9] + 0x178); piVar7 = piVar7 + 2) {
            if (*piVar7 == iVar6) {
              iVar3 = piVar7[1];
              goto LAB_004277d9;
            }
          }
          iVar3 = 0;
LAB_004277d9:
          if (iVar3 != 0) goto LAB_004277dd;
          if ((0x50 < iVar6) && (iVar6 < 0x5a)) {
            pcStack_450 = s_Houses_STDesc_iff_006c2678;
            goto LAB_0042780a;
          }
          if ((0x59 < iVar6) && (iVar6 < 100)) {
            pcStack_450 = s_Houses_MTDesc_iff_006c2664;
            goto LAB_0042780a;
          }
        }
        else {
          pcStack_450 = s_Houses_DTDesc_iff_006c26bc;
LAB_0042780a:
          iStack_44c = 0xffffffff;
          iStack_454 = 0x427815;
          FUN_0046f847();
        }
        iStack_44c = 0x427820;
        FUN_0046f5cd();
        pcStack_450 = (char *)(unaff_EBP + -0x204);
        iStack_44c = 1;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        iStack_454 = 0x42783a;
        iVar3 = FUN_0046f71c();
        iStack_44c = 0x427847;
        FUN_004706f0();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (iVar3 == 0) {
          iStack_44c = 1;
          iStack_454 = unaff_EBP + -0x448;
          uStack_458 = 0x42786a;
          pcStack_450 = (char *)(iVar6 + 2000);
          iVar3 = FUN_00470d31();
          if (iVar3 == 0) {
            iStack_44c = 0xffffffff;
            pcStack_450 = &DAT_006de560;
            iStack_454 = 1;
            uStack_458 = 0x427883;
            FUN_0047132c();
            iStack_44c = 0xffffffff;
            pcStack_450 = &DAT_006de560;
            iStack_454 = 2;
            uStack_458 = 0x427892;
            FUN_0047132c();
          }
          pcStack_450 = (char *)(unaff_EBP + -0x448);
          iStack_454 = 0x4278a5;
          iStack_44c = iVar6 + 2000;
          FUN_00470757();
          iStack_44c = 0x4278b0;
          FUN_0046b7ee();
        }
        *(undefined1 *)(unaff_EBP + -4) = 2;
        iStack_44c = 0x4278bf;
        FUN_004712d0();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        iStack_44c = 0x4278ce;
        FUN_0046b2e6();
      }
      iStack_44c = 0x4278d6;
      FUN_0042888d();
      iVar3 = *(int *)(unaff_EBP + -0x20);
      goto LAB_004278d9;
    }
  }
  iVar3 = -1;
LAB_004278d9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

