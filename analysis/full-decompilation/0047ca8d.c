
void __thiscall FUN_0047ca8d(int param_1,byte *param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(param_1 + 8);
  if (0 < iVar1) {
    do {
      iVar3 = 0;
      do {
        pbVar2 = (byte *)(*(int *)(*(int *)(param_1 + 0xc) + (char)iVar3 * 4) + (int)(char)local_8);
        *pbVar2 = *pbVar2 & *param_2;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
      local_8 = local_8 + 1;
    } while (local_8 < iVar1);
  }
  return;
}

