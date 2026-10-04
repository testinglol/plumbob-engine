
void __thiscall FUN_00630fee(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int local_24;
  int local_1c;
  undefined2 *local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x4a40);
  bVar2 = *(char *)(param_1 + 0x4a0c) - 1U & 0xf;
  *(byte *)(param_1 + 0x4a0c) = bVar2;
  uVar4 = bVar2 & 1;
  if (0 < iVar1) {
    local_18 = param_2;
    local_10 = (uint)bVar2 * 4 + (uVar4 ^ 1) * 0x484 + 4 + param_1;
    local_14 = (int)param_3;
    local_c = param_1 + 4;
    local_24 = iVar1;
    do {
      FUN_006312ec(local_c + ((*(byte *)(param_1 + 0x4a0c) + uVar4 & 0xf) + uVar4 * 0x120) * 4,
                   local_10,local_14);
      if (param_2 != (undefined2 *)0x0) {
        param_3 = local_18;
        local_1c = 0x10;
        do {
          iVar3 = __ftol();
          if (iVar3 < 0x8000) {
            if (iVar3 < -0x8000) {
              *param_3 = 0x8000;
            }
            else {
              *param_3 = (short)iVar3;
            }
          }
          else {
            *param_3 = 0x7fff;
          }
          param_3 = param_3 + iVar1;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        iVar3 = __ftol();
        if (iVar3 < 0x8000) {
          if (iVar3 < -0x8000) {
            *param_3 = 0x8000;
          }
          else {
            *param_3 = (short)iVar3;
          }
        }
        else {
          *param_3 = 0x7fff;
        }
        local_1c = 0xf;
        do {
          param_3 = param_3 + iVar1;
          iVar3 = __ftol();
          if (iVar3 < 0x8000) {
            if (iVar3 < -0x8000) {
              *param_3 = 0x8000;
            }
            else {
              *param_3 = (short)iVar3;
            }
          }
          else {
            *param_3 = 0x7fff;
          }
          local_1c = local_1c + -1;
        } while (local_1c != 0);
      }
      local_14 = local_14 + 0x80;
      local_18 = local_18 + 1;
      local_c = local_c + 0x900;
      local_10 = local_10 + 0x900;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  return;
}

