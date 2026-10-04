
undefined4 FUN_0043d7c8(void)

{
  int *piVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  size_t sVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  ushort *puVar12;
  undefined4 uVar13;
  char *pcVar14;
  int extraout_ECX;
  undefined2 extraout_var;
  int iVar15;
  int unaff_EBP;
  short sVar16;
  short *psVar17;
  int iVar18;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_0055e4e2(unaff_EBP + -0x29);
  iVar18 = *(int *)(extraout_ECX + 0x20);
  iVar7 = *(int *)(extraout_ECX + 0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x20) = iVar18;
  iVar9 = extraout_ECX;
  if (iVar18 != iVar7) {
    do {
      iVar7 = FUN_00457e1c();
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if ((iVar7 != 0) && (*(char *)(iVar7 + 0xc) != '\0')) {
        *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x4c);
        iVar7 = FUN_0043f353(*(undefined4 *)(unaff_EBP + -0x50),*(undefined4 *)(unaff_EBP + -0x4c),
                             unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + 8));
        if (iVar7 == *(int *)(unaff_EBP + -0x24)) {
          FUN_0043e5f0(unaff_EBP + -0x14);
          FUN_0046f824(unaff_EBP + -0x144,0,0x40);
          *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_0066651c;
          FUN_00457f7a(unaff_EBP + -0x150);
          FUN_00475714(0x10);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          iVar7 = FUN_00475b91(*(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14),
                               CONCAT22(extraout_var,
                                        *(undefined2 *)(*(int *)(unaff_EBP + -0x14) + 0x18)));
          if (iVar7 == 0) {
            uVar6 = (**(code **)(**(int **)(*(int *)(unaff_EBP + -0x14) + 0x14) + 0x20))();
            iVar15 = *(int *)(unaff_EBP + -0x14);
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
            *(undefined4 *)(unaff_EBP + -0x28) = 0;
            *(undefined1 *)(unaff_EBP + -0x19) = uVar6;
            iVar7 = *(int *)(iVar15 + 4);
            if (0 < iVar7) {
              do {
                if (*(char *)(unaff_EBP + -0xd) != '\0') goto LAB_0043d9f5;
                iVar9 = *(int *)(unaff_EBP + -0x28);
                if ((iVar9 < 0) || (iVar7 <= iVar9)) {
                  iVar7 = 0;
                }
                else {
                  iVar7 = *(int *)(*(int *)(iVar15 + 0x10) + iVar9 * 4);
                }
                if ((iVar9 < 0) || (*(int *)(unaff_EBP + -0x68) <= iVar9)) {
                  iVar9 = 0;
                }
                else {
                  iVar9 = *(int *)(*(int *)(unaff_EBP + -0x5c) + iVar9 * 4);
                }
                if ((*(short *)(iVar7 + 0x1c) == 0x32) && ((*(uint *)(iVar7 + 0x14) >> 7 & 1) == 0))
                {
                  if ((iVar9 == 0) ||
                     ((*(short *)(iVar9 + 0x1c) != 0x32 ||
                      (*(int *)(iVar7 + 0xc) != *(int *)(iVar9 + 0xc))))) {
                    *(undefined1 *)(unaff_EBP + -0xd) = 1;
                  }
                  else {
                    iVar4 = *(int *)(iVar15 + 8);
                    *(undefined4 *)(unaff_EBP + -0x24) = 0;
                    if (0 < iVar4) {
                      puVar10 = *(undefined4 **)(iVar9 + 8);
                      iVar7 = *(int *)(iVar7 + 8) - (int)puVar10;
                      do {
                        puVar2 = (undefined4 *)(iVar7 + (int)puVar10);
                        *(undefined4 *)(unaff_EBP + -0x34) = *puVar2;
                        *(undefined2 *)(unaff_EBP + -0x30) = *(undefined2 *)(puVar2 + 1);
                        *(undefined4 *)(unaff_EBP + -0x3c) = *puVar10;
                        *(undefined2 *)(unaff_EBP + -0x38) = *(undefined2 *)(puVar10 + 1);
                        sVar16 = (short)*(undefined4 *)(unaff_EBP + -0x32);
                        if (sVar16 != *(short *)(unaff_EBP + -0x3a)) {
LAB_0043d9d2:
                          *(undefined1 *)(unaff_EBP + -0xd) = 1;
                          break;
                        }
                        if (((int)*(short *)(unaff_EBP + -0x30) + (int)sVar16 !=
                             (int)*(short *)(unaff_EBP + -0x38) + (int)*(short *)(unaff_EBP + -0x3a)
                            ) || (*(short *)(unaff_EBP + -0x34) != *(short *)(unaff_EBP + -0x3c))) {
                          iVar15 = *(int *)(unaff_EBP + -0x14);
                          goto LAB_0043d9d2;
                        }
                        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
                        iVar15 = *(int *)(unaff_EBP + -0x14);
                        puVar10 = (undefined4 *)((int)puVar10 + 6);
                      } while (*(int *)(unaff_EBP + -0x24) < *(int *)(iVar15 + 8));
                      iVar18 = *(int *)(unaff_EBP + -0x20);
                    }
                  }
                }
                *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
                iVar7 = *(int *)(iVar15 + 4);
              } while (*(int *)(unaff_EBP + -0x28) < iVar7);
              if (*(char *)(unaff_EBP + -0xd) != '\0') {
LAB_0043d9f5:
                FUN_0046f824(unaff_EBP + -0xac,0,0x40);
                *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066651c;
                FUN_0046fa40((int)*(short *)(*(int *)(unaff_EBP + -0x14) + 0x18));
                if (*(char *)(unaff_EBP + -0x19) == '\0') {
                  pcVar14 = s_Differences_found_in_read_only_t_006c3abc;
                }
                else {
                  iVar7 = FUN_004573f9();
                  uVar13 = *(undefined4 *)(iVar7 + 0x18);
                  FUN_0046f824(unaff_EBP + -0xf8,0,0x40);
                  *(undefined ***)(unaff_EBP + -0x104) = &PTR_FUN_0066651c;
                  FUN_0046f847(uVar13,0xffffffff);
                  FUN_0046f847(s_tree_table_006c3ab0,0xffffffff);
                  FUN_00475797(unaff_EBP + -0x104);
                  pcVar14 = s_Saved_differences_for_tree_table_006c3a8c;
                }
                sVar8 = _strlen(pcVar14);
                FUN_00412d8a(pcVar14,pcVar14 + sVar8);
                pcVar14 = *(char **)(unaff_EBP + -0x14c);
                sVar8 = _strlen(pcVar14);
                FUN_00412d8a(pcVar14,pcVar14 + sVar8);
                sVar8 = _strlen(s___id_006c3a84);
                FUN_00412d8a(s___id_006c3a84,s___id_006c3a84 + sVar8);
                pcVar14 = *(char **)(unaff_EBP + -0xb4);
                sVar8 = _strlen(pcVar14);
                FUN_00412d8a(pcVar14,pcVar14 + sVar8);
                sVar8 = _strlen(&DAT_006c08dc);
                FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar8);
              }
              iVar9 = *(int *)(unaff_EBP + -0x18);
            }
          }
          else {
            FUN_0043e34e(s_Could_not_load_tree_table_from_o_006c3ae8);
            *(char **)(unaff_EBP + -0x20) = *(char **)(unaff_EBP + -0x14c);
            sVar8 = _strlen(*(char **)(unaff_EBP + -0x14c));
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x20),sVar8 + *(int *)(unaff_EBP + -0x20));
            sVar8 = _strlen(&DAT_006c08dc);
            FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar8);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00475754();
        }
      }
      iVar18 = iVar18 + 4;
      iVar7 = *(int *)(iVar9 + 0x24);
      *(int *)(unaff_EBP + -0x20) = iVar18;
    } while (iVar18 != iVar7);
  }
  FUN_00580a92(unaff_EBP + -0x34);
  iVar7 = *(int *)(unaff_EBP + -0x34);
  *(int *)(unaff_EBP + -0x44) = iVar7;
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x30);
  while (iVar7 != 0) {
    piVar11 = (int *)FUN_006359f2(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 0x34),0,
                                  &iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,
                                  0);
    if ((piVar11[0x92] - piVar11[0x91] & 0xfffffff8U) != 0) {
      FUN_0046f824(unaff_EBP + -0x364,0,0x104);
      *(undefined ***)(unaff_EBP + -0x370) = &PTR_FUN_006664e8;
      FUN_0046f824(unaff_EBP + -0x254,0,0x104);
      *(undefined ***)(unaff_EBP + -0x260) = &PTR_FUN_006664e8;
      (**(code **)(*piVar11 + 0x24))(unaff_EBP + -0x260);
      FUN_0041218d(unaff_EBP + -0x260,unaff_EBP + -0x370);
      uVar6 = (**(code **)(*piVar11 + 0x20))();
      psVar17 = (short *)piVar11[0x91];
      *(undefined1 *)(unaff_EBP + -0x19) = uVar6;
      for (; psVar17 != (short *)piVar11[0x92]; psVar17 = psVar17 + 4) {
        sVar16 = *psVar17;
        iVar7 = *piVar11;
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        iVar7 = (**(code **)(iVar7 + 0x38))(0x42434f4e,sVar16,0);
        *(int *)(unaff_EBP + -0x14) = iVar7;
        if (iVar7 != 0) {
          *(uint *)(unaff_EBP + -0x18) = **(ushort **)(psVar17 + 2) & 0x7fff;
          puVar12 = (ushort *)FUN_00420048(*(undefined4 *)(unaff_EBP + -0x14));
          uVar5 = *(uint *)(unaff_EBP + -0x18);
          uVar3 = *puVar12;
          *(ushort **)(unaff_EBP + -0x20) = puVar12;
          if (uVar5 == (uVar3 & 0x7fff)) {
            if (0 < (int)uVar5) {
              *(uint *)(unaff_EBP + -0x18) = uVar5;
              iVar7 = 2;
              while( true ) {
                if (*(short *)(iVar7 + (int)puVar12) != *(short *)(*(int *)(psVar17 + 2) + iVar7)) {
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
                iVar7 = iVar7 + 2;
                piVar1 = (int *)(unaff_EBP + -0x18);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) break;
                puVar12 = *(ushort **)(unaff_EBP + -0x20);
              }
            }
          }
          else {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          FUN_0042004f(*(undefined4 *)(unaff_EBP + -0x14));
          if (*(char *)(unaff_EBP + -0xd) != '\0') {
            if (*(char *)(unaff_EBP + -0x19) == '\0') {
              sVar8 = _strlen(s_Read_only_constants_are_differen_006c3a4c);
              pcVar14 = s_Read_only_constants_are_differen_006c3a4c;
            }
            else {
              iVar7 = (**(ushort **)(psVar17 + 2) & 0x7fff) * 2 + 2;
              *(int *)(unaff_EBP + -0x20) = iVar7;
              FUN_004200aa(*(undefined4 *)(unaff_EBP + -0x14),iVar7);
              uVar13 = FUN_00420048(*(undefined4 *)(unaff_EBP + -0x14));
              *(undefined4 *)(unaff_EBP + -0x18) = uVar13;
              FUN_005a92b0(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(psVar17 + 2),
                           *(undefined4 *)(unaff_EBP + -0x20));
              FUN_0042004f(*(undefined4 *)(unaff_EBP + -0x14));
              **(ushort **)(unaff_EBP + -0x18) = **(ushort **)(unaff_EBP + -0x18) | 0x8000;
              (**(code **)(*piVar11 + 0x7c))(*(undefined4 *)(unaff_EBP + -0x14));
              sVar8 = _strlen(s_Wrote_constants_006c3a70);
              pcVar14 = s_Wrote_constants_006c3a70;
            }
            FUN_00412d8a(pcVar14,pcVar14 + sVar8);
            FUN_0046f824(unaff_EBP + -0xac,0,0x40);
            sVar16 = *psVar17;
            *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066651c;
            FUN_0046fa40((int)sVar16);
            *(char **)(unaff_EBP + -0x18) = *(char **)(unaff_EBP + -0x36c);
            sVar8 = _strlen(*(char **)(unaff_EBP + -0x36c));
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),sVar8 + *(int *)(unaff_EBP + -0x18));
            sVar8 = _strlen(s___id_006c3a84);
            FUN_00412d8a(s___id_006c3a84,s___id_006c3a84 + sVar8);
            *(char **)(unaff_EBP + -0x18) = *(char **)(unaff_EBP + -0xb4);
            sVar8 = _strlen(*(char **)(unaff_EBP + -0xb4));
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),sVar8 + *(int *)(unaff_EBP + -0x18));
            sVar8 = _strlen(&DAT_006c08dc);
            FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar8);
          }
        }
      }
    }
    FUN_0043ef9b();
    iVar7 = *(int *)(unaff_EBP + -0x44);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

