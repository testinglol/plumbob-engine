
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0063bf8e(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  ushort uVar9;
  
  if (param_3 == 0) {
    return 0;
  }
  if (CONCAT22(DAT_0070513c._2_2_,(undefined2)DAT_0070513c) == 0) {
    iVar4 = FUN_00646400(param_1,param_2,param_3);
    return iVar4;
  }
  FUN_0063d88b(0x19);
  iVar4 = param_3;
  do {
    param_3 = iVar4 + -1;
    bVar1 = *param_1;
    uVar8 = (uint)bVar1;
    uVar9 = (ushort)bVar1;
    pbVar5 = param_1 + 1;
    if ((*(byte *)((int)&DAT_00705240 + uVar8 + 1) & 4) == 0) {
      if ((*(byte *)((int)&DAT_00705240 + uVar8 + 1) & 0x10) == 0x10) {
        uVar9 = (ushort)(byte)(&DAT_00705140)[uVar8];
      }
LAB_0063c061:
      uVar8 = (uint)*param_2;
      pbVar6 = param_2 + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar8 + 1) & 4) == 0) {
        param_2 = pbVar6;
        if ((*(byte *)((int)&DAT_00705240 + uVar8 + 1) & 0x10) == 0x10) {
          uVar8 = (uint)(byte)(&DAT_00705140)[uVar8];
        }
      }
      else {
        if (param_3 != 0) {
          param_3 = iVar4 + -2;
          if (*pbVar6 != 0) {
            pbVar7 = param_2 + 2;
            uVar3 = CONCAT11(*param_2,*pbVar6);
            uVar8 = (uint)uVar3;
            param_2 = pbVar7;
            if ((uVar3 < DAT_00705130) || (DAT_00705132 < uVar3)) {
              if ((DAT_00705134._2_2_ <= uVar3) && (uVar3 <= DAT_00705138)) {
                uVar8 = uVar8 + CONCAT22((undefined2)DAT_0070513c,_DAT_0070513a);
              }
            }
            else {
              uVar8 = uVar8 + DAT_00705134;
            }
            goto LAB_0063c0dd;
          }
        }
        uVar8 = 0;
        param_2 = pbVar6;
      }
    }
    else {
      if (param_3 != 0) {
        bVar2 = *pbVar5;
        if (bVar2 == 0) {
          uVar9 = 0;
        }
        else {
          pbVar5 = param_1 + 2;
          uVar9 = CONCAT11(bVar1,bVar2);
          if ((uVar9 < DAT_00705130) || (DAT_00705132 < uVar9)) {
            if ((DAT_00705134._2_2_ <= uVar9) && (uVar9 <= DAT_00705138)) {
              uVar9 = uVar9 + _DAT_0070513a;
            }
          }
          else {
            uVar9 = uVar9 + (short)DAT_00705134;
          }
        }
        goto LAB_0063c061;
      }
      uVar8 = (uint)*param_2;
      uVar9 = 0;
      if ((*(byte *)((int)&DAT_00705240 + uVar8 + 1) & 4) != 0) {
LAB_0063c10b:
        FUN_0063d8ec(0x19);
        return 0;
      }
    }
LAB_0063c0dd:
    if (uVar9 != (ushort)uVar8) {
      FUN_0063d8ec(0x19);
      return (-(uint)((ushort)uVar8 < uVar9) & 2) - 1;
    }
    if ((uVar9 == 0) || (param_1 = pbVar5, iVar4 = param_3, param_3 == 0)) goto LAB_0063c10b;
  } while( true );
}

