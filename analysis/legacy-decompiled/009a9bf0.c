
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int * __thiscall FUN_009a9bf0(int param_1,int param_2,int *param_3,uint param_4,int param_5)

{
  _Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
  *this;
  byte *pbVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *******pppppppuVar15;
  undefined2 *puVar16;
  float fVar17;
  char *pcVar18;
  undefined4 uVar19;
  undefined1 local_98 [4];
  undefined4 local_94;
  int *local_90;
  int *local_8c;
  int local_88;
  undefined1 local_84 [4];
  int *local_80;
  uint local_7c;
  int local_78;
  int local_74 [5];
  uint local_60;
  char local_5c [8];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 local_48;
  char local_44 [8];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *******local_2c [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00c4e7bd;
  local_10 = ExceptionList;
  uVar5 = DAT_00dd0b80 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_80 = param_3;
  local_7c = param_4;
  local_78 = param_1;
  local_14 = uVar5;
  if ((param_5 == 0) &&
     (piVar14 = (int *)**(int **)(param_1 + 0xc), piVar14 != *(int **)(param_1 + 0xc))) {
    do {
      piVar9 = (int *)piVar14[2];
      iVar6 = (**(code **)(*piVar9 + 0x14))(uVar5);
      if ((iVar6 == param_2) &&
         ((piVar7 = (int *)(**(code **)(*piVar9 + 0x18))(), piVar7 == local_80 &&
          (uVar8 = (**(code **)(*piVar9 + 0x24))(), uVar8 == local_7c)))) {
        (**(code **)(*piVar9 + 4))();
        ExceptionList = local_10;
        return piVar9;
      }
      piVar14 = (int *)*piVar14;
    } while (piVar14 != (int *)*(int *)(local_78 + 0xc));
  }
  iVar6 = local_78;
  piVar14 = (int *)(local_78 + 0x40);
  FUN_00960050(piVar14);
  local_8 = 0;
  if (param_5 == 0) {
    piVar9 = (int *)(**(code **)(*DAT_00e1d354 + 4))();
    param_5 = (**(code **)(*piVar9 + 0x1c))();
  }
  if ((((param_5 == 0xf) || (param_5 == 0x11)) || (param_5 == 0x12)) ||
     ((param_5 == 0x14 || (param_5 == 0x13)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_90 = (int *)0x0;
  local_8c = (int *)0x0;
  local_88 = 0;
  local_8._0_1_ = 1;
  if (!bVar2) {
    if (param_5 == 0xd) {
      uVar19 = 8;
      pcVar18 = "Russian/";
LAB_009a9d28:
      FUN_0040ff80(pcVar18,uVar19);
    }
    else if (param_5 == 0x10) {
      uVar19 = 7;
      pcVar18 = "Polish/";
      goto LAB_009a9d28;
    }
    FUN_0040ff80("VariableSans_",0xd);
    piVar14 = local_80;
    wsprintfA((LPSTR)&local_94,"%02d",local_80);
    pcVar18 = (char *)&local_94;
    do {
      cVar4 = *pcVar18;
      pcVar18 = pcVar18 + 1;
    } while (cVar4 != '\0');
    FUN_0040ff80(&local_94,(int)pcVar18 - ((int)&local_94 + 1));
    local_94 = (int *)((uint)local_94 & 0xffffff00);
    if ((local_7c & 1) != 0) {
      puVar16 = (undefined2 *)(local_98 + 3);
      do {
        pcVar18 = (char *)((int)puVar16 + 1);
        puVar16 = (undefined2 *)((int)puVar16 + 1);
      } while (*pcVar18 != '\0');
      *puVar16 = DAT_00c6ca04;
      piVar14 = local_80;
    }
    pcVar18 = (char *)&local_94;
    do {
      cVar4 = *pcVar18;
      pcVar18 = pcVar18 + 1;
    } while (cVar4 != '\0');
    if (pcVar18 != (char *)((int)&local_94 + 1)) {
      FUN_0040ff80(&DAT_00c593c4,1);
      pcVar18 = (char *)&local_94;
      do {
        cVar4 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      } while (cVar4 != '\0');
      FUN_0040ff80(&local_94,(int)pcVar18 - ((int)&local_94 + 1));
    }
    FUN_0040ff80(&DAT_00ca5da4,4);
LAB_009aa3ea:
    local_80 = (int *)FUN_00a30d62(0x90);
    local_8 = CONCAT31(local_8._1_3_,0xc);
    if (local_80 == (int *)0x0) {
LAB_009aa43a:
      piVar14 = (int *)0x0;
    }
    else {
      piVar14 = (int *)FUN_009ab6d0(local_2c,param_2,piVar14,local_7c);
    }
LAB_009aa43c:
    local_8._0_1_ = 1;
    cVar4 = FUN_009a94b0(piVar14,local_2c);
    if (cVar4 == '\0') {
      if (piVar14 != (int *)0x0) {
        (**(code **)*piVar14)(1);
      }
      piVar9 = local_8c;
      piVar14 = local_90;
      if (local_90 != (int *)0x0) {
        for (; piVar14 != piVar9; piVar14 = piVar14 + 6) {
          uVar5 = piVar14[5];
          if (0xf < uVar5) {
            iVar6 = *piVar14;
            uVar8 = uVar5 + 1;
            iVar10 = iVar6;
            if (0xfff < uVar8) {
              iVar10 = *(int *)(iVar6 + -4);
              uVar8 = uVar5 + 0x24;
              if (0x1f < (iVar6 - iVar10) - 4U) goto LAB_009aa648;
            }
            FUN_00a30993(iVar10,uVar8);
          }
          piVar14[4] = 0;
          piVar14[5] = 0xf;
          *(undefined1 *)piVar14 = 0;
        }
        uVar5 = ((local_88 - (int)local_90) / 0x18) * 0x18;
        piVar14 = local_90;
        if (0xfff < uVar5) {
          piVar14 = (int *)local_90[-1];
          uVar5 = uVar5 + 0x23;
          if ((undefined1 *)0x1f < (undefined1 *)((int)local_90 + (-4 - (int)piVar14)))
          goto LAB_009aa648;
        }
        FUN_00a30993(piVar14,uVar5);
        local_90 = (int *)0x0;
        local_8c = (int *)0x0;
        local_88 = 0;
      }
      FUN_009601d0();
      ExceptionList = local_10;
      return (int *)0x0;
    }
    if (local_90 != (int *)0x0) {
      local_80 = local_8c;
      piVar9 = local_8c;
      piVar7 = local_90;
      if (local_90 != local_8c) {
        do {
          uVar5 = piVar7[5];
          if (0xf < uVar5) {
            iVar6 = *piVar7;
            uVar8 = uVar5 + 1;
            iVar10 = iVar6;
            if (0xfff < uVar8) {
              iVar10 = *(int *)(iVar6 + -4);
              uVar8 = uVar5 + 0x24;
              if (0x1f < (iVar6 - iVar10) - 4U) goto LAB_009aa648;
            }
            FUN_00a30993(iVar10,uVar8);
            piVar9 = local_80;
          }
          piVar7[4] = 0;
          piVar7[5] = 0xf;
          *(undefined1 *)piVar7 = 0;
          piVar7 = piVar7 + 6;
        } while (piVar7 != piVar9);
      }
      uVar5 = ((local_88 - (int)local_90) / 0x18) * 0x18;
      piVar9 = local_90;
      if (0xfff < uVar5) {
        piVar9 = (int *)local_90[-1];
        uVar5 = uVar5 + 0x23;
        if ((undefined1 *)0x1f < (undefined1 *)((int)local_90 + (-4 - (int)piVar9)))
        goto LAB_009aa648;
      }
      FUN_00a30993(piVar9,uVar5);
      local_90 = (int *)0x0;
      local_8c = (int *)0x0;
      local_88 = 0;
    }
    FUN_009601d0();
    ExceptionList = local_10;
    return piVar14;
  }
  switch(param_5) {
  case 0xf:
    uStack_50 = 0;
    local_4c = 0xb;
    local_48 = 0xf;
    local_5c[0] = s_FONT12J_FON_00ca5dac[0];
    local_5c[1] = s_FONT12J_FON_00ca5dac[1];
    local_5c[2] = s_FONT12J_FON_00ca5dac[2];
    local_5c[3] = s_FONT12J_FON_00ca5dac[3];
    local_5c[4] = s_FONT12J_FON_00ca5dac[4];
    local_5c[5] = s_FONT12J_FON_00ca5dac[5];
    local_5c[6] = s_FONT12J_FON_00ca5dac[6];
    local_5c[7] = s_FONT12J_FON_00ca5dac[7];
    uStack_54._0_3_ = CONCAT12(s_FONT12J_FON_00ca5dac[10],s_FONT12J_FON_00ca5dac._8_2_);
    uStack_54 = (uint)(uint3)uStack_54;
    uStack_38 = 0;
    local_34 = 0xb;
    local_30 = 0xf;
    local_44[0] = s_FONT16J_FON_00ca5db8[0];
    local_44[1] = s_FONT16J_FON_00ca5db8[1];
    local_44[2] = s_FONT16J_FON_00ca5db8[2];
    local_44[3] = s_FONT16J_FON_00ca5db8[3];
    local_44[4] = s_FONT16J_FON_00ca5db8[4];
    local_44[5] = s_FONT16J_FON_00ca5db8[5];
    local_44[6] = s_FONT16J_FON_00ca5db8[6];
    local_44[7] = s_FONT16J_FON_00ca5db8[7];
    uStack_3c._0_3_ = CONCAT12(s_FONT16J_FON_00ca5db8[10],s_FONT16J_FON_00ca5db8._8_2_);
    uStack_3c = (uint)(uint3)uStack_3c;
    local_8._0_1_ = 3;
    FUN_009ab490(&local_94,0,local_5c,local_2c);
    local_8._0_1_ = 1;
    _eh_vector_destructor_iterator_(local_5c,0x18,2,FUN_00414bd0);
    pcVar18 = "FONT16J.FON";
    if (local_80 < &DAT_00000010) {
      pcVar18 = "FONT12J.FON";
    }
    FUN_0040ff80(pcVar18,0xb);
    break;
  default:
    piVar14 = local_80;
    goto LAB_009aa3ea;
  case 0x11:
    FUN_009a8660(0,"font16gb.fon");
    uVar19 = 0xc;
    pcVar18 = "font16gb.fon";
    goto LAB_009aa0a3;
  case 0x12:
    FUN_009a8660(0,"font16b5.fon");
    uVar19 = 0xc;
    pcVar18 = "font16b5.fon";
LAB_009aa0a3:
    FUN_0040ff80(pcVar18,uVar19);
    break;
  case 0x13:
    FUN_0040ff80("font20th.fon",0xc);
    if (*(char *)(local_78 + 0x58) == '\0') {
      if (0xf < *(uint *)(iVar6 + 0x54)) {
        piVar14 = (int *)*piVar14;
      }
      FUN_009b2130(piVar14,param_5);
      *(undefined1 *)(local_78 + 0x58) = 1;
    }
    local_80 = (int *)FUN_00a30d62(0x98);
    local_8 = CONCAT31(local_8._1_3_,6);
    if (local_80 == (int *)0x0) goto LAB_009aa43a;
    piVar14 = (int *)FUN_009acf50(local_2c);
    goto LAB_009aa43c;
  case 0x14:
    uStack_50 = 0;
    local_4c = 0xb;
    local_48 = 0xf;
    local_5c[0] = s_FONT12K_FON_00ca5df4[0];
    local_5c[1] = s_FONT12K_FON_00ca5df4[1];
    local_5c[2] = s_FONT12K_FON_00ca5df4[2];
    local_5c[3] = s_FONT12K_FON_00ca5df4[3];
    local_5c[4] = s_FONT12K_FON_00ca5df4[4];
    local_5c[5] = s_FONT12K_FON_00ca5df4[5];
    local_5c[6] = s_FONT12K_FON_00ca5df4[6];
    local_5c[7] = s_FONT12K_FON_00ca5df4[7];
    uStack_54._0_3_ = CONCAT12(s_FONT12K_FON_00ca5df4[10],s_FONT12K_FON_00ca5df4._8_2_);
    uStack_54 = (uint)(uint3)uStack_54;
    uStack_38 = 0;
    local_34 = 0xb;
    local_30 = 0xf;
    local_44[0] = s_FONT16K_FON_00ca5e00[0];
    local_44[1] = s_FONT16K_FON_00ca5e00[1];
    local_44[2] = s_FONT16K_FON_00ca5e00[2];
    local_44[3] = s_FONT16K_FON_00ca5e00[3];
    local_44[4] = s_FONT16K_FON_00ca5e00[4];
    local_44[5] = s_FONT16K_FON_00ca5e00[5];
    local_44[6] = s_FONT16K_FON_00ca5e00[6];
    local_44[7] = s_FONT16K_FON_00ca5e00[7];
    uStack_3c._0_3_ = CONCAT12(s_FONT16K_FON_00ca5e00[10],s_FONT16K_FON_00ca5e00._8_2_);
    uStack_3c = (uint)(uint3)uStack_3c;
    local_8._0_1_ = 5;
    FUN_009ab490(&local_94,0,local_5c,local_2c);
    local_8._0_1_ = 1;
    _eh_vector_destructor_iterator_(local_5c,0x18,2,FUN_00414bd0);
    uVar19 = 0xb;
    if (&DAT_0000000f < local_80) {
      pcVar18 = "FONT16K.FON";
      goto LAB_009aa0a3;
    }
    FUN_0040ff80("FONT12K.FON",0xb);
  }
  if (*(char *)(local_78 + 0x59) == '\0') {
    piVar9 = piVar14;
    if (0xf < *(uint *)(iVar6 + 0x54)) {
      piVar9 = (int *)*piVar14;
    }
    FUN_009b31a0(piVar9,param_5);
    local_94 = local_8c;
    piVar9 = local_90;
    if (local_90 != local_8c) {
      do {
        iVar10 = FUN_00a30d62(0x98);
        local_8._0_1_ = 7;
        if (iVar10 == 0) {
          local_80 = (int *)0x0;
        }
        else {
          local_80 = (int *)FUN_009af6c0(local_2c,1);
        }
        local_8._0_1_ = 1;
        uVar3 = (undefined1)local_8;
        local_8._0_1_ = 1;
        if (0x7fffffffU - *(int *)(iVar6 + 0x50) < (uint)piVar9[4]) {
          local_8._0_1_ = uVar3;
                    /* WARNING: Subroutine does not return */
          FUN_0040ff40();
        }
        piVar7 = piVar14;
        if (0xf < *(uint *)(iVar6 + 0x54)) {
          piVar7 = (int *)*piVar14;
        }
        piVar11 = piVar9;
        if (0xf < (uint)piVar9[5]) {
          piVar11 = (int *)*piVar9;
        }
        FUN_0044c390(local_80,piVar14,piVar7,*(int *)(iVar6 + 0x50),piVar11,piVar9[4]);
        local_8._0_1_ = 8;
        FUN_00960090(local_74);
        local_8._0_1_ = 9;
        cVar4 = FUN_009a94b0(local_80,local_44);
        FUN_009601d0();
        local_8._0_1_ = 1;
        if (0xf < local_60) {
          uVar5 = local_60 + 1;
          iVar10 = local_74[0];
          if (0xfff < uVar5) {
            iVar10 = *(int *)(local_74[0] + -4);
            uVar5 = local_60 + 0x24;
            if (0x1f < (local_74[0] - iVar10) - 4U) goto LAB_009aa648;
          }
          FUN_00a30993(iVar10,uVar5);
        }
        if ((cVar4 == '\0') && (local_80 != (int *)0x0)) {
          (**(code **)*local_80)(1);
        }
        piVar9 = piVar9 + 6;
      } while (piVar9 != local_94);
    }
    *(undefined1 *)(local_78 + 0x59) = 1;
  }
  iVar6 = local_78;
  this = (_Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
          *)(local_78 + 0x1c);
  uVar5 = 0x811c9dc5;
  pppppppuVar15 = local_2c;
  if (0xf < local_18) {
    pppppppuVar15 = local_2c[0];
  }
  uVar8 = 0;
  if (local_1c != 0) {
    do {
      pbVar1 = (byte *)((int)pppppppuVar15 + uVar8);
      uVar8 = uVar8 + 1;
      uVar5 = (*pbVar1 ^ uVar5) * 0x1000193;
    } while (uVar8 < local_1c);
  }
  FUN_009a8850(local_98,local_2c,uVar5);
  piVar14 = local_94;
  if (local_94 == (int *)0x0) {
    if (*(int *)(iVar6 + 0x24) == 0x71c71c7) {
                    /* WARNING: Subroutine does not return */
      FUN_00a0a80f("unordered_map/set too long");
    }
    local_8._0_1_ = 10;
    iVar10 = FUN_00a30d62(0x24);
    local_80 = (int *)(iVar10 + 8);
    FUN_00437df0(local_2c);
    local_80[6] = 0;
    iVar12 = *(int *)(iVar6 + 0x24) + 1;
    local_8._0_1_ = 0xb;
    fVar17 = (float)((double)iVar12 + (double)(&DAT_00c57f00)[-(iVar12 >> 0x1f)]) /
             (float)((double)*(int *)(iVar6 + 0x38) +
                    (double)(&DAT_00c57f00)[-(*(int *)(iVar6 + 0x38) >> 0x1f)]);
    if (*(float *)this <= fVar17 && fVar17 != *(float *)this) {
      std::
      _Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
      ::_Rehash_for_1(this);
      puVar13 = (undefined4 *)FUN_009a8850(local_84,local_80,uVar5);
      local_98 = (undefined1  [4])*puVar13;
    }
    piVar14 = (int *)FUN_009aaee0(uVar5,local_98,iVar10);
    local_8._0_1_ = 1;
  }
  piVar14 = (int *)piVar14[8];
  (**(code **)(*piVar14 + 4))();
  if (local_90 != (int *)0x0) {
    FUN_009a85f0(local_90,local_8c,&local_90);
    uVar5 = ((local_88 - (int)local_90) / 0x18) * 0x18;
    piVar9 = local_90;
    if (0xfff < uVar5) {
      piVar9 = (int *)local_90[-1];
      uVar5 = uVar5 + 0x23;
      if ((undefined1 *)0x1f < (undefined1 *)((int)local_90 + (-4 - (int)piVar9))) {
LAB_009aa648:
                    /* WARNING: Subroutine does not return */
        FUN_00a4104b();
      }
    }
    FUN_00a30993(piVar9,uVar5);
    local_90 = (int *)0x0;
    local_8c = (int *)0x0;
    local_88 = 0;
  }
  FUN_009601d0();
  ExceptionList = local_10;
  return piVar14;
}

