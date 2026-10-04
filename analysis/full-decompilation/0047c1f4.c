
void FUN_0047c1f4(int param_1,int param_2,int param_3,int param_4)

{
  POINT pt;
  int iVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  RECT local_1c;
  int local_c;
  int local_8;
  
  iVar1 = DAT_006e54dc;
  local_1c.left = param_1 + 1;
  local_c = 0;
  local_1c.right = (*(int *)(DAT_006e54dc + 0x10) - param_4) + -1;
  local_1c.top = param_2 + 1;
  local_1c.bottom = (*(int *)(DAT_006e54dc + 0x10) - param_3) + -1;
  iVar3 = *(int *)(DAT_006e54dc + 0x10);
  if (0 < iVar3) {
    do {
      local_8 = 0;
      if (0 < iVar3) {
        iVar3 = (int)(char)local_c;
        do {
          iVar4 = (int)(char)local_8;
          param_1._3_1_ =
               *(byte *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x34) + 0xc) + iVar3 * 4) + iVar4);
          pt.y = local_8;
          pt.x = local_c;
          BVar2 = PtInRect(&local_1c,pt);
          if (BVar2 == 0) {
            param_1._3_1_ = param_1._3_1_ | 0x20;
          }
          else {
            param_1._3_1_ = param_1._3_1_ & 0xdf;
          }
          local_8 = local_8 + 1;
          *(byte *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x34) + 0xc) + iVar3 * 4) + iVar4) =
               param_1._3_1_;
        } while (local_8 < *(int *)(iVar1 + 0x10));
      }
      iVar3 = *(int *)(iVar1 + 0x10);
      local_c = local_c + 1;
    } while (local_c < iVar3);
  }
  return;
}

