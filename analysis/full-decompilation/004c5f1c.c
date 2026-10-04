
int FUN_004c5f1c(void)

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int extraout_ECX;
  uint uVar8;
  uint uVar9;
  int unaff_EBP;
  int iVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  undefined4 auStack_c0 [5];
  undefined4 uStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  int *piStack_9c;
  
  FUN_00634c24();
  piStack_9c = *(int **)(extraout_ECX + 0x18);
  piVar1 = (int *)(extraout_ECX + 0x18);
  uStack_a0 = 0x4c5f43;
  FUN_004a17d3();
  if (*(int *)(unaff_EBP + 0x10) < 0x3f) {
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    piStack_9c = (int *)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uStack_a0 = 0x4c5f8b;
    FUN_004a1873();
    *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0x38;
    piStack_9c = (int *)0x0;
    uStack_a0 = 0x57414c6d;
    *(undefined4 *)(unaff_EBP + -0x10) = 0x57414c6d;
    uStack_a4 = *(undefined4 *)(unaff_EBP + 8);
    iStack_a8 = unaff_EBP + -0x14;
    uStack_ac = 0x4c5fab;
    iVar4 = FUN_004a22ca();
    *(int *)(unaff_EBP + 8) = iVar4;
    if (iVar4 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004a1740();
      iVar4 = *(int *)(unaff_EBP + 8);
      goto LAB_004c623e;
    }
    uStack_a0 = 0x4c5fd3;
    piStack_9c = piVar1;
    FUN_004a1c86();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004a1740();
  }
  else {
    piStack_9c = (int *)0x1;
    uStack_a0 = 0x57414c6d;
    *(undefined4 *)(unaff_EBP + -0x10) = 0x57414c6d;
    uStack_a4 = *(undefined4 *)(unaff_EBP + 8);
    iStack_a8 = unaff_EBP + -0x14;
    *(int **)(unaff_EBP + -0x14) = piVar1;
    uStack_ac = 0x4c5f67;
    iVar4 = FUN_004a2273();
    if (iVar4 != 0) goto LAB_004c623e;
  }
  piStack_9c = (int *)0x4c5feb;
  puVar5 = operator_new(0x1fffe);
  *(undefined4 **)(unaff_EBP + 0x10) = puVar5;
  for (iVar4 = 0x7fff; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0xffff;
  for (iVar4 = *piVar1; iVar4 != *(int *)(extraout_ECX + 0x1c); iVar4 = iVar4 + 0x11c) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    for (iVar10 = *(int *)(extraout_ECX + 0x24); iVar10 != *(int *)(extraout_ECX + 0x28);
        iVar10 = iVar10 + 8) {
      piStack_9c = (int *)0x4c601c;
      cVar2 = FUN_004a1f53();
      if (cVar2 != '\0') {
        *(int *)(unaff_EBP + 8) = iVar10 - *(int *)(extraout_ECX + 0x24) >> 3;
        break;
      }
    }
    for (puVar11 = *(ushort **)(iVar4 + 0x110); puVar11 != *(ushort **)(iVar4 + 0x114);
        puVar11 = puVar11 + 4) {
      if (*(int *)(unaff_EBP + 8) != 0) {
        piStack_9c = *(int **)(unaff_EBP + 8);
        uStack_a0 = 0x4c6051;
        uVar3 = FUN_004c5d4e();
        *(undefined2 *)(*(int *)(unaff_EBP + 0x10) + (uint)*puVar11 * 2) = uVar3;
      }
      if (*(short *)(*(int *)(unaff_EBP + 0x10) + (uint)*puVar11 * 2) == -1) {
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(puVar11 + 2);
        piStack_9c = (int *)0x4c607a;
        uVar3 = FUN_004c5cad();
        iVar10 = *(int *)(unaff_EBP + 0x10);
        *(undefined2 *)(iVar10 + (uint)*puVar11 * 2) = uVar3;
        if (*(short *)(iVar10 + (uint)*puVar11 * 2) == -1) {
          *(undefined2 *)(iVar10 + (uint)*puVar11 * 2) = 1;
        }
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x10);
  puVar5 = (undefined4 *)(unaff_EBP + -0x68);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x1c) = 1;
  do {
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    if (0 < *(int *)(unaff_EBP + -0x2c)) {
      do {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        do {
          *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(unaff_EBP + -0x28);
          *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + -0x1c);
          piStack_9c = (int *)(unaff_EBP + -0x94);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          uStack_a0 = 0x4c60fe;
          puVar5 = (undefined4 *)FUN_00479737();
          *(undefined1 *)(unaff_EBP + 0xb) = 0;
          uVar9 = 0;
          puVar12 = (undefined4 *)(unaff_EBP + -0x68);
          for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar12 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar12 = puVar12 + 1;
          }
          if ((*(int *)(unaff_EBP + -0x68) != 0) &&
             (uVar9 = 1, ((byte)*(undefined4 *)(unaff_EBP + -0x68) & 1) != 1)) {
            do {
              uVar9 = uVar9 * 2;
            } while ((uVar9 & *(uint *)(unaff_EBP + -0x68)) != uVar9);
          }
          if (uVar9 != 0) {
            do {
              uVar6 = 1;
              if (uVar9 == 0x10) {
                *(undefined4 *)(unaff_EBP + -0x10) = 4;
                uVar6 = 2;
                *(undefined4 *)(unaff_EBP + -0x14) = 2;
              }
              else if (uVar9 == 0x20) {
                *(undefined4 *)(unaff_EBP + -0x14) = 1;
                *(undefined4 *)(unaff_EBP + -0x10) = 3;
                uVar6 = 2;
              }
              else {
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
              }
              *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
              do {
                uStack_a0 = 0x4c6175;
                piStack_9c = (int *)uVar9;
                uVar7 = FUN_00467e89();
                if ((((0x1e < (int)uVar7) && ((int)uVar7 < 0xf8)) ||
                    ((0xff < (int)uVar7 && ((int)uVar7 < 0xffff)))) &&
                   (uVar8 = (uint)*(ushort *)(*(int *)(unaff_EBP + 0x10) + uVar7 * 2),
                   uVar8 != uVar7)) {
                  uStack_a4 = 0x4c61a5;
                  uStack_a0 = uVar8;
                  piStack_9c = (int *)uVar9;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
                piVar1 = (int *)(unaff_EBP + -0x18);
                *piVar1 = *piVar1 + -1;
              } while (*piVar1 != 0);
              do {
                uVar9 = uVar9 * 2;
                if ((uVar9 & *(uint *)(unaff_EBP + -0x68)) == uVar9) break;
              } while ((int)uVar9 < 0x20);
            } while (((int)uVar9 < 0x20) && (uVar9 != 0));
            if (*(char *)(unaff_EBP + 0xb) != '\0') {
              *(undefined4 **)(unaff_EBP + 8) = auStack_c0;
              puVar5 = (undefined4 *)(unaff_EBP + -0x68);
              puVar12 = auStack_c0;
              for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar12 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar12 = puVar12 + 1;
              }
              FUN_00479954(unaff_EBP + -0x20);
            }
          }
          if ((*(byte *)(unaff_EBP + -0x40) & 0x10) != 0) {
            puVar5 = (undefined4 *)(unaff_EBP + -0x68);
            for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
          }
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
          *(undefined1 *)(unaff_EBP + -4) = 1;
        } while (*(int *)(unaff_EBP + -0x24) < *(int *)(unaff_EBP + -0x2c));
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
      } while (*(int *)(unaff_EBP + -0x28) < *(int *)(unaff_EBP + -0x2c));
    }
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
  } while (*(int *)(unaff_EBP + -0x1c) < 3);
  piStack_9c = (int *)0x4c623b;
  FUN_006321f0();
  iVar4 = 0;
LAB_004c623e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

