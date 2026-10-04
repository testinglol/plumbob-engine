
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0063be2d(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  ushort uVar7;
  ushort uVar8;
  
  if (param_3 != 0) {
    if (CONCAT22(DAT_0070513c._2_2_,(undefined2)DAT_0070513c) == 0) {
      iVar3 = FUN_00646400(param_1,param_2,param_3);
      return iVar3;
    }
    FUN_0063d88b(0x19);
    do {
      param_3 = param_3 + -1;
      bVar1 = *param_1;
      uVar4 = (uint)bVar1;
      uVar8 = (ushort)bVar1;
      pbVar5 = param_1 + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 4) == 0) {
        if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 0x10) == 0x10) {
          uVar8 = (ushort)(byte)(&DAT_00705140)[uVar4];
        }
      }
      else {
        bVar2 = *pbVar5;
        if (bVar2 == 0) {
          uVar8 = 0;
        }
        else {
          pbVar5 = param_1 + 2;
          uVar8 = CONCAT11(bVar1,bVar2);
          if ((uVar8 < DAT_00705130) || (DAT_00705132 < uVar8)) {
            if ((DAT_00705134._2_2_ <= uVar8) && (uVar8 <= DAT_00705138)) {
              uVar8 = uVar8 + _DAT_0070513a;
            }
          }
          else {
            uVar8 = uVar8 + (short)DAT_00705134;
          }
        }
      }
      bVar1 = *param_2;
      uVar4 = (uint)bVar1;
      uVar7 = (ushort)bVar1;
      pbVar6 = param_2 + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 4) == 0) {
        if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 0x10) == 0x10) {
          uVar7 = (ushort)(byte)(&DAT_00705140)[uVar4];
        }
      }
      else {
        bVar2 = *pbVar6;
        if (bVar2 == 0) {
          uVar7 = 0;
        }
        else {
          pbVar6 = param_2 + 2;
          uVar7 = CONCAT11(bVar1,bVar2);
          if ((uVar7 < DAT_00705130) || (DAT_00705132 < uVar7)) {
            if ((DAT_00705134._2_2_ <= uVar7) && (uVar7 <= DAT_00705138)) {
              uVar7 = uVar7 + _DAT_0070513a;
            }
          }
          else {
            uVar7 = uVar7 + (short)DAT_00705134;
          }
        }
      }
      if (uVar8 != uVar7) {
        FUN_0063d8ec(0x19);
        return (-(uint)(uVar7 < uVar8) & 2) - 1;
      }
    } while ((uVar8 != 0) && (param_1 = pbVar5, param_2 = pbVar6, param_3 != 0));
    FUN_0063d8ec(0x19);
  }
  return 0;
}

