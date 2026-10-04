
int __thiscall FUN_00491113(int param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint3 uVar4;
  undefined1 extraout_var;
  undefined4 local_14;
  
  pcVar1 = param_2;
  iVar2 = DAT_006e54d8;
  if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)*param_2) &&
       ((int)*param_2 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
      (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)param_2[1])) &&
     (iVar2 = *(int *)(DAT_006e54d8 + 0x7c) + -1, param_2[1] <= iVar2)) {
    local_14 = 1;
    iVar2 = FUN_00491801(param_2);
    if ((char)iVar2 != '\0') {
      param_2 = (char *)&local_14;
      local_14 = CONCAT13(extraout_var,*(undefined3 *)pcVar1);
      iVar3 = FUN_004796d9(&param_2);
      iVar2 = (uint)*(byte *)(iVar3 + 1) + param_3;
      if (iVar2 < 0x41) {
        if (iVar2 < 0) {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0x40;
      }
      local_14 = (uint)*(byte *)(iVar3 + 1) - iVar2;
      iVar3 = FUN_00636bef();
      if (iVar3 != 0) {
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + DAT_006e57d0 * iVar3;
        local_14 = iVar2;
        FUN_004909e0(pcVar1);
        local_14 = (int)pcVar1[1];
        iVar2 = FUN_00491375((int)*pcVar1,local_14,(int)*pcVar1);
        return iVar2;
      }
      uVar4 = 0;
      *(char *)(param_1 + 0x34) = *pcVar1;
      *(char *)(param_1 + 0x35) = pcVar1[1];
      *(char *)(param_1 + 0x36) = pcVar1[2];
      if (param_3 < 1) {
        *(undefined4 *)(param_1 + 0x38) = 3;
      }
      else {
        *(undefined4 *)(param_1 + 0x38) = 2;
      }
      goto LAB_00491224;
    }
  }
  *(undefined4 *)(param_1 + 0x38) = 1;
  uVar4 = (uint3)((uint)iVar2 >> 8);
  *(char *)(param_1 + 0x34) = *pcVar1;
  *(char *)(param_1 + 0x35) = pcVar1[1];
  *(char *)(param_1 + 0x36) = pcVar1[2];
LAB_00491224:
  return (uint)uVar4 << 8;
}

