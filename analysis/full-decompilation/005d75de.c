
void __fastcall FUN_005d75de(int param_1)

{
  char cVar1;
  int *piVar2;
  LONG local_24;
  LONG local_20;
  int local_1c;
  int local_18;
  tagPOINT local_14;
  tagPOINT local_c;
  
  local_24 = *(LONG *)(param_1 + 0x7c);
  local_20 = *(LONG *)(param_1 + 0x80);
  local_1c = *(int *)(param_1 + 0x84);
  local_18 = *(int *)(param_1 + 0x88);
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  cVar1 = (**(code **)(*piVar2 + 0x18))();
  if ((cVar1 == '\0') && (DAT_006fe8cc != (HWND)0x0)) {
    local_c.x = 0;
    local_14.x = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
    local_c.y = 0;
    local_14.y = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
    ClientToScreen(DAT_006fe8cc,&local_c);
    ClientToScreen(DAT_006fe8cc,&local_14);
    local_24 = local_c.x;
    local_20 = local_c.y;
    local_1c = local_14.x;
    local_18 = local_14.y;
  }
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x24))();
  (**(code **)(*piVar2 + 0xf0))(&local_24);
  return;
}

