
void FUN_00617380(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9)

{
  byte bVar1;
  byte bVar2;
  double dVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int local_3c;
  
  switch(param_9) {
  case 1:
    if (0 < param_2) {
      pbVar6 = (byte *)((int)param_1 + 3);
      do {
        *pbVar6 = *pbVar6 >> 1;
        pbVar6 = pbVar6 + 4;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    break;
  case 2:
    if (0 < param_2) {
      do {
        *param_1 = (int)*param_1 >> 1 & 0x7f7f7f7f;
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    break;
  case 3:
    if (0 < param_2) {
      pbVar6 = (byte *)((int)param_1 + 3);
      do {
        param_2 = param_2 + -1;
        *pbVar6 = (byte)((int)(*pbVar6 + 1) >> 1);
        pbVar6 = pbVar6 + 4;
      } while (param_2 != 0);
      return;
    }
    break;
  case 4:
    if (0 < param_2) {
      do {
        *param_1 = (*param_1 >> 1 & 0x7f7f7f7f) + (*param_1 & 0x1010101);
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    break;
  default:
    uVar7 = FUN_0062b9b0(param_3,param_4,0,0,0,0x406fe000);
    uVar8 = FUN_0062b9b0(param_3,param_5,0,0,0,0x406fe000);
    uVar9 = FUN_0062b9b0(param_3,param_6,0,0,0,0x406fe000);
    uVar10 = FUN_0062b9b0(param_3,param_7,0,0,0,0x406fe000);
    FUN_0062b2e0(param_3,&DAT_00677a4c,(double)param_8);
    local_3c = 0;
    if (0 < param_2) {
      do {
        bVar5 = *(byte *)((int)param_1 + 3);
        FUN_0062b2e0(param_3,&DAT_006c0a74,(double)bVar5);
        bVar1 = *(byte *)((int)param_1 + 2);
        FUN_0062b2e0(param_3,&DAT_006c16d8,(double)bVar1);
        bVar2 = *(byte *)((int)param_1 + 1);
        FUN_0062b2e0(param_3,&DAT_006778b4,(double)bVar2);
        uVar4 = *param_1;
        FUN_0062b2e0(param_3,&DAT_006778b0,(double)(byte)uVar4);
        FUN_0062b2e0(param_3,&DAT_006c6f28,(double)local_3c);
        FUN_0062b2e0(param_3,&DAT_006778ac,(double)local_3c);
        FUN_0062b2e0(param_3,&DAT_00677a44,
                     (double)CONCAT31(CONCAT21(CONCAT11(bVar5,bVar1),bVar2),(byte)uVar4));
        dVar3 = (double)*(byte *)((int)param_1 + 3);
        FUN_0062ba20(uVar7,dVar3,0);
        iVar11 = __ftol();
        if (iVar11 < 0x100) {
          FUN_0062ba20(uVar7,dVar3,0);
          iVar11 = __ftol();
          if (-1 < iVar11) goto LAB_00617646;
          bVar5 = 0;
        }
        else {
LAB_00617646:
          FUN_0062ba20(uVar7,dVar3,0);
          iVar11 = __ftol();
          if (iVar11 < 0x100) {
            FUN_0062ba20(uVar7,dVar3,0);
            bVar5 = __ftol();
          }
          else {
            bVar5 = 0xff;
          }
        }
        *(byte *)((int)param_1 + 3) = bVar5;
        dVar3 = (double)*(byte *)((int)param_1 + 2);
        FUN_0062ba20(uVar8,dVar3,0);
        iVar11 = __ftol();
        if (iVar11 < 0x100) {
          FUN_0062ba20(uVar8,dVar3,0);
          iVar11 = __ftol();
          if (-1 < iVar11) goto LAB_006176ef;
          bVar5 = 0;
        }
        else {
LAB_006176ef:
          FUN_0062ba20(uVar8,dVar3,0);
          iVar11 = __ftol();
          if (iVar11 < 0x100) {
            FUN_0062ba20(uVar8,dVar3,0);
            bVar5 = __ftol();
          }
          else {
            bVar5 = 0xff;
          }
        }
        *(byte *)((int)param_1 + 2) = bVar5;
        dVar3 = (double)*(byte *)((int)param_1 + 1);
        FUN_0062ba20(uVar9,dVar3,0);
        iVar11 = __ftol();
        if (iVar11 < 0x100) {
          FUN_0062ba20(uVar9,dVar3,0);
          iVar11 = __ftol();
          if (-1 < iVar11) goto LAB_00617798;
          bVar5 = 0;
        }
        else {
LAB_00617798:
          FUN_0062ba20(uVar9,dVar3,0);
          iVar11 = __ftol();
          if (iVar11 < 0x100) {
            FUN_0062ba20(uVar9,dVar3,0);
            bVar5 = __ftol();
          }
          else {
            bVar5 = 0xff;
          }
        }
        *(byte *)((int)param_1 + 1) = bVar5;
        dVar3 = (double)(byte)*param_1;
        FUN_0062ba20(uVar10,dVar3,0);
        iVar11 = __ftol();
        if (iVar11 < 0x100) {
          FUN_0062ba20(uVar10,dVar3,0);
          iVar11 = __ftol();
          if (-1 < iVar11) goto LAB_00617840;
          bVar5 = 0;
        }
        else {
LAB_00617840:
          FUN_0062ba20(uVar10,dVar3,0);
          iVar11 = __ftol();
          if (iVar11 < 0x100) {
            FUN_0062ba20(uVar10,dVar3,0);
            bVar5 = __ftol();
          }
          else {
            bVar5 = 0xff;
          }
        }
        *(byte *)param_1 = bVar5;
        param_1 = param_1 + 1;
        local_3c = local_3c + 1;
      } while (local_3c < param_2);
    }
    FUN_00626170();
    FUN_00626170(uVar8);
    FUN_00626170(uVar9);
    FUN_00626170(uVar10);
  }
  return;
}

