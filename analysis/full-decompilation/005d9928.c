
void __thiscall FUN_005d9928(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  tagPOINT local_c;
  
  local_c.x = param_1;
  local_c.y = param_1;
  GetCursorPos(&local_c);
  ScreenToClient(DAT_006fe8cc,&local_c);
  *param_2 = local_c.x;
  *param_3 = local_c.y;
  if (*param_2 < 0) {
    *param_2 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x2c);
    if (*(int *)(iVar1 + 0x84) - *(int *)(iVar1 + 0x7c) <= *param_2) {
      *param_2 = (*(int *)(iVar1 + 0x84) - *(int *)(iVar1 + 0x7c)) + -1;
    }
  }
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x2c);
    if (*(int *)(iVar1 + 0x88) - *(int *)(iVar1 + 0x80) <= *param_3) {
      *param_3 = (*(int *)(iVar1 + 0x88) - *(int *)(iVar1 + 0x80)) + -1;
    }
  }
  return;
}

