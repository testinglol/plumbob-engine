
void __thiscall FUN_00506635(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10;
  uint local_8;
  
  local_10 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2 != 0) {
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x420) + local_8 * 4);
      if (iVar3 != 0) {
        iVar1 = FUN_00492d2c();
        if ((iVar3 == param_2) || (iVar1 == 0)) {
          iVar3 = FUN_0046d9e5();
          iVar2 = FUN_004cba72();
          FUN_004cf9c0(local_8,param_2);
          FUN_004cee86(0x200);
          if ((*(int *)(param_1 + 0x42c) != 0) &&
             (*(char *)(*(int *)(param_1 + 0x42c) + 0xf0) != '\0')) {
            FUN_005083f4(*(undefined4 *)(*(int *)(param_1 + 0x420) + local_8 * 4),param_1);
          }
          if (iVar3 < iVar2) {
            if (iVar1 != 0) {
              FUN_005e46f0(0);
            }
            FUN_00484901(7);
            FUN_00492c37();
          }
          else {
            iVar3 = 1;
            local_10 = 1;
            iVar2 = iVar3;
            if (iVar1 != 0) goto LAB_0050668d;
          }
        }
        else {
          iVar3 = 0;
          iVar2 = local_10;
LAB_0050668d:
          local_10 = iVar2;
          FUN_005e46f0(iVar3);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(*(int *)(param_1 + 0x424) - *(int *)(param_1 + 0x420) >> 2));
    if (local_10 != 0) {
      return;
    }
  }
  FUN_004cf9c0(0xffffffff,0);
  FUN_004cee86(0x200);
  return;
}

