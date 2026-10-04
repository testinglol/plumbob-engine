
undefined4 FUN_00491375(void)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  char cVar8;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  int iVar11;
  undefined4 local_38;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x12) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  local_38 = unaff_EBP + -0xe;
  FUN_0055e4e2();
  local_38 = unaff_EBP + -0xd;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined1 *)(unaff_EBP + -0xd) = 0xfb;
  FUN_0047ca8d();
  iVar5 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x18) = iVar5;
  if (iVar5 <= *(int *)(unaff_EBP + 0x10)) {
    iVar11 = *(int *)(unaff_EBP + 0x14);
    iVar9 = iVar5;
    do {
      for (iVar10 = *(int *)(unaff_EBP + 0xc); iVar10 <= iVar11; iVar10 = iVar10 + 1) {
        if ((((iVar9 == iVar5) || (iVar9 == *(int *)(unaff_EBP + 0x10))) ||
            (iVar10 == *(int *)(unaff_EBP + 0xc))) || (iVar10 == iVar11)) {
          *(char *)(unaff_EBP + 8) = (char)iVar9;
          *(char *)(unaff_EBP + 9) = (char)iVar10;
          *(undefined1 *)(unaff_EBP + 10) = 1;
          local_38 = unaff_EBP + 8;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_0047c34d();
          iVar9 = *(int *)(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 1;
        }
        else {
          iVar2 = *(int *)(*(int *)(DAT_006e57c0 + 0xc) + iVar9 * 4);
          *(byte *)(iVar2 + iVar10) = *(byte *)(iVar2 + iVar10) | 4;
        }
      }
      iVar9 = iVar9 + 1;
      *(int *)(unaff_EBP + -0x18) = iVar9;
    } while (iVar9 <= *(int *)(unaff_EBP + 0x10));
  }
  *(undefined4 *)(unaff_EBP + 0x14) = 0;
  if ((*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34)) / 3 != 0) {
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    iVar5 = DAT_006e54d8;
    do {
      iVar11 = *(int *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 1;
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 3;
      pcVar4 = (char *)(iVar11 + *(int *)(unaff_EBP + -0x34));
      *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(iVar11 + 1 + *(int *)(unaff_EBP + -0x34))
      ;
      cVar3 = *pcVar4;
      cVar8 = pcVar4[2];
      iVar11 = *(int *)(iVar5 + 0x70);
      *(char *)(unaff_EBP + -0x14) = cVar3;
      iVar9 = (int)cVar3;
      *(char *)(unaff_EBP + -0x12) = cVar8;
      if (((iVar11 + 1 <= iVar9) && (iVar9 <= *(int *)(iVar5 + 0x74) + -1)) &&
         ((iVar11 = (int)*(char *)(unaff_EBP + -0x13), *(int *)(iVar5 + 0x78) + 1 <= iVar11 &&
          (iVar11 <= *(int *)(iVar5 + 0x7c) + -1)))) {
        *(undefined4 **)(unaff_EBP + 8) = &local_38;
        local_38._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x13),cVar3);
        local_38._3_1_ = (undefined1)((uint)iVar5 >> 0x18);
        local_38._0_3_ = CONCAT12(cVar8,(undefined2)local_38);
        iVar5 = FUN_004796d9(unaff_EBP + -0x24);
        *(uint *)(unaff_EBP + -0x18) = (uint)*(byte *)(iVar5 + 1);
        pcVar4 = &DAT_006e57b4;
        iVar5 = *(int *)(DAT_006e57c0 + 0xc);
        *(undefined1 **)(unaff_EBP + 8) = &DAT_006e57b4;
        pbVar6 = (byte *)(*(int *)(iVar5 + iVar9 * 4) + iVar11);
        iVar11 = *(int *)(unaff_EBP + -0x1c);
        *pbVar6 = *pbVar6 | 4;
        iVar5 = DAT_006e54d8;
        do {
          *(char *)(unaff_EBP + 0xe) = cVar8;
          cVar3 = *pcVar4 + *(char *)(unaff_EBP + -0x14);
          cVar8 = pcVar4[1] + *(char *)(unaff_EBP + -0x13);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          *(char *)(unaff_EBP + 0xc) = cVar3;
          *(char *)(unaff_EBP + 0xd) = cVar8;
          if ((((int)cVar3 < *(int *)(iVar5 + 0x70) + 1) ||
              (*(int *)(iVar5 + 0x74) + -1 < (int)cVar3)) ||
             (((int)cVar8 < *(int *)(iVar5 + 0x78) + 1 || (*(int *)(iVar5 + 0x7c) + -1 < (int)cVar8)
              ))) {
            *(undefined1 *)(unaff_EBP + -4) = 1;
          }
          else {
            *(undefined4 **)(unaff_EBP + -0x20) = &local_38;
            local_38._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0xd),cVar3);
            local_38._3_1_ = (undefined1)((uint)iVar5 >> 0x18);
            local_38._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0xe),(undefined2)local_38);
            iVar9 = FUN_004796d9(unaff_EBP + -0x28);
            iVar5 = *(int *)(unaff_EBP + -0x18);
            iVar9 = (uint)*(byte *)(iVar9 + 1) - iVar5;
            if ((5 < iVar9) || (iVar9 < -5)) {
              local_38 = *(undefined4 *)(unaff_EBP + 0xc);
              *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x30);
              iVar10 = FUN_004921b0(*(int *)(unaff_EBP + -0x34) + *(int *)(unaff_EBP + 0x10),
                                    *(undefined4 *)(unaff_EBP + -0x30),unaff_EBP + 0xc);
              if (iVar10 == *(int *)(unaff_EBP + -0x20)) {
                if ((*(byte *)(*(int *)(*(int *)(DAT_006e57c0 + 0xc) +
                                       *(char *)(unaff_EBP + 0xc) * 4) +
                              (int)*(char *)(unaff_EBP + 0xd)) & 4) == 0) {
                  local_38 = 1;
                  cVar3 = FUN_00491801(unaff_EBP + 0xc);
                  if (cVar3 != '\0') {
                    if (iVar9 < 6) {
                      local_38 = iVar5 + -5;
                      iVar9 = -iVar9;
                    }
                    else {
                      local_38 = iVar5 + 5;
                    }
                    *(int *)(iVar11 + 0x30) = *(int *)(iVar11 + 0x30) + DAT_006e57d0 * (iVar9 + -5);
                    FUN_004909e0(unaff_EBP + 0xc);
                    local_38 = unaff_EBP + 0xc;
                    FUN_0047c34d();
                    goto LAB_00491603;
                  }
                }
                uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
                *(undefined1 *)(unaff_EBP + -4) = 0;
                *(undefined4 *)(iVar11 + 0x38) = 1;
                *(undefined1 *)(iVar11 + 0x34) = uVar1;
                *(undefined1 *)(iVar11 + 0x35) = *(undefined1 *)(unaff_EBP + 0xd);
                *(undefined1 *)(iVar11 + 0x36) = *(undefined1 *)(unaff_EBP + 0xe);
                local_38 = 0x491677;
                FUN_00468a63();
                uVar7 = 0;
                goto LAB_00491641;
              }
            }
LAB_00491603:
            iVar5 = DAT_006e54d8;
            *(undefined1 *)(unaff_EBP + -4) = 1;
          }
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 3;
          if (0x6e57bf < *(int *)(unaff_EBP + 8)) break;
          cVar8 = *(char *)(unaff_EBP + -0x12);
          pcVar4 = *(char **)(unaff_EBP + 8);
        } while( true );
      }
    } while (*(uint *)(unaff_EBP + 0x14) <
             (uint)((*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34)) / 3));
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  local_38 = 0x49163f;
  FUN_00468a63();
  uVar7 = 1;
LAB_00491641:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

