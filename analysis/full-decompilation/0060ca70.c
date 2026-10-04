
void FUN_0060ca70(byte *param_1,byte *param_2,byte *param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int local_4;
  
  if (0 < param_6) {
    local_4 = param_6;
    do {
      if (param_4 < 4) {
        pbVar1 = (byte *)(param_8 + (uint)*param_2 * 4);
        if (pbVar1[3] < 0x11) {
          bVar5 = *param_3;
LAB_0060cbd7:
          *param_1 = bVar5;
        }
        else {
          pbVar2 = (byte *)(param_8 + (uint)*param_3 * 4);
          if (0x10 < pbVar2[3]) {
            param_6._3_1_ = (undefined1)((int)((uint)pbVar2[3] + (uint)pbVar1[3]) >> 1);
            param_6._0_3_ =
                 CONCAT12((char)((int)((uint)pbVar2[2] + (uint)pbVar1[2]) >> 1),
                          CONCAT11((char)((int)((uint)pbVar2[1] + (uint)pbVar1[1]) >> 1),
                                   (char)((int)((uint)*pbVar2 + (uint)*pbVar1) >> 1)));
            bVar5 = FUN_0060cc10(&param_6,param_7,param_8);
            goto LAB_0060cbd7;
          }
          *param_1 = *param_2;
        }
        param_1 = param_1 + 1;
      }
      else {
        bVar5 = param_2[3];
        uVar7 = (uint)bVar5;
        bVar3 = param_3[3];
        uVar6 = (uint)bVar3;
        if (uVar6 < uVar7) {
LAB_0060cade:
          if (uVar6 < 0x41) {
            bVar3 = param_2[1];
            *param_1 = *param_2;
            bVar4 = param_2[2];
            param_1[1] = bVar3;
            param_1[2] = bVar4;
            param_1[3] = bVar5;
            param_1 = param_1 + 4;
          }
          else {
LAB_0060cafe:
            bVar5 = *param_2;
            bVar3 = *param_3;
            param_1[3] = (byte)((int)(uVar6 + uVar7) >> 1);
            *param_1 = (byte)((int)((uint)bVar5 + (uint)bVar3) >> 1);
            param_1[1] = (byte)((int)((uint)param_2[1] + (uint)param_3[1]) >> 1);
            param_1[2] = (byte)((int)((uint)param_2[2] + (uint)param_3[2]) >> 1);
            param_1 = param_1 + 4;
          }
        }
        else {
          if (0x40 < uVar7) {
            if (uVar6 <= uVar7) goto LAB_0060cade;
            goto LAB_0060cafe;
          }
          *param_1 = *param_3;
          param_1[1] = param_3[1];
          param_1[2] = param_3[2];
          param_1[3] = bVar3;
          param_1 = param_1 + 4;
        }
      }
      param_2 = param_2 + param_5;
      param_3 = param_3 + param_5;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

