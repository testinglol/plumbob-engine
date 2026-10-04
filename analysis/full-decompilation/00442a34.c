
undefined4 __thiscall FUN_00442a34(int param_1,int *param_2)

{
  undefined2 uVar1;
  short sVar2;
  int local_60;
  undefined2 local_5c;
  undefined1 local_54 [4];
  undefined4 local_50;
  undefined1 local_40 [20];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0x52636f6e;
  local_1c = 0;
  sVar2 = (**(code **)(*param_2 + 0x34))(0x52636f6e);
  local_20 = (int)sVar2;
  for (local_8 = local_20; 0 < local_8; local_8 = local_8 + -1) {
    local_c = (**(code **)(*param_2 + 0x38))(0x52636f6e,local_8,FUN_00465037);
    if (local_c != 0) {
      local_24 = FUN_00420048(local_c);
      local_2c = *(undefined4 *)(local_24 + 8);
      FUN_0042004f(local_c);
      FUN_00455b98(local_2c,param_1);
      FUN_00449d6b(local_40,local_c,local_2c,&local_28);
      if (local_1c == 0) {
        local_1c = local_28;
      }
    }
  }
  local_8 = 1;
  for (local_10 = *(int *)(param_1 + 0x30); local_10 != 0; local_10 = *(int *)(local_10 + 0xe0)) {
    local_c = (**(code **)(*param_2 + 0x38))(0x52636f6e,local_8,FUN_00465037);
    if (local_c != 0) {
      FUN_00455b62(local_10);
      FUN_00449d6b(local_54,local_c,local_50,0);
      FUN_00465a06(local_c);
    }
    local_8 = local_8 + 1;
  }
  if (local_1c < 0x17) {
    for (local_18 = *(int *)(param_1 + 0x30); local_18 != 0; local_18 = *(int *)(local_18 + 0xe0)) {
      FUN_0043270d(local_18);
      if (local_60 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined2 *)(local_60 + 0xf0);
      }
      *(undefined2 *)(local_18 + 0x4e) = uVar1;
      *(undefined2 *)(local_18 + 0x50) = local_5c;
    }
  }
  FUN_00442bdf();
  FUN_00443cf3();
  return 0;
}

