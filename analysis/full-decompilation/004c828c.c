
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c828c(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8,undefined4 param_9,undefined4 param_10,int param_11,
                 undefined4 param_12)

{
  char cVar1;
  int iVar2;
  undefined2 uVar9;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ushort *puVar10;
  float10 fVar11;
  undefined1 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  short local_2c;
  short local_2a;
  short local_28;
  short local_26;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar5 = param_8;
  FUN_00492d2c();
  local_5c = 0x7fffffff;
  local_58 = 0x7fffffff;
  local_54 = -0x80000000;
  local_50 = -0x80000000;
  iVar2 = FUN_004c8f7a(param_3);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0xc);
    puVar10 = (ushort *)(*(int *)(iVar3 + 0xc + param_4 * 4) + iVar3);
    uVar9 = (undefined2)((uint)iVar3 >> 0x10);
    FUN_00464479(&local_2c,0,0,CONCAT22(uVar9,*puVar10),CONCAT22(uVar9,puVar10[1]));
    param_5 = param_5 + (short)puVar10[7];
    param_6 = param_6 + (short)puVar10[6];
    FUN_004643bc(&local_2c,param_5,param_6);
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    cVar1 = FUN_004c8728(&DAT_006f0bc0,&local_2c,&local_4c);
    if (((cVar1 == '\0') && (local_40 + local_48 < (int)(uint)puVar10[1])) &&
       (local_4c + local_44 < (int)(uint)*puVar10)) {
      local_5c = local_2a + local_4c;
      local_58 = local_2c + local_48;
      local_54 = local_26 - local_44;
      local_50 = local_28 - local_40;
      iVar3 = FUN_00492d2c();
      iVar4 = FUN_004cebb0();
      param_8 = 0;
      iVar3 = *(int *)(iVar4 + (7 - iVar3) * 4) + DAT_006f0084 * -4 + local_2c * 4;
      if ((char)param_12 == '\0') {
        cVar1 = FUN_004b4708();
        if (cVar1 == '\0') {
          cVar1 = FUN_004b470c();
          if (cVar1 == '\0') {
            cVar1 = FUN_004b4700();
            if (cVar1 == '\0') {
              cVar1 = FUN_004b4704();
              if (cVar1 == '\0') {
                fVar11 = (float10)FUN_004b46a4();
              }
              else {
                fVar11 = (float10)FUN_004b46a4();
                fVar11 = fVar11 * (float10)_DAT_006f0130;
              }
              param_8 = FUN_004b9722((float)fVar11);
            }
            else {
              param_8 = *(int *)(iVar2 + 8) + 0x620;
            }
          }
          else {
            param_8 = *(int *)(iVar2 + 8) + 0xa20;
          }
        }
        else {
          param_8 = *(int *)(iVar2 + 8) + 0x820;
        }
      }
      cVar1 = FUN_004b4616(3,1);
      if (cVar1 == '\0') {
        local_18 = (int)*(char *)(param_2 + 2);
        iVar5 = FUN_00492d2c();
        iVar4 = FUN_004cebb0();
        uVar7 = 0;
        iVar5 = *(int *)(iVar4 + (0x24 - iVar5) * 4);
        uVar6 = FUN_00492d2c(0);
        FUN_004cebb0(param_2,uVar6);
        iVar4 = FUN_004c9f9a(param_2,uVar6,uVar7);
        iVar5 = (local_18 + -1) * iVar5 + 0x41 + param_11 + iVar4;
      }
      else {
        uVar6 = *(undefined4 *)(iVar5 + 0x24);
        FUN_004cebb0(iVar5,uVar6);
        iVar5 = FUN_0049a73d(iVar5,uVar6);
      }
      iVar5 = iVar5 - *(int *)(iVar3 + (short)puVar10[6] * -4);
      if (((char)param_12 == '\0') && (DAT_006f013a != '\0')) {
        puVar16 = &local_20;
        puVar15 = &local_24;
        puVar14 = &local_10;
        puVar13 = &local_14;
        uVar6 = FUN_00492d2c(puVar13,puVar14,puVar15,puVar16);
        param_3 = FUN_004c81b6(param_9,uVar6,puVar13,puVar14,puVar15,puVar16);
      }
      else {
        param_3 = 0;
      }
      uVar6 = FUN_00492d2c();
      cVar1 = FUN_004b465e();
      if ((cVar1 != '\0') && (cVar1 = FUN_004b4665(), cVar1 != '\0')) {
        if (((char)param_12 != '\0') ||
           ((param_3 == 0 ||
            (fVar11 = (float10)FUN_004b46a4(),
            ABS(fVar11 - (float10)_DAT_00666748) <= (float10)_DAT_0067343c)))) {
          local_18 = DAT_006f0bd4 >> 1;
          local_1c = DAT_006f0bd0 + (local_18 * param_6 + param_5) * 2;
          local_8 = DAT_006f0bbc >> 1;
          local_c = DAT_006f0bcc + (local_8 * param_6 + param_5) * 2;
          FUN_0049f5a6(&local_c,&local_1c,puVar10,param_8,iVar5,iVar3,&local_4c,param_10,param_12);
        }
        else {
          local_18 = DAT_006f0bd4 >> 1;
          local_8 = DAT_006f0bbc >> 1;
          if (param_3 == 1) {
            local_1c = DAT_006f0bd0 + (local_18 * param_6 + param_5) * 2;
            local_c = DAT_006f0bcc + (local_8 * param_6 + param_5) * 2;
            FUN_004b46a4(*(int *)(iVar2 + 8) + 0x20,iVar5,iVar3,&local_4c,param_10);
            uVar7 = __ftol();
            puVar12 = local_34;
            FUN_004b5717(puVar12,local_14,local_10,uVar6,uVar7);
            uVar6 = FUN_004b5e6f(puVar12,local_14,local_10,uVar6);
            FUN_004b6d77(&local_c,&local_1c,puVar10,uVar6);
          }
          else if (param_3 == 2) {
            local_1c = DAT_006f0bd0 + (local_18 * param_6 + param_5) * 2;
            local_c = DAT_006f0bcc + (local_8 * param_6 + param_5) * 2;
            FUN_004b46a4(*(int *)(iVar2 + 8) + 0x20,iVar5,iVar3,&local_4c,param_10);
            uVar8 = __ftol();
            puVar12 = local_34;
            uVar7 = uVar6;
            FUN_004b5717(puVar12,local_24,local_20,uVar6,uVar8);
            uVar7 = FUN_004b5e6f(puVar12,local_24,local_20,uVar7);
            puVar12 = local_3c;
            FUN_004b5717(puVar12,local_14,local_10,uVar6,uVar7);
            uVar6 = FUN_004b5e6f(puVar12,local_14,local_10,uVar6);
            FUN_004b638a(&local_c,&local_1c,puVar10,uVar6);
          }
        }
      }
    }
  }
  *param_1 = local_5c;
  param_1[1] = local_58;
  param_1[2] = local_54;
  param_1[3] = local_50;
  return;
}

