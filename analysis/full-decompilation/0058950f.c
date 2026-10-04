
undefined4 __thiscall FUN_0058950f(int *param_1,int param_2,short *param_3)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  short *psVar4;
  short *psVar5;
  char cVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined2 *puVar11;
  char *pcVar12;
  undefined *puVar13;
  int local_c;
  char local_5;
  
  psVar4 = param_3;
  iVar7 = param_1[100];
  if (iVar7 != 0) {
    if (iVar7 < 1) {
      return 2;
    }
    if (3 < iVar7) {
      return 2;
    }
  }
  local_5 = DAT_006f29f4;
  sVar3 = *param_3;
  if ((*(byte *)((int)param_3 + 5) & 4) != 0) {
    if ((sVar3 < 0) || ((short)(ushort)*(byte *)(param_2 + 7) <= sVar3)) {
      param_2 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    iVar7 = FUN_004752f8();
    sVar3 = *(short *)(iVar7 + sVar3 * 2);
  }
  iVar7 = FUN_0047eda6();
  psVar5 = param_3;
  if (iVar7 == 1) {
    if (sVar3 == 0) {
      (**(code **)(*param_1 + 0x104))(param_1 + 5);
    }
    else {
      param_2 = (**(code **)(*param_1 + 300))(param_2,psVar4);
      *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar4 + 5) >> 7;
      iVar7 = (**(code **)(*param_1 + 0x100))
                        (param_1 + 5,param_2,*(byte *)((int)psVar4 + 5) >> 1 & 1);
      if (iVar7 == 0) {
        if (local_5 != '\0') {
          if (param_2 == 0) {
            pcVar8 = s__NULL_skill__006d0580;
          }
          else if (*(int *)(param_2 + 8) == *(int *)(param_2 + 4)) {
            pcVar8 = s__unnamed_skill__006d0590;
          }
          else {
            pcVar8 = *(char **)(param_2 + 4);
          }
          iVar7 = (int)sVar3;
          puVar13 = &DAT_006c08dc;
          pcVar12 = s___id_006c3a84;
          FUN_005bc69b(s_Could_not_start_background_anima_006d0558);
          FUN_005bc69b(pcVar8);
          FUN_005bc69b(pcVar12);
          FUN_005bc69b(iVar7);
          FUN_005bc69b(puVar13);
        }
        FUN_00452c2d(*(undefined4 *)(*(int *)(param_1[0x4e] + 0x11c) + 0xc),0,
                     s_missing_animation_tree_006d0540,0);
      }
      iVar7 = param_1[5];
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x40) = 1;
        FUN_00598687(0xfffffff6);
      }
    }
  }
  else if (iVar7 == 2) {
    if (sVar3 == 0) {
      (**(code **)(*param_1 + 0x104))(param_1 + 0x4f);
      param_1[0x6a] = 0;
    }
    else {
      param_2 = (**(code **)(*param_1 + 300))(param_2,psVar4);
      *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar4 + 5) >> 7;
      iVar7 = (**(code **)(*param_1 + 0x100))
                        (param_1 + 0x4f,param_2,*(byte *)((int)psVar4 + 5) >> 1 & 1);
      if (iVar7 == 0) {
        if (local_5 != '\0') {
          if (param_2 == 0) {
            pcVar8 = s__NULL_skill__006d0580;
          }
          else if (*(int *)(param_2 + 8) == *(int *)(param_2 + 4)) {
            pcVar8 = s__unnamed_skill__006d0590;
          }
          else {
            pcVar8 = *(char **)(param_2 + 4);
          }
          iVar7 = (int)sVar3;
          puVar13 = &DAT_006c08dc;
          pcVar12 = s___id_006c3a84;
          FUN_005bc69b(s_Could_not_start_carry_animation_006d0d64);
          FUN_005bc69b(pcVar8);
          FUN_005bc69b(pcVar12);
          FUN_005bc69b(iVar7);
          FUN_005bc69b(puVar13);
        }
        FUN_00452c2d(*(undefined4 *)(*(int *)(param_1[0x4e] + 0x11c) + 0xc),0,
                     s_missing_animation_tree_006d0540,0);
      }
      iVar7 = param_1[0x4f];
      if (iVar7 == 0) {
        return 1;
      }
      param_1[0x6a] = 6;
      *(undefined4 *)(iVar7 + 0x40) = 1;
      FUN_00598687(10);
    }
    param_1[0x6b] = -1;
  }
  else {
    param_3 = (short *)((uint)param_3 & 0xffffff);
    if (iVar7 == 3) {
      param_3 = (short *)CONCAT13(1,(int3)psVar5);
    }
    if (sVar3 != 0) {
      if (param_1[0x28] == 0) {
        iVar7 = (**(code **)(*param_1 + 300))(param_2,psVar4);
        FUN_004071be(param_1[0xb],param_1[0xc]);
        (**(code **)(*param_1 + 0xfc))();
        piVar1 = param_1 + 3;
        *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar4 + 5) >> 7;
        iVar9 = (**(code **)(*param_1 + 0x100))(piVar1,iVar7,*(byte *)((int)psVar4 + 5) >> 1 & 1);
        if (iVar9 == 0) {
          if (local_5 != '\0') {
            if (iVar7 == 0) {
              pcVar8 = s__NULL_skill__006d0580;
            }
            else if (*(int *)(iVar7 + 8) == *(int *)(iVar7 + 4)) {
              pcVar8 = s__unnamed_skill__006d0590;
            }
            else {
              pcVar8 = *(char **)(iVar7 + 4);
            }
            iVar7 = (int)sVar3;
            puVar13 = &DAT_006c08dc;
            pcVar12 = s___id_006c3a84;
            FUN_005bc69b(s_Could_not_start_animation_006d0524);
            FUN_005bc69b(pcVar8);
            FUN_005bc69b(pcVar12);
            FUN_005bc69b(iVar7);
            FUN_005bc69b(puVar13);
          }
          FUN_00452c2d(*(undefined4 *)(*(int *)(param_1[0x4e] + 0x11c) + 0xc),0,
                       s_missing_animation_tree_006d0540,0);
          uVar10 = (**(code **)(*param_1 + 0xf4))(0x25);
          (**(code **)(*param_1 + 0x100))(piVar1,uVar10,0);
        }
        *(uint *)(*piVar1 + 0x68) = (*(byte *)((int)psVar4 + 5) & 8) >> 3;
        *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar4 + 5) >> 7;
        *(byte *)(param_1 + 0xa7) = *(byte *)((int)psVar4 + 5) >> 6 & 1;
        if (param_3._3_1_ != '\0') {
          (**(code **)(*param_1 + 0x104))(param_1 + 0x4f);
          param_1[0x6b] = -1;
          param_1[0x69] = 1;
        }
        param_1[0x29] = 0;
        param_1[100] = 0;
        param_1[0x26] = -1;
        param_1[0x28] = 1;
      }
      local_c = 0;
      iVar7 = (**(code **)(*param_1 + 0x80))(&local_c);
      if (iVar7 == 0) {
        iVar7 = (**(code **)(*param_1 + 0x108))(param_1 + 3);
        if ((iVar7 == 0) &&
           ((*(int *)(param_1[3] + 0x68) == 0 || (cVar6 = FUN_0045d92c(), cVar6 == '\0')))) {
          return 2;
        }
        iVar7 = param_1[0x29];
        if ((char)psVar4[3] <= iVar7) {
          param_1[0x28] = 0;
          FUN_005928c4();
          (**(code **)(*param_1 + 0x58))();
          param_1[0x69] = 0;
          *(undefined2 *)(param_1[0x4e] + 0x5b2) = 0;
          return 1;
        }
        local_c = iVar7;
        if ((*(byte *)((int)psVar4 + 5) >> 1 & 1) != 0) {
          local_c = ((char)psVar4[3] - iVar7) + -1;
        }
        if (local_5 != '\0') {
          pcVar8 = s_Animation_006d04d4;
          puVar13 = &DAT_006c5bd0;
          FUN_005bc69b(*(undefined4 *)(*(int *)(param_1[0x4e] + 0x11c) + 0x18));
          FUN_005bc69b(puVar13);
          FUN_005bc69b(pcVar8);
          uVar10 = FUN_00589c5c(param_1[3]);
          FUN_005bc69b(uVar10);
          puVar13 = &DAT_006c08dc;
          pcVar8 = s_Firing_substitute_event___006d04b8;
          iVar7 = local_c;
          FUN_005bc69b(s_deficient_in_events__006d04a0);
          FUN_005bc69b(pcVar8);
          FUN_005bc69b(iVar7);
          FUN_005bc69b(puVar13);
        }
        if ((*(byte *)((int)psVar4 + 5) & 0x20) == 0) {
          if (*(char *)(param_2 + 7) == '\0') {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          puVar11 = (undefined2 *)FUN_004752f8();
          *puVar11 = (undefined2)local_c;
        }
        else {
          bVar2 = *(byte *)(psVar4 + 1);
          if ((uint)*(byte *)(param_2 + 6) <= (uint)bVar2) {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          iVar7 = FUN_004752fc();
          *(undefined2 *)(iVar7 + (uint)bVar2 * 2) = (undefined2)local_c;
        }
        param_1[0x29] = param_1[0x29] + 1;
      }
      else {
        if (local_c < 100) {
          iVar7 = param_1[0x29];
          iVar9 = iVar7;
          if ((*(byte *)((int)psVar4 + 5) >> 1 & 1) != 0) {
            iVar9 = ((char)psVar4[3] - iVar7) + -1;
          }
          if (((char)psVar4[3] <= iVar9) || (iVar9 < 0)) {
            iVar9 = -1;
          }
          if ((local_c != iVar9) || (local_c < 0)) {
            if (local_5 == '\0') {
              return 2;
            }
            puVar13 = &DAT_006c5bd0;
            FUN_005bc69b(*(undefined4 *)(*(int *)(param_1[0x4e] + 0x11c) + 0x18));
            FUN_005bc69b(puVar13);
            if ((iVar9 < 0) || ((char)psVar4[3] <= iVar9)) {
              pcVar8 = s_in_animation_006d0514;
              iVar7 = local_c;
              FUN_005bc69b(s_Extra_event_006d04e4);
              FUN_005bc69b(iVar7);
              FUN_005bc69b(pcVar8);
            }
            else {
              pcVar12 = s_in_animation_006d0514;
              pcVar8 = s_instead_of_006d0504;
              iVar7 = local_c;
              FUN_005bc69b(s_Expected_event_006d04f4);
              FUN_005bc69b(iVar9);
              FUN_005bc69b(pcVar8);
              FUN_005bc69b(iVar7);
              FUN_005bc69b(pcVar12);
            }
            uVar10 = FUN_00589c5c(param_1[3]);
            FUN_005bc69b(uVar10);
            FUN_005bc69b(&DAT_006d04e0);
            return 2;
          }
          param_1[0x29] = iVar7 + 1;
          local_c = iVar9;
        }
        if ((*(byte *)((int)psVar4 + 5) & 0x20) == 0) {
          if (*(char *)(param_2 + 7) == '\0') {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          puVar11 = (undefined2 *)FUN_004752f8();
          *puVar11 = (undefined2)local_c;
        }
        else {
          bVar2 = *(byte *)(psVar4 + 1);
          if ((uint)*(byte *)(param_2 + 6) <= (uint)bVar2) {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          iVar7 = FUN_004752fc();
          *(undefined2 *)(iVar7 + (uint)bVar2 * 2) = (undefined2)local_c;
        }
      }
      return 0;
    }
    (**(code **)(*param_1 + 0xfc))();
    FUN_005928c4();
    *(undefined2 *)(param_1[0x4e] + 0x5b2) = 0;
    param_1[0x69] = 0;
  }
  return 1;
}

