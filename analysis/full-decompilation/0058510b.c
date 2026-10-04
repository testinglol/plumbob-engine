
undefined4 __thiscall FUN_0058510b(int *param_1,int param_2,short *param_3)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  char cVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  char *pcVar11;
  undefined *puVar12;
  
  psVar5 = param_3;
  iVar7 = param_2;
  cVar4 = DAT_006f29f4;
  sVar3 = *param_3;
  if ((*(byte *)((int)param_3 + 5) & 4) != 0) {
    if ((sVar3 < 0) || ((short)(ushort)*(byte *)(param_2 + 7) <= sVar3)) {
      param_2 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    iVar6 = FUN_004752f8();
    sVar3 = *(short *)(iVar6 + sVar3 * 2);
  }
  iVar6 = FUN_0047eda6();
  if (iVar6 == 1) {
    if (sVar3 != 0) {
      param_2 = (**(code **)(*param_1 + 300))(iVar7,psVar5);
      *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar5 + 5) >> 7;
      iVar7 = (**(code **)(*param_1 + 0x100))
                        (param_1 + 5,param_2,(*(byte *)((int)psVar5 + 5) & 2) >> 1);
      if (iVar7 == 0) {
        if (cVar4 != '\0') {
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
          puVar12 = &DAT_006c08dc;
          pcVar11 = s___id_006c3a84;
          FUN_005bc69b(s_Could_not_start_background_anima_006d0558);
          FUN_005bc69b(pcVar8);
          FUN_005bc69b(pcVar11);
          FUN_005bc69b(iVar7);
          FUN_005bc69b(puVar12);
        }
        FUN_00452c2d(*(undefined4 *)(*(int *)(param_1[1] + 0x11c) + 0xc),0,
                     s_missing_animation_tree_006d0540,0);
      }
      iVar7 = param_1[5];
      if (iVar7 != 0) {
        *(undefined4 *)(iVar7 + 0x40) = 1;
        FUN_00598687(0xfffffff6);
        return 1;
      }
      return 1;
    }
    (**(code **)(*param_1 + 0x104))(param_1 + 5);
  }
  else {
    if (sVar3 != 0) {
      if (param_1[0x28] == 0) {
        iVar7 = (**(code **)(*param_1 + 300))(iVar7,psVar5);
        FUN_004071be(param_1[0xb],param_1[0xc]);
        (**(code **)(*param_1 + 0xfc))();
        piVar1 = param_1 + 3;
        *(byte *)(param_1 + 0x2a) = *(byte *)((int)psVar5 + 5) >> 7;
        iVar6 = (**(code **)(*param_1 + 0x100))(piVar1,iVar7,*(byte *)((int)psVar5 + 5) >> 1 & 1);
        if (iVar6 == 0) {
          if (cVar4 != '\0') {
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
            puVar12 = &DAT_006c08dc;
            pcVar11 = s___id_006c3a84;
            FUN_005bc69b(s_Could_not_start_animation_006d0524);
            FUN_005bc69b(pcVar8);
            FUN_005bc69b(pcVar11);
            FUN_005bc69b(iVar7);
            FUN_005bc69b(puVar12);
          }
          FUN_00452c2d(*(undefined4 *)(*(int *)(param_1[1] + 0x11c) + 0xc),0,
                       s_missing_animation_tree_006d0540,0);
          uVar9 = (**(code **)(*param_1 + 0xf4))(0x25);
          (**(code **)(*param_1 + 0x100))(piVar1,uVar9,0);
        }
        *(uint *)(*piVar1 + 0x68) = (*(byte *)((int)psVar5 + 5) & 8) >> 3;
        param_1[0x29] = 0;
        param_1[0x26] = -1;
        param_1[0x28] = 1;
        iVar7 = param_2;
      }
      param_3 = (short *)0x0;
      iVar6 = (**(code **)(*param_1 + 0x80))(&param_3);
      if (iVar6 == 0) {
        iVar6 = (**(code **)(*param_1 + 0x108))(param_1 + 3);
        if ((iVar6 == 0) && (*(int *)(param_1[3] + 0x68) == 0)) {
          return 2;
        }
        iVar6 = param_1[0x29];
        if ((char)psVar5[3] <= iVar6) {
          param_1[0x28] = 0;
          (**(code **)(*param_1 + 0x58))();
          return 1;
        }
        param_3 = (short *)iVar6;
        if ((*(byte *)((int)psVar5 + 5) >> 1 & 1) != 0) {
          param_3 = (short *)(((char)psVar5[3] - iVar6) + -1);
        }
        if (cVar4 != '\0') {
          pcVar8 = s_Animation_006d04d4;
          puVar12 = &DAT_006c5bd0;
          FUN_005bc69b(*(undefined4 *)(*(int *)(param_1[1] + 0x11c) + 0x18));
          FUN_005bc69b(puVar12);
          FUN_005bc69b(pcVar8);
          uVar9 = FUN_00589c5c(param_1[3]);
          FUN_005bc69b(uVar9);
          puVar12 = &DAT_006c08dc;
          pcVar8 = s_Firing_substitute_event___006d04b8;
          iVar7 = (int)param_3;
          FUN_005bc69b(s_deficient_in_events__006d04a0);
          FUN_005bc69b(pcVar8);
          FUN_005bc69b(iVar7);
          FUN_005bc69b(puVar12);
          iVar7 = param_2;
        }
        if ((*(byte *)((int)psVar5 + 5) & 0x20) == 0) {
          if (*(char *)(iVar7 + 7) == '\0') {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          puVar10 = (undefined2 *)FUN_004752f8();
          *puVar10 = param_3._0_2_;
        }
        else {
          bVar2 = *(byte *)(psVar5 + 1);
          if ((uint)*(byte *)(iVar7 + 6) <= (uint)bVar2) {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          iVar7 = FUN_004752fc();
          *(undefined2 *)(iVar7 + (uint)bVar2 * 2) = param_3._0_2_;
        }
        param_1[0x29] = param_1[0x29] + 1;
      }
      else {
        if ((int)param_3 < 100) {
          iVar7 = param_1[0x29];
          iVar6 = iVar7;
          if ((*(byte *)((int)psVar5 + 5) >> 1 & 1) != 0) {
            iVar6 = ((char)psVar5[3] - iVar7) + -1;
          }
          if (((char)psVar5[3] <= iVar6) || (iVar6 < 0)) {
            iVar6 = -1;
          }
          if ((param_3 != (short *)iVar6) || ((int)param_3 < 0)) {
            if (cVar4 == '\0') {
              return 2;
            }
            puVar12 = &DAT_006c5bd0;
            FUN_005bc69b(*(undefined4 *)(*(int *)(param_1[1] + 0x11c) + 0x18));
            FUN_005bc69b(puVar12);
            if ((iVar6 < 0) || ((char)psVar5[3] <= iVar6)) {
              pcVar8 = s_in_animation_006d0514;
              iVar7 = (int)param_3;
              FUN_005bc69b(s_Extra_event_006d04e4);
              FUN_005bc69b(iVar7);
              FUN_005bc69b(pcVar8);
            }
            else {
              pcVar11 = s_in_animation_006d0514;
              pcVar8 = s_instead_of_006d0504;
              iVar7 = (int)param_3;
              FUN_005bc69b(s_Expected_event_006d04f4);
              FUN_005bc69b(iVar6);
              FUN_005bc69b(pcVar8);
              FUN_005bc69b(iVar7);
              FUN_005bc69b(pcVar11);
            }
            uVar9 = FUN_00589c5c(param_1[3]);
            FUN_005bc69b(uVar9);
            FUN_005bc69b(&DAT_006d04e0);
            return 2;
          }
          param_1[0x29] = iVar7 + 1;
          iVar7 = param_2;
          param_3 = (short *)iVar6;
        }
        if ((*(byte *)((int)psVar5 + 5) & 0x20) == 0) {
          if (*(char *)(iVar7 + 7) == '\0') {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          puVar10 = (undefined2 *)FUN_004752f8();
          *puVar10 = param_3._0_2_;
        }
        else {
          bVar2 = *(byte *)(psVar5 + 1);
          if ((uint)*(byte *)(iVar7 + 6) <= (uint)bVar2) {
            param_2 = 8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          iVar7 = FUN_004752fc();
          *(undefined2 *)(iVar7 + (uint)bVar2 * 2) = param_3._0_2_;
        }
      }
      return 0;
    }
    (**(code **)(*param_1 + 0xfc))();
  }
  return 1;
}

