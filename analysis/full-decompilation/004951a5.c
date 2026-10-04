
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined1 FUN_004951a5(void)

{
  ushort uVar1;
  short sVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  char cVar10;
  int extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 uVar12;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  int iVar11;
  char cVar13;
  int unaff_EBP;
  undefined4 *puVar14;
  bool bVar15;
  undefined4 local_2bc;
  
  FUN_00634c24();
  pcVar3 = *(char **)(unaff_EBP + 8);
  cVar4 = *pcVar3;
  *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  local_2bc._0_2_ = CONCAT11(pcVar3[1],cVar4);
  local_2bc._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
  local_2bc._0_3_ = CONCAT12(pcVar3[2],(undefined2)local_2bc);
  FUN_00467768(unaff_EBP + -0xa8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  switch(*(undefined4 *)(unaff_EBP + 0x10)) {
  case 0:
  case 1:
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    break;
  case 2:
  case 3:
    *(undefined4 *)(unaff_EBP + -0x10) = 2;
    break;
  case 4:
  case 5:
    *(undefined4 *)(unaff_EBP + -0x10) = 0x20;
    break;
  case 6:
  case 7:
    *(undefined4 *)(unaff_EBP + -0x10) = 0x10;
    break;
  default:
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    local_2bc = *(undefined1 **)(unaff_EBP + -0x10);
    cVar4 = FUN_00496e92(pcVar3);
    if (cVar4 != '\0') {
      iVar7 = *(int *)(extraout_ECX + 0xe038);
      uVar12 = extraout_var;
      if ((((iVar7 != 2) && (iVar7 != 0xc)) && (iVar7 != 0xd)) && (iVar7 != 0xe)) {
        local_2bc = *(undefined1 **)(unaff_EBP + -0x10);
        cVar4 = FUN_004950b8(pcVar3);
        uVar12 = extraout_var_00;
        if (cVar4 == '\0') goto LAB_00496052;
      }
      cVar4 = *pcVar3;
      *(undefined4 **)(unaff_EBP + 8) = &local_2bc;
      local_2bc._0_2_ = CONCAT11(pcVar3[1],cVar4);
      local_2bc._0_3_ = CONCAT12(pcVar3[2],(undefined2)local_2bc);
      local_2bc = (undefined1 *)CONCAT13(uVar12,(uint3)local_2bc);
      iVar7 = FUN_00488924();
      if (iVar7 != 0) {
        local_2bc = *(undefined1 **)(unaff_EBP + -0x10);
        cVar4 = FUN_0053c06c();
        *(char *)(unaff_EBP + 0xb) = cVar4;
        if (cVar4 != '\0') {
          cVar4 = *pcVar3;
          *(undefined4 **)(unaff_EBP + 0x10) = &local_2bc;
          local_2bc._0_2_ = CONCAT11(pcVar3[1],cVar4);
          local_2bc._0_3_ = CONCAT12(pcVar3[2],(undefined2)local_2bc);
          local_2bc = (undefined1 *)CONCAT13(extraout_var_01,(uint3)local_2bc);
          uVar8 = FUN_004893e4();
          *(uint *)(unaff_EBP + 0x10) = uVar8 & 1;
          if ((uVar8 & 1) == 0) {
            iVar7 = *(int *)(extraout_ECX + 0xe038);
            if (((iVar7 == 2) || (iVar7 == 0xc)) || ((iVar7 == 0xd || (iVar7 == 0xe)))) {
              local_2bc = (undefined1 *)0x4955b7;
              iVar7 = FUN_00492b26();
              if (iVar7 == 1) goto LAB_00495693;
            }
            iVar7 = *(int *)(unaff_EBP + -0x10);
            if (iVar7 < 1) goto LAB_00495693;
            if (iVar7 < 3) {
              *(char *)(unaff_EBP + 0x10) = *pcVar3;
              *(char *)(unaff_EBP + 0x11) = pcVar3[1];
              *(char *)(unaff_EBP + 0x12) = pcVar3[2];
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (iVar7 == 1) {
                local_2bc = &DAT_006e4822;
                FUN_00461b74();
                *(undefined1 *)(unaff_EBP + 0xe) = 0;
                *(char *)(unaff_EBP + 0x10) =
                     *(char *)(unaff_EBP + 0x10) + *(char *)(unaff_EBP + 0xc);
                cVar4 = *(char *)(unaff_EBP + 0xd);
                uVar12 = extraout_var_02;
              }
              else {
                local_2bc = &DAT_006e481c;
                FUN_00461b74();
                *(undefined1 *)(unaff_EBP + -0x2e) = 0;
                *(char *)(unaff_EBP + 0x10) =
                     *(char *)(unaff_EBP + 0x10) + *(char *)(unaff_EBP + -0x30);
                cVar4 = *(char *)(unaff_EBP + -0x2f);
                uVar12 = extraout_var_03;
              }
              *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + cVar4;
              *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
              local_2bc._0_2_ =
                   CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),*(undefined1 *)(unaff_EBP + 0x10));
              local_2bc._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
              local_2bc = (undefined1 *)CONCAT13(uVar12,(uint3)local_2bc);
              uVar8 = FUN_004893e4();
              if ((uVar8 & 1) == 0) {
                if (*(int *)(extraout_ECX + 0xe064) == 0) {
                  *(undefined4 *)(extraout_ECX + 0xe064) = 0x20;
                }
                *(undefined1 *)(unaff_EBP + 0xb) = 0;
              }
              *(undefined1 *)(unaff_EBP + -4) = 0;
              goto LAB_00495693;
            }
            if ((iVar7 != 0x10) && (iVar7 != 0x20)) goto LAB_00495693;
            if (*(int *)(extraout_ECX + 0xe064) == 0) {
              *(undefined4 *)(extraout_ECX + 0xe064) = 0x20;
            }
LAB_00496049:
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
          }
          else {
LAB_00495693:
            if (*(char *)(unaff_EBP + 0xb) != '\0') {
              *(char *)(unaff_EBP + -0x18) = *pcVar3;
              *(char *)(unaff_EBP + -0x17) = pcVar3[1];
              *(char *)(unaff_EBP + -0x16) = pcVar3[2];
              iVar7 = DAT_006e54d8;
              *(undefined1 *)(unaff_EBP + -4) = 2;
              local_2bc = (undefined1 *)(-*(int *)(iVar7 + 0x84) & 3);
              FUN_00434ffd();
              local_2bc = (undefined1 *)0x0;
              FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x18);
              iVar7 = DAT_006e54d8;
              if (0 < *(int *)(unaff_EBP + -0x10)) {
                if (*(int *)(unaff_EBP + -0x10) < 3) {
                  iVar11 = *(int *)(unaff_EBP + -0x28);
                  while (DAT_006e54d8 = iVar7, iVar11 != 0) {
                    if (*(short *)(*(int *)(iVar11 + 0x118) + 0x12) != 2) {
                      uVar1 = *(ushort *)(iVar11 + 100);
                      iVar11 = *(int *)(&DAT_006f4620 +
                                       ((((int)(-(int)*(short *)(iVar11 + 0x4c) & 7U) >> 1) -
                                         *(int *)(iVar7 + 0x84) & 3U) * 0x40 +
                                       *(int *)(unaff_EBP + -0x10)) * 4);
                      if (((((iVar11 == 1) && ((uVar1 & 0x800) != 0)) ||
                           ((iVar11 == 8 && ((uVar1 & 0x400) != 0)))) ||
                          ((iVar11 == 2 && ((uVar1 & 0x100) != 0)))) ||
                         ((iVar11 == 4 && ((uVar1 & 0x200) != 0)))) {
                        *(undefined1 *)(unaff_EBP + 0xb) = 0;
                        if (*(int *)(extraout_ECX + 0xe064) != 0) goto LAB_004959ac;
                        *(undefined4 *)(extraout_ECX + 0xe064) = 0xb;
                        break;
                      }
                    }
                    local_2bc = (undefined1 *)0x4957e9;
                    FUN_0043f3b9();
                    iVar7 = DAT_006e54d8;
                    iVar11 = *(int *)(unaff_EBP + -0x28);
                  }
                  iVar7 = DAT_006e54d8;
                  if (*(char *)(unaff_EBP + 0xb) != '\0') {
                    *(char *)(unaff_EBP + 0x10) = *pcVar3;
                    *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                    *(char *)(unaff_EBP + 0x12) = pcVar3[2];
                    if (*(int *)(unaff_EBP + -0x10) == 1) {
                      local_2bc = &DAT_006e4822;
                      FUN_00461b74();
                      *(undefined1 *)(unaff_EBP + -0x32) = 0;
                      *(char *)(unaff_EBP + 0x10) =
                           *(char *)(unaff_EBP + 0x10) + *(char *)(unaff_EBP + -0x34);
                      cVar4 = *(char *)(unaff_EBP + -0x33);
                    }
                    else {
                      local_2bc = &DAT_006e481c;
                      FUN_00461b74();
                      *(undefined1 *)(unaff_EBP + -0x36) = 0;
                      *(char *)(unaff_EBP + 0x10) =
                           *(char *)(unaff_EBP + 0x10) + *(char *)(unaff_EBP + -0x38);
                      cVar4 = *(char *)(unaff_EBP + -0x37);
                    }
                    *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + cVar4;
                    *(undefined1 *)(unaff_EBP + -0x1c) = *(undefined1 *)(unaff_EBP + 0x10);
                    *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(unaff_EBP + 0x11);
                    *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(unaff_EBP + 0x12);
                    iVar7 = DAT_006e54d8;
                    *(undefined1 *)(unaff_EBP + -4) = 4;
                    local_2bc = (undefined1 *)(-*(int *)(iVar7 + 0x84) & 3);
                    FUN_00434ffd();
                    local_2bc = (undefined1 *)0x0;
                    *(undefined4 *)(unaff_EBP + -0x14) =
                         *(undefined4 *)(&DAT_006f4820 + *(int *)(unaff_EBP + -0x10) * 4);
                    FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x1c);
                    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x7c);
                    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x78);
                    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x74);
                    if (*(int *)(unaff_EBP + -0x78) != 0) {
                      iVar11 = *(int *)(unaff_EBP + -0x28);
                      do {
                        iVar7 = DAT_006e54d8;
                        if (*(short *)(*(int *)(iVar11 + 0x118) + 0x12) != 2) {
                          uVar1 = *(ushort *)(iVar11 + 100);
                          iVar11 = *(int *)(&DAT_006f4620 +
                                           ((((int)(-(int)*(short *)(iVar11 + 0x4c) & 7U) >> 1) -
                                             *(int *)(DAT_006e54d8 + 0x84) & 3U) * 0x40 +
                                           *(int *)(unaff_EBP + -0x14)) * 4);
                          if ((((iVar11 == 1) && ((uVar1 & 0x800) != 0)) ||
                              ((iVar11 == 8 && ((uVar1 & 0x400) != 0)))) ||
                             (((iVar11 == 2 && ((uVar1 & 0x100) != 0)) ||
                              ((iVar11 == 4 && ((uVar1 & 0x200) != 0)))))) {
                            *(undefined1 *)(unaff_EBP + 0xb) = 0;
                            piVar6 = (int *)(*(int *)(unaff_EBP + -0x20) + 0xe064);
                            if (*piVar6 != 0) goto LAB_004959ac;
                            *piVar6 = 0xb;
                            break;
                          }
                        }
                        local_2bc = (undefined1 *)0x495943;
                        FUN_0043f3b9();
                        iVar11 = *(int *)(unaff_EBP + -0x28);
                      } while (iVar11 != 0);
                    }
                    iVar7 = DAT_006e54d8;
                    if (*(char *)(unaff_EBP + 0xb) != '\0') {
                      local_2bc = (undefined1 *)(unaff_EBP + -0x18);
                      cVar4 = FUN_004790e8();
                      iVar7 = DAT_006e54d8;
                      if (cVar4 != '\0') {
                        local_2bc = (undefined1 *)(unaff_EBP + -0x1c);
                        cVar4 = FUN_004790e8();
                        iVar7 = DAT_006e54d8;
                        if (cVar4 != '\0') {
                          piVar6 = (int *)(*(int *)(unaff_EBP + -0x20) + 0xe064);
                          iVar7 = *piVar6;
                          goto LAB_0049599a;
                        }
                      }
                    }
                  }
                }
                else if ((*(int *)(unaff_EBP + -0x10) == 0x10) ||
                        (*(int *)(unaff_EBP + -0x10) == 0x20)) {
                  while (*(int *)(unaff_EBP + -0x28) != 0) {
                    if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x28) + 0x118) + 0x12) != 9) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                      if (*(int *)(extraout_ECX + 0xe064) != 0) goto LAB_004959ac;
                      *(undefined4 *)(extraout_ECX + 0xe064) = 0xb;
                      break;
                    }
                    local_2bc = (undefined1 *)0x49571c;
                    FUN_0043f3b9();
                  }
                  iVar7 = DAT_006e54d8;
                  if (*(char *)(unaff_EBP + 0xb) != '\0') {
                    local_2bc = (undefined1 *)(unaff_EBP + -0x18);
                    cVar4 = FUN_004790e8();
                    iVar7 = DAT_006e54d8;
                    if (cVar4 != '\0') {
                      iVar7 = *(int *)(extraout_ECX + 0xe064);
                      piVar6 = (int *)(extraout_ECX + 0xe064);
LAB_0049599a:
                      if (iVar7 == 0) {
                        *piVar6 = 0x1d;
                      }
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                }
              }
LAB_004959ac:
              *(undefined1 *)(unaff_EBP + -4) = 0;
              if (*(char *)(unaff_EBP + 0xb) != '\0') {
                *(undefined1 *)(unaff_EBP + 0x12) = 0;
                puVar9 = (undefined4 *)(unaff_EBP + -100);
                for (iVar11 = 0xb; iVar11 != 0; iVar11 = iVar11 + -1) {
                  *puVar9 = 0;
                  puVar9 = puVar9 + 1;
                }
                iVar11 = *(int *)(unaff_EBP + -0x10);
                *(undefined1 *)(unaff_EBP + -4) = 6;
                if (iVar11 == 1) {
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar5 = pcVar3[2];
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + -1;
                  *(char *)(unaff_EBP + 0x12) = cVar5;
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if ((((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1))
                      && (*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11))) &&
                     ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x1b0);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x10) == 0x10) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  cVar4 = pcVar3[1];
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x10) = *pcVar3;
                  cVar4 = cVar4 + '\x01';
                  *(char *)(unaff_EBP + 0x12) = pcVar3[2];
                  *(char *)(unaff_EBP + 0x11) = cVar4;
                  if (((iVar11 + 1 <= (int)*(char *)(unaff_EBP + 0x10)) &&
                      ((int)*(char *)(unaff_EBP + 0x10) <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)cVar4 &&
                      ((int)cVar4 <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),
                                  CONCAT11(cVar4,*(undefined1 *)(unaff_EBP + 0x10)));
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x208);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x10) == 0x10) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  cVar4 = pcVar3[1];
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x10) = *pcVar3;
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x12) = pcVar3[2];
                  *(char *)(unaff_EBP + 0x11) = cVar4;
                  if (((iVar11 + 1 <= (int)*(char *)(unaff_EBP + 0x10)) &&
                      ((int)*(char *)(unaff_EBP + 0x10) <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)cVar4 &&
                      ((int)cVar4 <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),
                                  CONCAT11(cVar4,*(undefined1 *)(unaff_EBP + 0x10)));
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x260);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x20) == 0x20) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  iVar11 = *(int *)(iVar7 + 0x70);
                  cVar4 = pcVar3[2];
                  cVar10 = *pcVar3 + -1;
                  cVar5 = pcVar3[1] + '\x01';
                  *(char *)(unaff_EBP + 0x12) = cVar4;
                  *(char *)(unaff_EBP + 0x10) = cVar10;
                  *(char *)(unaff_EBP + 0x11) = cVar5;
                  if ((((iVar11 + 1 <= (int)cVar10) && ((int)cVar10 <= *(int *)(iVar7 + 0x74) + -1))
                      && (*(int *)(iVar7 + 0x78) + 1 <= (int)cVar5)) &&
                     ((int)cVar5 <= *(int *)(iVar7 + 0x7c) + -1)) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar10);
                    local_2bc._0_3_ = CONCAT12(cVar4,(undefined2)local_2bc);
                    iVar7 = unaff_EBP + -0x2b8;
LAB_00495fde:
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(iVar7);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    bVar15 = ((byte)*(undefined4 *)(unaff_EBP + -100) & 0x20) == 0x20;
LAB_00495ffc:
                    if (bVar15) {
LAB_00495ffe:
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                    }
                  }
                }
                else if (iVar11 == 2) {
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar5 = pcVar3[2];
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + -1;
                  *(char *)(unaff_EBP + 0x12) = cVar5;
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if (((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11) &&
                      ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x234);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x10) == 0x10) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar4 = cVar4 + '\x01';
                  *(char *)(unaff_EBP + 0x12) = pcVar3[2];
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if (((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11) &&
                      ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0xd4);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x10) == 0x10) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x12) = pcVar3[2];
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if ((((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1))
                      && (*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11))) &&
                     ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x100);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    iVar7 = DAT_006e54d8;
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 0x20) == 0x20) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  iVar11 = *(int *)(iVar7 + 0x70);
                  cVar4 = pcVar3[2];
                  cVar10 = *pcVar3 + '\x01';
                  cVar5 = pcVar3[1] + -1;
                  *(char *)(unaff_EBP + 0x12) = cVar4;
                  *(char *)(unaff_EBP + 0x10) = cVar10;
                  *(char *)(unaff_EBP + 0x11) = cVar5;
                  if (((iVar11 + 1 <= (int)cVar10) && ((int)cVar10 <= *(int *)(iVar7 + 0x74) + -1))
                     && ((*(int *)(iVar7 + 0x78) + 1 <= (int)cVar5 &&
                         ((int)cVar5 <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar10);
                    local_2bc._0_3_ = CONCAT12(cVar4,(undefined2)local_2bc);
                    iVar7 = unaff_EBP + -0x158;
                    goto LAB_00495fde;
                  }
                }
                else if (iVar11 == 0x10) {
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar5 = pcVar3[2];
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + -1;
                  *(char *)(unaff_EBP + 0x12) = cVar5;
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if (((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11) &&
                      ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x28c);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    if ((((byte)*(undefined4 *)(unaff_EBP + -100) & 4) == 4) ||
                       (iVar7 = DAT_006e54d8, ((byte)*(undefined4 *)(unaff_EBP + -100) & 8) == 8)) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  iVar11 = *(int *)(iVar7 + 0x70);
                  cVar4 = pcVar3[2];
                  cVar10 = *pcVar3 + '\x01';
                  cVar5 = pcVar3[1] + '\x01';
                  *(char *)(unaff_EBP + 0x12) = cVar4;
                  *(char *)(unaff_EBP + 0x10) = cVar10;
                  *(char *)(unaff_EBP + 0x11) = cVar5;
                  if ((((iVar11 + 1 <= (int)cVar10) && ((int)cVar10 <= *(int *)(iVar7 + 0x74) + -1))
                      && (*(int *)(iVar7 + 0x78) + 1 <= (int)cVar5)) &&
                     ((int)cVar5 <= *(int *)(iVar7 + 0x7c) + -1)) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar10);
                    local_2bc._0_3_ = CONCAT12(cVar4,(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x184);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 1) == 1) goto LAB_00495ffe;
                    bVar15 = ((byte)*(undefined4 *)(unaff_EBP + -100) & 2) == 2;
                    goto LAB_00495ffc;
                  }
                }
                else if (iVar11 == 0x20) {
                  cVar4 = *pcVar3;
                  iVar11 = *(int *)(iVar7 + 0x70);
                  *(char *)(unaff_EBP + 0x11) = pcVar3[1];
                  cVar5 = pcVar3[2];
                  cVar4 = cVar4 + -1;
                  *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + '\x01';
                  *(char *)(unaff_EBP + 0x12) = cVar5;
                  *(char *)(unaff_EBP + 0x10) = cVar4;
                  if (((iVar11 + 1 <= (int)cVar4) && ((int)cVar4 <= *(int *)(iVar7 + 0x74) + -1)) &&
                     ((*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x11) &&
                      ((int)*(char *)(unaff_EBP + 0x11) <= *(int *)(iVar7 + 0x7c) + -1)))) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar4);
                    local_2bc._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + 0x12),(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -0x1dc);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    if ((((byte)*(undefined4 *)(unaff_EBP + -100) & 2) == 2) ||
                       (iVar7 = DAT_006e54d8, ((byte)*(undefined4 *)(unaff_EBP + -100) & 4) == 4)) {
                      *(undefined1 *)(unaff_EBP + 0xb) = 0;
                      iVar7 = DAT_006e54d8;
                    }
                  }
                  iVar11 = *(int *)(iVar7 + 0x70);
                  cVar4 = pcVar3[2];
                  cVar10 = *pcVar3 + '\x01';
                  cVar5 = pcVar3[1] + -1;
                  *(char *)(unaff_EBP + 0x12) = cVar4;
                  *(char *)(unaff_EBP + 0x10) = cVar10;
                  *(char *)(unaff_EBP + 0x11) = cVar5;
                  if ((((iVar11 + 1 <= (int)cVar10) && ((int)cVar10 <= *(int *)(iVar7 + 0x74) + -1))
                      && (*(int *)(iVar7 + 0x78) + 1 <= (int)cVar5)) &&
                     ((int)cVar5 <= *(int *)(iVar7 + 0x7c) + -1)) {
                    *(undefined4 **)(unaff_EBP + -0x14) = &local_2bc;
                    local_2bc._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x11),cVar10);
                    local_2bc._0_3_ = CONCAT12(cVar4,(undefined2)local_2bc);
                    local_2bc = (undefined1 *)(uint)(uint3)local_2bc;
                    puVar9 = (undefined4 *)FUN_00467768(unaff_EBP + -300);
                    puVar14 = (undefined4 *)(unaff_EBP + -100);
                    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
                      *puVar14 = *puVar9;
                      puVar9 = puVar9 + 1;
                      puVar14 = puVar14 + 1;
                    }
                    if (((byte)*(undefined4 *)(unaff_EBP + -100) & 1) != 1) {
                      bVar15 = ((byte)*(undefined4 *)(unaff_EBP + -100) & 8) == 8;
                      goto LAB_00495ffc;
                    }
                    goto LAB_00495ffe;
                  }
                }
                *(undefined1 *)(unaff_EBP + -4) = 0;
                if ((*(char *)(unaff_EBP + 0xb) != '\0') &&
                   ((*(uint *)(unaff_EBP + -0x10) & *(uint *)(unaff_EBP + -0xa8)) !=
                    *(uint *)(unaff_EBP + -0x10))) {
                  iVar7 = *(int *)(unaff_EBP + -0x20);
                  local_2bc = *(undefined1 **)(&DAT_006e57e8 + *(int *)(iVar7 + 0xe038) * 4);
                  cVar4 = FUN_00492b81();
                  if (cVar4 == '\0') {
                    *(undefined1 *)(iVar7 + 0xe060) = 1;
                    goto LAB_00496049;
                  }
                  *(undefined1 *)(iVar7 + 0xe060) = 0;
                }
              }
            }
          }
        }
        uVar12 = *(undefined1 *)(unaff_EBP + 0xb);
        goto LAB_00496054;
      }
    }
  }
  else if (*(int *)(unaff_EBP + 0xc) == 1) {
    switch(*(undefined4 *)(unaff_EBP + 0x10)) {
    case 0:
    case 1:
      local_2bc = (undefined1 *)0x1;
      break;
    case 2:
    case 3:
      local_2bc = (undefined1 *)0x2;
      break;
    case 4:
    case 5:
      local_2bc = (undefined1 *)0x20;
      break;
    case 6:
    case 7:
      local_2bc = (undefined1 *)0x10;
      break;
    default:
      local_2bc = (undefined1 *)0x0;
    }
    *(bool *)(unaff_EBP + 0xb) =
         (undefined1 *)((uint)local_2bc & *(uint *)(unaff_EBP + -0xa8)) == local_2bc;
    if (*(char *)(unaff_EBP + 0xb) != '\0') {
      *(char *)(unaff_EBP + -0x1c) = *pcVar3;
      *(char *)(unaff_EBP + -0x1b) = pcVar3[1];
      *(char *)(unaff_EBP + -0x1a) = pcVar3[2];
      iVar7 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      local_2bc = (undefined1 *)(-*(int *)(iVar7 + 0x84) & 3);
      FUN_00434ffd();
      local_2bc = (undefined1 *)0x0;
      FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x1c);
      if ((0 < *(int *)(unaff_EBP + -0x10)) && (*(int *)(unaff_EBP + -0x10) < 3)) {
        piVar6 = *(int **)(unaff_EBP + -0x28);
        while (piVar6 != (int *)0x0) {
          if (*(short *)(piVar6[0x46] + 0x12) == 8) {
            local_2bc = (undefined1 *)0x4952e7;
            cVar4 = (**(code **)(*piVar6 + 0x70))();
            if (cVar4 == '\0') {
              *(undefined1 *)(unaff_EBP + 0xb) = 0;
              piVar6 = (int *)(*(int *)(unaff_EBP + -0x20) + 0xe064);
              if (*piVar6 == 0) {
                *piVar6 = 0x23;
              }
              goto LAB_004954de;
            }
          }
          if ((*(short *)(piVar6[0x46] + 0x12) != 8) && (*(short *)(piVar6[0x46] + 0x12) != 2)) {
            uVar1 = *(ushort *)(piVar6 + 0x19);
            iVar7 = *(int *)(&DAT_006f4620 +
                            ((((int)(-(int)(short)piVar6[0x13] & 7U) >> 1) -
                              *(int *)(DAT_006e54d8 + 0x84) & 3U) * 0x40 +
                            *(int *)(unaff_EBP + -0x10)) * 4);
            if (((((iVar7 == 1) && ((uVar1 & 8) != 0)) || ((iVar7 == 8 && ((uVar1 & 4) != 0)))) ||
                ((iVar7 == 2 && ((uVar1 & 1) != 0)))) || ((iVar7 == 4 && ((uVar1 & 2) != 0)))) {
              *(undefined1 *)(unaff_EBP + 0xb) = 0;
              piVar6 = (int *)(*(int *)(unaff_EBP + -0x20) + 0xe064);
              if (*piVar6 != 0) goto LAB_004954de;
              *piVar6 = 0xb;
              break;
            }
          }
          local_2bc = (undefined1 *)0x49535a;
          FUN_0043f3b9();
          piVar6 = *(int **)(unaff_EBP + -0x28);
        }
        if (*(char *)(unaff_EBP + 0xb) != '\0') {
          cVar4 = *pcVar3;
          cVar5 = pcVar3[1];
          cVar10 = pcVar3[2];
          *(char *)(unaff_EBP + -0x16) = cVar10;
          if (*(int *)(unaff_EBP + -0x10) == 1) {
            *(undefined1 *)(unaff_EBP + 0x10) = DAT_006e4822;
            cVar13 = DAT_006e4823;
            cVar4 = cVar4 + *(char *)(unaff_EBP + 0x10);
            *(char *)(unaff_EBP + 0x11) = DAT_006e4823;
            *(char *)(unaff_EBP + -0x18) = cVar4;
          }
          else {
            *(undefined1 *)(unaff_EBP + 0x10) = DAT_006e481c;
            cVar13 = DAT_006e481d;
            cVar4 = cVar4 + *(char *)(unaff_EBP + 0x10);
            *(char *)(unaff_EBP + 0x11) = DAT_006e481d;
            *(char *)(unaff_EBP + -0x18) = cVar4;
          }
          *(char *)(unaff_EBP + -0x17) = cVar5 + cVar13;
          *(char *)(unaff_EBP + 0x10) = cVar4;
          *(char *)(unaff_EBP + 0x11) = cVar5 + cVar13;
          *(char *)(unaff_EBP + 0x12) = cVar10;
          iVar7 = DAT_006e54d8;
          *(undefined1 *)(unaff_EBP + -4) = 9;
          local_2bc = (undefined1 *)(-*(int *)(iVar7 + 0x84) & 3);
          FUN_00434ffd();
          local_2bc = (undefined1 *)0x0;
          iVar7 = *(int *)(&DAT_006f4820 + *(int *)(unaff_EBP + -0x10) * 4);
          FUN_0043f371(*DAT_006e486c,unaff_EBP + 0x10);
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x70);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x6c);
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x68);
          if (*(int *)(unaff_EBP + -0x6c) != 0) {
            iVar11 = *(int *)(unaff_EBP + -0x28);
            do {
              sVar2 = *(short *)(*(int *)(iVar11 + 0x118) + 0x12);
              if ((sVar2 != 8) && (sVar2 != 2)) {
                uVar1 = *(ushort *)(iVar11 + 100);
                iVar11 = *(int *)(&DAT_006f4620 +
                                 (((-CONCAT22((short)((uint)iVar11 >> 0x10),
                                              *(undefined2 *)(iVar11 + 0x4c)) >> 1) -
                                   *(int *)(DAT_006e54d8 + 0x84) & 3U) * 0x40 + iVar7) * 4);
                if ((((iVar11 == 1) && ((uVar1 & 8) != 0)) ||
                    (((iVar11 == 8 && ((uVar1 & 4) != 0)) || ((iVar11 == 2 && ((uVar1 & 1) != 0)))))
                    ) || ((iVar11 == 4 && ((uVar1 & 2) != 0)))) {
                  *(undefined1 *)(unaff_EBP + 0xb) = 0;
                  piVar6 = (int *)(*(int *)(unaff_EBP + -0x20) + 0xe064);
                  if (*piVar6 == 0) {
                    *piVar6 = 0xb;
                  }
                  break;
                }
              }
              local_2bc = (undefined1 *)0x4954be;
              FUN_0043f3b9();
              iVar11 = *(int *)(unaff_EBP + -0x28);
            } while (iVar11 != 0);
          }
        }
      }
    }
LAB_004954de:
    uVar12 = *(undefined1 *)(unaff_EBP + 0xb);
    goto LAB_00496054;
  }
LAB_00496052:
  uVar12 = 0;
LAB_00496054:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar12;
}

