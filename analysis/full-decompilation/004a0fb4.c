
int FUN_004a0fb4(void)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int extraout_ECX;
  uint uVar9;
  int unaff_EBP;
  int iVar10;
  ushort *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 auStack_c4 [5];
  undefined4 uStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  int *piStack_a0;
  
  FUN_00634c24();
  piStack_a0 = *(int **)(extraout_ECX + 0x18);
  piVar12 = (int *)(extraout_ECX + 0x18);
  uStack_a4 = 0x4a0fdb;
  FUN_004a17d3();
  if (*(int *)(unaff_EBP + 0x10) < 0x3f) {
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    piStack_a0 = (int *)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uStack_a4 = 0x4a1023;
    FUN_004a1873();
    *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x38;
    piStack_a0 = (int *)0x0;
    uStack_a4 = 0x464c526d;
    *(undefined4 *)(unaff_EBP + -0x18) = 0x464c526d;
    uStack_a8 = *(undefined4 *)(unaff_EBP + 8);
    iStack_ac = unaff_EBP + -0x1c;
    uStack_b0 = 0x4a1043;
    iVar6 = FUN_004a22ca();
    *(int *)(unaff_EBP + 8) = iVar6;
    if (iVar6 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004a1740();
      iVar6 = *(int *)(unaff_EBP + 8);
      goto LAB_004a1345;
    }
    uStack_a4 = 0x4a106b;
    piStack_a0 = piVar12;
    FUN_004a1c86();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004a1740();
  }
  else {
    piStack_a0 = (int *)0x1;
    uStack_a4 = 0x464c526d;
    *(undefined4 *)(unaff_EBP + -0x18) = 0x464c526d;
    uStack_a8 = *(undefined4 *)(unaff_EBP + 8);
    iStack_ac = unaff_EBP + -0x1c;
    *(int **)(unaff_EBP + -0x1c) = piVar12;
    uStack_b0 = 0x4a0fff;
    iVar6 = FUN_004a2273();
    if (iVar6 != 0) goto LAB_004a1345;
  }
  piStack_a0 = (int *)0x4a1083;
  puVar7 = operator_new(0x1fffe);
  *(undefined4 **)(unaff_EBP + 0x10) = puVar7;
  for (iVar6 = 0x7fff; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xffffffff;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0xffff;
  for (iVar6 = *piVar12; iVar6 != *(int *)(extraout_ECX + 0x1c); iVar6 = iVar6 + 0x11c) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    for (iVar10 = *(int *)(extraout_ECX + 0x24); iVar10 != *(int *)(extraout_ECX + 0x28);
        iVar10 = iVar10 + 8) {
      piStack_a0 = (int *)0x4a10b4;
      cVar4 = FUN_004a1f53();
      if (cVar4 != '\0') {
        *(int *)(unaff_EBP + 8) = iVar10 - *(int *)(extraout_ECX + 0x24) >> 3;
        break;
      }
    }
    for (puVar11 = *(ushort **)(iVar6 + 0x110); puVar11 != *(ushort **)(iVar6 + 0x114);
        puVar11 = puVar11 + 4) {
      if (*(int *)(unaff_EBP + 8) != 0) {
        piStack_a0 = (int *)(uint)puVar11[1];
        uStack_a4 = *(undefined4 *)(unaff_EBP + 8);
        uStack_a8 = 0x4a10eb;
        uVar5 = FUN_004a0dfb();
        *(undefined2 *)(*(int *)(unaff_EBP + 0x10) + (uint)*puVar11 * 2) = uVar5;
      }
      if (*(short *)(*(int *)(unaff_EBP + 0x10) + (uint)*puVar11 * 2) == -1) {
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(puVar11 + 2);
        piStack_a0 = (int *)(unaff_EBP + -0x20);
        uStack_a4 = 0x4a1116;
        uVar5 = FUN_004a0d36();
        iVar10 = *(int *)(unaff_EBP + 0x10);
        *(undefined2 *)(iVar10 + (uint)*puVar11 * 2) = uVar5;
        if (*(short *)(iVar10 + (uint)*puVar11 * 2) == -1) {
          *(undefined2 *)(iVar10 + (uint)*puVar11 * 2) = 1;
        }
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x10);
  puVar7 = (undefined4 *)(unaff_EBP + -0x6c);
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  do {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (0 < *(int *)(unaff_EBP + -0x2c)) {
LAB_004a116d:
      iVar6 = (int)*(char *)(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(int *)(unaff_EBP + -0x3c) = iVar6;
      iVar10 = *(char *)(unaff_EBP + -0x14) * 2;
      do {
        *(undefined1 *)(unaff_EBP + -0x23) = *(undefined1 *)(unaff_EBP + -0x14);
        *(char *)(unaff_EBP + -0x24) = *(char *)(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -0x22) = *(undefined1 *)(unaff_EBP + -0x10);
        iVar3 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x20 + iVar6 * 4);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        iVar8 = *(char *)(unaff_EBP + -0x28) * 4;
        uVar9 = (uint)*(ushort *)(*(int *)(*(int *)(iVar3 + 0xc) + iVar8) + iVar10);
        if (((uVar9 < 0x1e) || (0xfe < uVar9)) && ((uVar9 < 0x100 || (0xfffe < uVar9)))) {
          if (uVar9 != 0xff) goto LAB_004a12fb;
          piStack_a0 = (int *)(unaff_EBP + -0x98);
          uStack_a4 = 0x4a1214;
          puVar7 = (undefined4 *)FUN_00479737();
          puVar13 = (undefined4 *)(unaff_EBP + -0x6c);
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar13 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar13 = puVar13 + 1;
          }
          if ((*(byte *)(unaff_EBP + -0x6c) & 0x30) != 0) {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
            uVar9 = 0;
            if ((*(int *)(unaff_EBP + -0x6c) != 0) &&
               (uVar9 = 1, ((byte)*(undefined4 *)(unaff_EBP + -0x6c) & 1) != 1)) {
              do {
                uVar9 = uVar9 * 2;
              } while ((uVar9 & *(uint *)(unaff_EBP + -0x6c)) != uVar9);
            }
            if (uVar9 == 0x10) {
              *(undefined4 *)(unaff_EBP + -0x1c) = 2;
              *(undefined4 *)(unaff_EBP + -0x18) = 4;
            }
            else {
              if (uVar9 != 0x20) goto LAB_004a130b;
              *(undefined4 *)(unaff_EBP + -0x1c) = 1;
              *(undefined4 *)(unaff_EBP + -0x18) = 3;
            }
            piVar12 = (int *)(unaff_EBP + -0x1c);
            *(undefined4 *)(unaff_EBP + -0x20) = 2;
            do {
              iVar6 = *piVar12;
              if ((iVar6 == 2) || (uVar2 = *(ushort *)(unaff_EBP + -0x58), iVar6 == 1)) {
                uVar2 = *(ushort *)(unaff_EBP + -100);
              }
              uVar9 = (uint)uVar2;
              if ((((0x1d < uVar9) && (uVar9 < 0xff)) || ((0xff < uVar9 && (uVar9 < 0xffff)))) &&
                 (uVar2 = *(ushort *)(*(int *)(unaff_EBP + 0x10) + uVar9 * 2), uVar2 != uVar9)) {
                if ((iVar6 == 2) || (iVar6 == 1)) {
                  *(ushort *)(unaff_EBP + -100) = uVar2;
                }
                else {
                  *(ushort *)(unaff_EBP + -0x58) = uVar2;
                }
                *(uint *)(unaff_EBP + -0x44) = *(uint *)(unaff_EBP + -0x44) | 0x10;
                *(undefined1 *)(unaff_EBP + 0xb) = 1;
              }
              piVar12 = piVar12 + 1;
              piVar1 = (int *)(unaff_EBP + -0x20);
              *piVar1 = *piVar1 + -1;
            } while (*piVar1 != 0);
            if (*(char *)(unaff_EBP + 0xb) != '\0') {
              *(undefined4 **)(unaff_EBP + 8) = auStack_c4;
              puVar7 = (undefined4 *)(unaff_EBP + -0x6c);
              puVar13 = auStack_c4;
              for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar13 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar13 = puVar13 + 1;
              }
              FUN_00479954(unaff_EBP + -0x24);
            }
            goto LAB_004a12fb;
          }
        }
        else {
          uVar2 = *(ushort *)(*(int *)(unaff_EBP + 0x10) + uVar9 * 2);
          if (uVar2 != uVar9) {
            *(ushort *)
             (*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + 0xc) + 0x20 + iVar6 * 4) + 0xc) +
                      iVar8) + iVar10) = uVar2;
          }
LAB_004a12fb:
          if ((*(byte *)(unaff_EBP + -0x44) & 0x10) != 0) {
            puVar7 = (undefined4 *)(unaff_EBP + -0x6c);
            for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar7 = 0;
              puVar7 = puVar7 + 1;
            }
          }
        }
LAB_004a130b:
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (*(int *)(unaff_EBP + -0x2c) <= *(int *)(unaff_EBP + -0x28)) goto code_r0x004a131e;
        iVar6 = *(int *)(unaff_EBP + -0x3c);
      } while( true );
    }
LAB_004a132d:
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 3);
  piStack_a0 = (int *)0x4a1342;
  FUN_006321f0();
  iVar6 = 0;
LAB_004a1345:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
code_r0x004a131e:
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
  if (*(int *)(unaff_EBP + -0x2c) <= *(int *)(unaff_EBP + -0x14)) goto LAB_004a132d;
  goto LAB_004a116d;
}

