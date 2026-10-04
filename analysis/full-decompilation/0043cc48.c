
/* WARNING (jumptable): Unable to track spacebase fully for stack */

int FUN_0043cc48(void)

{
  undefined2 *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  ushort *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int extraout_ECX;
  uint uVar13;
  int unaff_EBP;
  char *pcVar14;
  uint uVar15;
  int iVar16;
  TypeDescriptor *pTVar17;
  TypeDescriptor *pTVar18;
  undefined2 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x34) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x268,0,0x104);
  *(undefined ***)(unaff_EBP + -0x274) = &PTR_FUN_006664e8;
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar20 = 0xffffffff;
  uVar5 = FUN_0041532c(0,0xffffffff);
  FUN_0046f847(uVar5,uVar20);
  FUN_0046f847(s_Tuning_txt_006c3a04,0xffffffff);
  FUN_0046ea4d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar6 = FUN_0046eaca(unaff_EBP + -0x274);
  if (iVar6 == 0) {
    uVar5 = FUN_0046ed90();
    *(undefined4 *)(unaff_EBP + -0x20) = uVar5;
    iVar6 = FUN_0046ed9c();
    if (iVar6 < 2) {
      pcVar14 = s_Not_enough_columns_in_the_text_f_006c39c8;
    }
    else if (*(int *)(unaff_EBP + -0x20) < 1) {
      pcVar14 = s_Not_enough_rows_in_the_text_file_006c39a4;
    }
    else {
      uVar5 = FUN_0046edbd(1,0);
      FUN_0046f824(unaff_EBP + -0x484,0,0x100);
      *(undefined ***)(unaff_EBP + -0x490) = &PTR_FUN_00666524;
      FUN_0046f847(uVar5,0xffffffff);
      iVar6 = FUN_0046fab1(DAT_006e4ba4,0);
      if (iVar6 == 0) {
        iVar6 = FUN_00635f62((uint)DAT_006e4ba8 + *(int *)(unaff_EBP + -0x48c));
        if (iVar6 == 2) {
          FUN_00580a92(unaff_EBP + -0x44);
          iVar6 = *(int *)(unaff_EBP + -0x44);
          *(int *)(unaff_EBP + -0x2c) = iVar6;
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x40);
          while (iVar6 != 0) {
            FUN_006359f2(*(undefined4 *)(*(int *)(unaff_EBP + -0x2c) + 0x34),0,
                         &iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0);
            FUN_004569a5();
            FUN_0043ef9b();
            iVar6 = *(int *)(unaff_EBP + -0x2c);
          }
          puVar8 = operator_new(0x202);
          *puVar8 = *puVar8 | 0x8000;
          *(ushort **)(unaff_EBP + -0x3c) = puVar8;
          iVar6 = 1;
          *(undefined4 *)(unaff_EBP + -0x10) = 1;
          if (1 < *(int *)(unaff_EBP + -0x20)) {
            do {
              uVar5 = FUN_0046edbd(0,iVar6);
              FUN_0046f824(unaff_EBP + -0x378,0,0x104);
              *(undefined ***)(unaff_EBP + -900) = &PTR_FUN_006664e8;
              FUN_0046f847(uVar5,0xffffffff);
              if (*(short *)(unaff_EBP + -0x37c) != 0) {
                uVar21 = 0;
                pTVar18 = &ObjResFile::RTTI_Type_Descriptor;
                pTVar17 = &iResFile::RTTI_Type_Descriptor;
                uVar20 = 0;
                uVar5 = FUN_00411c32(unaff_EBP + -900);
                piVar9 = (int *)FUN_006359f2(uVar5,uVar20,pTVar17,pTVar18,uVar21);
                *(int **)(unaff_EBP + -0x30) = piVar9;
                if (piVar9 == (int *)0x0) {
                  FUN_00580a92(unaff_EBP + -0x50);
                  iVar10 = *(int *)(unaff_EBP + -0x50);
                  *(int *)(unaff_EBP + -0x2c) = iVar10;
                  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x4c);
                  while (iVar10 != 0) {
                    FUN_0046f824(unaff_EBP + -0x6a4,0,0x104);
                    *(undefined ***)(unaff_EBP + -0x6b0) = &PTR_FUN_006664e8;
                    FUN_0046f824(unaff_EBP + -0x8c4,0,0x104);
                    *(undefined ***)(unaff_EBP + -0x8d0) = &PTR_FUN_006664e8;
                    FUN_0046f824(unaff_EBP + -0x7b4,0,0x104);
                    *(undefined ***)(unaff_EBP + -0x7c0) = &PTR_FUN_006664e8;
                    FUN_0046f824(unaff_EBP + -0x594,0,0x104);
                    *(undefined ***)(unaff_EBP + -0x5a0) = &PTR_FUN_006664e8;
                    (**(code **)(**(int **)(*(int *)(unaff_EBP + -0x2c) + 0x34) + 0x24))
                              (unaff_EBP + -0x6b0);
                    FUN_0041207e(unaff_EBP + -0x6b0,unaff_EBP + -0x8d0,unaff_EBP + -0x5a0,
                                 unaff_EBP + -0x7c0);
                    iVar10 = FUN_0046f973(unaff_EBP + -900);
                    if (iVar10 == 0) {
                      piVar9 = (int *)FUN_006359f2(*(undefined4 *)
                                                    (*(int *)(unaff_EBP + -0x2c) + 0x34),0,
                                                   &iResFile::RTTI_Type_Descriptor,
                                                   &ObjResFile::RTTI_Type_Descriptor,0);
                      *(int **)(unaff_EBP + -0x30) = piVar9;
                      break;
                    }
                    FUN_0043ef9b();
                    iVar10 = *(int *)(unaff_EBP + -0x2c);
                  }
                }
                FUN_0046f824(unaff_EBP + -0x158,0,0x100);
                *(undefined ***)(unaff_EBP + -0x164) = &PTR_FUN_00666524;
                if (piVar9 == (int *)0x0) {
                  pcVar14 = s_Object_file_not_found__006c3940;
                  uVar5 = 0;
LAB_0043d312:
                  FUN_0043d6ae(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,uVar5,iVar6,pcVar14)
                  ;
                }
                else {
                  uVar20 = 0xffffffff;
                  uVar5 = FUN_0046edbd(1,iVar6);
                  FUN_0046f847(uVar5,uVar20);
                  iVar10 = FUN_0046fab1(&DAT_006c0c28,0);
                  if (iVar10 < 0) {
                    pcVar14 = s_Colon_separator_not_found__006c3924;
                    goto LAB_0043d30f;
                  }
                  *(undefined2 *)(unaff_EBP + -0x15c) = 0;
                  **(undefined1 **)(unaff_EBP + -0x160) = 0;
                  iVar11 = iVar10;
                  uVar5 = FUN_0046edbd(1,iVar6);
                  FUN_0046f847(uVar5,iVar11);
                  iVar11 = _strcmp(*(char **)(unaff_EBP + -0x160),&DAT_006c3920);
                  if (iVar11 == 0) {
                    iVar11 = FUN_0046edbd(1,iVar6);
                    iVar10 = FUN_00635f62(iVar11 + 1 + iVar10);
                    *(int *)(unaff_EBP + -0x48) = iVar10;
                    if (iVar10 == 0) {
                      pcVar14 = s_Could_not_parse_guid__006c3908;
                    }
                    else {
                      FUN_00575b11(unaff_EBP + -0x58,unaff_EBP + -0x48);
                      if (*(int *)(unaff_EBP + -0x58) == 0) {
                        pcVar14 = s_Could_not_find_object_with_guid__006c38e4;
                      }
                      else {
                        iVar10 = FUN_00457e1c();
                        *(int *)(unaff_EBP + -0x30) = iVar10;
                        if (iVar10 != 0) {
                          iVar6 = iVar6 + 1;
                          *(undefined1 *)(iVar10 + 0xc) = 1;
                          if (*(int *)(unaff_EBP + -0x20) <= iVar6) goto LAB_0043d45f;
                          do {
                            iVar10 = FUN_0046edbd(0,iVar6);
                            if (iVar10 == 0) break;
                            iVar11 = 0;
                            iVar10 = FUN_0046eeb1(0,iVar6);
                            uVar5 = FUN_0046eeb1(1,iVar6);
                            *(undefined4 *)(unaff_EBP + -0x38) = uVar5;
                            uVar5 = FUN_0046edbd(2,iVar6);
                            *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
                            uVar5 = FUN_0046eeb1(3,iVar6);
                            *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
                            piVar9 = *(int **)(*(int *)(unaff_EBP + -0x30) + 0x10);
                            if ((piVar9 != (int *)0x0) &&
                               (iVar2 = *(int *)(*(int *)(unaff_EBP + -0x30) + 4), 0 < iVar2)) {
                              do {
                                iVar16 = *piVar9;
                                if (*(int *)(iVar16 + 0x18) == iVar10) goto LAB_0043d17b;
                                iVar11 = iVar11 + 1;
                                piVar9 = piVar9 + 1;
                              } while (iVar11 < iVar2);
                            }
                            iVar16 = 0;
LAB_0043d17b:
                            if (iVar16 == 0) {
                              pcVar14 = s_Tree_table_entry_not_found__006c38a0;
                              uVar5 = 0;
                              goto LAB_0043d2bd;
                            }
                            uVar5 = *(undefined4 *)(unaff_EBP + -0x38);
                            *(undefined4 *)(iVar16 + 0x1c) = 0x32;
                            switch(uVar5) {
                            case 1:
                              iVar10 = 9;
                              break;
                            case 2:
                              iVar10 = 6;
                              break;
                            case 3:
                              iVar10 = 5;
                              break;
                            case 4:
                              iVar10 = 0xf;
                              break;
                            case 5:
                              iVar10 = 7;
                              break;
                            case 6:
                              iVar10 = 8;
                              break;
                            case 7:
                              iVar10 = 3;
                              break;
                            case 8:
                              iVar10 = 0xd;
                              break;
                            case 9:
                              iVar10 = 0xe;
                              break;
                            default:
                              pcVar14 = s_Invalid_motive_specified__006c3880;
                              uVar5 = 1;
                              goto LAB_0043d2bd;
                            }
                            puVar1 = (undefined2 *)(*(int *)(iVar16 + 8) + iVar10 * 6);
                            iVar10 = _strcmp(&DAT_006c389c,*(char **)(unaff_EBP + -0x10));
                            if (iVar10 == 0) {
                              puVar1[2] = (short)*(undefined4 *)(unaff_EBP + -0x24) - puVar1[1];
                            }
                            else {
                              iVar10 = _strcmp((char *)0x6c387c,*(char **)(unaff_EBP + -0x10));
                              if (iVar10 == 0) {
                                switch(*(undefined4 *)(unaff_EBP + -0x24)) {
                                case 0x12:
                                  uVar19 = 3;
                                  break;
                                case 0x13:
                                  uVar19 = 0xb;
                                  break;
                                case 0x14:
                                  uVar19 = 1;
                                  break;
                                case 0x15:
                                  uVar19 = 9;
                                  break;
                                case 0x16:
                                  uVar19 = 7;
                                  break;
                                case 0x17:
                                  uVar19 = 0x15;
                                  break;
                                case 0x18:
                                  uVar19 = 0xf;
                                  break;
                                case 0x19:
                                  uVar19 = 0xe;
                                  break;
                                case 0x1a:
                                  uVar19 = 0x13;
                                  break;
                                case 0x1b:
                                  uVar19 = 0x16;
                                  break;
                                case 0x1c:
                                  uVar19 = 0x10;
                                  break;
                                default:
                                  pcVar14 = s_Invalid_advertisement_specified__006c3858;
code_r0x0043d2a6:
                                  uVar5 = 3;
LAB_0043d2bd:
                                  FUN_0043d6ae(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,
                                               uVar5,iVar6,pcVar14);
                                  goto code_r0x0043d2cc;
                                case 0x21:
                                  uVar19 = 4;
                                  break;
                                case 0x22:
                                  uVar19 = 0xc;
                                  break;
                                case 0x23:
                                  uVar19 = 2;
                                  break;
                                case 0x24:
                                  uVar19 = 10;
                                  break;
                                case 0x25:
                                  uVar19 = 8;
                                }
                                puVar1[1] = 1;
                                *puVar1 = uVar19;
                              }
                              else {
                                iVar10 = _strcmp((char *)0x6c3854,*(char **)(unaff_EBP + -0x10));
                                if (iVar10 != 0) {
                                  pcVar14 = s_Invalid_constant_type_specified__006c3810;
                                  uVar5 = 2;
                                  goto LAB_0043d2bd;
                                }
                                uVar5 = FUN_0046edbd(3,iVar6);
                                iVar10 = func_0x0043d50b(uVar5);
                                if (iVar10 < 0) {
                                  pcVar14 = s_Invalid_attenuation_specified__006c3834;
                                  goto code_r0x0043d2a6;
                                }
                                FUN_00476033(iVar10);
                              }
                            }
code_r0x0043d2cc:
                            iVar6 = iVar6 + 1;
                          } while (iVar6 < *(int *)(unaff_EBP + -0x20));
                          goto LAB_0043d448;
                        }
                        pcVar14 = s_Tree_table_not_found_for_given_o_006c38bc;
                      }
                    }
                    uVar5 = 1;
                    goto LAB_0043d312;
                  }
                  uVar5 = FUN_0046eeb1(1,iVar6);
                  *(undefined4 *)(unaff_EBP + -0x40) = uVar5;
                  if ((short)uVar5 == 0) {
                    pcVar14 = s_Could_not_parse_constants_id__006c37f0;
LAB_0043d30f:
                    uVar5 = 1;
                    goto LAB_0043d312;
                  }
                  iVar10 = (**(code **)(*piVar9 + 0x38))(0x42434f4e,uVar5,FUN_00402024);
                  if (iVar10 == 0) {
                    pcVar14 = s_Constants_of_given_id_do_not_exi_006c37cc;
                    goto LAB_0043d30f;
                  }
                  puVar8 = (ushort *)FUN_00420048(iVar10);
                  uVar4 = *puVar8;
                  FUN_0042004f(iVar10);
                  if ((short)uVar4 < 0) {
                    uVar4 = *puVar8;
                    puVar3 = *(ushort **)(unaff_EBP + -0x3c);
                    uVar15 = uVar4 & 0x7fff;
                    *puVar3 = *puVar3 ^ ((ushort)uVar15 ^ *puVar3) & 0x7fff;
                    if (0x100 < uVar15) {
                      pcVar14 = s_Temporary_storage_not_large_enou_006c3774;
                      goto LAB_0043d370;
                    }
                    if ((uVar4 & 0x7fff) != 0) {
                      uVar13 = uVar15;
                      puVar12 = puVar3;
                      do {
                        puVar12 = puVar12 + 1;
                        *puVar12 = *(ushort *)(((int)puVar8 - (int)puVar3) + (int)puVar12);
                        uVar13 = uVar13 - 1;
                      } while (uVar13 != 0);
                    }
                    iVar10 = *(int *)(unaff_EBP + -0x10);
                    iVar6 = iVar10 + 1;
                    *(int *)(unaff_EBP + -0x38) = iVar6;
                    iVar6 = FUN_0046edbd(0,iVar6);
                    if (iVar6 == 0) {
                      FUN_0043d6ae(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,0,iVar10,
                                   s_Empty_constants_set_found__006c3758);
                    }
                    iVar6 = *(int *)(unaff_EBP + -0x38);
                    while ((*(int *)(unaff_EBP + -0x10) = iVar6, iVar6 < *(int *)(unaff_EBP + -0x20)
                           && (iVar10 = FUN_0046edbd(0,iVar6), iVar10 != 0))) {
                      iVar10 = FUN_0046edbd(1,iVar6);
                      if (iVar10 != 0) {
                        uVar5 = FUN_0046eeb1(0,iVar6);
                        *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
                        uVar4 = FUN_0046eeb1(1,iVar6);
                        if ((int)uVar15 < *(int *)(unaff_EBP + -0x24)) {
                          FUN_0043d6ae(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,0,iVar6,
                                       s_Index_exceeds_programmed_index_c_006c3730);
                        }
                        else {
                          puVar3[*(int *)(unaff_EBP + -0x24) + 1] = uVar4;
                        }
                      }
                      iVar6 = iVar6 + 1;
                    }
                    FUN_004568c7(*(undefined4 *)(unaff_EBP + -0x40),puVar3);
                  }
                  else {
                    pcVar14 = s_Constants_of_given_id_are_not_ma_006c3798;
LAB_0043d370:
                    FUN_0043d6ae(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c,1,
                                 *(undefined4 *)(unaff_EBP + -0x10),pcVar14);
                  }
                  iVar6 = *(int *)(unaff_EBP + -0x10);
                }
LAB_0043d448:
                while ((iVar6 < *(int *)(unaff_EBP + -0x20) &&
                       (iVar10 = FUN_0046edbd(0,iVar6), iVar10 != 0))) {
                  iVar6 = iVar6 + 1;
                }
              }
LAB_0043d45f:
              iVar6 = iVar6 + 1;
              *(int *)(unaff_EBP + -0x10) = iVar6;
            } while (iVar6 < *(int *)(unaff_EBP + -0x20));
            puVar8 = *(ushort **)(unaff_EBP + -0x3c);
          }
          FUN_006321f0(puVar8);
          iVar6 = 0;
          goto LAB_0043d478;
        }
        pcVar14 = s_Version_is_too_old__must_be_2_or_006c3958;
      }
      else {
        pcVar14 = s_Could_not_read_version_header__006c3984;
      }
    }
    sVar7 = _strlen(pcVar14);
    FUN_00412d8a(pcVar14,pcVar14 + sVar7);
    iVar6 = -1;
  }
  else {
    sVar7 = _strlen(s_File_not_found___006c39f0);
    FUN_00412d8a(s_File_not_found___006c39f0,s_File_not_found___006c39f0 + sVar7);
    pcVar14 = *(char **)(unaff_EBP + -0x270);
    sVar7 = _strlen(pcVar14);
    FUN_00412d8a(pcVar14,pcVar14 + sVar7);
  }
LAB_0043d478:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046ea5a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
}

