
void FUN_006178e0(byte *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  double dVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int local_38;
  
  uVar7 = FUN_0062b9b0(param_4,param_5,0,0,0,0x406fe000);
  FUN_0062b2e0(param_4,&DAT_00677a4c,(double)param_6);
  local_38 = 0;
  if (0 < param_3) {
    do {
      bVar6 = *param_1;
      uVar9 = (uint)bVar6;
      bVar1 = *(byte *)(param_2 + 2 + uVar9 * 4);
      bVar2 = *(byte *)(param_2 + 3 + uVar9 * 4);
      bVar3 = *(byte *)(param_2 + 1 + uVar9 * 4);
      bVar4 = *(byte *)(param_2 + uVar9 * 4);
      FUN_0062b2e0(param_4,&DAT_006c0a74,(double)bVar2);
      FUN_0062b2e0(param_4,&DAT_006c16d8,(double)bVar1);
      FUN_0062b2e0(param_4,&DAT_006778b4,(double)bVar3);
      FUN_0062b2e0(param_4,&DAT_006778b0,(double)bVar4);
      FUN_0062b2e0(param_4,&DAT_006c6f28,(double)local_38);
      FUN_0062b2e0(param_4,&DAT_006778ac,(double)uVar9);
      FUN_0062b2e0(param_4,&DAT_00677a44,
                   (double)CONCAT31(CONCAT21(CONCAT11(bVar2,bVar1),bVar3),bVar4));
      dVar5 = (double)bVar6;
      FUN_0062ba20(uVar7,dVar5,0);
      iVar8 = __ftol();
      if (iVar8 < 0x100) {
        FUN_0062ba20(uVar7,dVar5,0);
        iVar8 = __ftol();
        if (-1 < iVar8) goto LAB_00617a9e;
        bVar6 = 0;
      }
      else {
LAB_00617a9e:
        FUN_0062ba20(uVar7,dVar5,0);
        iVar8 = __ftol();
        if (iVar8 < 0x100) {
          FUN_0062ba20(uVar7,dVar5,0);
          bVar6 = __ftol();
        }
        else {
          bVar6 = 0xff;
        }
      }
      *param_1 = bVar6;
      param_1 = param_1 + 1;
      local_38 = local_38 + 1;
    } while (local_38 < param_3);
  }
  FUN_00626170();
  return;
}

