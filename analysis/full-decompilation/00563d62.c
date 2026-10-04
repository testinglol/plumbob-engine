
undefined4 __fastcall FUN_00563d62(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if ((0 < *(int *)(param_1 + 0x134)) || (0 < *(int *)(param_1 + 0x138))) {
    local_1c = *(undefined4 *)(param_1 + 0x7c);
    local_18 = *(undefined4 *)(param_1 + 0x80);
    local_14 = *(undefined4 *)(param_1 + 0x84);
    local_10 = *(undefined4 *)(param_1 + 0x88);
    FUN_004df599(&local_2c,(int *)(param_1 + 0x134));
    FUN_0055ffd5(*(undefined4 *)(param_1 + 0x5c),&local_1c,&local_2c,DAT_006f2a68);
  }
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar1 = *(int *)(param_1 + 0x13c);
      local_2c = *(undefined4 *)(iVar1 + 0x14);
      local_28 = *(undefined4 *)(iVar1 + 0x18);
      local_24 = *(undefined4 *)(iVar1 + 0x1c);
      local_20 = *(undefined4 *)(iVar1 + 0x20);
      local_c = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x134);
      local_8 = *(int *)(param_1 + 0x138) + *(int *)(param_1 + 0x20);
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      FUN_004ba5ac(&local_c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x13c),&local_2c,&local_1c,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

