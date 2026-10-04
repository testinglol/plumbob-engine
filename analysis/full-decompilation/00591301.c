
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00591301(void)

{
  char *_Str1;
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar5;
  int iVar4;
  int *extraout_ECX;
  int iVar6;
  char *pcVar7;
  int unaff_EBP;
  bool bVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  iVar2 = *(int *)(*(int *)(unaff_EBP + 0x14) + 8) - *(int *)(*(int *)(unaff_EBP + 0x14) + 4) >> 3;
  *(int *)(unaff_EBP + -0x18) = iVar2;
  if (0 < iVar2) {
    do {
      iVar6 = *(int *)(unaff_EBP + -0x14) * 8;
      iVar2 = *(int *)(*(int *)(unaff_EBP + 0x14) + 4);
      pcVar7 = *(char **)(iVar6 + 4 + iVar2);
      _Str1 = *(char **)(iVar6 + iVar2);
      uVar3 = FUN_00635f62(pcVar7);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
      iVar2 = _strcmp(_Str1,&DAT_006d060c);
      if (iVar2 == 0) {
        (**(code **)(*extraout_ECX + 0x7c))(*(undefined4 *)(unaff_EBP + -0x10));
      }
      else {
        iVar2 = _strcmp(_Str1,s_interruptable_006d05fc);
        if ((iVar2 == 0) || (iVar2 = _strcmp(_Str1,s_interruptible_006d05ec), iVar2 == 0)) {
          *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x68) = *(undefined4 *)(unaff_EBP + -0x10);
        }
        else {
          iVar2 = _strcmp(_Str1,s_anchor_006d0d50);
          if (iVar2 == 0) {
            iVar2 = *(int *)(unaff_EBP + 8);
            *(undefined4 *)(iVar2 + 0x70) = 0;
            if (iVar2 == extraout_ECX[3]) {
              if (*(int *)(unaff_EBP + -0x10) == 0) {
                *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x6c) = 0;
                if (extraout_ECX[10] == *(int *)(unaff_EBP + 0xc)) {
                  extraout_ECX[9] = 0;
                  extraout_ECX[10] = 0;
                }
              }
              else {
                iVar2 = *(int *)(unaff_EBP + 0xc);
                *(int *)(*(int *)(unaff_EBP + 8) + 0x6c) = iVar2;
                if (extraout_ECX[10] != iVar2) {
                  extraout_ECX[9] = 0;
                  extraout_ECX[10] = iVar2;
                }
              }
            }
          }
          else {
            iVar2 = _strcmp(_Str1,s_dress_006d05e4);
            if (iVar2 == 0) {
              FUN_005b870f(pcVar7);
              *(undefined4 *)(unaff_EBP + -4) = 0;
              FUN_005b870f(&DAT_006de560);
              iVar2 = *extraout_ECX;
              *(undefined1 *)(unaff_EBP + -4) = 1;
              (**(code **)(iVar2 + 0xd8))(unaff_EBP + -0x3c,unaff_EBP + -0x24);
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_005b8770();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
            else {
              iVar2 = _strcmp(_Str1,s_undress_006d05dc);
              if (iVar2 != 0) {
                iVar2 = _strcmp(_Str1,s_lefthand_006d1a30);
                if (iVar2 == 0) {
                  *(undefined2 *)(extraout_ECX[0x4e] + 0x5b8) = *(undefined2 *)(unaff_EBP + -0x10);
                }
                else {
                  iVar2 = _strcmp(_Str1,s_righthand_006d1a24);
                  if (iVar2 == 0) {
                    *(undefined2 *)(extraout_ECX[0x4e] + 0x5ba) = *(undefined2 *)(unaff_EBP + -0x10)
                    ;
                  }
                  else {
                    iVar2 = _strcmp(_Str1,s_censor_006d1a1c);
                    if (iVar2 == 0) {
                      *(undefined2 *)(extraout_ECX[0x4e] + 0x5c8) =
                           *(undefined2 *)(unaff_EBP + -0x10);
                    }
                    else {
                      iVar2 = _strcmp(_Str1,s_sound_006cb77c);
                      if (iVar2 == 0) {
                        if (*(char *)(DAT_006e486c + 0x5b) != '\0') {
                          FUN_006358b0(unaff_EBP + -0x43c,&DAT_006d05d8);
                          FUN_006358c0(unaff_EBP + -0x43c,pcVar7);
                          FUN_004a6ba5(extraout_ECX[0x4e],unaff_EBP + -0x43c);
                        }
                        cVar1 = FUN_00432644();
                        iVar2 = extraout_ECX[0x4e];
                        if (cVar1 == '\0') {
                          if (*(short *)(iVar2 + 0x60e) < 2) goto LAB_005917a3;
                          uVar3 = 0xfffffffc;
                        }
                        else {
LAB_005915d7:
                          uVar3 = CONCAT22((short)((uint)iVar2 >> 0x10),
                                           *(undefined2 *)(iVar2 + 0xf0));
                        }
LAB_0059175a:
                        FUN_0057a7f7(pcVar7,uVar3);
                      }
                      else {
                        iVar2 = _strcmp(_Str1,s_selectedsound_006d1a0c);
                        if (iVar2 == 0) {
                          cVar1 = FUN_0045e67a();
                          if (cVar1 != '\0') {
LAB_005915d5:
                            iVar2 = extraout_ECX[0x4e];
                            goto LAB_005915d7;
                          }
                        }
                        else {
                          iVar2 = _strcmp(_Str1,s_deselectedsound_006d19fc);
                          if (iVar2 == 0) {
                            cVar1 = FUN_0045e67a();
                            if (cVar1 == '\0') goto LAB_005915d5;
                          }
                          else {
                            iVar2 = _strcmp(_Str1,s_footstep_006cf3bc);
                            if (iVar2 == 0) {
                              if (_DAT_0067343c < ABS((float)extraout_ECX[0x20] - _DAT_00671edc)) {
                                iVar2 = *(int *)(unaff_EBP + -0x10);
                                iVar6 = iVar2;
                                if (iVar2 < 0) {
                                  iVar6 = -iVar2;
                                }
                                iVar6 = FUN_00589043(iVar6);
                                if (iVar6 != -1) {
                                  iVar4 = extraout_ECX[0x6c];
                                  bVar8 = true;
                                  if ((((iVar4 != 1) && (iVar4 != 2)) && (iVar4 != 5)) &&
                                     (iVar4 != 0xe)) {
                                    bVar8 = false;
                                  }
                                  switch(iVar6) {
                                  case 1:
                                  case 2:
                                    if (bVar8) {
                                      pcVar7 = s_footstep_hard_noshoe_006d19d4;
                                    }
                                    else {
                                      pcVar7 = s_footstep_hard_006d19ec;
                                    }
                                    break;
                                  case 3:
                                  case 5:
                                    if (bVar8) {
                                      pcVar7 = s_footstep_medium_noshoe_006d19ac;
                                    }
                                    else {
                                      pcVar7 = s_footstep_medium_006d19c4;
                                    }
                                    break;
                                  case 4:
code_r0x005916db:
                                    if (bVar8) {
                                      pcVar7 = s_footstep_soft_noshoe_006d1918;
                                    }
                                    else {
                                      pcVar7 = s_footstep_soft_006d1908;
                                    }
                                    break;
                                  case 6:
                                    pcVar7 = s_footstep_plant_006d199c;
                                    break;
                                  case 7:
                                    pcVar7 = s_footstep_trash_006d198c;
                                    break;
                                  case 8:
                                    pcVar7 = s_footstep_ash_006d197c;
                                    break;
                                  case 9:
                                    pcVar7 = s_footstep_roach_006d196c;
                                    break;
                                  case 10:
                                    pcVar7 = s_footstep_puddle_006d195c;
                                    break;
                                  case 0xb:
                                    pcVar7 = s_footstep_pool_swim_stroke_006d1940;
                                    break;
                                  default:
                                    cVar1 = FUN_004c4902();
                                    if (cVar1 == '\x01') {
                                      pcVar7 = s_footstep_snow_006d1930;
                                    }
                                    else {
                                      if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x24) == 99)
                                      goto code_r0x005916db;
                                      pcVar7 = s_footstep_terrain_noshoe_006d18f0;
                                      if (!bVar8) {
                                        pcVar7 = s_footstep_terrain_006d18dc;
                                      }
                                    }
                                  }
                                  iVar6 = extraout_ECX[0x4e];
                                  if ((((*(byte *)(iVar6 + 0x634) & 1) != 1) &&
                                      ((*(byte *)(iVar6 + 0x614) & 1) != 1)) &&
                                     ((*(byte *)(iVar6 + 0x620) & 8) == 0)) {
                                    bVar8 = *(float *)(*(int *)(unaff_EBP + 8) + 0x24) <
                                            _DAT_0066657c;
                                    uVar5 = (undefined2)((uint)*(int *)(unaff_EBP + 8) >> 0x10);
                                    iVar4 = (uint)CONCAT21(uVar5,bVar8) << 8;
                                    if (bVar8) {
                                      if (iVar2 != -2) {
                                        bVar8 = iVar2 == -1;
LAB_0059174f:
                                        uVar5 = (undefined2)((uint)iVar4 >> 0x10);
                                        if (!bVar8) goto LAB_005917a3;
                                      }
                                    }
                                    else {
                                      uVar5 = 0;
                                      if (iVar2 != 1) {
                                        iVar4 = iVar2 + -2;
                                        bVar8 = iVar4 == 0;
                                        goto LAB_0059174f;
                                      }
                                    }
                                    uVar3 = CONCAT22(uVar5,*(undefined2 *)(iVar6 + 0xf0));
                                    goto LAB_0059175a;
                                  }
                                }
                              }
                            }
                            else {
                              iVar2 = _strcmp(_Str1,s_discontinuity_006d18cc);
                              if ((iVar2 == 0) && (extraout_ECX[4] != 0)) {
                                FUN_005a0903(extraout_ECX[4]);
                                extraout_ECX[4] = 0;
                                extraout_ECX[0x68] = 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                goto LAB_005917a3;
              }
              FUN_005b870f(pcVar7);
              iVar2 = *extraout_ECX;
              *(undefined4 *)(unaff_EBP + -4) = 2;
              (**(code **)(iVar2 + 0xdc))(unaff_EBP + -0x30);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
            FUN_005b8770();
          }
        }
      }
LAB_005917a3:
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

