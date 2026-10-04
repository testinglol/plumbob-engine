
undefined4 __fastcall FUN_0046a497(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  float local_1c;
  float local_18;
  int local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_8 = 0;
  iVar3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2;
  if (1 < iVar3) {
    local_24 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 3;
    local_20 = iVar3;
    do {
      iVar2 = *(int *)(param_1 + 0x58) + 1;
      local_14 = 100 / (iVar2 * iVar2);
      if (local_14 < 1) {
        local_14 = 1;
      }
      iVar2 = 1;
      if (1 < iVar3) {
        do {
          FUN_004696ba(*(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 4 + -4),
                       *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 4),&local_58);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_10 = iVar2 * 8;
          local_28 = iVar2 + 1;
          local_40 = *(undefined4 *)(local_10 + -8 + iVar3);
          piVar4 = (int *)(local_10 + iVar3);
          local_3c = piVar4[-1];
          local_30 = *piVar4;
          local_2c = piVar4[1];
          if (local_28 < local_24) {
            local_38 = *(int *)(local_10 + 8 + iVar3);
            local_34 = *(int *)(local_10 + 0xc + iVar3);
          }
          else {
            local_38 = *piVar4;
            local_34 = piVar4[1];
          }
          fVar5 = (float10)FUN_0046a781(local_40,local_3c,local_30,local_2c);
          local_1c = (float)fVar5;
          fVar5 = (float10)FUN_0046a781(*piVar4,piVar4[1],local_38,local_34);
          iVar3 = local_14;
          local_48 = local_30;
          local_44 = local_2c;
          local_18 = (float)(fVar5 + (float10)local_1c);
          local_c = local_18;
          if (2 < local_50 - local_58) {
            piVar4 = (int *)(local_10 + *(int *)(param_1 + 0x1c));
            iVar2 = *piVar4;
            local_2c = piVar4[1];
            if (iVar2 < local_50 - local_14) {
              iVar2 = iVar2 + local_14;
              fVar5 = (float10)FUN_0046a781(iVar2,local_2c,local_38,local_34);
              local_1c = (float)fVar5;
              fVar5 = (float10)FUN_0046a781(local_40,local_3c,iVar2,local_2c);
              local_1c = (float)(fVar5 + (float10)local_1c);
              if (local_1c < local_18) {
                local_44 = local_2c;
                local_48 = iVar2;
                local_c = local_1c;
              }
              local_8 = local_8 + (uint)(local_1c < local_18);
            }
            piVar4 = (int *)(local_10 + *(int *)(param_1 + 0x1c));
            iVar2 = *piVar4;
            local_2c = piVar4[1];
            if (local_58 + iVar3 < iVar2) {
              iVar2 = iVar2 - iVar3;
              fVar5 = (float10)FUN_0046a781(iVar2,local_2c,local_38,local_34);
              local_1c = (float)fVar5;
              fVar5 = (float10)FUN_0046a781(local_40,local_3c,iVar2,local_2c);
              local_1c = (float)(fVar5 + (float10)local_1c);
              bVar1 = local_1c < local_c;
              if (bVar1) {
                local_44 = local_2c;
                local_48 = iVar2;
                local_c = local_1c;
              }
              local_8 = local_8 + (uint)bVar1;
            }
          }
          if (2 < local_4c - local_54) {
            piVar4 = (int *)(local_10 + *(int *)(param_1 + 0x1c));
            local_30 = *piVar4;
            iVar2 = piVar4[1];
            if (iVar2 < local_4c - iVar3) {
              iVar2 = iVar2 + iVar3;
              fVar5 = (float10)FUN_0046a781(local_30,iVar2,local_38,local_34);
              local_1c = (float)fVar5;
              fVar5 = (float10)FUN_0046a781(local_40,local_3c,local_30,iVar2);
              local_1c = (float)(fVar5 + (float10)local_1c);
              bVar1 = local_1c < local_c;
              if (bVar1) {
                local_48 = local_30;
                local_44 = iVar2;
                local_c = local_1c;
              }
              local_8 = local_8 + (uint)bVar1;
            }
            piVar4 = (int *)(local_10 + *(int *)(param_1 + 0x1c));
            local_30 = *piVar4;
            iVar2 = piVar4[1];
            if (local_54 + iVar3 < iVar2) {
              iVar2 = iVar2 - iVar3;
              fVar5 = (float10)FUN_0046a781(local_30,iVar2,local_38,local_34);
              iVar3 = local_30;
              local_1c = (float)fVar5;
              fVar5 = (float10)FUN_0046a781(local_40,local_3c,local_30,iVar2);
              local_1c = (float)(fVar5 + (float10)local_1c);
              if (local_1c < local_c) {
                local_48 = iVar3;
                local_44 = iVar2;
              }
              local_8 = local_8 + (uint)(local_1c < local_c);
            }
          }
          piVar4 = (int *)(local_10 + *(int *)(param_1 + 0x1c));
          *piVar4 = local_48;
          piVar4[1] = local_44;
          iVar2 = local_28;
        } while (local_28 < local_20);
        iVar3 = local_20;
        if (local_8 != 0) {
          return 0;
        }
      }
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
    } while (1 < local_14);
  }
  return 1;
}

