
uint FUN_00434895(void)

{
  undefined2 uVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  undefined1 uVar5;
  char cVar6;
  short sVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  char cVar15;
  undefined4 extraout_ECX;
  int iVar16;
  int unaff_EBP;
  undefined4 uVar17;
  undefined4 uVar18;
  
  FUN_00634c24();
  pcVar2 = *(char **)(unaff_EBP + 8);
  iVar16 = *(int *)(pcVar2 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x2c) = extraout_ECX;
  if (iVar16 == -1) {
    *(undefined4 *)(unaff_EBP + -0x30) = 0xffffffff;
  }
  else {
    *(int *)(unaff_EBP + -0x30) = iVar16;
  }
  iVar4 = DAT_006e54dc;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  iVar16 = *(int *)(iVar4 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(int *)(unaff_EBP + -0x34) = iVar16 << 3;
  cVar6 = *pcVar2;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  if (cVar6 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    puVar8 = (undefined4 *)FUN_004a6994(unaff_EBP + -0x40);
    *(undefined4 *)(unaff_EBP + -0x48) = *puVar8;
    *(undefined4 *)(unaff_EBP + -0x44) = puVar8[1];
    uVar12 = FUN_00433116(unaff_EBP + -0x48,1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar6 = FUN_00434d5c(uVar12);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (cVar6 != '\0') {
      iVar16 = *(int *)(DAT_006e54dc + 0x10);
      *(undefined1 *)(unaff_EBP + -0x1a) = 0;
      uVar5 = (undefined1)(iVar16 / 2);
      *(undefined1 *)(unaff_EBP + -0x1c) = uVar5;
      *(undefined1 *)(unaff_EBP + -0x1b) = uVar5;
      iVar16 = DAT_006e54d8;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar12 = FUN_00434d11(*(undefined4 *)(iVar16 + 0x70),*(undefined4 *)(iVar16 + 0x78),0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00434d2a(uVar12);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar8 = (undefined4 *)FUN_00434d3d(unaff_EBP + -0x40);
      uVar12 = *puVar8;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x48) = uVar12;
      *(undefined4 *)(unaff_EBP + -0x44) = puVar8[1];
    }
    FUN_0047bd91(unaff_EBP + -0x44,unaff_EBP + -0x48,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(pcVar2 + 0xc);
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(pcVar2 + 4);
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(pcVar2 + 8);
  }
  if (pcVar2[0x17] != '\0') {
    if (((*(int *)(unaff_EBP + -0x44) == 1) && (*(int *)(unaff_EBP + -0x48) == 1)) ||
       (*pcVar2 == '\0')) {
      uVar9 = *(uint *)(iVar4 + 0x10);
      uVar10 = FUN_0046f556();
      *(uint *)(unaff_EBP + -0x44) = uVar10 % uVar9;
      uVar9 = *(uint *)(iVar4 + 0x10);
      uVar10 = FUN_0046f556();
      *(uint *)(unaff_EBP + -0x48) = uVar10 % uVar9;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(pcVar2 + 4);
      *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(pcVar2 + 8);
      do {
        uVar9 = FUN_0046f556();
        uVar10 = FUN_0046f556();
        *(undefined1 *)(unaff_EBP + -0x26) = 0;
        *(char *)(unaff_EBP + -0x28) = (char)(uVar9 % 10) + -5;
        *(char *)(unaff_EBP + -0x27) = (char)(uVar10 % 10) + -5;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        piVar11 = (int *)FUN_00434d3d(unaff_EBP + -0x40);
        *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + piVar11[1];
        *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + *piVar11;
        uVar12 = FUN_00433116(unaff_EBP + -0x48,1);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        cVar6 = FUN_00434d5c(uVar12);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      } while (cVar6 != '\0');
    }
    FUN_0047bd91(unaff_EBP + -0x44,unaff_EBP + -0x48,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
  }
  cVar6 = (char)(*(int *)(unaff_EBP + -0x44) >> 4);
  *(char *)(unaff_EBP + -0x10) = cVar6;
  cVar15 = (char)(*(int *)(unaff_EBP + -0x48) >> 4);
  *(char *)(unaff_EBP + -0xf) = cVar15;
  *(char *)(unaff_EBP + -0xe) = *(char *)(unaff_EBP + -0x20);
  iVar16 = *(int *)(iVar4 + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  if (iVar16 + -1 <= (int)cVar6) {
    *(char *)(unaff_EBP + -0x10) = (char)iVar16 + -2;
  }
  if (*(char *)(unaff_EBP + -0x10) < '\x01') {
    *(undefined1 *)(unaff_EBP + -0x10) = 1;
  }
  if (iVar16 + -1 <= (int)cVar15) {
    *(char *)(unaff_EBP + -0xf) = (char)iVar16 + -2;
  }
  if (*(char *)(unaff_EBP + -0xf) < '\x01') {
    *(undefined1 *)(unaff_EBP + -0xf) = 1;
  }
  iVar16 = *(int *)(iVar4 + 0x28 + *(char *)(unaff_EBP + -0x20) * 4);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  iVar16 = *(int *)(*(int *)(iVar16 + 0xc) + *(char *)(unaff_EBP + -0x10) * 4);
  uVar1 = *(undefined2 *)(iVar16 + *(char *)(unaff_EBP + -0xf) * 2);
  uVar9 = CONCAT22((short)((uint)iVar16 >> 0x10),uVar1);
  *(undefined2 *)(unaff_EBP + -0x38) = uVar1;
  if (0 < *(int *)(unaff_EBP + -0x34)) {
    do {
      if (0xfff < *(int *)(unaff_EBP + -0x28)) break;
      *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(unaff_EBP + -0x20);
      cVar6 = *(char *)(unaff_EBP + -0x18) + *(char *)(unaff_EBP + -0x10);
      cVar15 = *(char *)(unaff_EBP + -0xf) + *(char *)(unaff_EBP + -0x14);
      bVar3 = true;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      *(char *)(unaff_EBP + -0x1c) = cVar6;
      *(char *)(unaff_EBP + -0x1b) = cVar15;
      if (((cVar6 < '\x01') || (iVar16 = *(int *)(iVar4 + 0x10) + -1, iVar16 <= cVar6)) ||
         ((cVar15 < '\x01' || (iVar16 <= cVar15)))) {
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        FUN_00479737(unaff_EBP + -0x7c,unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        if (((((*(byte *)(unaff_EBP + -0x7c) & 0x30) == 0) &&
             ((iVar16 = *(int *)(unaff_EBP + 8), *(char *)(iVar16 + 0x15) == '\0' ||
              (sVar7 = FUN_004325af(unaff_EBP + -0x1c), sVar7 == 0)))) &&
            ((*(char *)(iVar16 + 0x14) == '\0' ||
             (*(short *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x28 + *(char *)(unaff_EBP + -0x1a) * 4)
                                          + 0xc) + *(char *)(unaff_EBP + -0x1c) * 4) +
                        *(char *)(unaff_EBP + -0x1b) * 2) == *(short *)(unaff_EBP + -0x38))))) &&
           ((cVar6 = FUN_004790e8(unaff_EBP + -0x1c), cVar6 == '\0' &&
            (((*(char *)(iVar16 + 0x16) == '\0' || (DAT_006e4a84 != 0)) ||
             (uVar9 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x34) + 0xc) +
                                                *(char *)(unaff_EBP + -0x1c) * 4) +
                                       (int)*(char *)(unaff_EBP + -0x1b)) & 0x20) >> 5,
             *(uint *)(unaff_EBP + -0x3c) = uVar9, uVar9 != 0)))))) {
          uVar18 = 0;
          uVar17 = 0;
          iVar16 = **(int **)(unaff_EBP + -0x2c);
          uVar12 = *(undefined4 *)(unaff_EBP + -0x20);
          uVar13 = FUN_00434d3d(unaff_EBP + -0x50);
          cVar6 = (**(code **)(iVar16 + 0x54))(uVar13,uVar12,uVar17,uVar18);
          if (cVar6 == '\0') goto LAB_00434c40;
        }
        else {
LAB_00434c40:
          bVar3 = false;
        }
        *(undefined1 *)(unaff_EBP + -4) = 6;
        if (bVar3) {
          puVar14 = (undefined4 *)FUN_00434d3d(unaff_EBP + -0x50);
          puVar8 = *(undefined4 **)(unaff_EBP + 0xc);
          *puVar8 = *puVar14;
          puVar8[1] = puVar14[1];
          uVar9 = CONCAT31((int3)((uint)puVar8 >> 8),1);
          goto LAB_00434ce1;
        }
      }
      iVar16 = *(int *)(unaff_EBP + -0x30);
      if (iVar16 == -1) {
        if (-*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14)) {
          if (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14)) goto LAB_00434c77;
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + -1;
        }
        else if (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14)) {
LAB_00434c77:
          if (*(int *)(unaff_EBP + -0x14) < -*(int *)(unaff_EBP + -0x18)) {
            if (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14)) {
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            }
          }
          else {
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          }
        }
        else {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -1;
        }
      }
      else if (iVar16 == 0) {
LAB_00434cb7:
        if (*(int *)(unaff_EBP + -0x14) < 1) {
          iVar16 = 1 - *(int *)(unaff_EBP + -0x14);
        }
        else {
          iVar16 = -*(int *)(unaff_EBP + -0x14);
        }
        *(int *)(unaff_EBP + -0x14) = iVar16;
      }
      else {
        if (iVar16 != 2) {
          if (iVar16 == 4) goto LAB_00434cb7;
          if (iVar16 != 6) goto LAB_00434ccc;
        }
        if (*(int *)(unaff_EBP + -0x18) < 1) {
          iVar16 = 1 - *(int *)(unaff_EBP + -0x18);
        }
        else {
          iVar16 = -*(int *)(unaff_EBP + -0x18);
        }
        *(int *)(unaff_EBP + -0x18) = iVar16;
      }
LAB_00434ccc:
      uVar9 = *(uint *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
      *(undefined1 *)(unaff_EBP + -4) = 5;
    } while ((int)uVar9 < *(int *)(unaff_EBP + -0x34));
  }
  uVar9 = uVar9 & 0xffffff00;
LAB_00434ce1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

