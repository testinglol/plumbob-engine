
undefined1 __fastcall FUN_0060423d(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 *local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  int *local_c;
  int *local_8;
  
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  _memset(&local_34,0,0x14);
  _memset(&local_20,0,0x12);
  local_24 = &local_20;
  local_20 = 1;
  local_1e = 1;
  local_1c = 0x2b11;
  local_18 = 0x5622;
  local_14 = 2;
  local_12 = 0x10;
  local_10 = 0;
  local_34 = 0x14;
  local_2c = 0x400;
  local_30 = 0x12;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                    (*(int **)(param_1 + 0x50),&local_34,&local_8,0);
  if (iVar2 == 0) {
    (**(code **)*local_8)(local_8,&DAT_00677238,&local_c);
    uVar1 = FUN_00607a38(local_c);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
      local_8 = (int *)0x0;
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

