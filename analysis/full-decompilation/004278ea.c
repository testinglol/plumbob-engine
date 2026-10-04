
undefined4 FUN_004278ea(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int extraout_ECX;
  int unaff_EBP;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 auStack_a4 [7];
  undefined4 uStack_88;
  int iStack_84;
  char *pcStack_80;
  int iStack_7c;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x28) = extraout_ECX;
  if (*(int *)(extraout_ECX + 0x164) == 0) {
    iStack_7c = *(undefined4 *)(unaff_EBP + 8);
    pcStack_80 = (char *)0x427911;
    iVar4 = FUN_00425ddf();
    if (iVar4 != 0) {
      iVar4 = *(int *)(iVar4 + 0x10c);
      iStack_7c = 0xffffffff;
      pcStack_80 = *(char **)(unaff_EBP + 8);
      iStack_84 = 0x42792f;
      FUN_0042808b();
      iStack_7c = 0;
      pcStack_80 = (char *)0x9;
      iVar1 = *(int *)(*DAT_006e486c + 0x1c);
      iStack_84 = 0x427945;
      FUN_0046dae0();
      for (piVar7 = *(int **)(extraout_ECX + 0x154); piVar7 != *(int **)(extraout_ECX + 0x158);
          piVar7 = piVar7 + 1) {
        if (*(int *)(*piVar7 + 0x10c) == iVar4) {
          iVar4 = *piVar7;
          goto LAB_0042796a;
        }
      }
      iVar4 = 0;
LAB_0042796a:
      *(undefined4 *)(iVar4 + 0x13c) = 0;
      if (iVar4 != 0) {
        *(uint *)(iVar4 + 0x138) = *(uint *)(iVar4 + 0x138) & 0xfffffff7;
      }
      iStack_7c = DAT_006e486c[0x11];
      pcStack_80 = (char *)0x42798b;
      FUN_00425316();
      iStack_7c = 0x40;
      pcStack_80 = (char *)0x0;
      iVar4 = *(int *)(*DAT_006e486c + 0x14);
      iStack_84 = unaff_EBP + -0x6c;
      uStack_88 = 0x4279a5;
      FUN_0046f824();
      iStack_7c = 0xffffffff;
      pcStack_80 = s_evict_lot_006c26d0;
      *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066651c;
      iStack_84 = 0x4279bb;
      FUN_0046f847();
      pcStack_80 = (char *)(unaff_EBP + -0x78);
      iStack_7c = 0;
      iStack_84 = 0x4279c8;
      FUN_00444781();
      iStack_7c = *(int *)(iVar4 + 0x30);
      *(int *)(unaff_EBP + -0x18) = iStack_7c;
      if (iStack_7c != 0) {
        while( true ) {
          *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iStack_7c + 0xe0);
          pcStack_80 = (char *)0x4279e9;
          FUN_0043270d();
          if ((*(int *)(unaff_EBP + -0x38) == 0) &&
             (iVar8 = *(int *)(unaff_EBP + -0x18), *(short *)(*(int *)(iVar8 + 0x118) + 0x12) == 2))
          {
            iStack_7c = CONCAT22((short)((uint)iVar8 >> 0x10),*(undefined2 *)(iVar8 + 0xf0));
            pcStack_80 = (char *)0x427a0e;
            FUN_0044127f();
            iVar8 = *(int *)(iVar4 + 0x30);
          }
          else {
            iVar8 = *(int *)(unaff_EBP + -0x14);
          }
          *(int *)(unaff_EBP + -0x18) = iVar8;
          if (iVar8 == 0) break;
          iStack_7c = *(int *)(unaff_EBP + -0x18);
        }
      }
      iVar8 = extraout_ECX;
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        iVar8 = *(int *)(iVar4 + 0x30);
        while (iVar8 != 0) {
          *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar8 + 0xe0);
          pcStack_80 = (char *)0x427a40;
          iStack_7c = iVar8;
          FUN_0043270d();
          if (*(int *)(unaff_EBP + -0x38) == 0) {
            iStack_7c = 0x427a4d;
            cVar3 = FUN_0043557a();
            if (cVar3 == '\0') {
              iStack_7c = 0x427a58;
              cVar3 = FUN_00432644();
              if ((cVar3 != '\0') &&
                 (((*(byte *)(iVar8 + 0xa0) & 0x10) != 0 ||
                  ((*(byte *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x30 + *(char *)(iVar8 + 0xfe) * 4)
                                               + 0xc) + *(char *)(iVar8 + 0xfc) * 4) +
                             (int)*(char *)(iVar8 + 0xfd)) & 0x20) != 0)))) goto LAB_00427a9e;
            }
            iStack_7c = CONCAT22((short)((uint)iVar8 >> 0x10),*(undefined2 *)(iVar8 + 0xf0));
            pcStack_80 = (char *)0x427a98;
            FUN_0044127f();
            *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar4 + 0x30);
          }
LAB_00427a9e:
          iVar8 = *(int *)(unaff_EBP + -0x14);
        }
        puVar9 = (undefined4 *)(unaff_EBP + -0x58);
        for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 1;
        do {
          iVar4 = *(int *)(iVar1 + 0x10);
          *(undefined4 *)(unaff_EBP + -0x10) = 1;
          if (1 < iVar4 + -1) {
            do {
              iStack_7c = 1;
              *(undefined4 *)(unaff_EBP + -0x18) = 1;
              if (1 < iVar4 + -1) {
                iVar4 = (int)*(char *)(unaff_EBP + -0x14);
                iVar8 = (int)*(char *)(unaff_EBP + -0x10);
                *(int *)(unaff_EBP + -0x20) = iVar4;
                *(int *)(unaff_EBP + -0x24) = iVar8;
                do {
                  *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(unaff_EBP + -0x10);
                  *(char *)(unaff_EBP + -0x1c) = *(char *)(unaff_EBP + -0x18);
                  *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(unaff_EBP + -0x14);
                  iVar2 = *(int *)(iVar1 + 0x30 + iVar4 * 4);
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  iVar6 = *(char *)(unaff_EBP + -0x18) * 4;
                  if ((*(byte *)(*(int *)(*(int *)(iVar2 + 0xc) + iVar6) + iVar8) & 0x20) == 0) {
                    iVar4 = *(int *)(iVar1 + 0x20 + iVar4 * 4);
                    *(undefined4 **)(unaff_EBP + -0x2c) = auStack_a4;
                    *(undefined2 *)(*(int *)(*(int *)(iVar4 + 0xc) + iVar6) + iVar8 * 2) = 0;
                    puVar9 = (undefined4 *)(unaff_EBP + -0x58);
                    puVar10 = auStack_a4;
                    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar10 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar10 = puVar10 + 1;
                    }
                    FUN_00479954(unaff_EBP + -0x1c);
                    iVar4 = *(int *)(unaff_EBP + -0x20);
                    iVar8 = *(int *)(unaff_EBP + -0x24);
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  iVar2 = *(int *)(iVar1 + 0x10);
                  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
                } while (*(int *)(unaff_EBP + -0x18) < iVar2 + -1);
              }
              iVar4 = *(int *)(iVar1 + 0x10);
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            } while (*(int *)(unaff_EBP + -0x10) < iVar4 + -1);
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(int *)(unaff_EBP + -0x14) < 3);
        iStack_7c = 0x427b72;
        FUN_004790b4();
        iStack_7c = 0x427b79;
        FUN_00461b8d();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        iVar8 = *(int *)(unaff_EBP + -0x28);
      }
      iStack_7c = 0;
      pcStack_80 = (char *)0x1a;
      iStack_84 = 0x427b96;
      FUN_0046dae0();
      iStack_7c = 0x427ba3;
      FUN_0046da96();
      iStack_7c = 0x427baf;
      FUN_004165e9();
      iStack_7c = 0;
      pcStack_80 = (char *)0x91;
      iStack_84 = 0x427bbb;
      FUN_0040766a();
      if (*(int *)(unaff_EBP + 0xc) != 0) {
        do {
          piVar7 = *(int **)(iVar8 + 0x148);
          while( true ) {
            if (piVar7 == *(int **)(iVar8 + 0x14c)) goto LAB_00427bf7;
            if ((*piVar7 != 0) && ((int)*(short *)(*piVar7 + 0xfa) == *(int *)(unaff_EBP + 8)))
            break;
            piVar7 = piVar7 + 1;
          }
          iStack_7c = *piVar7;
          pcStack_80 = (char *)0x427bf3;
          iVar4 = FUN_00427017();
        } while (iVar4 == 0);
      }
LAB_00427bf7:
      iStack_7c = 1;
      pcStack_80 = (char *)0x427bfd;
      FUN_004a695b();
      iStack_7c = 0x427c05;
      uVar5 = FUN_004286d1();
      iStack_7c = 0x427c0e;
      FUN_0042888d();
      goto LAB_00427c10;
    }
  }
  uVar5 = 0xffffffff;
LAB_00427c10:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

