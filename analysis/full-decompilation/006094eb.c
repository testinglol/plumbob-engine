
bool __thiscall FUN_006094eb(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*param_1 != 0) && (param_1[0xb] <= param_4)) {
    param_4 = param_4 - param_1[0xb];
    iVar1 = FUN_00609589(param_2);
    if (iVar1 == 0) {
      if (param_3 < 0) {
        return false;
      }
      iVar1 = param_1[2];
      if (iVar1 <= param_3) {
        return false;
      }
      if (param_4 < 0) {
        return false;
      }
      iVar2 = param_1[3];
    }
    else {
      if (param_3 < 0) {
        return false;
      }
      iVar1 = param_1[5];
      if (iVar1 <= param_3) {
        return false;
      }
      if (param_4 < 0) {
        return false;
      }
      iVar2 = param_1[6];
    }
    if (param_4 < iVar2) {
      iVar2 = FUN_00609342(param_2);
      return ((byte)(1 << (7U - (char)(param_3 % 8) & 0x1f)) &
             *(byte *)(iVar2 + ((iVar1 + 7) / 8) * param_4 + param_3 / 8)) != 0;
    }
  }
  return false;
}

