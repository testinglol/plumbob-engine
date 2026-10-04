
undefined4 FUN_0048955c(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  short *psVar8;
  undefined4 extraout_ECX;
  int iVar9;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  int iVar10;
  int iVar11;
  undefined1 extraout_var_01;
  uint uVar12;
  int iVar13;
  int unaff_EBP;
  int iVar14;
  bool bVar15;
  int iStack_b4;
  undefined4 local_b0;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x54) = extraout_ECX;
  local_b0 = 0x489577;
  uVar3 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar3;
  *(char *)(unaff_EBP + -0x1a) = (char)uVar3;
  iVar13 = **(int **)(unaff_EBP + 8);
  uVar1 = (undefined1)((*(int **)(unaff_EBP + 8))[1] >> 4);
  *(undefined1 *)(unaff_EBP + -0x1c) = uVar1;
  *(char *)(unaff_EBP + -0x1b) = (char)(iVar13 >> 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + 8) = &local_b0;
  local_b0._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x1b),uVar1);
  local_b0._3_1_ = (char)(iVar13 >> 0x1c);
  local_b0._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x1a),(undefined2)local_b0);
  iStack_b4 = 0x4895b6;
  uVar4 = FUN_00489b59();
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(*DAT_006e486c + 0x24);
  if ((short)uVar4 != -5) {
    local_b0 = 0x10;
    *(int **)(unaff_EBP + 8) = &iStack_b4;
    FUN_00461b74(unaff_EBP + -0x1c);
    cVar2 = FUN_004687d9();
    if (cVar2 == '\0') {
      local_b0 = 0x20;
      *(int **)(unaff_EBP + 8) = &iStack_b4;
      FUN_00461b74(unaff_EBP + -0x1c);
      cVar2 = FUN_004687d9();
      if (cVar2 == '\0') {
        iStack_b4 = 0x489614;
        local_b0 = uVar4;
        puVar5 = (undefined2 *)FUN_004670a4();
        *(undefined2 **)(unaff_EBP + 0x10) = puVar5;
        goto LAB_00489726;
      }
    }
  }
  *(undefined1 *)(unaff_EBP + -0x40) = *(undefined1 *)(unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -0x3f) = *(undefined1 *)(unaff_EBP + -0x1b);
  *(undefined1 *)(unaff_EBP + -0x3e) = *(undefined1 *)(unaff_EBP + -0x1a);
  iVar13 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  local_b0 = -*(int *)(iVar13 + 0x84) & 3;
  iStack_b4 = 0x48964b;
  FUN_00434ffd();
  local_b0 = unaff_EBP + -0x20;
  iStack_b4 = unaff_EBP + -0x18;
  FUN_004672d0(unaff_EBP + -0x40,unaff_EBP + -0x28,unaff_EBP + -0x24);
  iVar13 = DAT_006e54d8;
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    iVar14 = 0;
  }
  else {
    iVar14 = ((*(int *)(unaff_EBP + -0x18) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) + 1;
  }
  *(int *)(unaff_EBP + -0x18) = iVar14;
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    iVar13 = 0;
  }
  else {
    iVar13 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(iVar13 + 0x84)) - 1U & 3) + 1;
  }
  *(int *)(unaff_EBP + -0x20) = iVar13;
  *(undefined4 **)(unaff_EBP + 8) = &local_b0;
  local_b0._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x1b),*(undefined1 *)(unaff_EBP + -0x1c));
  local_b0._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x1a),(undefined2)local_b0);
  local_b0 = (uint)(uint3)local_b0;
  iStack_b4 = unaff_EBP + -0xac;
  FUN_00467768();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (((byte)*(undefined4 *)(unaff_EBP + -0xac) & 0x20) == 0x20) {
    *(int *)(unaff_EBP + -0x10) = (int)*(char *)(unaff_EBP + -0x1b);
    iStack_b4 = unaff_EBP + -0x14;
    *(int *)(unaff_EBP + -0x14) = (int)*(char *)(unaff_EBP + -0x1c);
    local_b0 = uVar3;
    uVar6 = FUN_004a6a71();
    *(undefined4 *)(unaff_EBP + 8) = uVar6;
    if (*(short *)(unaff_EBP + 0x12) < *(short *)(unaff_EBP + 10)) {
      bVar15 = *(int *)(unaff_EBP + -0x18) == 1;
    }
    else {
      bVar15 = *(int *)(unaff_EBP + -0x18) == 3;
    }
    if (bVar15) {
      puVar5 = *(undefined2 **)(unaff_EBP + -0x28);
    }
    else {
LAB_0048971c:
      puVar5 = *(undefined2 **)(unaff_EBP + -0x24);
    }
  }
  else {
    puVar5 = *(undefined2 **)(unaff_EBP + -0x28);
    if (*(int *)(unaff_EBP + -0x18) != 2) goto LAB_0048971c;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined2 **)(unaff_EBP + 0x10) = puVar5;
LAB_00489726:
  if ((uVar4 & 0x3ff) == 0) {
LAB_00489b55:
    uVar3 = 0;
  }
  else {
    iVar14 = *(int *)(puVar5 + 2);
    iVar13 = *(int *)(puVar5 + 4);
    *(undefined2 *)(unaff_EBP + -0x3c) = *puVar5;
    *(int *)(unaff_EBP + -0x50) = iVar14;
    if (iVar14 != iVar13) {
      do {
        local_b0 = unaff_EBP + -0x14;
        iStack_b4 = 0x489757;
        FUN_00434d3d();
        *(char *)(unaff_EBP + 10) = (char)uVar3;
        *(char *)(unaff_EBP + 8) = (char)(*(int *)(unaff_EBP + -0x10) >> 4);
        *(char *)(unaff_EBP + 9) = (char)(*(int *)(unaff_EBP + -0x14) >> 4);
        iVar13 = DAT_006e54d8;
        local_b0 = 0x400;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        iStack_b4 = *(int *)(iVar13 + 0x84);
        FUN_0047bd91(unaff_EBP + -0x10,unaff_EBP + -0x14);
        puVar7 = (undefined4 *)(unaff_EBP + -0x38);
        iVar13 = 2;
        iVar9 = iVar13;
        do {
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7 = puVar7 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar9 = 0;
        if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x40 + *(char *)(unaff_EBP + 10) * 4
                                                ) + 0xc) + *(char *)(unaff_EBP + 8) * 4) +
                     *(char *)(unaff_EBP + 9) * 0xe) == '\0') {
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x14);
          *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x10);
          iVar9 = 1;
        }
        else {
          local_b0 = *(undefined4 *)(DAT_006e54d8 + 0x84);
          iStack_b4 = 0x4897e2;
          FUN_00434ffd();
          *(undefined4 **)(unaff_EBP + -0x48) = &local_b0;
          local_b0._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
          local_b0._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_b0);
          local_b0 = CONCAT13(extraout_var,(uint3)local_b0);
          iStack_b4 = unaff_EBP + -0x80;
          FUN_00467768();
          *(undefined1 *)(unaff_EBP + -4) = 4;
          if (((byte)*(undefined4 *)(unaff_EBP + -0x80) & 0x10) == 0x10) {
            local_b0 = unaff_EBP + -0x20;
            iStack_b4 = unaff_EBP + -0x18;
            cVar2 = FUN_004672d0(iVar14,unaff_EBP + -0x28,unaff_EBP + -0x24);
            iVar11 = DAT_006e54d8;
            if (cVar2 == '\0') {
              *(undefined4 **)(unaff_EBP + -0x48) = &local_b0;
              local_b0._0_2_ =
                   CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
              local_b0._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_b0);
              local_b0 = CONCAT13(extraout_var_00,(uint3)local_b0);
              iStack_b4 = 0x489899;
              local_b0 = FUN_00489b59();
              iStack_b4 = 0x4898a2;
              psVar8 = (short *)FUN_004670a4();
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
              *(undefined4 *)(unaff_EBP + -0x20) = 0;
              *(short **)(unaff_EBP + -0x28) = psVar8;
              *(short **)(unaff_EBP + -0x24) = psVar8;
            }
            else {
              if (*(int *)(unaff_EBP + -0x18) == 0) {
                iVar10 = 0;
              }
              else {
                iVar10 = ((*(int *)(unaff_EBP + -0x18) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) +
                         1;
              }
              *(int *)(unaff_EBP + -0x18) = iVar10;
              if (*(int *)(unaff_EBP + -0x20) == 0) {
                iVar11 = 0;
              }
              else {
                iVar11 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(iVar11 + 0x84)) - 1U & 3) + 1;
              }
              psVar8 = *(short **)(unaff_EBP + -0x28);
              *(int *)(unaff_EBP + -0x20) = iVar11;
            }
            if ((psVar8 == (short *)0x0) || (*psVar8 != *(short *)(unaff_EBP + -0x3c))) {
              uVar12 = *(uint *)(unaff_EBP + -0x14);
              uVar4 = *(uint *)(unaff_EBP + -0x10);
            }
            else {
              if (*(int *)(unaff_EBP + -0x18) == 2) {
                uVar4 = *(uint *)(unaff_EBP + -0x10) | 0xf;
                uVar12 = *(uint *)(unaff_EBP + -0x14) | 0xf;
                *(uint *)(unaff_EBP + -0x10) = uVar4;
              }
              else {
                uVar4 = *(uint *)(unaff_EBP + -0x10);
                if (*(int *)(unaff_EBP + -0x18) != 4) {
                  *(uint *)(unaff_EBP + -0x34) = uVar4 | 0xf;
                  *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x14) | 0xf;
                  uVar4 = uVar4 & 0xfffffff0;
                  uVar12 = *(uint *)(unaff_EBP + -0x14) & 0xfffffff0;
                  *(uint *)(unaff_EBP + -0x10) = uVar4;
                  *(uint *)(unaff_EBP + -0x14) = uVar12;
                  *(uint *)(unaff_EBP + -0x30) = uVar12;
                  *(uint *)(unaff_EBP + -0x2c) = uVar4;
                  iVar9 = iVar13;
                  goto LAB_00489921;
                }
                uVar4 = uVar4 & 0xfffffff0;
                *(uint *)(unaff_EBP + -0x10) = uVar4;
                uVar12 = *(uint *)(unaff_EBP + -0x14) & 0xfffffff0;
              }
              *(uint *)(unaff_EBP + -0x14) = uVar12;
              *(uint *)(unaff_EBP + -0x38) = uVar12;
              *(uint *)(unaff_EBP + -0x34) = uVar4;
              iVar9 = 1;
            }
LAB_00489921:
            if (((*(int *)(unaff_EBP + -0x24) != 0) && (*(short **)(unaff_EBP + -0x24) != psVar8))
               && (**(short **)(unaff_EBP + -0x24) == *(short *)(unaff_EBP + -0x3c))) {
              if (*(int *)(unaff_EBP + -0x20) == 2) {
                uVar4 = uVar4 | 0xf;
LAB_0048994d:
                *(uint *)(unaff_EBP + -0x10) = uVar4;
                uVar12 = uVar12 | 0xf;
              }
              else {
                if (*(int *)(unaff_EBP + -0x20) != 4) {
                  uVar12 = uVar12 | 0xf;
                  uVar4 = uVar4 | 0xf;
                  *(uint *)(unaff_EBP + -0x38 + iVar9 * 8) = uVar12;
                  *(uint *)(unaff_EBP + -0x34 + iVar9 * 8) = uVar4;
                  iVar9 = iVar9 + 1;
                }
                uVar4 = uVar4 & 0xfffffff0;
LAB_00489ab8:
                *(uint *)(unaff_EBP + -0x10) = uVar4;
                uVar12 = uVar12 & 0xfffffff0;
              }
              *(uint *)(unaff_EBP + -0x38 + iVar9 * 8) = uVar12;
              *(uint *)(unaff_EBP + -0x34 + iVar9 * 8) = uVar4;
              *(uint *)(unaff_EBP + -0x14) = uVar12;
              iVar9 = iVar9 + 1;
            }
          }
          else if (((byte)*(undefined4 *)(unaff_EBP + -0x80) & 0x20) == 0x20) {
            local_b0 = unaff_EBP + -0x20;
            iStack_b4 = unaff_EBP + -0x18;
            cVar2 = FUN_004672d0(iVar14,unaff_EBP + -0x28,unaff_EBP + -0x24);
            iVar11 = DAT_006e54d8;
            if (cVar2 == '\0') {
              *(undefined4 **)(unaff_EBP + -0x48) = &local_b0;
              local_b0._0_2_ =
                   CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
              local_b0._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_b0);
              local_b0 = CONCAT13(extraout_var_01,(uint3)local_b0);
              iStack_b4 = 0x489a02;
              local_b0 = FUN_00489b59();
              iStack_b4 = 0x489a0b;
              psVar8 = (short *)FUN_004670a4();
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
              *(undefined4 *)(unaff_EBP + -0x20) = 0;
              *(short **)(unaff_EBP + -0x28) = psVar8;
              *(short **)(unaff_EBP + -0x24) = psVar8;
            }
            else {
              if (*(int *)(unaff_EBP + -0x18) == 0) {
                iVar10 = 0;
              }
              else {
                iVar10 = ((*(int *)(unaff_EBP + -0x18) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) +
                         1;
              }
              *(int *)(unaff_EBP + -0x18) = iVar10;
              if (*(int *)(unaff_EBP + -0x20) == 0) {
                iVar11 = 0;
              }
              else {
                iVar11 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(iVar11 + 0x84)) - 1U & 3) + 1;
              }
              psVar8 = *(short **)(unaff_EBP + -0x28);
              *(int *)(unaff_EBP + -0x20) = iVar11;
            }
            if ((psVar8 == (short *)0x0) || (*psVar8 != *(short *)(unaff_EBP + -0x3c))) {
              uVar12 = *(uint *)(unaff_EBP + -0x14);
              uVar4 = *(uint *)(unaff_EBP + -0x10);
            }
            else {
              if (*(int *)(unaff_EBP + -0x18) == 1) {
                uVar4 = *(uint *)(unaff_EBP + -0x10) & 0xfffffff0;
                uVar12 = *(uint *)(unaff_EBP + -0x14) | 0xf;
                *(uint *)(unaff_EBP + -0x10) = uVar4;
              }
              else {
                if (*(int *)(unaff_EBP + -0x18) != 3) {
                  uVar4 = *(uint *)(unaff_EBP + -0x10) & 0xfffffff0;
                  *(uint *)(unaff_EBP + -0x34) = uVar4;
                  *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x14) | 0xf;
                  uVar4 = uVar4 | 0xf;
                  uVar12 = *(uint *)(unaff_EBP + -0x14) & 0xfffffff0;
                  *(uint *)(unaff_EBP + -0x10) = uVar4;
                  *(uint *)(unaff_EBP + -0x14) = uVar12;
                  *(uint *)(unaff_EBP + -0x30) = uVar12;
                  *(uint *)(unaff_EBP + -0x2c) = uVar4;
                  iVar9 = iVar13;
                  goto LAB_00489a8a;
                }
                uVar4 = *(uint *)(unaff_EBP + -0x10) | 0xf;
                *(uint *)(unaff_EBP + -0x10) = uVar4;
                uVar12 = *(uint *)(unaff_EBP + -0x14) & 0xfffffff0;
              }
              *(uint *)(unaff_EBP + -0x14) = uVar12;
              *(uint *)(unaff_EBP + -0x38) = uVar12;
              *(uint *)(unaff_EBP + -0x34) = uVar4;
              iVar9 = 1;
            }
LAB_00489a8a:
            if (((*(int *)(unaff_EBP + -0x24) != 0) && (*(short **)(unaff_EBP + -0x24) != psVar8))
               && (**(short **)(unaff_EBP + -0x24) == *(short *)(unaff_EBP + -0x3c))) {
              if (*(int *)(unaff_EBP + -0x20) != 1) {
                if (*(int *)(unaff_EBP + -0x20) != 3) {
                  uVar12 = uVar12 | 0xf;
                  uVar4 = uVar4 & 0xfffffff0;
                  *(uint *)(unaff_EBP + -0x38 + iVar9 * 8) = uVar12;
                  *(uint *)(unaff_EBP + -0x34 + iVar9 * 8) = uVar4;
                  iVar9 = iVar9 + 1;
                }
                uVar4 = uVar4 | 0xf;
                goto LAB_00489ab8;
              }
              uVar4 = uVar4 & 0xfffffff0;
              goto LAB_0048994d;
            }
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x10);
            iVar9 = 1;
          }
          *(undefined1 *)(unaff_EBP + -4) = 3;
        }
        iVar13 = 0;
        if (iVar9 != 0) {
          iVar14 = unaff_EBP + -0x38;
          do {
            local_b0 = 0;
            iStack_b4 = 0;
            cVar2 = FUN_00488de7(iVar14,*(undefined4 *)(unaff_EBP + -0x4c),
                                 *(undefined4 *)(unaff_EBP + 0xc));
            if (cVar2 == '\0') goto LAB_00489b55;
            iVar13 = iVar13 + 1;
            iVar14 = iVar14 + 8;
          } while (iVar13 < iVar9);
          iVar14 = *(int *)(unaff_EBP + -0x50);
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        iVar14 = iVar14 + 3;
        iVar13 = *(int *)(*(int *)(unaff_EBP + 0x10) + 8);
        *(int *)(unaff_EBP + -0x50) = iVar14;
        if (iVar14 == iVar13) break;
        uVar3 = *(undefined4 *)(unaff_EBP + -0x4c);
      } while( true );
    }
    uVar3 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

