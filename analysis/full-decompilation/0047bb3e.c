
void __fastcall FUN_0047bb3e(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(param_1 + 0x14);
  local_c = param_1;
  if (0 < *(int *)(iVar1 + 8)) {
    do {
      sVar2 = 0;
      if (0 < *(int *)(iVar1 + 4)) {
        iVar3 = (int)(char)local_8;
        do {
          local_c._0_3_ = CONCAT12(1,CONCAT11((char)sVar2,(char)local_8));
          iVar1 = *(int *)(*(int *)(iVar1 + 0xc) + iVar3 * 4);
          FUN_0047b747(&local_c,CONCAT31((int3)((uint)iVar1 >> 8),
                                         *(undefined1 *)(iVar1 + 1 + (char)sVar2 * 4)));
          iVar1 = *(int *)(param_1 + 0x14);
          sVar2 = sVar2 + 1;
        } while ((int)sVar2 < *(int *)(iVar1 + 4));
      }
      local_8 = local_8 + 1;
      iVar1 = *(int *)(param_1 + 0x14);
    } while ((int)(short)local_8 < *(int *)(iVar1 + 8));
  }
  return;
}

