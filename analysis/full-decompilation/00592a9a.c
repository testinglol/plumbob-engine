
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00592a9a(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  short local_20;
  short local_1e;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_6;
  char local_5;
  
  iVar6 = *(int *)(param_1 + 0x138);
  if (((iVar6 != 0) && (*(short *)(iVar6 + 0x8e) == 0)) && (-1 < *(short *)(iVar6 + 0x84))) {
    piVar1 = *(int **)(DAT_006e486c + 4);
    local_c = param_1;
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    iVar6 = *(int *)(iVar2 + 0x10);
    iVar2 = *(int *)(iVar2 + 0x14);
    local_1c = (**(code **)(*piVar1 + 0x14))();
    local_24 = _DAT_00671ed0 * _DAT_00666cbc;
    FUN_00434e9b(&local_24);
    local_24 = (float)(1 << ((char)local_1c + 1U & 0x1f));
    local_14 = __ftol();
    iVar3 = *(int *)(local_c + 0x138);
    local_10 = *(int *)(iVar3 + 0x110);
    local_34 = *(undefined4 *)(iVar3 + 0xf4);
    local_30 = *(undefined4 *)(iVar3 + 0xf8);
    FUN_0047bd91(&local_30,&local_34,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
    (**(code **)*piVar1)(&local_20,local_34,local_30,local_10,DAT_006f0088,0);
    local_2c = (int)local_1e;
    local_28 = (int)local_20;
    local_24 = *(float *)(DAT_006f2a08 + 0xb0);
    iVar3 = (**(code **)(*piVar1 + 0x38))();
    if (local_10 == iVar3) {
      iVar3 = FUN_0045c4b5();
      if (iVar3 == 0) {
        local_44 = iVar6 / 4;
        iVar6 = (iVar6 * 3) / 4;
        iVar3 = iVar2 / 4 + local_14;
        iVar2 = (iVar2 * 3) / 4;
      }
      else {
        local_44 = 0x10 << ((byte)local_1c & 0x1f);
        iVar6 = iVar6 - local_44;
        iVar3 = (local_14 * 9) / 8;
        iVar2 = iVar2 - local_14 / 8;
      }
      if (((local_2c < local_44) || (local_28 < iVar3)) ||
         ((iVar6 <= local_2c || (iVar2 <= local_28)))) {
        local_4c = local_2c;
        iVar4 = local_28;
        if (*(int *)(local_c + 0x188) != 0) {
          local_5c = 0;
          local_58 = 0;
          local_54 = 1;
          local_50 = 1;
          FUN_004ba5ac(&local_2c);
          local_5 = '\0';
          local_18 = (iVar6 - local_44) + -0x20;
          local_6 = '\0';
          iVar6 = (*(int **)(local_c + 0x184))[1];
          local_1c = (iVar2 - iVar3) + -0x20;
          iVar2 = **(int **)(local_c + 0x184);
          iVar3 = *(int *)(local_c + 0x180);
          while ((iVar3 < (iVar6 - iVar2 >> 3) + -1 && ((local_5 == '\0' || (local_6 == '\0'))))) {
            local_3c = *(undefined4 *)(**(int **)(local_c + 0x184) + iVar3 * 8);
            local_38 = *(undefined4 *)(**(int **)(local_c + 0x184) + 4 + iVar3 * 8);
            FUN_0047bd91(&local_38,&local_3c,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
            (**(code **)*piVar1)(&local_24,local_3c,local_38,local_10,DAT_006f0088,0);
            iVar4 = (int)local_24._2_2_;
            iVar5 = (int)(short)local_24;
            if (local_5 == '\0') {
              if (iVar4 < local_5c) {
                local_5c = iVar4;
                if (local_18 < local_54 - iVar4) {
                  local_5c = local_54 - local_18;
LAB_00592d85:
                  local_5 = '\x01';
                }
              }
              else if ((local_54 <= iVar4) && (local_54 = iVar4 + 1, local_18 < local_54 - local_5c)
                      ) {
                local_54 = local_18 + local_5c;
                goto LAB_00592d85;
              }
            }
            if (local_6 == '\0') {
              if (iVar5 < local_58) {
                local_58 = iVar5;
                if (local_1c < local_50 - iVar5) {
                  local_58 = local_50 - local_1c;
LAB_00592dc5:
                  local_6 = '\x01';
                }
              }
              else if ((local_50 <= iVar5) && (local_50 = iVar5 + 1, local_1c < local_50 - local_58)
                      ) {
                local_50 = local_58 + local_1c;
                goto LAB_00592dc5;
              }
            }
            iVar3 = iVar3 + 1;
          }
          local_4c = (local_54 + local_5c) / 2;
          iVar4 = (local_50 + local_58) / 2;
        }
        FUN_004a798b(local_4c,iVar4 + local_14 / -2,param_2);
        FUN_004b1668(0,0);
      }
    }
    else {
      local_28 = local_28 + local_14 / -2;
      FUN_004a82db(local_10,0);
      FUN_004b1668(0,0);
      if (local_24 != 0.0) {
        FUN_004cefa3(local_10,0);
      }
      FUN_004a798b(local_2c,local_28,param_2);
    }
  }
  return;
}

