
undefined4 FUN_004a553d(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  size_t sVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  int iVar22;
  byte bVar23;
  char cVar24;
  int iVar25;
  int iVar26;
  int *piVar27;
  char *pcVar28;
  undefined ***pppuVar29;
  char *pcVar30;
  CHAR local_610 [256];
  undefined1 local_510 [1024];
  CHAR local_110 [256];
  undefined **local_10 [2];
  char local_6;
  char local_5;
  
  iVar16 = param_2;
  iVar25 = param_1;
  if ((((param_2 != 0) && (uVar17 = 2, param_2 != 1)) && (param_2 != 2)) && (param_2 != 4)) {
    if (param_2 == 3) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
        pcVar30 = *(char **)(*(int *)(param_1 + 4) + 0xc);
        if (pcVar30 == (char *)0x0) {
          pcVar30 = s_Null_token__006c71e8;
        }
        else {
          sVar15 = _strlen(pcVar30);
          iVar25 = 0;
          if (0 < (int)sVar15) {
            do {
              iVar16 = FUN_006368c3((int)pcVar30[iVar25]);
              if (iVar16 == 0) goto LAB_004a558d;
              iVar25 = iVar25 + 1;
            } while (iVar25 < (int)sVar15);
          }
          FUN_00634d24(pcVar30,&DAT_006c08e4,&param_2);
          if (DAT_006e486c[7] != 0) {
            FUN_0046d9f8(param_2);
            return 1;
          }
          pcVar30 = s_NULL_Simulator__006c71d8;
        }
      }
      else {
LAB_004a558d:
        pcVar30 = s_format_is__money__amt____e_g___m_006c71f4;
      }
      goto LAB_004a6466;
    }
    if (param_2 == 5) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
        iVar16 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
        param_2 = 0;
        iVar25 = *(int *)(DAT_006e54dc + 0x10);
        if (0 < iVar25) {
          iVar19 = 0x40;
          iVar21 = DAT_006e54dc;
          do {
            iVar26 = 0;
            if (0 < iVar25) {
              do {
                iVar25 = *(int *)(*(int *)(*(int *)(iVar21 + 0x14) + 0xc) + (char)iVar26 * 4);
                uVar1 = *(uint *)(iVar25 + (char)param_2 * 4);
                iVar21 = (uVar1 & 0xff) + iVar16;
                if (iVar21 < 0) {
                  iVar21 = 0;
                }
                if (0x40 < iVar21) {
                  iVar21 = iVar19;
                }
                iVar22 = (uVar1 >> 8 & 0xff) + iVar16;
                if (iVar22 < 0) {
                  iVar22 = 0;
                }
                if (0x40 < iVar22) {
                  iVar22 = iVar19;
                }
                param_1._0_2_ = CONCAT11((char)iVar22,(char)iVar21);
                iVar21 = (uVar1 >> 0x10 & 0xff) + iVar16;
                if (iVar21 < 0) {
                  iVar21 = 0;
                }
                if (0x40 < iVar21) {
                  iVar21 = iVar19;
                }
                iVar22 = (uVar1 >> 0x18) + iVar16;
                if (iVar22 < 0) {
                  iVar22 = 0;
                }
                if (0x40 < iVar22) {
                  iVar22 = iVar19;
                }
                param_1 = CONCAT13((char)iVar22,CONCAT12((char)iVar21,(undefined2)param_1));
                *(int *)(iVar25 + (char)param_2 * 4) = param_1;
                iVar26 = iVar26 + 1;
                iVar21 = DAT_006e54dc;
              } while (iVar26 < *(int *)(DAT_006e54dc + 0x10));
            }
            iVar25 = *(int *)(iVar21 + 0x10);
            param_2 = param_2 + 1;
          } while (param_2 < iVar25);
        }
        FUN_0040766a(0x85,0);
        FUN_0040766a(0x83,0);
        return 1;
      }
      pcVar30 = s_useage__alt_add__amt__006c71c0;
      goto LAB_004a6466;
    }
    if (param_2 == 6) {
      if (*(int *)(DAT_006e54d8 + 0x84) == 0) {
        if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 3) {
          uVar17 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
          uVar18 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0x18));
          iVar25 = *(int *)(DAT_006e54d8 + 0x10);
          iVar16 = FUN_00636bef(uVar17);
          if ((iVar16 < iVar25 + -1) &&
             (iVar25 = *(int *)(DAT_006e54d8 + 0x10), iVar16 = FUN_00636bef(uVar18),
             iVar16 < iVar25 + -1)) {
            param_1._0_2_ = (undefined2)uVar18;
            param_2 = CONCAT22((undefined2)param_1,(short)uVar17);
            FUN_0040766a(0x106,param_2);
            FUN_0040766a(0x83,0);
            FUN_0040766a(0x91,0);
            uVar17 = 0;
            FUN_00540a5b(0);
            FUN_005407ce(uVar17);
            return 1;
          }
          pcVar30 = s_Offset_too_big__006c7158;
        }
        else {
          pcVar30 = s_Usage__offset_world__x_amt___y_a_006c7168;
        }
      }
      else {
        pcVar30 = s_Sorry__must_be_in_rotation_0__Us_006c718c;
      }
      goto LAB_004a6466;
    }
    if (param_2 == 7) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
        iVar25 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
        if ((4 < iVar25) && (iVar16 = *(int *)(DAT_006e54dc + 0x10), iVar25 <= iVar16)) {
          param_2 = 0;
          iVar19 = (iVar16 - iVar25) / 2;
          iVar25 = DAT_006e54dc;
          if (iVar16 < 1) {
            return 1;
          }
          do {
            param_1 = 0;
            if (0 < iVar16) {
              do {
                iVar25 = *(int *)(*(int *)(*(int *)(iVar25 + 0x34) + 0xc) + (char)param_1 * 4);
                bVar23 = *(byte *)(iVar25 + (char)param_2);
                if ((((param_1 < iVar19) || (iVar16 - iVar19 <= param_1)) || (param_2 < iVar19)) ||
                   (iVar16 - iVar19 <= param_2)) {
                  bVar23 = bVar23 | 0x20;
                }
                else {
                  bVar23 = bVar23 & 0xdf;
                }
                param_1 = param_1 + 1;
                *(byte *)(iVar25 + (char)param_2) = bVar23;
                iVar16 = *(int *)(DAT_006e54dc + 0x10);
                iVar25 = DAT_006e54dc;
              } while (param_1 < iVar16);
            }
            iVar16 = *(int *)(iVar25 + 0x10);
            param_2 = param_2 + 1;
          } while (param_2 < iVar16);
          return 1;
        }
        pcVar30 = s_size_out_of_range__006c712c;
      }
      else {
        pcVar30 = s_Usage__edit_size__size__006c7140;
      }
      goto LAB_004a6466;
    }
    if (param_2 == 8) {
      if (*(int *)(*(int *)(DAT_006f2a08 + 0x88) + 0xf8) != 0) {
        if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) &&
           ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3)) {
          return 0;
        }
        local_10[0] = (undefined **)&DAT_006c7110;
        local_10[1] = &PTR_DAT_006c710c;
        iVar25 = 0;
        pppuVar29 = local_10;
        do {
          iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),(char *)*pppuVar29);
          if (iVar16 == 0) {
            if (iVar25 == 0) {
              uVar17 = 1;
LAB_004a5942:
              FUN_0050a33d(uVar17);
              return 1;
            }
            if (iVar25 == 1) {
              uVar17 = 0;
              goto LAB_004a5942;
            }
          }
          iVar25 = iVar25 + 1;
          pppuVar29 = pppuVar29 + 1;
          if (1 < iVar25) {
            return 1;
          }
        } while( true );
      }
      pcVar30 = s_Sweep_meter_is_NULL__006c7114;
      goto LAB_004a6466;
    }
    if (param_2 == 9) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
        pcVar30 = *(char **)(*(int *)(param_1 + 4) + 0xc);
        iVar25 = _strcmp(&DAT_006c3a18,pcVar30);
        if (iVar25 == 0) {
          uVar17 = 0;
LAB_004a59b9:
          iVar25 = *(int *)(*DAT_006e486c + 0x14);
          for (piVar27 = *(int **)(iVar25 + 0x84); piVar27 != *(int **)(iVar25 + 0x88);
              piVar27 = piVar27 + 1) {
            if ((((int *)*piVar27 != (int *)0x0) &&
                (piVar20 = (int *)(**(code **)(*(int *)*piVar27 + 0x8c))(), piVar20 != (int *)0x0))
               && (iVar16 = (**(code **)(*piVar20 + 0xac))(), iVar16 != 0)) {
              FUN_005a18a4(uVar17);
            }
          }
          return 1;
        }
        iVar25 = _strcmp(s_medium_006c3a1c,pcVar30);
        if (iVar25 == 0) {
          uVar17 = 1;
          goto LAB_004a59b9;
        }
        iVar25 = _strcmp(&DAT_006c3a24,pcVar30);
        if (iVar25 == 0) goto LAB_004a59b9;
      }
      pcVar30 = s_Usage__people_quality__low_mediu_006c70e4;
      goto LAB_004a6466;
    }
    if (param_2 == 10) {
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
        iVar25 = _strcmp(s_default_006c0a4c,*(char **)(*(int *)(param_1 + 4) + 0xc));
        if (iVar25 != 0) {
          iVar25 = _strcmp(s_status_006c70dc,*(char **)(*(int *)(param_1 + 4) + 0xc));
          if (iVar25 != 0) {
            return 0;
          }
          wsprintfA(local_610,s_Genable_Status___Enabled_HouseVi_006c70ac);
          local_510[0] = 0;
          pcVar28 = s_false_006c0ab4;
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723a == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Terrain____s_006c7098,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723b == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Floors____s_006c7084,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723c == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Walls____s_006c7070,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723d == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Clear_Refresh____s_006c705c,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723e == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Objects____s_006c7048,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c723f == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_People____s_006c7034,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006f0094 == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Full_Draw____s_006c7024,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c7240 == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Static_Rows____s_006c700c,pcVar30);
          FUN_006358c0(local_510,local_110);
          pcVar30 = &DAT_006c0aac;
          if (DAT_006c7241 == '\0') {
            pcVar30 = s_false_006c0ab4;
          }
          wsprintfA(local_110,s_Draw_Static____s_006c6ff8,pcVar30);
          FUN_006358c0(local_510,local_110);
          if (DAT_006f0095 != '\0') {
            pcVar28 = &DAT_006c0aac;
          }
          wsprintfA(local_110,s_Old_Clear____s_006c6fe8,pcVar28);
          FUN_006358c0(local_510,local_110);
LAB_004a5cd5:
          FUN_004f6994(local_510,local_610,0,0);
          return 1;
        }
        DAT_006f0094 = '\0';
        DAT_006f0095 = '\0';
        DAT_006c723a = '\x01';
        DAT_006c723b = '\x01';
        DAT_006c723c = '\x01';
        DAT_006c723d = '\x01';
        DAT_006c723e = '\x01';
        DAT_006c723f = '\x01';
        DAT_006c7240 = '\x01';
        DAT_006c7241 = '\x01';
        cVar2 = DAT_006c723a;
        cVar3 = DAT_006c723b;
        cVar4 = DAT_006c723c;
        cVar5 = DAT_006c723d;
        cVar6 = DAT_006c723e;
        cVar7 = DAT_006c723f;
        cVar8 = DAT_006c7240;
        cVar9 = DAT_006c7241;
        cVar10 = DAT_006f0094;
        cVar11 = DAT_006f0095;
      }
      else {
        if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3) {
          return 0;
        }
        iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0x18),&DAT_006c7110);
        if (iVar25 == 0) {
          cVar24 = '\x01';
        }
        else {
          iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0x18),(char *)&PTR_DAT_006c710c);
          if (iVar25 != 0) {
            return 0;
          }
          cVar24 = '\0';
        }
        iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_terrain_006c6fe0);
        cVar2 = cVar24;
        cVar3 = DAT_006c723b;
        cVar4 = DAT_006c723c;
        cVar5 = DAT_006c723d;
        cVar6 = DAT_006c723e;
        cVar7 = DAT_006c723f;
        cVar8 = DAT_006c7240;
        cVar9 = DAT_006c7241;
        cVar10 = DAT_006f0094;
        cVar11 = DAT_006f0095;
        if (((((iVar25 != 0) &&
              (iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_floors_006c1e18),
              cVar2 = DAT_006c723a, cVar3 = cVar24, cVar4 = DAT_006c723c, cVar5 = DAT_006c723d,
              cVar6 = DAT_006c723e, cVar7 = DAT_006c723f, cVar8 = DAT_006c7240, cVar9 = DAT_006c7241
              , cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0)) &&
             ((iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_walls_006c1e20),
              cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = cVar24, cVar5 = DAT_006c723d,
              cVar6 = DAT_006c723e, cVar7 = DAT_006c723f, cVar8 = DAT_006c7240, cVar9 = DAT_006c7241
              , cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0 &&
              (((iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_clear_006c53ac),
                cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c, cVar5 = cVar24,
                cVar6 = DAT_006c723e, cVar7 = DAT_006c723f, cVar8 = DAT_006c7240,
                cVar9 = DAT_006c7241, cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0 &&
                (iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_objects_006c4f20),
                cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
                cVar5 = DAT_006c723d, cVar6 = cVar24, cVar7 = DAT_006c723f, cVar8 = DAT_006c7240,
                cVar9 = DAT_006c7241, cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0)) &&
               (iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_people_006c6fd8),
               cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
               cVar5 = DAT_006c723d, cVar6 = DAT_006c723e, cVar7 = cVar24, cVar8 = DAT_006c7240,
               cVar9 = DAT_006c7241, cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0))))))
            && ((iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_full_draw_006c6fcc),
                cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
                cVar5 = DAT_006c723d, cVar6 = DAT_006c723e, cVar7 = DAT_006c723f,
                cVar8 = DAT_006c7240, cVar9 = DAT_006c7241, cVar10 = cVar24, cVar11 = DAT_006f0095,
                iVar25 != 0 &&
                (iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_static_rows_006c6fc0),
                cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
                cVar5 = DAT_006c723d, cVar6 = DAT_006c723e, cVar7 = DAT_006c723f, cVar8 = cVar24,
                cVar9 = DAT_006c7241, cVar10 = DAT_006f0094, cVar11 = DAT_006f0095, iVar25 != 0))))
           && ((iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_static_006c6fb8),
               cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
               cVar5 = DAT_006c723d, cVar6 = DAT_006c723e, cVar7 = DAT_006c723f,
               cVar8 = DAT_006c7240, cVar9 = cVar24, cVar10 = DAT_006f0094, cVar11 = DAT_006f0095,
               iVar25 != 0 &&
               ((iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),s_old_clear_006c6fac),
                cVar2 = DAT_006c723a, cVar3 = DAT_006c723b, cVar4 = DAT_006c723c,
                cVar5 = DAT_006c723d, cVar6 = DAT_006c723e, cVar7 = DAT_006c723f,
                cVar8 = DAT_006c7240, cVar9 = DAT_006c7241, cVar10 = DAT_006f0094, cVar11 = cVar24,
                iVar25 != 0 &&
                (iVar25 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),
                                  (char *)&PTR_s_ire_altitude_layer_006c6c38_0x29_006c6fa8),
                cVar2 = cVar24, cVar3 = cVar24, cVar4 = cVar24, cVar5 = cVar24, cVar6 = cVar24,
                cVar7 = cVar24, cVar8 = cVar24, cVar9 = cVar24, cVar10 = DAT_006f0094,
                cVar11 = DAT_006f0095, iVar25 != 0)))))) {
          return 0;
        }
      }
LAB_004a5a87:
      DAT_006f0095 = cVar11;
      DAT_006f0094 = cVar10;
      DAT_006c7241 = cVar9;
      DAT_006c7240 = cVar8;
      DAT_006c723f = cVar7;
      DAT_006c723e = cVar6;
      DAT_006c723d = cVar5;
      DAT_006c723c = cVar4;
      DAT_006c723b = cVar3;
      DAT_006c723a = cVar2;
      FUN_004a6a39();
      return 1;
    }
    if (param_2 != 0xb) {
      if (param_2 != 0xc) {
        if (param_2 != 0xd) {
          if (param_2 != 0xe) {
            if (param_2 != 0xf) {
              if (param_2 != 0x10) {
                return 1;
              }
              if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) &&
                 ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3)) {
                return 0;
              }
              local_10[0] = (undefined **)&DAT_006c7110;
              local_10[1] = &PTR_DAT_006c710c;
              iVar25 = 0;
              pppuVar29 = local_10;
              do {
                iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),(char *)*pppuVar29);
                if (iVar16 == 0) {
                  if (iVar25 == 0) {
                    return 1;
                  }
                  if (iVar25 == 1) {
                    return 1;
                  }
                }
                iVar25 = iVar25 + 1;
                pppuVar29 = pppuVar29 + 1;
                if (1 < iVar25) {
                  return 1;
                }
              } while( true );
            }
            if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) &&
               ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3)) {
              return 0;
            }
            local_10[0] = (undefined **)&DAT_006c7110;
            local_10[1] = &PTR_DAT_006c710c;
            iVar25 = 0;
            pppuVar29 = local_10;
            do {
              iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),(char *)*pppuVar29);
              if (iVar16 == 0) {
                if (iVar25 == 0) {
                  *(undefined1 *)(DAT_006e486c[1] + 0x180) = 1;
                  return 1;
                }
                if (iVar25 == 1) {
                  *(undefined1 *)(DAT_006e486c[1] + 0x180) = 0;
                  return 1;
                }
              }
              iVar25 = iVar25 + 1;
              pppuVar29 = pppuVar29 + 1;
              if (1 < iVar25) {
                return 1;
              }
            } while( true );
          }
          if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) &&
             ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3)) {
            return 0;
          }
          local_10[0] = (undefined **)&DAT_006c7110;
          local_10[1] = &PTR_DAT_006c710c;
          iVar25 = 0;
          pppuVar29 = local_10;
          do {
            iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0xc),(char *)*pppuVar29);
            if (iVar16 == 0) {
              if (iVar25 == 0) {
                *(undefined1 *)(DAT_006e486c[1] + 0x518) = 1;
                return 1;
              }
              if (iVar25 == 1) {
                *(undefined1 *)(DAT_006e486c[1] + 0x518) = 0;
                return 1;
              }
            }
            iVar25 = iVar25 + 1;
            pppuVar29 = pppuVar29 + 1;
            if (1 < iVar25) {
              return 1;
            }
          } while( true );
        }
        iVar16 = DAT_006e486c[1];
        cVar24 = *(char *)(iVar16 + 0x17e);
        local_5 = *(char *)(iVar16 + 0x17f);
        param_2 = CONCAT13(*(undefined1 *)(iVar16 + 0x17d),0xd);
        local_6 = cVar24;
        if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
          iVar25 = _strcmp(s_default_006c0a4c,*(char **)(*(int *)(param_1 + 4) + 0xc));
          cVar2 = DAT_006c723a;
          cVar3 = DAT_006c723b;
          cVar4 = DAT_006c723c;
          cVar5 = DAT_006c723d;
          cVar6 = DAT_006c723e;
          cVar7 = DAT_006c723f;
          cVar8 = DAT_006c7240;
          cVar9 = DAT_006c7241;
          cVar10 = DAT_006f0094;
          cVar11 = DAT_006f0095;
          if (iVar25 != 0) {
            iVar25 = _strcmp(s_status_006c70dc,*(char **)(*(int *)(param_1 + 4) + 0xc));
            if (iVar25 != 0) {
              return 0;
            }
            wsprintfA(local_610,s_DamageList_Status_006c6ed8);
            local_510[0] = 0;
            pcVar28 = s_false_006c0ab4;
            pcVar30 = &DAT_006c0aac;
            if (param_2._3_1_ == '\0') {
              pcVar30 = s_false_006c0ab4;
            }
            wsprintfA(local_110,s_Draw_Refresh_Damage____s_006c6ebc,pcVar30);
            FUN_006358c0(local_510,local_110);
            pcVar30 = &DAT_006c0aac;
            if (local_5 == '\0') {
              pcVar30 = s_false_006c0ab4;
            }
            wsprintfA(local_110,s_Draw_Current_Damage____s_006c6ea0,pcVar30);
            FUN_006358c0(local_510,local_110);
            if (local_6 != '\0') {
              pcVar28 = &DAT_006c0aac;
            }
            wsprintfA(local_110,s_Draw_Previous_Damage____s_006c6e84,pcVar28);
            FUN_006358c0(local_510,local_110);
            goto LAB_004a5cd5;
          }
        }
        else {
          if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 3) {
            return 0;
          }
          iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0x18),&DAT_006c7110);
          if (iVar16 == 0) {
            param_1._3_1_ = '\x01';
          }
          else {
            iVar16 = _strcmp(*(char **)(*(int *)(param_1 + 4) + 0x18),(char *)&PTR_DAT_006c710c);
            if (iVar16 != 0) {
              return 0;
            }
            param_1._3_1_ = '\0';
          }
          iVar16 = _strcmp(*(char **)(*(int *)(iVar25 + 4) + 0xc),s_refresh_006c6e7c);
          if (iVar16 == 0) {
            param_2 = CONCAT13(param_1._3_1_,(undefined3)param_2);
            param_1._3_1_ = cVar24;
          }
          else {
            iVar16 = _strcmp(*(char **)(*(int *)(iVar25 + 4) + 0xc),s_current_006c6e74);
            if (iVar16 == 0) {
              local_5 = param_1._3_1_;
              param_1._3_1_ = cVar24;
            }
            else {
              iVar16 = _strcmp(*(char **)(*(int *)(iVar25 + 4) + 0xc),s_previous_006c6e68);
              if (iVar16 != 0) {
                iVar25 = _strcmp(*(char **)(*(int *)(iVar25 + 4) + 0xc),
                                 (char *)&PTR_s_ire_altitude_layer_006c6c38_0x29_006c6fa8);
                if (iVar25 != 0) {
                  return 0;
                }
                param_2 = CONCAT13(param_1._3_1_,(undefined3)param_2);
                local_5 = param_1._3_1_;
                local_6 = param_1._3_1_;
              }
            }
          }
          *(char *)(DAT_006e486c[1] + 0x17d) = param_2._3_1_;
          *(char *)(DAT_006e486c[1] + 0x17e) = param_1._3_1_;
          *(char *)(DAT_006e486c[1] + 0x17f) = local_5;
          cVar2 = DAT_006c723a;
          cVar3 = DAT_006c723b;
          cVar4 = DAT_006c723c;
          cVar5 = DAT_006c723d;
          cVar6 = DAT_006c723e;
          cVar7 = DAT_006c723f;
          cVar8 = DAT_006c7240;
          cVar9 = DAT_006c7241;
          cVar10 = DAT_006f0094;
          cVar11 = DAT_006f0095;
        }
        goto LAB_004a5a87;
      }
      if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) ||
         (((iVar25 = _strcmp(&DAT_006c6fa0,*(char **)(*(int *)(param_1 + 4) + 0xc)),
           uVar12 = DAT_006f0138, uVar13 = DAT_006f013a, iVar25 != 0 &&
           (iVar25 = _strcmp(s_vacation_006c6f94,*(char **)(*(int *)(param_1 + 4) + 0xc)),
           uVar12 = DAT_006f0138, uVar13 = DAT_006f013a, iVar25 != 0)) &&
          (iVar25 = _strcmp(&DAT_006c6f28,*(char **)(*(int *)(param_1 + 4) + 0xc)),
          uVar12 = DAT_006f0138, uVar13 = DAT_006f013a, iVar25 != 0)))) {
        pcVar30 = s__sims___vacation___x___are_the_o_006c6eec;
        goto LAB_004a6466;
      }
      goto LAB_004a6455;
    }
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
      iVar25 = _strcmp(&DAT_006c6fa0,*(char **)(*(int *)(param_1 + 4) + 0xc));
      uVar18 = 0;
      if (iVar25 != 0) {
        iVar25 = _strcmp(s_vacation_006c6f94,*(char **)(*(int *)(param_1 + 4) + 0xc));
        if (iVar25 == 0) {
          uVar18 = 1;
        }
        else {
          iVar25 = _strcmp(s_alpha_006c6f8c,*(char **)(*(int *)(param_1 + 4) + 0xc));
          uVar18 = uVar17;
          if (iVar25 != 0) {
            iVar25 = _strcmp(s_depth_006c6f84,*(char **)(*(int *)(param_1 + 4) + 0xc));
            if (iVar25 == 0) {
              uVar18 = 3;
            }
            else {
              iVar25 = _strcmp(s_index_006c6f7c,*(char **)(*(int *)(param_1 + 4) + 0xc));
              if (iVar25 != 0) goto LAB_004a5f71;
              uVar18 = 4;
            }
          }
        }
      }
      FUN_004bbabe(uVar18);
      uVar12 = DAT_006f0138;
      uVar13 = DAT_006f013a;
      goto LAB_004a6455;
    }
LAB_004a5f71:
    pcVar30 = s__sims___vacation___alpha___depth_006c6f2c;
    goto LAB_004a6466;
  }
  if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) {
LAB_004a645e:
    pcVar30 = s__on__and__off__are_the_only_acce_006c6e34;
LAB_004a6466:
    FUN_005d4bbf(pcVar30);
    return 0;
  }
  iVar25 = _strcmp(&DAT_006c7110,*(char **)(*(int *)(param_1 + 4) + 0xc));
  if (iVar25 == 0) {
    uVar14 = 1;
  }
  else {
    iVar25 = _strcmp((char *)&PTR_DAT_006c710c,*(char **)(*(int *)(param_1 + 4) + 0xc));
    if (iVar25 != 0) goto LAB_004a645e;
    uVar14 = 0;
  }
  if (iVar16 == 0) {
    DAT_006f0139 = uVar14;
    FUN_004bbabe(1);
    uVar12 = DAT_006f0138;
    uVar13 = DAT_006f013a;
  }
  else {
    uVar12 = DAT_006f0138;
    uVar13 = uVar14;
    if (((iVar16 != 1) && (uVar12 = uVar14, uVar13 = DAT_006f013a, iVar16 != 2)) &&
       ((uVar12 = DAT_006f0138, iVar16 == 4 && (DAT_006e486c[8] != 0)))) {
      FUN_004c440c(uVar14);
      uVar12 = DAT_006f0138;
      uVar13 = DAT_006f013a;
    }
  }
LAB_004a6455:
  DAT_006f013a = uVar13;
  DAT_006f0138 = uVar12;
  FUN_00476bf8();
  return 1;
}

