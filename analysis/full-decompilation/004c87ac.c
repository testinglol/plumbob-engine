
void FUN_004c87ac(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8,undefined4 param_9)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar7;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar8;
  undefined4 uVar9;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  int local_c;
  int local_8;
  
  local_2c = 0x7fffffff;
  local_28 = 0x7fffffff;
  local_24 = -0x80000000;
  local_20 = -0x80000000;
  iVar3 = FUN_004c8f7a(param_3);
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0xc);
    puVar8 = (ushort *)(*(int *)(iVar4 + 0xc + param_4 * 4) + iVar4);
    uVar7 = (undefined2)((uint)iVar4 >> 0x10);
    FUN_00464479(&local_14,0,0,CONCAT22(uVar7,*puVar8),CONCAT22(uVar7,puVar8[1]));
    FUN_004643bc(&local_14,param_5,param_6);
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    cVar2 = FUN_004c8728(&DAT_006f0bc0,&local_14,&local_3c);
    if ((cVar2 == '\0') && (local_30 + local_38 < (int)(uint)puVar8[1])) {
      if (local_34 + local_3c < (int)(uint)*puVar8) {
        local_2c = local_12 + local_3c;
        local_28 = local_14 + local_38;
        local_24 = local_e - local_34;
        local_20 = local_10 - local_30;
        iVar4 = FUN_00492d2c();
        iVar5 = FUN_004cebb0();
        iVar3 = *(int *)(iVar3 + 8);
        piVar1 = (int *)(*(int *)(iVar5 + (7 - iVar4) * 4) + DAT_006f0084 * -4 + local_14 * 4);
        cVar2 = FUN_004b4616(3,1);
        if (cVar2 == '\0') {
          local_8 = (int)*(char *)(param_2 + 2);
          iVar4 = FUN_00492d2c();
          iVar5 = FUN_004cebb0();
          uVar9 = 0;
          iVar4 = *(int *)(iVar5 + (0x24 - iVar4) * 4);
          uVar6 = FUN_00492d2c(0);
          FUN_004cebb0(param_2,uVar6);
          iVar5 = FUN_004c9f9a(param_2,uVar6,uVar9);
          iVar5 = iVar5 + (local_8 + -1) * iVar4;
        }
        else {
          uVar6 = *(undefined4 *)(param_8 + 0x24);
          FUN_004cebb0(param_8,uVar6);
          iVar5 = FUN_0049a73d(param_8,uVar6);
        }
        iVar4 = *piVar1;
        cVar2 = FUN_004b465e();
        if (cVar2 != '\0') {
          cVar2 = FUN_004b4665();
          if (cVar2 != '\0') {
            local_8 = DAT_006f0bd4 >> 1;
            local_c = DAT_006f0bd0 + (local_8 * param_6 + param_5) * 2;
            local_18 = DAT_006f0bbc >> 1;
            local_1c = DAT_006f0bcc + (local_18 * param_6 + param_5) * 2;
            FUN_004a6472(&local_1c,&local_c,puVar8,iVar3 + 0x420,iVar5 - iVar4,piVar1,&local_3c,
                         param_9);
          }
        }
      }
    }
  }
  *param_1 = local_2c;
  param_1[1] = local_28;
  param_1[2] = local_24;
  param_1[3] = local_20;
  return;
}

