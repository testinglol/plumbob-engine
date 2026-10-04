
void FUN_004b12d3(int param_1,int param_2,int *param_3,int param_4,int param_5,undefined2 *param_6,
                 int *param_7,int param_8)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((int)DAT_006f0bc2 < param_5 + param_1) && (param_1 < DAT_006f0bc6)) &&
      ((int)DAT_006f0bc0 < (int)param_6 + param_2)) && (param_2 < DAT_006f0bc4)) {
    iVar3 = DAT_006f0bbc >> 1;
    iVar4 = DAT_006f0bd4 >> 1;
    iVar7 = *param_3;
    puVar5 = (undefined2 *)(DAT_006f0bcc + (iVar3 * param_2 + param_1) * 2);
    iVar6 = param_3[1] * (int)param_6 + iVar7;
    local_8 = DAT_006f0bd0 + (iVar4 * param_2 + param_1) * 2;
    if (*(int *)(DAT_006e486c + 0x34) == 1) {
      if (iVar7 != iVar6) {
        local_c = param_2;
        do {
          if (DAT_006f0bc4 <= local_c) {
            return;
          }
          iVar1 = *param_7;
          if ((DAT_006f0bc0 <= local_c) && (local_14 = 0, 0 < param_5)) {
            local_10 = param_1;
            param_6 = puVar5;
            do {
              if (DAT_006f0bc6 <= local_10) break;
              if (((DAT_006f0bc2 <= local_10) &&
                  ((int)((uint)*(byte *)((iVar7 - param_1) + local_10) + param_4) < 0xf8)) &&
                 (iVar1 + param_8 <= (int)(uint)*(ushort *)((local_8 - (int)puVar5) + (int)param_6))
                 ) {
                FUN_00438f76(CONCAT22((short)((uint)param_6 >> 0x10),*param_6));
                uVar2 = FUN_00438f12();
                *param_6 = uVar2;
              }
              local_14 = local_14 + 1;
              local_10 = local_10 + 1;
              param_6 = param_6 + 1;
            } while (local_14 < param_5);
          }
          local_c = local_c + 1;
          puVar5 = puVar5 + iVar3;
          iVar7 = iVar7 + param_3[1];
          local_8 = local_8 + iVar4 * 2;
          param_7 = param_7 + 1;
        } while (iVar7 != iVar6);
      }
    }
    else if (iVar7 != iVar6) {
      local_c = param_2;
      do {
        if (DAT_006f0bc4 <= local_c) {
          return;
        }
        iVar1 = *param_7;
        if ((DAT_006f0bc0 <= local_c) && (local_10 = 0, 0 < param_5)) {
          local_14 = param_1;
          param_6 = puVar5;
          do {
            if (DAT_006f0bc6 <= local_14) break;
            if (((DAT_006f0bc2 <= local_14) &&
                ((int)((uint)*(byte *)(local_14 + (iVar7 - param_1)) + param_4) < 0xf8)) &&
               (iVar1 + param_8 <= (int)(uint)*(ushort *)((int)param_6 + (local_8 - (int)puVar5))))
            {
              FUN_00438f9b(CONCAT22((short)((uint)param_6 >> 0x10),*param_6));
              uVar2 = FUN_00438f12();
              *param_6 = uVar2;
            }
            local_10 = local_10 + 1;
            local_14 = local_14 + 1;
            param_6 = param_6 + 1;
          } while (local_10 < param_5);
        }
        local_c = local_c + 1;
        puVar5 = puVar5 + iVar3;
        iVar7 = iVar7 + param_3[1];
        local_8 = local_8 + iVar4 * 2;
        param_7 = param_7 + 1;
      } while (iVar7 != iVar6);
    }
  }
  return;
}

