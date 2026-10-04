
void FUN_004682e5(void)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  short *extraout_ECX;
  int iVar9;
  int iVar10;
  char cVar11;
  int unaff_EBP;
  short *psVar12;
  int iVar13;
  undefined8 uVar14;
  int iStack_a8;
  undefined1 *puStack_a4;
  
  FUN_00634c24();
  iVar9 = *(int *)(DAT_006e486c + 4);
  *(int *)(unaff_EBP + -0x3c) = iVar9;
  *(int *)(unaff_EBP + -0x2c) = *(int *)(iVar9 + 0x58) / 2;
  psVar12 = extraout_ECX + 0x40;
  for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
    psVar12[0] = 0;
    psVar12[1] = 0;
    psVar12 = psVar12 + 2;
  }
  puStack_a4 = (undefined1 *)0x468326;
  cVar4 = FUN_00468851();
  if (cVar4 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x48) = 0x7fffffff;
    *(undefined4 *)(unaff_EBP + -0x44) = 0x80000000;
    *(undefined4 *)(unaff_EBP + -0x40) = 0x80000000;
    puVar6 = *(undefined1 **)(extraout_ECX + 2);
    puVar2 = *(undefined1 **)(extraout_ECX + 4);
    *(undefined1 **)(unaff_EBP + -0x30) = puVar6;
    iVar9 = DAT_006e54d8;
    if (puVar6 != puVar2) {
      while( true ) {
        *(undefined1 *)(unaff_EBP + -0x10) = *puVar6;
        uVar5 = puVar6[2];
        *(undefined1 *)(unaff_EBP + -0xf) = puVar6[1];
        *(undefined1 *)(unaff_EBP + -0xe) = uVar5;
        puStack_a4 = *(undefined1 **)(iVar9 + 0x84);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iStack_a8 = 0x46837d;
        FUN_00434ffd();
        puStack_a4 = (undefined1 *)0x20;
        *(int **)(unaff_EBP + -0x14) = &iStack_a8;
        FUN_00461b74(unaff_EBP + -0x10);
        uVar5 = FUN_004687d9();
        *(undefined1 *)(unaff_EBP + -0x15) = uVar5;
        puVar1 = (uint *)(extraout_ECX + *(char *)(unaff_EBP + -0xf) * 4 + 0x40);
        puStack_a4 = (undefined1 *)0x4683b5;
        uVar14 = __allshl();
        *puVar1 = *puVar1 | (uint)uVar14;
        puVar1[1] = puVar1[1] | (uint)((ulonglong)uVar14 >> 0x20);
        puStack_a4 = (undefined1 *)0x0;
        iStack_a8 = DAT_006f0088;
        FUN_004a9e60(unaff_EBP + -0x68,(int)*(char *)(unaff_EBP + -0x10),
                     (int)*(char *)(unaff_EBP + -0xf),(int)*(char *)(unaff_EBP + -0xe));
        iVar9 = *(int *)(unaff_EBP + -0x2c);
        iVar13 = (*(short *)(unaff_EBP + -0x66) - iVar9) + 1;
        *(int *)(unaff_EBP + -0x20) = *(short *)(unaff_EBP + -0x66) + -2 + iVar9;
        *(int *)(unaff_EBP + -0x28) = iVar13;
        *(int *)(unaff_EBP + -0x24) = *(short *)(unaff_EBP + -0x68) + 1;
        *(int *)(unaff_EBP + -0x1c) = *(short *)(unaff_EBP + -0x68) + -2 + iVar9;
        iVar9 = DAT_006e54d8;
        if (*(char *)(unaff_EBP + -0x15) != '\0') {
          puStack_a4 = (undefined1 *)(unaff_EBP + -100);
          iStack_a8 = unaff_EBP + -0x60;
          FUN_004672d0(*(undefined4 *)(unaff_EBP + -0x30),unaff_EBP + -0x6c,unaff_EBP + -0x70);
          iVar9 = DAT_006e54d8;
          if (*(int *)(unaff_EBP + -0x60) == 0) {
            iVar7 = 0;
          }
          else {
            iVar7 = ((*(int *)(unaff_EBP + -0x60) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) + 1;
          }
          *(int *)(unaff_EBP + -0x60) = iVar7;
          if (*(int *)(unaff_EBP + -100) == 0) {
            iVar10 = 0;
          }
          else {
            iVar10 = ((*(int *)(unaff_EBP + -100) - *(int *)(iVar9 + 0x84)) - 1U & 3) + 1;
          }
          *(int *)(unaff_EBP + -100) = iVar10;
          if (((*(short **)(unaff_EBP + -0x6c) != (short *)0x0) &&
              (**(short **)(unaff_EBP + -0x6c) == *extraout_ECX)) ||
             ((*(short **)(unaff_EBP + -0x70) != (short *)0x0 &&
              (iVar7 = iVar10, **(short **)(unaff_EBP + -0x70) == *extraout_ECX)))) {
            if (iVar7 == 1) {
              *(int *)(unaff_EBP + -0x20) =
                   *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x2c);
            }
            else if (iVar7 == 3) {
              iVar13 = iVar13 + *(int *)(unaff_EBP + -0x2c);
              *(int *)(unaff_EBP + -0x28) = iVar13;
            }
          }
        }
        puVar8 = (undefined4 *)(unaff_EBP + -0x28);
        if (*(int *)(unaff_EBP + -0x4c) <= iVar13) {
          puVar8 = (undefined4 *)(unaff_EBP + -0x4c);
        }
        *(undefined4 *)(unaff_EBP + -0x4c) = *puVar8;
        puVar8 = (undefined4 *)(unaff_EBP + -0x24);
        if (*(int *)(unaff_EBP + -0x48) <= *(int *)(unaff_EBP + -0x24)) {
          puVar8 = (undefined4 *)(unaff_EBP + -0x48);
        }
        *(undefined4 *)(unaff_EBP + -0x48) = *puVar8;
        puVar8 = (undefined4 *)(unaff_EBP + -0x20);
        if (*(int *)(unaff_EBP + -0x20) <= *(int *)(unaff_EBP + -0x44)) {
          puVar8 = (undefined4 *)(unaff_EBP + -0x44);
        }
        *(undefined4 *)(unaff_EBP + -0x44) = *puVar8;
        puVar8 = (undefined4 *)(unaff_EBP + -0x1c);
        if (*(int *)(unaff_EBP + -0x1c) <= *(int *)(unaff_EBP + -0x40)) {
          puVar8 = (undefined4 *)(unaff_EBP + -0x40);
        }
        uVar3 = *puVar8;
        *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + DAT_006e4820;
        *(undefined4 *)(unaff_EBP + -0x40) = uVar3;
        *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + DAT_006e481f;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        while( true ) {
          if (((((int)*(char *)(unaff_EBP + -0x10) < *(int *)(iVar9 + 0x70) + 1) ||
               (*(int *)(iVar9 + 0x74) + -1 < (int)*(char *)(unaff_EBP + -0x10))) ||
              (iVar13 = (int)*(char *)(unaff_EBP + -0xf), iVar13 < *(int *)(iVar9 + 0x78) + 1)) ||
             (*(int *)(iVar9 + 0x7c) + -1 < iVar13)) {
            *(undefined4 *)(unaff_EBP + -0x14) = 1;
          }
          else {
            puStack_a4 = (undefined1 *)0x46854d;
            uVar14 = __allshl();
            if ((*(uint *)(extraout_ECX + iVar13 * 4 + 0x40) & (uint)uVar14) == 0 &&
                (*(uint *)(extraout_ECX + iVar13 * 4 + 0x42) & (uint)((ulonglong)uVar14 >> 0x20)) ==
                0) {
              puStack_a4 = (undefined1 *)(unaff_EBP + -0x10);
              iStack_a8 = unaff_EBP + -0x80;
              puVar8 = (undefined4 *)FUN_004ac469();
              *(undefined4 *)(unaff_EBP + -0x5c) = *puVar8;
              *(undefined4 *)(unaff_EBP + -0x58) = puVar8[1];
              *(undefined4 *)(unaff_EBP + -0x54) = puVar8[2];
              *(undefined4 *)(unaff_EBP + -0x50) = puVar8[3];
              iVar9 = DAT_006e54d8;
              if (-1 < (int)((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x58)) - 1U |
                             (*(int *)(unaff_EBP + -0x50) - *(int *)(unaff_EBP + -0x24)) - 1U |
                             (*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x28)) - 1U |
                            (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x5c)) - 1U)) {
                puVar1 = (uint *)(extraout_ECX + *(char *)(unaff_EBP + -0xf) * 4 + 0x40);
                puStack_a4 = (undefined1 *)0x4685b9;
                uVar14 = __allshl();
                *puVar1 = *puVar1 | (uint)uVar14;
                puVar1[1] = puVar1[1] | (uint)((ulonglong)uVar14 >> 0x20);
                iVar9 = DAT_006e54d8;
              }
            }
          }
          cVar4 = DAT_006e482f;
          *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + DAT_006e482e;
          *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + cVar4;
          if ((((int)*(char *)(unaff_EBP + -0x10) < *(int *)(iVar9 + 0x70) + 1) ||
              (*(int *)(iVar9 + 0x74) + -1 < (int)*(char *)(unaff_EBP + -0x10))) ||
             ((iVar13 = (int)*(char *)(unaff_EBP + -0xf), iVar13 < *(int *)(iVar9 + 0x78) + 1 ||
              (*(int *)(iVar9 + 0x7c) + -1 < iVar13)))) {
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          }
          else {
            puStack_a4 = (undefined1 *)0x468617;
            uVar14 = __allshl();
            if ((*(uint *)(extraout_ECX + iVar13 * 4 + 0x40) & (uint)uVar14) == 0 &&
                (*(uint *)(extraout_ECX + iVar13 * 4 + 0x42) & (uint)((ulonglong)uVar14 >> 0x20)) ==
                0) {
              puStack_a4 = (undefined1 *)(unaff_EBP + -0x10);
              iStack_a8 = unaff_EBP + -0x90;
              puVar8 = (undefined4 *)FUN_004ac469();
              *(undefined4 *)(unaff_EBP + -0x5c) = *puVar8;
              *(undefined4 *)(unaff_EBP + -0x58) = puVar8[1];
              *(undefined4 *)(unaff_EBP + -0x54) = puVar8[2];
              *(undefined4 *)(unaff_EBP + -0x50) = puVar8[3];
              if (-1 < (int)((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x58)) - 1U |
                             (*(int *)(unaff_EBP + -0x50) - *(int *)(unaff_EBP + -0x24)) - 1U |
                             (*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x28)) - 1U |
                            (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x5c)) - 1U)) {
                puVar1 = (uint *)(extraout_ECX + *(char *)(unaff_EBP + -0xf) * 4 + 0x40);
                puStack_a4 = (undefined1 *)0x468686;
                uVar14 = __allshl();
                *puVar1 = *puVar1 | (uint)uVar14;
                puVar1[1] = puVar1[1] | (uint)((ulonglong)uVar14 >> 0x20);
              }
            }
          }
          puStack_a4 = &DAT_006e481f;
          iStack_a8 = 0x4686a9;
          FUN_00461b74();
          iVar9 = DAT_006e54d8;
          cVar4 = *(char *)(unaff_EBP + -0x10) + *(char *)(unaff_EBP + -0x38);
          cVar11 = *(char *)(unaff_EBP + -0xf) + *(char *)(unaff_EBP + -0x37);
          *(undefined1 *)(unaff_EBP + -0x36) = 0;
          *(char *)(unaff_EBP + -0x10) = cVar4;
          *(char *)(unaff_EBP + -0xf) = cVar11;
          if ((((int)cVar4 < *(int *)(iVar9 + 0x70) + 1) ||
              (*(int *)(iVar9 + 0x74) + -1 < (int)cVar4)) ||
             ((iVar13 = (int)cVar11, iVar13 < *(int *)(iVar9 + 0x78) + 1 ||
              (*(int *)(iVar9 + 0x7c) + -1 < iVar13)))) {
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          }
          else {
            puStack_a4 = (undefined1 *)0x468705;
            uVar14 = __allshl();
            if ((*(uint *)(extraout_ECX + iVar13 * 4 + 0x40) & (uint)uVar14) == 0 &&
                (*(uint *)(extraout_ECX + iVar13 * 4 + 0x42) & (uint)((ulonglong)uVar14 >> 0x20)) ==
                0) {
              puStack_a4 = (undefined1 *)(unaff_EBP + -0x10);
              iStack_a8 = unaff_EBP + -0xa0;
              puVar8 = (undefined4 *)FUN_004ac469();
              *(undefined4 *)(unaff_EBP + -0x5c) = *puVar8;
              *(undefined4 *)(unaff_EBP + -0x58) = puVar8[1];
              *(undefined4 *)(unaff_EBP + -0x54) = puVar8[2];
              *(undefined4 *)(unaff_EBP + -0x50) = puVar8[3];
              iVar9 = DAT_006e54d8;
              if (-1 < (int)((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x58)) - 1U |
                             (*(int *)(unaff_EBP + -0x50) - *(int *)(unaff_EBP + -0x24)) - 1U |
                             (*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x28)) - 1U |
                            (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x5c)) - 1U)) {
                puVar1 = (uint *)(extraout_ECX + *(char *)(unaff_EBP + -0xf) * 4 + 0x40);
                puStack_a4 = (undefined1 *)0x468774;
                uVar14 = __allshl();
                *puVar1 = *puVar1 | (uint)uVar14;
                puVar1[1] = puVar1[1] | (uint)((ulonglong)uVar14 >> 0x20);
                iVar9 = DAT_006e54d8;
              }
            }
          }
          if (2 < *(int *)(unaff_EBP + -0x14)) break;
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          puStack_a4 = &DAT_006e481f;
          iStack_a8 = 0x468796;
          FUN_00461b74();
          *(undefined1 *)(unaff_EBP + -0x32) = 0;
          *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + *(char *)(unaff_EBP + -0x34)
          ;
          *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + *(char *)(unaff_EBP + -0x33);
          iVar9 = DAT_006e54d8;
        }
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 3;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + -0x30) == *(int *)(extraout_ECX + 4)) break;
        puVar6 = *(undefined1 **)(unaff_EBP + -0x30);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

