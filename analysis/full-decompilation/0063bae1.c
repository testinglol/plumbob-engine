
int FUN_0063bae1(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  byte *local_10;
  byte *local_c;
  byte local_8;
  byte local_7;
  
  if (DAT_0070513c == 0) {
    iVar2 = FUN_00646330(param_1,param_2);
  }
  else {
    FUN_0063d88b(0x19);
    local_10 = param_2 + -1;
    local_c = param_1 + -1;
    do {
      uVar7 = (uint)*param_1;
      pbVar4 = param_1 + 1;
      pbVar1 = local_c + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar7 + 1) & 4) == 0) {
        param_1 = pbVar4;
        local_c = pbVar1;
        if ((*(byte *)((int)&DAT_00705240 + uVar7 + 1) & 0x10) == 0x10) {
          uVar7 = (uint)(byte)(&DAT_00705140)[uVar7];
        }
      }
      else if (*pbVar4 == 0) {
        uVar7 = 0;
        param_1 = pbVar4;
        local_c = pbVar1;
      }
      else {
        iVar2 = FUN_0064439a(DAT_00705344,0x200,pbVar1,2,&local_8,2,DAT_00705124,1);
        if (iVar2 == 1) {
          uVar7 = (uint)local_8;
        }
        else {
          if (iVar2 != 2) goto LAB_0063bc45;
          uVar7 = (uint)local_8 * 0x100 + (uint)local_7;
        }
        param_1 = param_1 + 2;
        local_c = local_c + 2;
      }
      uVar3 = (uint)*param_2;
      uVar5 = (ushort)*param_2;
      pbVar4 = param_2 + 1;
      pbVar1 = local_10 + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar3 + 1) & 4) == 0) {
        param_2 = pbVar4;
        local_10 = pbVar1;
        if ((*(byte *)((int)&DAT_00705240 + uVar3 + 1) & 0x10) == 0x10) {
          uVar5 = (ushort)(byte)(&DAT_00705140)[uVar3];
        }
      }
      else if (*pbVar4 == 0) {
        uVar5 = 0;
        param_2 = pbVar4;
        local_10 = pbVar1;
      }
      else {
        iVar2 = FUN_0064439a(DAT_00705344,0x200,pbVar1,2,&local_8,2,DAT_00705124,1);
        if (iVar2 == 1) {
          uVar5 = (ushort)local_8;
        }
        else {
          if (iVar2 != 2) {
LAB_0063bc45:
            FUN_0063d8ec(0x19);
            return 0x7fffffff;
          }
          uVar5 = (ushort)local_8 * 0x100 + (ushort)local_7;
        }
        param_2 = param_2 + 2;
        local_10 = local_10 + 2;
      }
      uVar6 = (ushort)uVar7;
      if (uVar6 != uVar5) {
        FUN_0063d8ec(0x19);
        return (-(uint)(uVar5 < uVar6) & 2) - 1;
      }
    } while (uVar6 != 0);
    FUN_0063d8ec(0x19);
    iVar2 = 0;
  }
  return iVar2;
}

