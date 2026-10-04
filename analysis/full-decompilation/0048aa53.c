
undefined4 FUN_0048aa53(void)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  short *psVar4;
  short *psVar5;
  undefined1 uVar6;
  char cVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  uint uVar10;
  undefined1 uVar11;
  undefined4 extraout_ECX;
  int iVar12;
  int iVar13;
  int *piVar14;
  char *pcVar15;
  int unaff_EBP;
  bool bVar16;
  undefined4 local_74;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0x10) == 0) goto LAB_0048ae87;
  piVar14 = *(int **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -0x2a) = *(undefined1 *)(unaff_EBP + 0xc);
  iVar13 = *piVar14;
  uVar6 = (undefined1)(piVar14[1] >> 4);
  *(undefined1 *)(unaff_EBP + -0x2c) = uVar6;
  uVar11 = (undefined1)(iVar13 >> 4);
  *(undefined1 *)(unaff_EBP + -0x2b) = uVar11;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + 0x10) = &local_74;
  local_74._0_2_ = CONCAT11(uVar11,uVar6);
  local_74._3_1_ = (char)(iVar13 >> 0x1c);
  local_74._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0xc),(undefined2)local_74);
  uVar8 = FUN_00489b59();
  *(undefined4 *)(unaff_EBP + 0x10) = uVar8;
  local_74 = 0x48aaaf;
  uVar8 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(*DAT_006e486c + 0x24);
  if (*(short *)(unaff_EBP + 0x10) == -5) {
    iVar13 = piVar14[1];
    *(char *)(unaff_EBP + 0x12) = (char)uVar8;
    *(char *)(unaff_EBP + 0x10) = (char)(iVar13 >> 4);
    *(char *)(unaff_EBP + 0x11) = (char)(*piVar14 >> 4);
    iVar13 = *(int *)(DAT_006e54d8 + 0x84);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    local_74 = -iVar13 & 3;
    FUN_00434ffd();
    local_74 = unaff_EBP + -0x1c;
    FUN_004672d0(unaff_EBP + 0x10,unaff_EBP + -0x14,unaff_EBP + -0x18,unaff_EBP + -0x10);
    iVar13 = DAT_006e54d8;
    if (*(int *)(unaff_EBP + -0x10) == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = ((*(int *)(unaff_EBP + -0x10) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) + 1;
    }
    *(int *)(unaff_EBP + -0x10) = iVar12;
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      iVar13 = 0;
    }
    else {
      iVar13 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(iVar13 + 0x84)) - 1U & 3) + 1;
    }
    *(int *)(unaff_EBP + -0x1c) = iVar13;
    local_74._0_2_ = CONCAT11((char)(*piVar14 >> 4),(char)(piVar14[1] >> 4));
    local_74._0_3_ = CONCAT12((char)uVar8,(undefined2)local_74);
    local_74 = (uint)(uint3)local_74;
    *(undefined4 **)(unaff_EBP + 8) = &local_74;
    FUN_00467768(unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (((byte)*(undefined4 *)(unaff_EBP + -0x70) & 0x20) == 0x20) {
      local_74 = uVar8;
      uVar8 = FUN_004a6a46(piVar14);
      *(undefined4 *)(unaff_EBP + 8) = uVar8;
      if (*(short *)(unaff_EBP + 0x16) < *(short *)(unaff_EBP + 10)) {
        bVar16 = *(int *)(unaff_EBP + -0x10) == 1;
      }
      else {
        bVar16 = *(int *)(unaff_EBP + -0x10) == 3;
      }
      if (bVar16) {
        puVar9 = *(undefined2 **)(unaff_EBP + -0x14);
      }
      else {
LAB_0048abb7:
        puVar9 = *(undefined2 **)(unaff_EBP + -0x18);
      }
    }
    else {
      puVar9 = *(undefined2 **)(unaff_EBP + -0x14);
      if (*(int *)(unaff_EBP + -0x10) != 2) goto LAB_0048abb7;
    }
    uVar3 = *puVar9;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined2 *)(unaff_EBP + 0x10) = uVar3;
  }
  local_74 = *(undefined4 *)(unaff_EBP + 0x10);
  iVar13 = FUN_004670a4();
  *(int *)(unaff_EBP + -0x3c) = iVar13;
  if (iVar13 != 0) {
    pcVar15 = *(char **)(iVar13 + 4);
    *(char **)(unaff_EBP + -0x38) = pcVar15;
    while (pcVar15 != *(char **)(iVar13 + 8)) {
      cVar7 = *pcVar15;
      cVar1 = pcVar15[1];
      cVar2 = pcVar15[2];
      *(char *)(unaff_EBP + 8) = cVar7;
      *(char *)(unaff_EBP + 9) = cVar1;
      *(char *)(unaff_EBP + 10) = cVar2;
      iVar13 = DAT_006e54dc;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (*(char *)(*(int *)(*(int *)(*(int *)(iVar13 + 0x40 + cVar2 * 4) + 0xc) + cVar7 * 4) +
                   cVar1 * 0xe) != '\0') {
        local_74 = unaff_EBP + 8;
        FUN_00479737(unaff_EBP + -0x70);
        iVar13 = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        if (*(int *)(unaff_EBP + -0x70) == 0) {
          *(undefined4 *)(unaff_EBP + 0xc) = 0;
        }
        else {
          uVar10 = 1;
          if (((byte)*(undefined4 *)(unaff_EBP + -0x70) & 1) != 1) {
            do {
              uVar10 = uVar10 * 2;
            } while ((uVar10 & *(uint *)(unaff_EBP + -0x70)) != uVar10);
          }
          *(uint *)(unaff_EBP + 0xc) = uVar10;
        }
        uVar10 = *(uint *)(unaff_EBP + 0xc);
        while (uVar10 != 0) {
          if ((*(int *)(unaff_EBP + 0xc) == 0x10) || (*(int *)(unaff_EBP + 0xc) == 0x20)) {
            *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + 8);
            *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(unaff_EBP + 9);
            *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + 10);
            local_74 = unaff_EBP + -0x1c;
            *(undefined1 *)(unaff_EBP + -4) = 5;
            cVar7 = FUN_004672d0(unaff_EBP + -0x20,unaff_EBP + -0x14,unaff_EBP + -0x18,
                                 unaff_EBP + -0x10);
            if (cVar7 == '\0') {
              if (*(int *)(unaff_EBP + 0xc) == 0x10) {
                *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 2;
                iVar13 = iVar13 + 1;
                *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 4;
              }
              else {
                *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 1;
                iVar13 = iVar13 + 1;
LAB_0048ad86:
                *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 3;
              }
            }
            else {
              psVar4 = *(short **)(unaff_EBP + -0x14);
              if ((psVar4 != (short *)0x0) && (*psVar4 == *(short *)(unaff_EBP + 0x10))) {
                iVar12 = *(int *)(unaff_EBP + -0x10);
                if (iVar12 == 1) {
                  *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 1;
                }
                else if (iVar12 == 3) {
LAB_0048ad21:
                  *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 3;
                }
                else if (iVar12 == 4) {
                  *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 2;
                }
                else {
                  if (iVar12 != 2) {
                    if (*(int *)(unaff_EBP + 0xc) != 0x10) {
                      *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 1;
                      iVar13 = iVar13 + 1;
                      goto LAB_0048ad21;
                    }
                    *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 2;
                    iVar13 = iVar13 + 1;
                  }
                  *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 4;
                }
                iVar13 = iVar13 + 1;
              }
              psVar5 = *(short **)(unaff_EBP + -0x18);
              if (((psVar5 == (short *)0x0) || (psVar5 == psVar4)) ||
                 (*psVar5 != *(short *)(unaff_EBP + 0x10))) goto LAB_0048ad8b;
              iVar12 = *(int *)(unaff_EBP + -0x1c);
              uVar8 = 1;
              if (iVar12 != 1) {
                if (iVar12 == 3) goto LAB_0048ad86;
                uVar8 = 4;
                if (iVar12 == 4) {
                  *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = 2;
                  goto LAB_0048ad8a;
                }
                if (iVar12 != 2) goto LAB_0048ad8b;
              }
              *(undefined4 *)(unaff_EBP + -0x44 + iVar13 * 4) = uVar8;
            }
LAB_0048ad8a:
            iVar13 = iVar13 + 1;
          }
          else {
            iVar13 = 1;
          }
LAB_0048ad8b:
          *(undefined1 *)(unaff_EBP + 0x14) = *(undefined1 *)(unaff_EBP + 8);
          *(undefined1 *)(unaff_EBP + 0x15) = *(undefined1 *)(unaff_EBP + 9);
          *(undefined1 *)(unaff_EBP + 0x16) = *(undefined1 *)(unaff_EBP + 10);
          iVar12 = DAT_006e54d8;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          local_74 = *(undefined4 *)(iVar12 + 0x84);
          FUN_00434ffd();
          iVar12 = DAT_006e54d8;
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          *(undefined4 *)(unaff_EBP + -0x34) =
               *(undefined4 *)
                (&DAT_006f4620 + (*(int *)(iVar12 + 0x84) * 0x40 + *(int *)(unaff_EBP + 0xc)) * 4);
          if (0 < iVar13) {
            piVar14 = (int *)(unaff_EBP + -0x44);
            do {
              if (*piVar14 != 0) {
                *piVar14 = *(int *)(&DAT_006f45d0 +
                                   (*(int *)(DAT_006e54d8 + 0x84) +
                                   *piVar14 + *(int *)(DAT_006e54d8 + 0x84) * 4) * 4);
              }
              iVar12 = *piVar14;
              local_74 = 0;
              cVar7 = FUN_00493897(unaff_EBP + 0x14,*(undefined4 *)(unaff_EBP + 0x18),
                                   *(undefined4 *)(unaff_EBP + -0x34),iVar12);
              if (cVar7 == '\0') {
                local_74 = 0x48ae3a;
                cVar7 = FUN_00493b85();
                if (cVar7 != '\0') {
                  uVar8 = 0;
                  goto LAB_0048ae89;
                }
              }
              else {
                local_74 = iVar12;
                FUN_004939fc(unaff_EBP + 0x14,*(undefined4 *)(unaff_EBP + 0x18),
                             *(undefined4 *)(unaff_EBP + -0x34));
              }
              *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
              piVar14 = piVar14 + 1;
            } while (*(int *)(unaff_EBP + -0x28) < iVar13);
            pcVar15 = *(char **)(unaff_EBP + -0x38);
          }
          uVar10 = *(uint *)(unaff_EBP + 0xc);
          do {
            uVar10 = uVar10 * 2;
            if ((uVar10 & *(uint *)(unaff_EBP + -0x70)) == uVar10) break;
          } while ((int)uVar10 < 0x20);
          if (0x1f < (int)uVar10) break;
          *(uint *)(unaff_EBP + 0xc) = uVar10;
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar13 = *(int *)(unaff_EBP + -0x3c);
      pcVar15 = pcVar15 + 3;
      *(char **)(unaff_EBP + -0x38) = pcVar15;
    }
  }
LAB_0048ae87:
  uVar8 = 1;
LAB_0048ae89:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

