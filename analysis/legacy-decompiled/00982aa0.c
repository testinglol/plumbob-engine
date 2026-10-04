
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00982cc8) */

undefined4 FUN_00982aa0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 local_60 [16];
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  code *local_34;
  int *local_30;
  int *local_2c;
  uint local_28;
  uint local_24;
  char local_1e;
  char local_1d;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00dd0b80 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_00462530();
  local_1c[0x1b] = iVar2;
  local_28 = (uint)(DAT_00e1d94d == '\0');
  *(bool *)((int)local_1c + 0x71) = DAT_00e1d94d == '\0';
  local_30 = local_1c + 0x12;
  local_34 = *(code **)(local_1c[0x12] + 8);
  piVar3 = (int *)(*local_34)(local_60);
  local_1c[0x20] = *piVar3;
  local_1c[0x21] = piVar3[1];
  local_1c[0x22] = piVar3[2];
  local_38 = DAT_00dcfeb0;
  local_3c = FUN_00982a90();
  local_40 = FUN_00983350();
  piVar3 = (int *)FUN_0044ca70(local_40,local_3c,local_38);
  local_1c[0x1d] = *piVar3;
  local_1c[0x1e] = piVar3[1];
  local_1c[0x1f] = piVar3[2];
  if (*(char *)((int)local_1c + 0x71) == '\0') {
    if (((uint)local_1c[0x20] < DAT_00dcfea8) || ((uint)local_1c[0x21] < DAT_00dcfeac)) {
      local_1d = '\x01';
    }
    else {
      local_1d = '\0';
    }
    local_1e = local_1d;
    if (local_1d != '\0') {
      *(undefined1 *)((int)local_1c + 0x71) = 1;
    }
  }
  local_44 = local_1c + 0x16;
  FUN_00982e20(0,0,DAT_00dcfea8,DAT_00dcfeac);
  if ((*(char *)((int)local_1c + 0x71) != '\0') &&
     (cVar1 = FUN_00982d90(&DAT_00dcfea8), cVar1 == '\0')) {
    *(undefined1 *)((int)local_1c + 0x71) = 0;
  }
  cVar1 = (**(code **)(local_1c[0x2e] + 0xc))();
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else {
    if (*(char *)((int)local_1c + 0x71) != '\0') {
      *(undefined1 *)((int)local_1c + 0x71) = 0;
      local_48 = *(code **)(*local_1c + 0x28);
      (*local_48)(1);
    }
    if (*(char *)((int)local_1c + 0x71) == '\0') {
      (**(code **)(local_1c[0x2e] + 0x194))();
    }
    local_1c[0x13] = 0;
    GetClientRect(DAT_00e1d43c,&local_18);
    local_50 = FUN_00981e10();
    local_4c = FUN_00982a00();
    cVar1 = FUN_009bfaa0(local_4c,local_18.right,local_18.bottom);
    if (cVar1 == '\0') {
      MessageBoxA((HWND)0x0,
                  "The game was unable to find a suitable Vulkan device on this machine. Please update your graphic card drivers and try again. More help: https://go.ea.com/sims-legacy"
                  ,"Vulkan Initialization Failed",0x42010);
      uVar4 = 0;
    }
    else {
      local_2c = (int *)FUN_00462530();
      (**(code **)(*local_2c + 0x18))();
      FUN_00964be0();
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        FUN_00982840(local_24);
      }
      uVar4 = 1;
    }
  }
  return uVar4;
}

